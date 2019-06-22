///////////////////////////////////////////////////////////////////////////////

#include "game_parser.h"
#include "file_wrapper.h"
#include "exceptions.h"
#include "game_utils.h"
#include "logger.h"
#include "utils.h"
#include "function_timer.h"
#include "compacted_position.h"

///////////////////////////////////////////////////////////////////////////////

GameParser::GameParser(FileWrapper& pgnFile_)
	: pgnFile(pgnFile_.file)
	, curGame(make_unique<Game>()) {
	//gameVec.reserve(1000000);
	//compactedPositionInfoVec.reserve(12000000);
}

void GameParser::parse() {
	parsePGN();
	long numPositions = generateCompactedPositions();
	fillCompactedPositionInfoVec(numPositions);
}

void GameParser::parsePGN() {

	log(__FUNCTION__);

	ASSERT(pgnFile != nullptr);

	compactedPositionVec.clear();

	char line[MAX_LINE_BUF_SZ];

	int numLines = 0;

	int state = STATE_LINE_START;
	int nextState = STATE_LINE_START;

	while (fgets(line, MAX_LINE_BUF_SZ, pgnFile)) {
		FunctionTimer fnTimer(__FUNCTION__ " parser");

		StringUtils::chomp(line);

		++numLines;

		if ((numLines % 1000) == 0) {
			log("# lines: %d, gameVec sz: %d", numLines, (int)gameVec.size());
		}

		switch (state) {
			case STATE_LINE_START:
			{
				state = parseLine_Start(line);
				break;
			}
			case STATE_LINE_IN_GAME_METADATA:
			{
				nextState = parseLine_InMetaData(line);

				if (nextState == STATE_LINE_IN_GAME_MOVES) {
					curPos.clear();
					nextState = parseLine_InGameMoves(line);
				}

				state = nextState;

				break;
			}
			case STATE_LINE_IN_GAME_MOVES:
			{
				nextState = parseLine_InGameMoves(line);
				state = nextState;
				break;
			}
		}
	}

	fclose(pgnFile);

	log("gamevec sz: %d", (int)gameVec.size());
	log("#" __FUNCTION__);
}

long GameParser::generateCompactedPositions() {
	long numPositions = 0;

	int numGames = gameVec.size();
	for (int i = 0; i < numGames; ++i) {
		Game& game = *gameVec[i];
		vector<unique_ptr<Move>>& moveVec = game.moveVec;
		Position pos;

		if ((i % 100) == 0) {
			log("game: (%d/%d)", i, numGames);
			log("numPositions: %ld", numPositions);
		}

		int numMoves = moveVec.size();
		vector<unique_ptr<CompactedPosition>>& compactedPosVec = game.compactedPositionVec;
		compactedPosVec.reserve(numMoves);

		for (int j = 0; j < numMoves; ++j) {
			const Move& move = *moveVec[j];

			{
				FunctionTimer getNextPosTimer(__FUNCTION__ " - pos.getNextPosition");

				pos.getNextPosition(pos, move);
				++numPositions;
			}

			{
				FunctionTimer getNextPosTimer(__FUNCTION__ " - pos.toCompactedPos");

				unique_ptr<CompactedPosition> compactPos = make_unique<CompactedPosition>();
				toCompactedPosition(pos, *compactPos);

				compactedPosVec.emplace_back(std::move(compactPos));
			}
		}
	}

	return numPositions;
}

void GameParser::fillCompactedPositionInfoVec(long numPositions) {
	compactedPositionInfoVec.reserve(numPositions);

	int numGames = gameVec.size();
	{
		for (int i = 0; i < numGames; ++i) {

			FunctionTimer timer(__FUNCTION__ " - build compactedPositionInfoVec");

			if ((i % 1000) == 0) {
				log("build compactedPositionInfoVec (%d/%d)", i, numGames);
			}

			Game& curGame = *gameVec[i];
			vector<unique_ptr<CompactedPosition>>& curGameCompactPosVec = curGame.compactedPositionVec;

			for (unique_ptr<CompactedPosition>& compactPos : curGameCompactPosVec) {
				unique_ptr<CompactedPositionInfo> compactPosInfo = make_unique<CompactedPositionInfo>(*compactPos);
				compactedPositionInfoVec.emplace_back(std::move(compactPosInfo));
			}
		}
	}

	{
		FunctionTimer timer(__FUNCTION__ " - sort");

		auto begin = compactedPositionInfoVec.begin();
		auto end = compactedPositionInfoVec.end();
		sort(begin, end, [](const unique_ptr<CompactedPositionInfo>& info1, const unique_ptr<CompactedPositionInfo>& info2) {
			return *info1 < *info2;
		});
	}

	{
		FunctionTimer timer(__FUNCTION__ " - erase");

		auto begin = compactedPositionInfoVec.begin();
		auto end = compactedPositionInfoVec.end();

		auto eraseIt = unique(begin, end, [](const unique_ptr<CompactedPositionInfo>& info1, const unique_ptr<CompactedPositionInfo>& info2) {
			return *info1 == *info2;
		});

		long numToKeep = distance(begin, eraseIt);
		long numToErase = compactedPositionInfoVec.size() - numToKeep;
		log("# positions: %ld. # to keep: %ld, # to erase: %ld", 
			(long)compactedPositionInfoVec.size(), numToKeep, numToErase);

		compactedPositionInfoVec.erase(eraseIt, compactedPositionInfoVec.end());
	}

	{
		auto begin = compactedPositionInfoVec.begin();
		auto end = compactedPositionInfoVec.end();
		log("compactedPositionInfoVec sz: %ld", (long)compactedPositionInfoVec.size());

		for (int i = 0; i < numGames; ++i) {
			FunctionTimer timer(__FUNCTION__ " - build compactedPositionMap");

			if ((i % 1000) == 0) {
				log("build compactedPositionMap (%d/%d)", i, numGames);
			}

			const Game& game = *gameVec[i];
			const vector<unique_ptr<CompactedPosition>>& curGameCompactPosVec = game.compactedPositionVec;

			for (const unique_ptr<CompactedPosition>& compactPos : curGameCompactPosVec) {
				unique_ptr<CompactedPositionInfo> curGameCurPosInfo = make_unique<CompactedPositionInfo>(*compactPos);
				auto itPair = equal_range(begin, end, curGameCurPosInfo,
										  [](const unique_ptr<CompactedPositionInfo>& info1, const unique_ptr<CompactedPositionInfo>& info2) {
					return *info1 < *info2;
				});

				auto it = itPair.first;
				ASSERT(it != end);

				unique_ptr<CompactedPositionInfo>& compactedPosInfo = *it;
				vector<int>& gameIndices = compactedPosInfo->gameIndices;
				gameIndices.emplace_back(i);
			}
		}
	}
}

