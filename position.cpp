///////////////////////////////////////////////////////////////////////////////

#include "position.h"
#include "move.h"
#include "exceptions.h"
#include "game_utils.h"

///////////////////////////////////////////////////////////////////////////////

static const PieceType STARTING_BOARD[eSquare_NumSquares] = {
	ePiece_WhiteRook, ePiece_WhiteKnight, ePiece_WhiteBishop, ePiece_WhiteQueen, ePiece_WhiteKing, ePiece_WhiteBishop, ePiece_WhiteKnight, ePiece_WhiteRook,
	ePiece_WhitePawn, ePiece_WhitePawn, ePiece_WhitePawn, ePiece_WhitePawn, ePiece_WhitePawn, ePiece_WhitePawn, ePiece_WhitePawn, ePiece_WhitePawn,
	ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None,
	ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None,
	ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None,
	ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None, ePiece_None,
	ePiece_BlackPawn, ePiece_BlackPawn, ePiece_BlackPawn, ePiece_BlackPawn, ePiece_BlackPawn, ePiece_BlackPawn, ePiece_BlackPawn, ePiece_BlackPawn,
	ePiece_BlackRook, ePiece_BlackKnight, ePiece_BlackBishop, ePiece_BlackQueen, ePiece_BlackKing, ePiece_BlackBishop, ePiece_BlackKnight, ePiece_BlackRook,
};

///////////////////////////////////////////////////////////////////////////////

Position::Position()
{
	clear();
}

void Position::clear()
{
	numHalfMoves_50MoveRule = 0;
	colorToMove = eColor_White;
	whiteCanCastleQSide = 1;
	whiteCanCastleKSide = 1;
	blackCanCastleQSide = 1;
	blackCanCastleKSide = 1;
	enPassantFile = eFile_None;
	std::copy(STARTING_BOARD, STARTING_BOARD + SZARR(STARTING_BOARD), board);
}

void Position::getNextPosition(const Position& prevPos, const Move& move)
{
	if (this != &prevPos) {
		*this = prevPos;
	}

	colorToMove = (prevPos.colorToMove == eColor_White ? eColor_Black : eColor_White);

	GetNextPosFn getNextPosFn = getNextPosFunctionByMoveType(move.moveType);
	if (getNextPosFn == nullptr) {
		int x = 1;
	}
	ASSERT(getNextPosFn != nullptr);

	(this->*getNextPosFn)(move);
}

void Position::getNextPosition_SimpleMove(const Move& move)
{
	board[move.vacatedSquare] = ePiece_None;
	board[move.occupiedSquare] = move.pieceOnOccupiedSquare;

	if (move.pieceOnOccupiedSquare == ePiece_WhitePawn
		|| move.pieceOnOccupiedSquare == ePiece_BlackPawn)
	{
		numHalfMoves_50MoveRule = 0;
	}
	else
	{
		++numHalfMoves_50MoveRule;
	}

	updateCastlingFromVacatedSquare(move.vacatedSquare);

	if (move.isDoublePawnMove())
	{
		enPassantFile = GameUtils::getFileFromSquare(move.occupiedSquare);
	}

}

void Position::getNextPosition_CaptureMove(const Move& move)
{
	board[move.vacatedSquare] = ePiece_None;
	board[move.occupiedSquare] = move.pieceOnOccupiedSquare;

	numHalfMoves_50MoveRule = 0;

	updateCastlingFromVacatedSquare(move.vacatedSquare);
	updateCastlingFromOccupiedSquare(move.occupiedSquare);

	enPassantFile = eFile_None;
}

void Position::getNextPosition_CastleMove(const Move& move)
{
	board[move.vacatedSquare] = ePiece_None;
	board[move.secondVacatedSquare] = ePiece_None;
	board[move.occupiedSquare] = move.pieceOnOccupiedSquare;
	board[move.secondOccupiedSquare] = move.pieceOnSecondOccupiedSquare;

	++numHalfMoves_50MoveRule;

	updateCastlingFromVacatedSquare(move.vacatedSquare);

	enPassantFile = eFile_None;
}

void Position::getNextPosition_EnPassantMove(const Move& move)
{
	board[move.vacatedSquare] = ePiece_None;
	board[move.secondVacatedSquare] = ePiece_None;
	board[move.occupiedSquare] = move.pieceOnOccupiedSquare;

	numHalfMoves_50MoveRule = 0;

	enPassantFile = eFile_None;
}

void Position::getNextPosition_PromotionMove(const Move& move)
{
	board[move.vacatedSquare] = ePiece_None;
	board[move.occupiedSquare] = move.pieceOnOccupiedSquare;

	numHalfMoves_50MoveRule = 0;

	updateCastlingFromVacatedSquare(move.vacatedSquare);
	updateCastlingFromOccupiedSquare(move.occupiedSquare);

	enPassantFile = eFile_None;
}

void Position::updateCastlingFromGivenSquare(INT8 square)
{
	if (square == eSquare_A1)
	{
		whiteCanCastleQSide = false;
	}

	if (square == eSquare_H1)
	{
		whiteCanCastleKSide = false;
	}

	if (square == eSquare_E1)
	{
		whiteCanCastleQSide = false;
		whiteCanCastleKSide = false;
	}

	if (square == eSquare_A8)
	{
		blackCanCastleQSide = false;
	}

	if (square == eSquare_H8)
	{
		blackCanCastleKSide = false;
	}

	if (square == eSquare_E8)
	{
		blackCanCastleQSide = false;
		blackCanCastleKSide = false;
	}
}

