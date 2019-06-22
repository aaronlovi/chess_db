#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "include_base.h"

// Chess constants
static const int MAX_HALF_MOVES_50_MOVE_RULE = 100;
static const int MATCH_ANY_HALF_MOVES_50_MOVE_RULE = 127;

// Generic vector/array sizes
static const int SMALL_VEC_SZ = 10;
static const int MEDIUM_VEC_SZ = 100;
static const int LARGE_VEC_SZ = 300;
static const int MAX_LINE_BUF_SZ = 1024;

// Numeric simple constants
static const int ONE_THOUSAND = 1000;
static const int ONE_MILLION = 1000000;
static const int ONE_BILLION = 1000000000;

// PGN key fields
static const char GAME_META_KEY_EVENT[] = "Event";
static const char GAME_META_KEY_SITE[] = "Site";
static const char GAME_META_KEY_GAMEDATE[] = "Date";
static const char GAME_META_KEY_EVENTDATE[] = "EventDate";
static const char GAME_META_KEY_ROUND[] = "Round";
static const char GAME_META_KEY_WHITEPLAYERNAME[] = "White";
static const char GAME_META_KEY_BLACKPLAYERNAME[] = "Black";
static const char GAME_META_KEY_WHITEELO[] = "WhiteElo";
static const char GAME_META_KEY_BLACKELO[] = "BlackElo";
static const char GAME_META_KEY_RESULT[] = "Result";
static const char GAME_META_KEY_ECOCODE[] = "ECO";

// PGN result fields
static const char GAME_RESULT_WHITE_WON[] = "1-0";
static const char GAME_RESULT_BLACK_WON[] = "0-1";
static const char GAME_RESULT_DRAW[] = "1/2-1/2";
static const char GAME_RESULT_OTHER[] = "*";

static const size_t MAX_GAME_META_KEY_LEN = SZARR(GAME_META_KEY_EVENTDATE);
static const size_t MAX_GAME_RESULT_LEN = SZARR(GAME_RESULT_DRAW);

static const char* DEFAULT_LOG_FILE_PREFIX = ".\\chess_db";

enum PieceType : INT8
{
	ePiece_None = INT8_MAX,

	ePiece_WhitePawn = 0,
	ePiece_WhiteKnight = 1,
	ePiece_WhiteBishop = 2,
	ePiece_WhiteRook = 3,
	ePiece_WhiteQueen = 4,
	ePiece_WhiteKing = 5,
	ePiece_BlackPawn = 6,
	ePiece_BlackKnight = 7,
	ePiece_BlackBishop = 8,
	ePiece_BlackRook = 9,
	ePiece_BlackQueen = 10,
	ePiece_BlackKing = 11,

	ePiece_NumPieces = 12
};

enum ColorType : INT8
{
	eColor_None = INT8_MAX,

	eColor_White = 0,
	eColor_Black = 1
};

enum SquareType : INT8
{
	eSquare_None = INT8_MAX,
	eSquare_NumSquares = 64,

	eSquare_A1 = 0, eSquare_B1 = 1, eSquare_C1 = 2, eSquare_D1 = 3, eSquare_E1 = 4, eSquare_F1 = 5, eSquare_G1 = 6, eSquare_H1 = 7,
	eSquare_A2 = 8, eSquare_B2 = 9, eSquare_C2 = 10, eSquare_D2 = 11, eSquare_E2 = 12, eSquare_F2 = 13, eSquare_G2 = 14, eSquare_H2 = 15,
	eSquare_A3 = 16, eSquare_B3 = 17, eSquare_C3 = 18, eSquare_D3 = 19, eSquare_E3 = 20, eSquare_F3 = 21, eSquare_G3 = 22, eSquare_H3 = 23,
	eSquare_A4 = 24, eSquare_B4 = 25, eSquare_C4 = 26, eSquare_D4 = 27, eSquare_E4 = 28, eSquare_F4 = 29, eSquare_G4 = 30, eSquare_H4 = 31,
	eSquare_A5 = 32, eSquare_B5 = 33, eSquare_C5 = 34, eSquare_D5 = 35, eSquare_E5 = 36, eSquare_F5 = 37, eSquare_G5 = 38, eSquare_H5 = 39,
	eSquare_A6 = 40, eSquare_B6 = 41, eSquare_C6 = 42, eSquare_D6 = 43, eSquare_E6 = 44, eSquare_F6 = 45, eSquare_G6 = 46, eSquare_H6 = 47,
	eSquare_A7 = 48, eSquare_B7 = 49, eSquare_C7 = 50, eSquare_D7 = 51, eSquare_E7 = 52, eSquare_F7 = 53, eSquare_G7 = 54, eSquare_H7 = 55,
	eSquare_A8 = 56, eSquare_B8 = 57, eSquare_C8 = 58, eSquare_D8 = 59, eSquare_E8 = 60, eSquare_F8 = 61, eSquare_G8 = 62, eSquare_H8 = 63
};

enum FileType : INT8
{
	eFile_None = INT8_MAX,
	eFile_NumFiles = 8,

	eFile_A = 0,
	eFile_B = 1,
	eFile_C = 2,
	eFile_D = 3,
	eFile_E = 4,
	eFile_F = 5,
	eFile_G = 6,
	eFile_H = 7
};

enum RankType : INT8
{
	eRank_None = INT8_MAX,
	eRank_NumRanks = 8,

	eRank_1 = 0,
	eRank_2 = 1,
	eRank_3 = 2,
	eRank_4 = 3,
	eRank_5 = 4,
	eRank_6 = 5,
	eRank_7 = 6,
	eRank_8 = 7
};

enum MoveType : INT8
{
	eMove_None = INT8_MAX,

	eMove_Simple = 1,
	eMove_Capture = 2,
	eMove_Castle = 3,
	eMove_EnPassant = 4,
	eMove_Promotion = 5
};

enum ResultType : INT8
{
	eResult_None = INT8_MAX,

	eResult_WhiteWon = 1,
	eResult_BlackWon = 2,
	eResult_Draw = 3,
	eResult_Other = 4
};

enum GameMetaDataKeyType : INT8
{
	eGameMetaDataKey_None = INT8_MAX,

	eGameMetaDataKey_Event = 1,
	eGameMetaDataKey_Site = 2,
	eGameMetaDataKey_GameDate = 3,
	eGameMetaDataKey_EventDate = 4,
	eGameMetaDataKey_Round = 5,
	eGameMetaDataKey_WhitePlayerName = 6,
	eGameMetaDataKey_BlackPlayerName = 7,
	eGameMetaDataKey_WhiteElo = 8,
	eGameMetaDataKey_BlackElo = 9,
	eGameMetaDataKey_Result = 10,
	eGameMetaDataKey_EcoCode = 11
};

#endif // CONSTANTS_H
