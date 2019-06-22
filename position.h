#ifndef POSITION_H
#define POSITION_H

///////////////////////////////////////////////////////////////////////////////

#include "date.h"
#include "constants.h"

struct Move;

///////////////////////////////////////////////////////////////////////////////

struct Position
{
	PieceType board[eSquare_NumSquares];
	int numHalfMoves_50MoveRule;
	ColorType colorToMove;
	INT8 whiteCanCastleQSide;
	INT8 whiteCanCastleKSide;
	INT8 blackCanCastleQSide;
	INT8 blackCanCastleKSide;
	FileType enPassantFile;

	Position();

	void clear();

	void getNextPosition(const Position& prevPos, const Move& move);
	void getNextPosition_SimpleMove(const Move& move);
	void getNextPosition_CaptureMove(const Move& move);
	void getNextPosition_CastleMove(const Move& move);
	void getNextPosition_EnPassantMove(const Move& move);
	void getNextPosition_PromotionMove(const Move& move);

	void updateCastlingFromGivenSquare(INT8 square);
	void updateCastlingFromVacatedSquare(INT8 vacatedSquare);
	void updateCastlingFromOccupiedSquare(INT8 occupiedSquare);

	bool canCastleKSide() const;
	bool canCastleQSide() const;

	bool canWhiteCastleKSide() const;
	bool canBlackCastleKSide() const;
	bool canWhiteCastleQSide() const;
	bool canBlackCastleQSide() const;

	typedef void(Position::*GetNextPosFn)(const Move& move);
};


///////////////////////////////////////////////////////////////////////////////

#endif // POSITION_H
