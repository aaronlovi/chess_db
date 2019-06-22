#include "compact_position_builder.h"
#include "constants.h"
#include "exceptions.h"
#include "game_utils.h"
#include "compacted_position.h"

///////////////////////////////////////////////////////////////////////////////

CompactPositionBuilder::CompactPositionBuilder()
	: state(STATE_START)
	, colorToMove(eColor_White)
	, curSquare(eSquare_A1)
{
	bits.reserve(MAX_POS_SIZE_BITS);
}

void CompactPositionBuilder::appendColorToMove(INT8 color) {
	if (state != STATE_START) {
		throw Exception("Error: " __FUNCTION__ "(color: %d) - Inavlid state: %d",
						color, state);
	}

	colorToMove = color;

	state = STATE_ADDING_PIECES;
}

void CompactPositionBuilder::appendPiece(PieceType piece) {
	if (piece == ePiece_None) {
		bits.push_back(false);
	} else {
		const vector<bool>* pieceRepresentation = nullptr;
		GameUtils::pieceToCompactPositionRepresentation(piece, &pieceRepresentation);
		for (const auto& pieceRepresentationBit : *pieceRepresentation) {
			bits.push_back(pieceRepresentationBit);
		}

		ColorType color = GameUtils::getColorOfPiece(piece);
		bits.push_back(color == eColor_White ? WHITE : BLACK);
	}

	++curSquare;
	nextState_appendingPieces();
}

void CompactPositionBuilder::append50MoveRuleNumHalfMoves(int numHalfMoves) {
	if (numHalfMoves != MATCH_ANY_HALF_MOVES_50_MOVE_RULE
		&& numHalfMoves > MAX_HALF_MOVES_50_MOVE_RULE) {
		numHalfMoves = MAX_HALF_MOVES_50_MOVE_RULE;
	}

	static const int NUM_BITS_REQUIRED = 7;

	int numBitsPushed = 0;
	while (numHalfMoves != 0) {
		int remainder = numHalfMoves % 2;
		bits.push_back(remainder ? true : false);
		numHalfMoves /= 2;

		++numBitsPushed;
	}

	while (numBitsPushed < NUM_BITS_REQUIRED) {
		bits.push_back(false);

		++numBitsPushed;
	}

	state = STATE_ADDING_EN_PASSANT_FILES;
}

void CompactPositionBuilder::appendEnPassantFile(FileType file) {
	int file_ = file;
	if (file == eFile_None) {
		file_ = eFile_NumFiles;
	}

	static const int NUM_BITS_REQUIRED = 4;

	int numBitsPushed = 0;
	while (file_ != 0) {
		int remainder = file_ % 2;
		bits.push_back(remainder ? true : false);
		file_ /= 2;

		++numBitsPushed;
	}

	while (numBitsPushed < NUM_BITS_REQUIRED) {
		bits.push_back(false);

		++numBitsPushed;
	}

	state = STATE_ADDING_CASTLING_OPTIONS;
}

void CompactPositionBuilder::appendCastlingOptions(bool canWhiteCastleQSide, bool canWhiteCastleKSide, bool canBlackCastleQSide, bool canBlackCastleKSide) {
	bits.push_back(canWhiteCastleQSide ? true : false);
	bits.push_back(canWhiteCastleKSide ? true : false);
	bits.push_back(canBlackCastleQSide ? true : false);
	bits.push_back(canBlackCastleKSide ? true : false);

	state = STATE_END;
}

void CompactPositionBuilder::toPosition(CompactedPosition& pos) const {
	int bitNum = 0;
	int wordNum = 0;
	INT64* curWord = &(pos.B1);

	for (const auto& val : bits) {

		if (val) {
			*curWord |= (ONE64 << bitNum);
		}

		++bitNum;

		if (bitNum == 64) {
			bitNum = 0;
			++wordNum;
			
			switch (wordNum) {
				case 1: curWord = &(pos.B2); break;
				case 2: curWord = &(pos.B3); break;
				case 3: curWord = &(pos.B4); break;
				default: ASSERT(0);
			}
		}
	}
}

void CompactPositionBuilder::clear() {
	state = STATE_START;
	colorToMove = eColor_White;
	curSquare = eSquare_A1;
	bits.clear();
}

void CompactPositionBuilder::nextState_appendingPieces() {
	if (state != STATE_ADDING_PIECES) {
		throw Exception("Error: " __FUNCTION__ "(state: %d) - invalid state", state);
	}

	if (curSquare > eSquare_H8) {
		state = STATE_ADDING_50_MOVE_RULE_NUM_HALF_MOVES;
	}
}

///////////////////////////////////////////////////////////////////////////////
