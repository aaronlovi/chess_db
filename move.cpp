///////////////////////////////////////////////////////////////////////////////

#include "move.h"
#include "constants.h"
#include "exceptions.h"
#include "game_utils.h"
#include "logger.h"

///////////////////////////////////////////////////////////////////////////////

Move::Move()
	: moveType(eMove_None)
	, vacatedSquare(eSquare_None)
	, secondVacatedSquare(eSquare_None)
	, occupiedSquare(eSquare_None)
	, secondOccupiedSquare(eSquare_None)
	, pieceOnOccupiedSquare(ePiece_None)
	, pieceOnSecondOccupiedSquare(ePiece_None)
{

}

bool Move::isDoublePawnMove() const
{
	if (moveType != eMove_Simple)
	{
		return false;
	}

	if (pieceOnOccupiedSquare == ePiece_WhitePawn
		&& occupiedSquare > vacatedSquare
		&& occupiedSquare - vacatedSquare == eRank_NumRanks * 2)
	{
		return true;
	}

	if (pieceOnOccupiedSquare == ePiece_BlackPawn
		&& vacatedSquare > occupiedSquare
		&& vacatedSquare - occupiedSquare == eRank_NumRanks * 2)
	{
		return true;
	}

	return false;
}

ColorType Move::getColorOfMove() const {
	return GameUtils::getColorOfPiece(pieceOnOccupiedSquare);
}

///////////////////////////////////////////////////////////////////////////////
