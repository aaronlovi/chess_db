#ifndef COMPACT_POSITION_BUILDER_H
#define COMPACT_POSITION_BUILDER_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"
#include "constants.h"

struct CompactedPosition;

///////////////////////////////////////////////////////////////////////////////

struct CompactPositionBuilder
{
	static const int MAX_POS_SIZE_BITS = 64 * 4;
	static const bool WHITE = true;
	static const bool BLACK = false;
	static const INT8 MAX_NUM_EMPTY_SQUARES_ADDED_IN_A_ROW = 2;

	static const int STATE_START = 0;
	static const int STATE_ADDED_COLOR_TO_MOVE = 1;
	static const int STATE_ADDING_PIECES = 2;
	static const int STATE_ADDING_50_MOVE_RULE_NUM_HALF_MOVES = 3;
	static const int STATE_ADDING_EN_PASSANT_FILES = 4;
	static const int STATE_ADDING_CASTLING_OPTIONS = 5;
	static const int STATE_END = 6;

	int state;
	vector<bool> bits;
	INT8 colorToMove;
	INT8 curSquare;

	CompactPositionBuilder();

	void appendColorToMove(INT8 color);
	void appendPiece(PieceType piece);

	void append50MoveRuleNumHalfMoves(int numHalfMoves);
	void appendEnPassantFile(FileType file);
	void appendCastlingOptions(bool canWhiteCastleQSide, bool canWhiteCastleKSide, bool canBlackCastleQSide, bool canBlackCastleKSide);

	void toPosition(CompactedPosition& pos) const;

	void clear();

private: // Helper functions
	void nextState_appendingPieces();
};

///////////////////////////////////////////////////////////////////////////////

#endif // COMPACT_POSITION_BUILDER_H