int GameParser::parseLine_Start(const char* line) {
	static const int STATE_START = 0;
	static const int STATE_METADATA_START = 1;
	static const int STATE_METADATA_IN_KEY = 2;
	static const int STATE_METADATA_END_OF_KEY = 3;
	static const int STATE_METADATA_IN_VALUE = 4;
	static const int STATE_BAD_LINE = 255;
	static const int STATE_FINISHED = 256;

	int state = STATE_START;
	string curWord;
	GameMetaDataKeyType keyType = eGameMetaDataKey_None;

	for (const char* p = line
		 ; p && *p && *p != '\n' && state != STATE_BAD_LINE && state != STATE_FINISHED
		 ; ++p) {
		char c = *p;
		switch (state) {
			case STATE_START:
			{
				if (c == '[') {
					curWord.clear();
					state = STATE_METADATA_START;
				} else {
					state = STATE_FINISHED;
				}

				break;
			}
			case STATE_METADATA_START:
			{
				if (isspace(c)) {
					// Do nothing
				} else {
					curWord.push_back(c);
					state = STATE_METADATA_IN_KEY;
				}

				break;
			}
			case STATE_METADATA_IN_KEY:
			{
				if (isspace(c)) {
					keyType = getGameMetaDataKeyFromString(curWord.c_str());
					if (keyType == eGameMetaDataKey_None) {
						state = STATE_BAD_LINE;
					} else {
						state = STATE_METADATA_END_OF_KEY;
					}
				} else {
					curWord.push_back(c);
				}

				break;
			}
			case STATE_METADATA_END_OF_KEY:
			{
				if (c == '"') {
					curWord.clear();
					state = STATE_METADATA_IN_VALUE;
				} else if (c == ']') {
					state = STATE_BAD_LINE;
				}

				break;
			}
			case STATE_METADATA_IN_VALUE:
			{
				if (c == '"') {
					curGame->metaData.updateKey(keyType, curWord.c_str());
					state = STATE_FINISHED;
				} else {
					curWord.push_back(c);
				}

				break;
			}
			case STATE_BAD_LINE:
			{
				break;
			}
			case STATE_FINISHED:
			{
				break;
			}
			default:
			{
				throw Exception("Error: invalid state in " __FUNCTION__ ": %d", state);
			}
		}
	}

	if (state == STATE_FINISHED) {
		return STATE_LINE_IN_GAME_METADATA;
	} else {
		return STATE_LINE_START;
	}
}

int GameParser::parseLine_InMetaData(const char* line) {
	static const int STATE_START = 0;
	static const int STATE_METADATA_START = 1;
	static const int STATE_METADATA_IN_KEY = 2;
	static const int STATE_METADATA_END_OF_KEY = 3;
	static const int STATE_METADATA_IN_VALUE = 4;
	static const int STATE_BAD_LINE = 255;
	static const int STATE_FINISHED = 256;

	int state = STATE_START;
	int nextParserState = STATE_LINE_IN_GAME_METADATA;
	string curWord;
	GameMetaDataKeyType keyType = eGameMetaDataKey_None;

	for (const char* p = line
		 ; p && *p && *p != '\n' && state != STATE_BAD_LINE && state != STATE_FINISHED
		 ; ++p) {
		char c = *p;
		switch (state) {
			case STATE_START:
			{
				if (c == '[') {
					curWord.clear();
					state = STATE_METADATA_START;
				} else if (c == '1') {
					nextParserState = STATE_LINE_IN_GAME_MOVES;
					state = STATE_FINISHED;
				} else {
					state = STATE_FINISHED;
				}

				break;
			}
			case STATE_METADATA_START:
			{
				if (isspace(c)) {
					// Do nothing
				} else {
					curWord.push_back(c);
					state = STATE_METADATA_IN_KEY;
				}

				break;
			}
			case STATE_METADATA_IN_KEY:
			{
				if (isspace(c)) {
					keyType = getGameMetaDataKeyFromString(curWord.c_str());
					if (keyType == eGameMetaDataKey_None) {
						state = STATE_BAD_LINE;
					} else {
						state = STATE_METADATA_END_OF_KEY;
					}
				} else {
					curWord.push_back(c);
				}

				break;
			}
			case STATE_METADATA_END_OF_KEY:
			{
				if (c == '"') {
					curWord.clear();
					state = STATE_METADATA_IN_VALUE;
				} else if (c == ']') {
					state = STATE_BAD_LINE;
				}

				break;
			}
			case STATE_METADATA_IN_VALUE:
			{
				if (c == '"') {
					curGame->metaData.updateKey(keyType, curWord.c_str());
					state = STATE_FINISHED;
				} else {
					curWord.push_back(c);
				}

				break;
			}
			case STATE_BAD_LINE:
			{
				break;
			}
			case STATE_FINISHED:
			{
				break;
			}
			default:
			{
				throw Exception("Error: invalid state in " __FUNCTION__ ": %d", state);
			}
		}
	}

	return nextParserState;
}

