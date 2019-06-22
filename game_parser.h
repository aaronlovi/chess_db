#ifndef GAME_PARSER_H
#define GAME_PARSER_H

///////////////////////////////////////////////////////////////////////////////

#include "position.h"
#include "game.h"
#include "compacted_position.h"
#include "compact_position_builder.h"

struct FileWrapper;

///////////////////////////////////////////////////////////////////////////////

struct GameParser
{
	static const int STATE_LINE_START = 0;
	static const int STATE_LINE_IN_GAME_METADATA = 1;
	static const int STATE_LINE_IN_GAME_MOVES = 2;

	vector<unique_ptr<Game>> gameVec;
	vector<unique_ptr<CompactedPositionInfo>> compactedPositionInfoVec;
	CompactPositionBuilder compactPositionBuilder;

	explicit GameParser(FileWrapper& pgnFile_);

	void parse();

private: // Helpers

	FILE* pgnFile;
	unique_ptr<Game> curGame;
	Position curPos;
	vector<CompactedPosition> compactedPositionVec;

	void parsePGN();
	long generateCompactedPositions();
	void fillCompactedPositionInfoVec(long numPositions);

	int parseLine_Start(const char* line);
	int parseLine_InMetaData(const char* line);
	int parseLine_InGameMoves(const char* line);

	void parseMove(const char* moveStr, unique_ptr<Move>& nextMove, bool& isEndOfGame);
};

///////////////////////////////////////////////////////////////////////////////

#endif // GAME_PARSER_H
