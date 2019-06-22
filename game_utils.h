#ifndef GAME_UTILS_H
#define GAME_UTILS_H

///////////////////////////////////////////////////////////////////////////////

#include "position.h"
#include "game_meta_data.h"

struct CompactedPosition;

///////////////////////////////////////////////////////////////////////////////

//void toExpandedPosition(const CompactedPosition& compactPos, Position& pos);
void toCompactedPosition(const Position& pos, CompactedPosition& compactPos);

Position::GetNextPosFn getNextPosFunctionByMoveType(INT8 moveType);

GameMetaDataKeyType getGameMetaDataKeyFromString(const char* keyTypeStr);
GameMetaData::UpdateKeyFn updateMetaDataKeyByKeyType(INT8 keyType);

///////////////////////////////////////////////////////////////////////////////

namespace GameUtils {
	PieceType pgnCharToPiece(
		char pgnChar						// RNBQK
		, ColorType sideToMove);

	FileType pgnCharToFile(char pgnChar);	// abcdefgh
	RankType pgnCharToRank(char pgnChar);   // 12345678

	PieceType iniFileCharToPiece(
		char iniFileChar					// prnkbqkPRNBQK_
	);

	FileType getFileFromSquare(SquareType square);
	RankType getRankFromSquare(SquareType square);
	SquareType getSquare(FileType file, RankType rank);
	SquareType findSquareMoveComesFrom(bool isCapture, PieceType pieceToMove, SquareType targetSquare, 
									   FileType moveMustComeFromThisFile, 
									   RankType moveMustComeFromThisRank,
									   const PieceType(&preMoveBoard)[eSquare_NumSquares]);
	ColorType getColorOfPiece(PieceType piece);
	void pieceToCompactPositionRepresentation(PieceType piece, const vector<bool>** const representation);

	void findSquaresWhitePawnMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresWhiteKnightMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresWhiteBishopMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresWhiteRookMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresWhiteQueenMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresWhiteKingMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresBlackPawnMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresBlackKnightMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresBlackBishopMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresBlackRookMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresBlackQueenMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);
	void findSquaresBlackKingMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSquaresFromVec);

	bool isKingAttacked(ColorType kingColor, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByWhitePawn(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByWhiteKnight(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByWhiteBishop(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByWhiteRook(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByWhiteQueen(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByWhiteKing(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByBlackPawn(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByBlackKnight(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByBlackBishop(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByBlackRook(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByBlackQueen(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
	bool isKingAttackedByBlackKing(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]);
};

///////////////////////////////////////////////////////////////////////////////

#endif // GAME_UTILS_H