int GameParser::parseLine_InGameMoves(const char* line) {
	FunctionTimer fnTimer(__FUNCTION__);

	static const int STATE_START = 0;
	static const int STATE_IN_MOVE = 1;
	static const int STATE_BAD_LINE = 255;
	static const int STATE_FINISHED = 256;

	int state = STATE_START;
	int nextParserState = STATE_LINE_IN_GAME_MOVES;
	string curWord;

	static auto fn = [&]() {
		bool isValidMove = false;
		bool isEndOfGame = false;
		unique_ptr<Move> nextMovePointer;
		parseMove(curWord.c_str(), nextMovePointer, isEndOfGame);

		if (nextMovePointer != nullptr) {
			curPos.getNextPosition(curPos, *nextMovePointer);

			vector<unique_ptr<Move>>& curGameMoveVec = curGame->moveVec;
			curGameMoveVec.emplace_back(move(nextMovePointer));
		}

		if (isEndOfGame) {
			nextParserState = STATE_LINE_START;
			state = STATE_FINISHED;
			gameVec.emplace_back(std::move(curGame));

			curGame = make_unique<Game>();
		} else {
			curWord.clear();
			state = STATE_START;
		}
	};

	for (const char* p = line
		 ; p && *p && *p != '\n' && state != STATE_BAD_LINE && state != STATE_FINISHED
		 ; ++p) {
		char c = *p;
		switch (state) {
			case STATE_START:
			{
				if (isalnum(c) || c == '*') {
					curWord.clear();
					curWord.push_back(c);
					state = STATE_IN_MOVE;
				}

				break;
			}
			case STATE_IN_MOVE:
			{
				if (isspace(c)) {

					fn();

				} else {
					curWord.push_back(c);
				}

				break;
			}
			default:
			{
				throw Exception("Error: invalid state in " __FUNCTION__ ": %d", state);
			}
		}
	}

	if (state == STATE_IN_MOVE) {

		fn();
	}

	return nextParserState;
}

