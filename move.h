#ifndef MOVE_H
#define MOVE_H

#include "include_base.h"
#include "constants.h"

// Difference between previous position and this position
struct Move
{
	MoveType moveType; // See MoveType
	SquareType vacatedSquare; // See SquareType
	SquareType secondVacatedSquare; // See SquareType
	SquareType occupiedSquare; // See SquareType
	SquareType secondOccupiedSquare; // See SquareType
	PieceType pieceOnOccupiedSquare; // See PieceType
	PieceType pieceOnSecondOccupiedSquare; // See PieceType

	Move();

	bool isDoublePawnMove() const;
	ColorType getColorOfMove() const;
};

#endif // MOVE_H