void Position::updateCastlingFromVacatedSquare(INT8 vacatedSquare)
{
	updateCastlingFromGivenSquare(vacatedSquare);
}

void Position::updateCastlingFromOccupiedSquare(INT8 occupiedSquare)
{
	updateCastlingFromGivenSquare(occupiedSquare);
}

bool Position::canCastleKSide() const {
	if (colorToMove == eColor_White) {
		return canWhiteCastleKSide();
	} else {
		return canBlackCastleKSide();
	}
}

bool Position::canCastleQSide() const {
	if (colorToMove == eColor_White) {
		return canWhiteCastleQSide();
	} else {
		return canBlackCastleQSide();
	}
}

bool Position::canWhiteCastleKSide() const {
	if (!whiteCanCastleKSide) {
		return false;
	}

	ASSERT(board[eSquare_E1] == ePiece_WhiteKing);
	ASSERT(board[eSquare_H1] == ePiece_WhiteRook);

	if (board[eSquare_F1] != ePiece_None) {
		return false;
	}

	if (board[eSquare_G1] != ePiece_None) {
		return false;
	}

	if (GameUtils::isKingAttacked(eColor_White, board)) {
		return false;
	}

	PieceType copyBoard[eSquare_NumSquares];
	std::copy(board, board + SZARR(board), copyBoard);

	copyBoard[eSquare_E1] = ePiece_None;
	copyBoard[eSquare_F1] = ePiece_WhiteKing;
	if (GameUtils::isKingAttacked(eColor_White, copyBoard)) {
		return false;
	}

	copyBoard[eSquare_F1] = ePiece_None;
	copyBoard[eSquare_G1] = ePiece_WhiteKing;
	if (GameUtils::isKingAttacked(eColor_White, copyBoard)) {
		return false;
	}

	return true;
}

bool Position::canBlackCastleKSide() const {
	if (!blackCanCastleKSide) {
		return false;
	}

	ASSERT(board[eSquare_E8] == ePiece_BlackKing);
	ASSERT(board[eSquare_H8] == ePiece_BlackRook);

	if (board[eSquare_F8] != ePiece_None) {
		return false;
	}

	if (board[eSquare_G8] != ePiece_None) {
		return false;
	}

	if (GameUtils::isKingAttacked(eColor_Black, board)) {
		return false;
	}

	PieceType copyBoard[eSquare_NumSquares];
	std::copy(board, board + SZARR(board), copyBoard);

	copyBoard[eSquare_E8] = ePiece_None;
	copyBoard[eSquare_F8] = ePiece_BlackKing;
	if (GameUtils::isKingAttacked(eColor_Black, copyBoard)) {
		return false;
	}

	copyBoard[eSquare_F8] = ePiece_None;
	copyBoard[eSquare_G8] = ePiece_BlackKing;
	if (GameUtils::isKingAttacked(eColor_Black, copyBoard)) {
		return false;
	}

	return true;
}

bool Position::canWhiteCastleQSide() const {
	if (!whiteCanCastleQSide) {
		return false;
	}

	ASSERT(board[eSquare_E1] == ePiece_WhiteKing);
	ASSERT(board[eSquare_A1] == ePiece_WhiteRook);

	if (board[eSquare_D1] != ePiece_None) {
		return false;
	}

	if (board[eSquare_C1] != ePiece_None) {
		return false;
	}

	if (board[eSquare_B1] != ePiece_None) {
		return false;
	}

	if (GameUtils::isKingAttacked(eColor_White, board)) {
		return false;
	}

	PieceType copyBoard[eSquare_NumSquares];
	std::copy(board, board + SZARR(board), copyBoard);

	copyBoard[eSquare_E1] = ePiece_None;
	copyBoard[eSquare_D1] = ePiece_WhiteKing;
	if (GameUtils::isKingAttacked(eColor_White, copyBoard)) {
		return false;
	}

	copyBoard[eSquare_D1] = ePiece_None;
	copyBoard[eSquare_C1] = ePiece_WhiteKing;
	if (GameUtils::isKingAttacked(eColor_White, copyBoard)) {
		return false;
	}

	return true;
}

bool Position::canBlackCastleQSide() const {
	if (!blackCanCastleQSide) {
		return false;
	}

	ASSERT(board[eSquare_E8] == ePiece_BlackKing);
	ASSERT(board[eSquare_A8] == ePiece_BlackRook);

	if (board[eSquare_D8] != ePiece_None) {
		return false;
	}

	if (board[eSquare_C8] != ePiece_None) {
		return false;
	}

	if (board[eSquare_B8] != ePiece_None) {
		return false;
	}

	if (GameUtils::isKingAttacked(eColor_Black, board)) {
		return false;
	}

	PieceType copyBoard[eSquare_NumSquares];
	std::copy(board, board + SZARR(board), copyBoard);

	copyBoard[eSquare_E8] = ePiece_None;
	copyBoard[eSquare_D8] = ePiece_BlackKing;
	if (GameUtils::isKingAttacked(eColor_Black, copyBoard)) {
		return false;
	}

	copyBoard[eSquare_D8] = ePiece_None;
	copyBoard[eSquare_C8] = ePiece_BlackKing;
	if (GameUtils::isKingAttacked(eColor_Black, copyBoard)) {
		return false;
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////