void GameParser::parseMove(const char* moveStr, unique_ptr<Move>& nextMove, bool& isEndOfGame) {
	static const int STATE_START = 0;
	static const int STATE_FOUND_NUMBER = 1; // e.g. 101.Nc3 or 1-0 or 1/2-1/2
	// static const int STATE_FOUND_NUMBER_DOT = 2; // e.g. 101.Nc3
	static const int STATE_FOUND_NUMBER_DASH = 3; // e.g. 1-0
	//static const int STATE_FOUND_NUMBER_DASH_NUMBER = 4; // e.g. 1-0
	static const int STATE_FOUND_NUMBER_SLASH = 5; // e.g. 1/2-1/2
	static const int STATE_FOUND_NUMBER_SLASH_NUMBER = 6; // e.g. 1/2-1/2
	static const int STATE_FOUND_NUMBER_SLASH_NUMBER_DASH = 7; // e.g. 1/2-1/2
	static const int STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER = 8; // e.g. 1/2-1/2
	static const int STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER_SLASH = 9; // e.g. 1/2-1/2
	//static const int STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER_SLASH_NUMBER = 10; // e.g. 1/2-1/2
	static const int STATE_FOUND_FILE = 11; // e.g. f5 or cxd8=Q+
	static const int STATE_FOUND_FILE_CAPTURE = 12; // e.g. cxd8=Q+
	static const int STATE_FOUND_FILE_CAPTURE_FILE = 13; // e.g. cxd8=Q+
	static const int STATE_FOUND_FILE_CAPTURE_FILE_RANK = 14; // e.g. cxd8=Q+
	static const int STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS = 15; // e.g. cxd8=Q+
	static const int STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS_PIECE = 16; // e.g. cxd8=Q+
	static const int STATE_FOUND_FILE_RANK = 17; // e.g. f8=Q+
	static const int STATE_FOUND_FILE_RANK_EQUALS = 18; // e.g. f8=Q+
	static const int STATE_FOUND_FILE_RANK_EQUALS_PIECE = 19; // e.g. f8=Q+
	static const int STATE_FOUND_PIECE = 20; // e.g. Nd5+ or Nxd8+ or Nbd7+ or N1d3+
	static const int STATE_FOUND_PIECE_CAPTURE = 21; // e.g. Nxd8+
	static const int STATE_FOUND_PIECE_CAPTURE_FILE = 22; // e.g. Nxd8+
	static const int STATE_FOUND_PIECE_CAPTURE_FILE_RANK = 23; // e.g. Nxd8+
	static const int STATE_FOUND_PIECE_FILE = 24; // e.g. Nd5+ or Nbd7+
	static const int STATE_FOUND_PIECE_FILE_RANK = 25; // e.g. Nd5+
	static const int STATE_FOUND_PIECE_FILE_FILE = 26; // e.g. Nbd7+
	static const int STATE_FOUND_PIECE_FILE_FILE_RANK = 27; // e.g. Nbd7+
	static const int STATE_FOUND_PIECE_RANK = 28; // e.g. N1d3+
	static const int STATE_FOUND_PIECE_RANK_FILE = 29; // e.g. N1d3+
	static const int STATE_FOUND_PIECE_RANK_FILE_RANK = 30; // e.g. N1d3+

	static const int STATE_FOUND_PIECE_FILE_CAPTURE = 31; // e.g. Nbxd5+
	static const int STATE_FOUND_PIECE_FILE_CAPTURE_FILE = 32; // e.g. Nbxd5+
	static const int STATE_FOUND_PIECE_FILE_CAPTURE_FILE_RANK = 33; // e.g. Nbxd5+

	static const int STATE_FOUND_PIECE_RANK_CAPTURE = 34; // e.g. R1xc2+
	static const int STATE_FOUND_PIECE_RANK_CAPTURE_FILE = 35; // e.g. R1xc2+
	static const int STATE_FOUND_PIECE_RANK_CAPTURE_FILE_RANK = 36; // e.g. R1xc2+

	static const int STATE_FOUND_CASTLE = 37; // e.g. O-O+ or O-O-O+
	static const int STATE_FOUND_CASTLE_DASH = 38; // e.g. O-O+ or O-O-O+
	static const int STATE_FOUND_CASTLE_DASH_CASTLE = 39; // e.g. O-O+ or O-O-O+
	static const int STATE_FOUND_CASTLE_DASH_CASTLE_DASH = 40; // e.g. O-O-O+
	static const int STATE_FOUND_CASTLE_DASH_CASTLE_DASH_CASTLE = 41; // e.g. O-O-O+
	static const int STATE_BAD = 255;
	static const int STATE_FINISHED = 256;

	int state = STATE_START;
	int prevState = STATE_START;

	bool foundMoveNum = false;

	char firstNum = 0;
	char secondNum = 0;
	bool isWhiteWin = false;
	bool isBlackWin = false;
	bool isDraw = false;
	bool isOtherResult = false;

	bool isCaptureOrEnPassant = false;
	bool isPromotion = false;
	bool isCastleKingSide = false;
	bool isCastleQueenSide = false;
	FileType file1 = eFile_None;
	FileType file2 = eFile_None;
	RankType rank1 = eRank_None;
	RankType rank2 = eRank_None;
	PieceType piece = ePiece_None;
	PieceType promotionPiece = ePiece_None;

	const char* p = moveStr;
	for (;
		 p && *p && state != STATE_BAD && state != STATE_FINISHED;
		 ++p) {
		char c = *p;
		prevState = state;

		switch (state) {
			case STATE_START:
			{
				if (isdigit(c)) {
					if (foundMoveNum) {
						state = STATE_BAD;
					} else {
						firstNum = c;
						state = STATE_FOUND_NUMBER;
					}
				} else if (islower(c)) {
					file1 = GameUtils::pgnCharToFile(c);
					if (file1 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_FILE;
					}
				} else if (c == 'O') {
					state = STATE_FOUND_CASTLE;
				} else if (isupper(c)) {
					piece = GameUtils::pgnCharToPiece(c, curPos.colorToMove);
					if (piece == ePiece_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE;
					}
				} else if (c == '*') {
					isOtherResult = true;
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER:
			{
				if (isdigit(c)) {
					// e.g. 101.Nc3
					//       ^
				} else if (c == '.') {
					// e.g. 101.Nc3
					foundMoveNum = true;
					state = STATE_START;
				} else if (c == '-') {
					// e.g. 1-0
					state = STATE_FOUND_NUMBER_DASH;
				} else if (c == '/') {
					// e.g. 1/2-1/2
					state = STATE_FOUND_NUMBER_SLASH;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER_DASH:
			{
				if (isdigit(c)) {
					// e.g. 1-0
					secondNum = c;

					if (firstNum == '0' && secondNum == '1') {
						isBlackWin = true;
						state = STATE_FINISHED;
					} else if (firstNum == '1' && secondNum == '0') {
						isWhiteWin = true;
						state = STATE_FINISHED;
					} else {
						state = STATE_BAD;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER_SLASH:
			{
				if (firstNum == '1' && c == '2') {
					// e.g. 1/2-1/2
					state = STATE_FOUND_NUMBER_SLASH_NUMBER;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER_SLASH_NUMBER:
			{
				if (c == '-') {
					state = STATE_FOUND_NUMBER_SLASH_NUMBER_DASH;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER_SLASH_NUMBER_DASH:
			{
				if (c == '1') {
					state = STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER:
			{
				if (c == '/') {
					state = STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER_SLASH;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER_SLASH:
			{
				if (c == '2') {
					isDraw = true;
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE:
			{
				if (c == 'x') {
					// e.g. cxd8=Q+
					state = STATE_FOUND_FILE_CAPTURE;
				} else if (isdigit(c)) {
					// e.g. c8=Q+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_CAPTURE:
			{
				if (isalpha(c)) {
					// e.g. cxd8=Q+
					file2 = GameUtils::pgnCharToFile(c);
					if (file2 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_FILE_CAPTURE_FILE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_CAPTURE_FILE:
			{
				if (isdigit(c)) {
					// e.g. cxd8=Q+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_FILE_CAPTURE_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_CAPTURE_FILE_RANK:
			{
				if (c == '=') {
					// e.g. cxd8=Q+
					isPromotion = true;
					state = STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS;
				} else if (c == '+' || c == '#') {
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS:
			{
				if (isupper(c)) {
					// e.g. cxd8=Q+
					promotionPiece = GameUtils::pgnCharToPiece(c, curPos.colorToMove);
					if (promotionPiece == ePiece_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS_PIECE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS_PIECE:
			{
				if (c == '+' || c == '#') {
					// e.g. cxd8=Q+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_RANK:
			{
				if (c == '=') {
					// e.g. c8=Q+
					isPromotion = true;
					state = STATE_FOUND_FILE_RANK_EQUALS;
				} else if (c == '+' || c == '#') {
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_RANK_EQUALS:
			{
				if (isupper(c)) {
					// e.g. c8=Q+
					promotionPiece = GameUtils::pgnCharToPiece(c, curPos.colorToMove);
					if (promotionPiece == ePiece_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_FILE_RANK_EQUALS_PIECE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_FILE_RANK_EQUALS_PIECE:
			{
				if (c == '+' || c == '#') {
					// e.g. c8=Q+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE:
			{
				if (c == 'x') {
					// e.g. Nxd8+
					state = STATE_FOUND_PIECE_CAPTURE;
				} else if (isalpha(c)) {
					// e.g. Nbd7+
					file1 = GameUtils::pgnCharToFile(c);
					if (file1 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_FILE;
					}
				} else if (isdigit(c)) {
					// e.g. N1d3+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_RANK;
					}
				}

				break;
			}
			case STATE_FOUND_PIECE_CAPTURE:
			{
				if (isalpha(c)) {
					// e.g. Nxd8+
					file1 = GameUtils::pgnCharToFile(c);
					if (file1 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_CAPTURE_FILE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_CAPTURE_FILE:
			{
				if (isdigit(c)) {
					// e.g. Nxd8+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_CAPTURE_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_CAPTURE_FILE_RANK:
			{
				if (c == '+' || c == '#') {
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE:
			{
				if (isdigit(c)) {
					// e.g. Nb3+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_FILE_RANK;
					}
				} else if (c == 'x') {
					// e.g. Nbxd5+
					isCaptureOrEnPassant = true;
					state = STATE_FOUND_PIECE_FILE_CAPTURE;
				} else if (isalpha(c)) {
					// e.g. Nbd7+
					file2 = GameUtils::pgnCharToFile(c);
					if (file2 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_FILE_FILE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE_RANK:
			{
				if (c == '+' || c == '#') {
					// e.g. Nb3+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE_FILE:
			{
				if (isdigit(c)) {
					// e.g. Nbd7+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_FILE_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE_FILE_RANK:
			{
				if (c == '+' || c == '#') {
					// e.g. Nbd7+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_RANK:
			{
				if (c == 'x') {
					// e.g. R1xc2+
					isCaptureOrEnPassant = true;
					state = STATE_FOUND_PIECE_RANK_CAPTURE;
				}
				else if (isalpha(c)) {
					// e.g. N1d3+
					file1 = GameUtils::pgnCharToFile(c);
					if (file1 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_RANK_FILE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_RANK_FILE:
			{
				if (isdigit(c)) {
					// e.g. N1d3+
					rank2 = GameUtils::pgnCharToRank(c);
					if (rank2 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_RANK_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_RANK_FILE_RANK:
			{
				if (c == '+' || c == '#') {
					// e.g. Nbd7+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE_CAPTURE:
			{
				if (islower(c)) {
					// e.g. Nbxd5+
					file2 = GameUtils::pgnCharToFile(c);
					if (file2 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_FILE_CAPTURE_FILE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE_CAPTURE_FILE:
			{
				if (isdigit(c)) {
					// e.g. Nbxd5+
					rank1 = GameUtils::pgnCharToRank(c);
					if (rank1 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_FILE_CAPTURE_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_FILE_CAPTURE_FILE_RANK:
			{
				if (c == '+' || c == '#') {
					// e.g. Nbxd5+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_RANK_CAPTURE:
			{
				if (islower(c)) {
					// e.g. R1xc2+
					file1 = GameUtils::pgnCharToFile(c);
					if (file1 == eFile_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_RANK_CAPTURE_FILE;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_RANK_CAPTURE_FILE:
			{
				if (isdigit(c)) {
					// e.g. R1xc2+
					rank2 = GameUtils::pgnCharToRank(c);
					if (rank2 == eRank_None) {
						state = STATE_BAD;
					} else {
						state = STATE_FOUND_PIECE_RANK_CAPTURE_FILE_RANK;
					}
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_PIECE_RANK_CAPTURE_FILE_RANK:
			{
				if (c == '+' || c == '#') {
					// e.g. R1xc2+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_CASTLE:
			{
				if (c == '-') {
					state = STATE_FOUND_CASTLE_DASH;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_CASTLE_DASH:
			{
				if (c == 'O') {
					state = STATE_FOUND_CASTLE_DASH_CASTLE;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_CASTLE_DASH_CASTLE:
			{
				if (c == '-') {
					state = STATE_FOUND_CASTLE_DASH_CASTLE_DASH;
				} else if (c == '+' || c == '#') {
					// e.g. 0-0+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_CASTLE_DASH_CASTLE_DASH:
			{
				if (c == 'O') {
					isCastleQueenSide = true;
					state = STATE_FOUND_CASTLE_DASH_CASTLE_DASH_CASTLE;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			case STATE_FOUND_CASTLE_DASH_CASTLE_DASH_CASTLE:
			{
				if (c == '+' || c == '#') {
					// e.g. 0-0-0+
					state = STATE_FINISHED;
				} else {
					state = STATE_BAD;
				}

				break;
			}
			default:
			{
				throw Exception("Error: invalid state in " __FUNCTION__ ": %d", state);
			}
		}
	}

	if (state == STATE_BAD) {
		throw Exception("Error: invalid move in " __FUNCTION__ ": (state: %d, move: %s)",
						state, moveStr);
	}

	if (state == STATE_FINISHED && p && *p) {
		switch (prevState) {
			case STATE_START: // e.g. *
			case STATE_FOUND_NUMBER_DASH: // i.e. "1-0" or "0-1"
			case STATE_FOUND_NUMBER_SLASH_NUMBER_DASH_NUMBER_SLASH: // i.e. "1/2-1/2"
			case STATE_FOUND_FILE_CAPTURE_FILE_RANK: // e.g. exf7
			case STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS_PIECE: // e.g. exd8=Q
			case STATE_FOUND_FILE_RANK: // e.g. d6
			case STATE_FOUND_FILE_RANK_EQUALS_PIECE: // e.g. d8=Q
			case STATE_FOUND_PIECE_CAPTURE_FILE_RANK: // e.g. Nxd7
			case STATE_FOUND_PIECE_FILE_RANK: // e.g. Na6
			case STATE_FOUND_PIECE_FILE_FILE_RANK: // e.g. Nbd7
			case STATE_FOUND_PIECE_RANK_FILE_RANK: // e.g. N1c3
			case STATE_FOUND_PIECE_RANK_CAPTURE_FILE_RANK: // e.g. R1xc2
			case STATE_FOUND_PIECE_FILE_CAPTURE_FILE_RANK: // e.g. Raxe5
			case STATE_FOUND_CASTLE_DASH_CASTLE: // e.g. O-O
			case STATE_FOUND_CASTLE_DASH_CASTLE_DASH_CASTLE: // e.g. O-O-O
			default:
			{
				throw Exception("Error: invalid move in " __FUNCTION__ ": (state: %d, move: %s)",
								state, moveStr);
			}
		}
	}

	if (isWhiteWin || isBlackWin || isDraw || isOtherResult) {
		isEndOfGame = true;
		return;
	} 

	INT8 finalState = (state == STATE_FINISHED) ? prevState : state;

	// TODO: Create move here
	switch (finalState) {
		case STATE_FOUND_FILE_CAPTURE_FILE_RANK: // e.g. exf7
		{
			nextMove = make_unique<Move>();

			bool isCapture = false;
			bool isEnPassant = false;
			RankType enPassantRank = (curPos.colorToMove == eColor_White) ? eRank_6 : eRank_3;
			PieceType capturingPiece = (curPos.colorToMove == eColor_White) ? ePiece_WhitePawn : ePiece_BlackPawn;

			if (file2 == curPos.enPassantFile && rank1 == enPassantRank) {
				SquareType enPassantSquare = GameUtils::getSquare(file2, enPassantRank);
				if (curPos.board[enPassantSquare] == ePiece_None) {
					isEnPassant = true;
				} else {
					isCapture = true;
				}
			} else {
				isCapture = true;
			}

			INT8 capturingPawnRank_ = eRank_None;
			SquareType occupiedSquare = GameUtils::getSquare(file2, rank1);
			ColorType capturedPieceColor = eColor_None;

			if (isCapture) {
				nextMove->moveType = eMove_Capture;
				capturingPawnRank_ = (curPos.colorToMove == eColor_White) ? rank1 - 1 : rank1 + 1;
				capturedPieceColor = GameUtils::getColorOfPiece(curPos.board[occupiedSquare]);
				nextMove->secondVacatedSquare = eSquare_None;
			} else { // isEnPassant
				nextMove->moveType = eMove_EnPassant;
				capturingPawnRank_ = (curPos.colorToMove == eColor_White) ? eRank_5 : eRank_4;
				RankType enPassantRank2 = static_cast<RankType>(capturingPawnRank_);
				SquareType enPassantSquare = GameUtils::getSquare(file2, enPassantRank2);
				capturedPieceColor = GameUtils::getColorOfPiece(curPos.board[enPassantSquare]);
				nextMove->secondVacatedSquare = enPassantSquare;
			}

			RankType capturingPawnRank = static_cast<RankType>(capturingPawnRank_);
			SquareType vacatedSquare = GameUtils::getSquare(file1, capturingPawnRank);

			nextMove->vacatedSquare = vacatedSquare;
			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = capturingPiece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			if (curPos.board[vacatedSquare] != capturingPiece) {
				nextMove.release();
			} else if (capturedPieceColor == curPos.colorToMove) {
				nextMove.release();
			}

			break;
		}
		case STATE_FOUND_FILE_CAPTURE_FILE_RANK_EQUALS_PIECE: // e.g. exd8=Q
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Capture;

			INT8 capturingPawnRank_ = (curPos.colorToMove == eColor_White) ? rank1 - 1 : rank1 + 1;
			RankType capturingPawnRank = static_cast<RankType>(capturingPawnRank_);

			SquareType vacatedSquare = GameUtils::getSquare(file1, capturingPawnRank);
			SquareType occupiedSquare = GameUtils::getSquare(file2, rank1);
			PieceType capturingPiece = (curPos.colorToMove == eColor_White) ? ePiece_WhitePawn : ePiece_BlackPawn;
			ColorType capturedPieceColor = GameUtils::getColorOfPiece(curPos.board[occupiedSquare]);

			nextMove->vacatedSquare = vacatedSquare;
			nextMove->secondVacatedSquare = eSquare_None;
			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = promotionPiece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			if (curPos.board[vacatedSquare] != capturingPiece) {
				nextMove.release();
			} else if (capturedPieceColor == curPos.colorToMove) {
				nextMove.release();
			}

			break;
		}
		case STATE_FOUND_FILE_RANK: // e.g. d6
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Simple;

			if (curPos.colorToMove == eColor_White) {
				if (rank1 < eRank_2) {
					nextMove.release();
					break;
				}
			} else {
				if (rank1 > eRank_7) {
					nextMove.release();
					break;
				}
			}

			int oneRankBack_ = (curPos.colorToMove == eColor_White) ? rank1 - 1 : rank1 + 1;
			RankType oneRankBack = static_cast<RankType>(oneRankBack_);
			SquareType oneRankBackSquare = GameUtils::getSquare(file1, oneRankBack);
			PieceType movingPiece = (curPos.colorToMove == eColor_White) ? ePiece_WhitePawn : ePiece_BlackPawn;
			PieceType oneRankBackPiece = curPos.board[oneRankBackSquare];

			if (oneRankBackPiece == movingPiece) {
				nextMove->vacatedSquare = oneRankBackSquare;
			} else { // Must be double-pawn move

				if (oneRankBackPiece != ePiece_None) { // Square in-between must be empty
					nextMove.release();
					break;
				}

				if (curPos.colorToMove == eColor_White && rank1 != eRank_4) {
					nextMove.release();
					break;
				} else if (curPos.colorToMove == eColor_Black && rank1 != eRank_5) {
					nextMove.release();
					break;
				}

				RankType twoRanksBack = (curPos.colorToMove == eColor_White) ? eRank_2 : eRank_7;
				SquareType twoRanksBackSquare = GameUtils::getSquare(file1, twoRanksBack);
				PieceType twoRanksBackPiece = curPos.board[twoRanksBackSquare];

				if (twoRanksBackPiece == movingPiece) {
					nextMove->vacatedSquare = twoRanksBackSquare;
				} else {
					nextMove.release();
					break;
				}
			}

			nextMove->occupiedSquare = GameUtils::getSquare(file1, rank1);
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = movingPiece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_FILE_RANK_EQUALS_PIECE: // e.g. d8=Q
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Promotion;

			RankType oneRankBack = eRank_None;
			if (curPos.colorToMove == eColor_White) {
				if (rank1 != eRank_8) {
					nextMove.release();
					break;
				}

				oneRankBack = eRank_7;
			} else {
				if (rank1 != eRank_1) {
					nextMove.release();
					break;
				}

				oneRankBack = eRank_2;
			}

			SquareType vacatedSquare = GameUtils::getSquare(file1, oneRankBack);
			PieceType movingPiece = (curPos.colorToMove == eColor_White) ? ePiece_WhitePawn : ePiece_BlackPawn;

			if (curPos.board[vacatedSquare] != movingPiece) {
				nextMove.release();
				break;
			}

			nextMove->vacatedSquare = vacatedSquare;
			nextMove->secondVacatedSquare = eSquare_None;
			nextMove->occupiedSquare = GameUtils::getSquare(file1, rank1);
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = promotionPiece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_PIECE_CAPTURE_FILE_RANK: // e.g. Nxd7
		{
			nextMove = make_unique<Move>();

			SquareType occupiedSquare = GameUtils::getSquare(file1, rank1);
			SquareType vacatedSquare = GameUtils::findSquareMoveComesFrom(true, piece, occupiedSquare, eFile_None, eRank_None,
																		  curPos.board);

			nextMove->moveType = eMove_Capture;
			nextMove->vacatedSquare = vacatedSquare;
			nextMove->secondVacatedSquare = eSquare_None;
			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = piece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			if (curPos.board[occupiedSquare] == ePiece_None) {
				nextMove.release();
			} else if (curPos.board[vacatedSquare] != piece) {
				nextMove.release();
			}

			break;
		}
		case STATE_FOUND_PIECE_FILE_RANK: // e.g. Na6
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Simple;

			SquareType occupiedSquare = GameUtils::getSquare(file1, rank1);

			nextMove->vacatedSquare = GameUtils::findSquareMoveComesFrom(false, piece, occupiedSquare, eFile_None, eRank_None,
																		curPos.board);

			nextMove->secondVacatedSquare = eSquare_None;

			if (curPos.board[occupiedSquare] != ePiece_None) {
				nextMove.release();
				break;
			}

			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = piece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_PIECE_FILE_FILE_RANK: // e.g. Nbd7
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Simple;

			SquareType occupiedSquare = GameUtils::getSquare(file2, rank1);

			nextMove->vacatedSquare = GameUtils::findSquareMoveComesFrom(false, piece, occupiedSquare, file1, eRank_None,
																		curPos.board);

			nextMove->secondVacatedSquare = eSquare_None;

			if (curPos.board[occupiedSquare] != ePiece_None) {
				nextMove.release();
				break;
			}

			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = piece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_PIECE_RANK_FILE_RANK: // e.g. N1c3
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Simple;

			SquareType occupiedSquare = GameUtils::getSquare(file1, rank2);

			nextMove->vacatedSquare = GameUtils::findSquareMoveComesFrom(false, piece, occupiedSquare, eFile_None, rank1,
																		curPos.board);

			nextMove->secondVacatedSquare = eSquare_None;

			if (curPos.board[occupiedSquare] != ePiece_None) {
				nextMove.release();
				break;
			}

			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = piece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_PIECE_RANK_CAPTURE_FILE_RANK: // e.g. R1xc2
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Capture;

			SquareType occupiedSquare = GameUtils::getSquare(file1, rank2);

			SquareType vacatedSquare = GameUtils::findSquareMoveComesFrom(true, piece, occupiedSquare, eFile_None, rank1,
																		  curPos.board);

			nextMove->vacatedSquare = vacatedSquare;
			nextMove->secondVacatedSquare = eSquare_None;

			if (curPos.board[occupiedSquare] == ePiece_None) {
				nextMove.release();
				break;
			} else if (curPos.board[vacatedSquare] != piece) {
				nextMove.release();
				break;
			}

			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = piece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_PIECE_FILE_CAPTURE_FILE_RANK: // e.g. Raxe5
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Capture;

			SquareType occupiedSquare = GameUtils::getSquare(file2, rank1);

			SquareType vacatedSquare = GameUtils::findSquareMoveComesFrom(true, piece, occupiedSquare, file1, eRank_None,
																		  curPos.board);

			nextMove->vacatedSquare = vacatedSquare;
			nextMove->secondVacatedSquare = eSquare_None;

			if (curPos.board[occupiedSquare] == ePiece_None) {
				nextMove.release();
				break;
			} else if (curPos.board[vacatedSquare] != piece) {
				nextMove.release();
				break;
			}

			nextMove->occupiedSquare = occupiedSquare;
			nextMove->secondOccupiedSquare = eSquare_None;
			nextMove->pieceOnOccupiedSquare = piece;
			nextMove->pieceOnSecondOccupiedSquare = ePiece_None;

			break;
		}
		case STATE_FOUND_CASTLE_DASH_CASTLE: // e.g. O-O
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Castle;
			nextMove->vacatedSquare = (curPos.colorToMove == eColor_White) ? eSquare_E1 : eSquare_E8;
			nextMove->secondVacatedSquare = (curPos.colorToMove == eColor_White) ? eSquare_H1 : eSquare_H8;
			nextMove->occupiedSquare = (curPos.colorToMove == eColor_White) ? eSquare_G1 : eSquare_G8;
			nextMove->secondOccupiedSquare = (curPos.colorToMove == eColor_White) ? eSquare_F1 : eSquare_F8;
			nextMove->pieceOnOccupiedSquare = (curPos.colorToMove == eColor_White) ? ePiece_WhiteKing : ePiece_BlackKing;
			nextMove->pieceOnSecondOccupiedSquare = (curPos.colorToMove == eColor_White) ? ePiece_WhiteRook : ePiece_BlackRook;

			if (!curPos.canCastleKSide()) {
				nextMove.release();
			}

			break;
		}
		case STATE_FOUND_CASTLE_DASH_CASTLE_DASH_CASTLE: // e.g. O-O-O
		{
			nextMove = make_unique<Move>();

			nextMove->moveType = eMove_Castle;
			nextMove->vacatedSquare = (curPos.colorToMove == eColor_White) ? eSquare_E1 : eSquare_E8;
			nextMove->secondVacatedSquare = (curPos.colorToMove == eColor_White) ? eSquare_A1 : eSquare_A8;
			nextMove->occupiedSquare = (curPos.colorToMove == eColor_White) ? eSquare_C1 : eSquare_C8;
			nextMove->secondOccupiedSquare = (curPos.colorToMove == eColor_White) ? eSquare_D1 : eSquare_D8;
			nextMove->pieceOnOccupiedSquare = (curPos.colorToMove == eColor_White) ? ePiece_WhiteKing : ePiece_BlackKing;
			nextMove->pieceOnSecondOccupiedSquare = (curPos.colorToMove == eColor_White) ? ePiece_WhiteRook : ePiece_BlackRook;

			if (!curPos.canCastleQSide()) {
				nextMove.release();
			}

			break;
		}
		default:
		{
			// TODO
			// May happen if a move number ends the line (e.g. "34.\n")
			//throw Exception("Error: invalid move in " __FUNCTION__ ": (state: %d, move: %s)",
			//				state, moveStr);
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
