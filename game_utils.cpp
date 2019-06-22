///////////////////////////////////////////////////////////////////////////////

#include "game_utils.h"
#include "exceptions.h"
#include "compact_position_builder.h"

///////////////////////////////////////////////////////////////////////////////

static vector<SquareType> KNIGHT_MOVE_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ eSquare_B3, eSquare_C2 },
	/*B1*/{ eSquare_A3, eSquare_C3, eSquare_D2 },
	/*C1*/{ eSquare_A2, eSquare_B3, eSquare_D3, eSquare_E2 },
	/*D1*/{ eSquare_B2, eSquare_C3, eSquare_E3, eSquare_F2 },
	/*E1*/{ eSquare_C2, eSquare_D3, eSquare_F3, eSquare_G2 },
	/*F1*/{ eSquare_D2, eSquare_E3, eSquare_G3, eSquare_H2 },
	/*G1*/{ eSquare_E2, eSquare_F3, eSquare_H3 },
	/*H1*/{ eSquare_F2, eSquare_G3 },

	/*A2*/{ eSquare_B4, eSquare_C3, eSquare_C1 },
	/*B2*/{ eSquare_C4, eSquare_D3, eSquare_D1, eSquare_A4 },
	/*C2*/{ eSquare_D4, eSquare_E3, eSquare_E1, eSquare_A1, eSquare_A3, eSquare_B4 },
	/*D2*/{ eSquare_E4, eSquare_F3, eSquare_F1, eSquare_B1, eSquare_B3, eSquare_C4 },
	/*E2*/{ eSquare_F4, eSquare_G3, eSquare_G1, eSquare_C1, eSquare_C3, eSquare_D4 },
	/*F2*/{ eSquare_G4, eSquare_H3, eSquare_H1, eSquare_D1, eSquare_D3, eSquare_E4 },
	/*G2*/{ eSquare_H4, eSquare_E1, eSquare_E3, eSquare_F4 },
	/*H2*/{ eSquare_F1, eSquare_F3, eSquare_G4 },

	/*A3*/{ eSquare_B5, eSquare_C4, eSquare_C2, eSquare_B1 },
	/*B3*/{ eSquare_C5, eSquare_D4, eSquare_D2, eSquare_C1, eSquare_A1, eSquare_A5 },
	/*C3*/{ eSquare_D5, eSquare_E4, eSquare_E2, eSquare_D1, eSquare_B1, eSquare_A2, eSquare_A4, eSquare_B5 },
	/*D3*/{ eSquare_E5, eSquare_F4, eSquare_F2, eSquare_E1, eSquare_C1, eSquare_B2, eSquare_B4, eSquare_C5 },
	/*E3*/{ eSquare_F5, eSquare_G4, eSquare_G2, eSquare_F1, eSquare_D1, eSquare_C2, eSquare_C4, eSquare_D5 },
	/*F3*/{ eSquare_G5, eSquare_H4, eSquare_H2, eSquare_G1, eSquare_E1, eSquare_D2, eSquare_D4, eSquare_E5 },
	/*G3*/{ eSquare_H5, eSquare_H1, eSquare_F1, eSquare_E2, eSquare_E4, eSquare_F5 },
	/*H3*/{ eSquare_G1, eSquare_F2, eSquare_F4, eSquare_G5 },

	/*A4*/{ eSquare_B6, eSquare_C5, eSquare_C3, eSquare_B2 },
	/*B4*/{ eSquare_C6, eSquare_D5, eSquare_D3, eSquare_C2, eSquare_A2, eSquare_A6 },
	/*C4*/{ eSquare_D6, eSquare_E5, eSquare_E3, eSquare_D2, eSquare_B2, eSquare_A3, eSquare_A5, eSquare_B6 },
	/*D4*/{ eSquare_E6, eSquare_F5, eSquare_F3, eSquare_E2, eSquare_C2, eSquare_B3, eSquare_B5, eSquare_C6 },
	/*E4*/{ eSquare_F6, eSquare_G5, eSquare_G3, eSquare_F2, eSquare_D2, eSquare_C3, eSquare_C5, eSquare_D6 },
	/*F4*/{ eSquare_G6, eSquare_H5, eSquare_H3, eSquare_G2, eSquare_E2, eSquare_D3, eSquare_D5, eSquare_E6 },
	/*G4*/{ eSquare_H6, eSquare_H2, eSquare_F2, eSquare_E3, eSquare_E5, eSquare_F6 },
	/*H4*/{ eSquare_G2, eSquare_F3, eSquare_F5, eSquare_G6 },

	/*A5*/{ eSquare_B7, eSquare_C6, eSquare_C4, eSquare_B3, },
	/*B5*/{ eSquare_C7, eSquare_D6, eSquare_D4, eSquare_C3, eSquare_A3, eSquare_A7 },
	/*C5*/{ eSquare_D7, eSquare_E6, eSquare_E4, eSquare_D3, eSquare_B3, eSquare_A4, eSquare_A6, eSquare_B7 },
	/*D5*/{ eSquare_E7, eSquare_F6, eSquare_F4, eSquare_E3, eSquare_C3, eSquare_B4, eSquare_B6, eSquare_C7 },
	/*E5*/{ eSquare_F7, eSquare_G6, eSquare_G4, eSquare_F3, eSquare_D3, eSquare_C4, eSquare_C6, eSquare_D7 },
	/*F5*/{ eSquare_G7, eSquare_H6, eSquare_H4, eSquare_G3, eSquare_E3, eSquare_D4, eSquare_D6, eSquare_E7 },
	/*G5*/{ eSquare_H7, eSquare_H3, eSquare_F3, eSquare_E4, eSquare_E6, eSquare_F7 },
	/*H5*/{ eSquare_G3, eSquare_F4, eSquare_F6, eSquare_G7 },

	/*A6*/{ eSquare_B8, eSquare_C7, eSquare_C5, eSquare_B4 },
	/*B6*/{ eSquare_C8, eSquare_D7, eSquare_D5, eSquare_C4, eSquare_A4, eSquare_A8 },
	/*C6*/{ eSquare_D8, eSquare_E7, eSquare_E5, eSquare_D4, eSquare_B4, eSquare_A5, eSquare_A7, eSquare_B8 },
	/*D6*/{ eSquare_E8, eSquare_F7, eSquare_F5, eSquare_E4, eSquare_C4, eSquare_B5, eSquare_B7, eSquare_C8 },
	/*E6*/{ eSquare_F8, eSquare_G7, eSquare_G5, eSquare_F4, eSquare_D4, eSquare_C5, eSquare_C7, eSquare_D8 },
	/*F6*/{ eSquare_G8, eSquare_H7, eSquare_H5, eSquare_G4, eSquare_E4, eSquare_D5, eSquare_D7, eSquare_E8 },
	/*G6*/{ eSquare_H8, eSquare_H4, eSquare_F4, eSquare_E5, eSquare_E7, eSquare_F8 },
	/*H6*/{ eSquare_G4, eSquare_F5, eSquare_F7, eSquare_G8 },

	/*A7*/{ eSquare_B5, eSquare_C6, eSquare_C8 },
	/*B7*/{ eSquare_C5, eSquare_D6, eSquare_D8, eSquare_A5 },
	/*C7*/{ eSquare_D5, eSquare_E6, eSquare_E8, eSquare_A8, eSquare_A6, eSquare_B5 },
	/*D7*/{ eSquare_E5, eSquare_F6, eSquare_F8, eSquare_B8, eSquare_B6, eSquare_C5 },
	/*E7*/{ eSquare_F5, eSquare_G6, eSquare_G8, eSquare_C8, eSquare_C6, eSquare_D5 },
	/*F7*/{ eSquare_G5, eSquare_H6, eSquare_H8, eSquare_D8, eSquare_D6, eSquare_E5 },
	/*G7*/{ eSquare_H5, eSquare_E8, eSquare_E6, eSquare_F5 },
	/*H7*/{ eSquare_F8, eSquare_F6, eSquare_G5 },

	/*A8*/{ eSquare_B6, eSquare_C7 },
	/*B8*/{ eSquare_A6, eSquare_C6, eSquare_D7 },
	/*C8*/{ eSquare_A7, eSquare_B6, eSquare_D6, eSquare_E7 },
	/*D8*/{ eSquare_B7, eSquare_C6, eSquare_E6, eSquare_F7 },
	/*E8*/{ eSquare_C7, eSquare_D6, eSquare_F6, eSquare_G7 },
	/*F8*/{ eSquare_D7, eSquare_E6, eSquare_G6, eSquare_H7 },
	/*G8*/{ eSquare_E7, eSquare_F6, eSquare_H6 },
	/*H8*/{ eSquare_F7, eSquare_G6 }
};

static vector<SquareType> ROOK_MOVE_UP_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ eSquare_A2, eSquare_A3, eSquare_A4, eSquare_A5, eSquare_A6, eSquare_A7, eSquare_A8 },
	/*B1*/{ eSquare_B2, eSquare_B3, eSquare_B4, eSquare_B5, eSquare_B6, eSquare_B7, eSquare_B8 },
	/*C1*/{ eSquare_C2, eSquare_C3, eSquare_C4, eSquare_C5, eSquare_C6, eSquare_C7, eSquare_C8 },
	/*D1*/{ eSquare_D2, eSquare_D3, eSquare_D4, eSquare_D5, eSquare_D6, eSquare_D7, eSquare_D8 },
	/*E1*/{ eSquare_E2, eSquare_E3, eSquare_E4, eSquare_E5, eSquare_E6, eSquare_E7, eSquare_E8 },
	/*F1*/{ eSquare_F2, eSquare_F3, eSquare_F4, eSquare_F5, eSquare_F6, eSquare_F7, eSquare_F8 },
	/*G1*/{ eSquare_G2, eSquare_G3, eSquare_G4, eSquare_G5, eSquare_G6, eSquare_G7, eSquare_G8 },
	/*H1*/{ eSquare_H2, eSquare_H3, eSquare_H4, eSquare_H5, eSquare_H6, eSquare_H7, eSquare_H8 },

	/*A2*/{ eSquare_A3, eSquare_A4, eSquare_A5, eSquare_A6, eSquare_A7, eSquare_A8 },
	/*B2*/{ eSquare_B3, eSquare_B4, eSquare_B5, eSquare_B6, eSquare_B7, eSquare_B8 },
	/*C2*/{ eSquare_C3, eSquare_C4, eSquare_C5, eSquare_C6, eSquare_C7, eSquare_C8 },
	/*D2*/{ eSquare_D3, eSquare_D4, eSquare_D5, eSquare_D6, eSquare_D7, eSquare_D8 },
	/*E2*/{ eSquare_E3, eSquare_E4, eSquare_E5, eSquare_E6, eSquare_E7, eSquare_E8 },
	/*F2*/{ eSquare_F3, eSquare_F4, eSquare_F5, eSquare_F6, eSquare_F7, eSquare_F8 },
	/*G2*/{ eSquare_G3, eSquare_G4, eSquare_G5, eSquare_G6, eSquare_G7, eSquare_G8 },
	/*H2*/{ eSquare_H3, eSquare_H4, eSquare_H5, eSquare_H6, eSquare_H7, eSquare_H8 },

	/*A3*/{ eSquare_A4, eSquare_A5, eSquare_A6, eSquare_A7, eSquare_A8 },
	/*B3*/{ eSquare_B4, eSquare_B5, eSquare_B6, eSquare_B7, eSquare_B8 },
	/*C3*/{ eSquare_C4, eSquare_C5, eSquare_C6, eSquare_C7, eSquare_C8 },
	/*D3*/{ eSquare_D4, eSquare_D5, eSquare_D6, eSquare_D7, eSquare_D8 },
	/*E3*/{ eSquare_E4, eSquare_E5, eSquare_E6, eSquare_E7, eSquare_E8 },
	/*F3*/{ eSquare_F4, eSquare_F5, eSquare_F6, eSquare_F7, eSquare_F8 },
	/*G3*/{ eSquare_G4, eSquare_G5, eSquare_G6, eSquare_G7, eSquare_G8 },
	/*H3*/{ eSquare_H4, eSquare_H5, eSquare_H6, eSquare_H7, eSquare_H8 },

	/*A4*/{ eSquare_A5, eSquare_A6, eSquare_A7, eSquare_A8 },
	/*B4*/{ eSquare_B5, eSquare_B6, eSquare_B7, eSquare_B8 },
	/*C4*/{ eSquare_C5, eSquare_C6, eSquare_C7, eSquare_C8 },
	/*D4*/{ eSquare_D5, eSquare_D6, eSquare_D7, eSquare_D8 },
	/*E4*/{ eSquare_E5, eSquare_E6, eSquare_E7, eSquare_E8 },
	/*F4*/{ eSquare_F5, eSquare_F6, eSquare_F7, eSquare_F8 },
	/*G4*/{ eSquare_G5, eSquare_G6, eSquare_G7, eSquare_G8 },
	/*H4*/{ eSquare_H5, eSquare_H6, eSquare_H7, eSquare_H8 },

	/*A5*/{ eSquare_A6, eSquare_A7, eSquare_A8 },
	/*B5*/{ eSquare_B6, eSquare_B7, eSquare_B8 },
	/*C5*/{ eSquare_C6, eSquare_C7, eSquare_C8 },
	/*D5*/{ eSquare_D6, eSquare_D7, eSquare_D8 },
	/*E5*/{ eSquare_E6, eSquare_E7, eSquare_E8 },
	/*F5*/{ eSquare_F6, eSquare_F7, eSquare_F8 },
	/*G5*/{ eSquare_G6, eSquare_G7, eSquare_G8 },
	/*H5*/{ eSquare_H6, eSquare_H7, eSquare_H8 },

	/*A6*/{ eSquare_A7, eSquare_A8 },
	/*B6*/{ eSquare_B7, eSquare_B8 },
	/*C6*/{ eSquare_C7, eSquare_C8 },
	/*D6*/{ eSquare_D7, eSquare_D8 },
	/*E6*/{ eSquare_E7, eSquare_E8 },
	/*F6*/{ eSquare_F7, eSquare_F8 },
	/*G6*/{ eSquare_G7, eSquare_G8 },
	/*H6*/{ eSquare_H7, eSquare_H8 },

	/*A7*/{ eSquare_A8 },
	/*B7*/{ eSquare_B8 },
	/*C7*/{ eSquare_C8 },
	/*D7*/{ eSquare_D8 },
	/*E7*/{ eSquare_E8 },
	/*F7*/{ eSquare_F8 },
	/*G7*/{ eSquare_G8 },
	/*H7*/{ eSquare_H8 },

	/*A8*/{ },
	/*B8*/{ },
	/*C8*/{ },
	/*D8*/{ },
	/*E8*/{ },
	/*F8*/{ },
	/*G8*/{ },
	/*H8*/{ }
};

static vector<SquareType> ROOK_MOVE_RIGHT_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ eSquare_B1, eSquare_C1, eSquare_D1, eSquare_E1, eSquare_F1, eSquare_G1, eSquare_H1 },
	/*B1*/{ eSquare_C1, eSquare_D1, eSquare_E1, eSquare_F1, eSquare_G1, eSquare_H1 },
	/*C1*/{ eSquare_D1, eSquare_E1, eSquare_F1, eSquare_G1, eSquare_H1 },
	/*D1*/{ eSquare_E1, eSquare_F1, eSquare_G1, eSquare_H1 },
	/*E1*/{ eSquare_F1, eSquare_G1, eSquare_H1 },
	/*F1*/{ eSquare_G1, eSquare_H1 },
	/*G1*/{ eSquare_H1 },
	/*H1*/{ },

	/*A2*/{ eSquare_B2, eSquare_C2, eSquare_D2, eSquare_E2, eSquare_F2, eSquare_G2, eSquare_H2 },
	/*B2*/{ eSquare_C2, eSquare_D2, eSquare_E2, eSquare_F2, eSquare_G2, eSquare_H2 },
	/*C2*/{ eSquare_D2, eSquare_E2, eSquare_F2, eSquare_G2, eSquare_H2 },
	/*D2*/{ eSquare_E2, eSquare_F2, eSquare_G2, eSquare_H2 },
	/*E2*/{ eSquare_F2, eSquare_G2, eSquare_H2 },
	/*F2*/{ eSquare_G2, eSquare_H2 },
	/*G2*/{ eSquare_H2 },
	/*H2*/{ },

	/*A3*/{ eSquare_B3, eSquare_C3, eSquare_D3, eSquare_E3, eSquare_F3, eSquare_G3, eSquare_H3 },
	/*B3*/{ eSquare_C3, eSquare_D3, eSquare_E3, eSquare_F3, eSquare_G3, eSquare_H3 },
	/*C3*/{ eSquare_D3, eSquare_E3, eSquare_F3, eSquare_G3, eSquare_H3 },
	/*D3*/{ eSquare_E3, eSquare_F3, eSquare_G3, eSquare_H3 },
	/*E3*/{ eSquare_F3, eSquare_G3, eSquare_H3 },
	/*F3*/{ eSquare_G3, eSquare_H3 },
	/*G3*/{ eSquare_H3 },
	/*H3*/{ },

	/*A4*/{ eSquare_B4, eSquare_C4, eSquare_D4, eSquare_E4, eSquare_F4, eSquare_G4, eSquare_H4 },
	/*B4*/{ eSquare_C4, eSquare_D4, eSquare_E4, eSquare_F4, eSquare_G4, eSquare_H4 },
	/*C4*/{ eSquare_D4, eSquare_E4, eSquare_F4, eSquare_G4, eSquare_H4 },
	/*D4*/{ eSquare_E4, eSquare_F4, eSquare_G4, eSquare_H4 },
	/*E4*/{ eSquare_F4, eSquare_G4, eSquare_H4 },
	/*F4*/{ eSquare_G4, eSquare_H4 },
	/*G4*/{ eSquare_H4 },
	/*H4*/{ },

	/*A5*/{ eSquare_B5, eSquare_C5, eSquare_D5, eSquare_E5, eSquare_F5, eSquare_G5, eSquare_H5 },
	/*B5*/{ eSquare_C5, eSquare_D5, eSquare_E5, eSquare_F5, eSquare_G5, eSquare_H5 },
	/*C5*/{ eSquare_D5, eSquare_E5, eSquare_F5, eSquare_G5, eSquare_H5 },
	/*D5*/{ eSquare_E5, eSquare_F5, eSquare_G5, eSquare_H5 },
	/*E5*/{ eSquare_F5, eSquare_G5, eSquare_H5 },
	/*F5*/{ eSquare_G5, eSquare_H5 },
	/*G5*/{ eSquare_H5 },
	/*H5*/{ },

	/*A6*/{ eSquare_B6, eSquare_C6, eSquare_D6, eSquare_E6, eSquare_F6, eSquare_G6, eSquare_H6 },
	/*B6*/{ eSquare_C6, eSquare_D6, eSquare_E6, eSquare_F6, eSquare_G6, eSquare_H6 },
	/*C6*/{ eSquare_D6, eSquare_E6, eSquare_F6, eSquare_G6, eSquare_H6 },
	/*D6*/{ eSquare_E6, eSquare_F6, eSquare_G6, eSquare_H6 },
	/*E6*/{ eSquare_F6, eSquare_G6, eSquare_H6 },
	/*F6*/{ eSquare_G6, eSquare_H6 },
	/*G6*/{ eSquare_H6 },
	/*H6*/{ },

	/*A7*/{ eSquare_B7, eSquare_C7, eSquare_D7, eSquare_E7, eSquare_F7, eSquare_G7, eSquare_H7 },
	/*B7*/{ eSquare_C7, eSquare_D7, eSquare_E7, eSquare_F7, eSquare_G7, eSquare_H7 },
	/*C7*/{ eSquare_D7, eSquare_E7, eSquare_F7, eSquare_G7, eSquare_H7 },
	/*D7*/{ eSquare_E7, eSquare_F7, eSquare_G7, eSquare_H7 },
	/*E7*/{ eSquare_F7, eSquare_G7, eSquare_H7 },
	/*F7*/{ eSquare_G7, eSquare_H7 },
	/*G7*/{ eSquare_H7 },
	/*H7*/{ },

	/*A8*/{ eSquare_B8, eSquare_C8, eSquare_D8, eSquare_E8, eSquare_F8, eSquare_G8, eSquare_H8 },
	/*B8*/{ eSquare_C8, eSquare_D8, eSquare_E8, eSquare_F8, eSquare_G8, eSquare_H8 },
	/*C8*/{ eSquare_D8, eSquare_E8, eSquare_F8, eSquare_G8, eSquare_H8 },
	/*D8*/{ eSquare_E8, eSquare_F8, eSquare_G8, eSquare_H8 },
	/*E8*/{ eSquare_F8, eSquare_G8, eSquare_H8 },
	/*F8*/{ eSquare_G8, eSquare_H8 },
	/*G8*/{ eSquare_H8 },
	/*H8*/{ },
};

static vector<SquareType> ROOK_MOVE_DOWN_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ },
	/*B1*/{ },
	/*C1*/{ },
	/*D1*/{ },
	/*E1*/{ },
	/*F1*/{ },
	/*G1*/{ },
	/*H1*/{ },

	/*A2*/{ eSquare_A1 },
	/*B2*/{ eSquare_B1 },
	/*C2*/{ eSquare_C1 },
	/*D2*/{ eSquare_D1 },
	/*E2*/{ eSquare_E1 },
	/*F2*/{ eSquare_F1 },
	/*G2*/{ eSquare_G1 },
	/*H2*/{ eSquare_H1 },

	/*A3*/{ eSquare_A2, eSquare_A1 },
	/*B3*/{ eSquare_B2, eSquare_B1 },
	/*C3*/{ eSquare_C2, eSquare_C1 },
	/*D3*/{ eSquare_D2, eSquare_D1 },
	/*E3*/{ eSquare_E2, eSquare_E1 },
	/*F3*/{ eSquare_F2, eSquare_F1 },
	/*G3*/{ eSquare_G2, eSquare_G1 },
	/*H3*/{ eSquare_H2, eSquare_H1 },

	/*A4*/{ eSquare_A3, eSquare_A2, eSquare_A1 },
	/*B4*/{ eSquare_B3, eSquare_B2, eSquare_B1 },
	/*C4*/{ eSquare_C3, eSquare_C2, eSquare_C1 },
	/*D4*/{ eSquare_D3, eSquare_D2, eSquare_D1 },
	/*E4*/{ eSquare_E3, eSquare_E2, eSquare_E1 },
	/*F4*/{ eSquare_F3, eSquare_F2, eSquare_F1 },
	/*G4*/{ eSquare_G3, eSquare_G2, eSquare_G1 },
	/*H4*/{ eSquare_H3, eSquare_H2, eSquare_H1 },

	/*A5*/{ eSquare_A4, eSquare_A3, eSquare_A2, eSquare_A1 },
	/*B5*/{ eSquare_B4, eSquare_B3, eSquare_B2, eSquare_B1 },
	/*C5*/{ eSquare_C4, eSquare_C3, eSquare_C2, eSquare_C1 },
	/*D5*/{ eSquare_D4, eSquare_D3, eSquare_D2, eSquare_D1 },
	/*E5*/{ eSquare_E4, eSquare_E3, eSquare_E2, eSquare_E1 },
	/*F5*/{ eSquare_F4, eSquare_F3, eSquare_F2, eSquare_F1 },
	/*G5*/{ eSquare_G4, eSquare_G3, eSquare_G2, eSquare_G1 },
	/*H5*/{ eSquare_H4, eSquare_H3, eSquare_H2, eSquare_H1 },

	/*A6*/{ eSquare_A5, eSquare_A4, eSquare_A3, eSquare_A2, eSquare_A1 },
	/*B6*/{ eSquare_B5, eSquare_B4, eSquare_B3, eSquare_B2, eSquare_B1 },
	/*C6*/{ eSquare_C5, eSquare_C4, eSquare_C3, eSquare_C2, eSquare_C1 },
	/*D6*/{ eSquare_D5, eSquare_D4, eSquare_D3, eSquare_D2, eSquare_D1 },
	/*E6*/{ eSquare_E5, eSquare_E4, eSquare_E3, eSquare_E2, eSquare_E1 },
	/*F6*/{ eSquare_F5, eSquare_F4, eSquare_F3, eSquare_F2, eSquare_F1 },
	/*G6*/{ eSquare_G5, eSquare_G4, eSquare_G3, eSquare_G2, eSquare_G1 },
	/*H6*/{ eSquare_H5, eSquare_H4, eSquare_H3, eSquare_H2, eSquare_H1 },

	/*A7*/{ eSquare_A6, eSquare_A5, eSquare_A4, eSquare_A3, eSquare_A2, eSquare_A1 },
	/*B7*/{ eSquare_B6, eSquare_B5, eSquare_B4, eSquare_B3, eSquare_B2, eSquare_B1 },
	/*C7*/{ eSquare_C6, eSquare_C5, eSquare_C4, eSquare_C3, eSquare_C2, eSquare_C1 },
	/*D7*/{ eSquare_D6, eSquare_D5, eSquare_D4, eSquare_D3, eSquare_D2, eSquare_D1 },
	/*E7*/{ eSquare_E6, eSquare_E5, eSquare_E4, eSquare_E3, eSquare_E2, eSquare_E1 },
	/*F7*/{ eSquare_F6, eSquare_F5, eSquare_F4, eSquare_F3, eSquare_F2, eSquare_F1 },
	/*G7*/{ eSquare_G6, eSquare_G5, eSquare_G4, eSquare_G3, eSquare_G2, eSquare_G1 },
	/*H7*/{ eSquare_H6, eSquare_H5, eSquare_H4, eSquare_H3, eSquare_H2, eSquare_H1 },

	/*A8*/{ eSquare_A7, eSquare_A6, eSquare_A5, eSquare_A4, eSquare_A3, eSquare_A2, eSquare_A1 },
	/*B8*/{ eSquare_B7, eSquare_B6, eSquare_B5, eSquare_B4, eSquare_B3, eSquare_B2, eSquare_B1 },
	/*C8*/{ eSquare_C7, eSquare_C6, eSquare_C5, eSquare_C4, eSquare_C3, eSquare_C2, eSquare_C1 },
	/*D8*/{ eSquare_D7, eSquare_D6, eSquare_D5, eSquare_D4, eSquare_D3, eSquare_D2, eSquare_D1 },
	/*E8*/{ eSquare_E7, eSquare_E6, eSquare_E5, eSquare_E4, eSquare_E3, eSquare_E2, eSquare_E1 },
	/*F8*/{ eSquare_F7, eSquare_F6, eSquare_F5, eSquare_F4, eSquare_F3, eSquare_F2, eSquare_F1 },
	/*G8*/{ eSquare_G7, eSquare_G6, eSquare_G5, eSquare_G4, eSquare_G3, eSquare_G2, eSquare_G1 },
	/*H8*/{ eSquare_H7, eSquare_H6, eSquare_H5, eSquare_H4, eSquare_H3, eSquare_H2, eSquare_H1 }
};

static vector<SquareType> ROOK_MOVE_LEFT_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ },
	/*B1*/{ eSquare_A1 },
	/*C1*/{ eSquare_B1, eSquare_A1 },
	/*D1*/{ eSquare_C1, eSquare_B1, eSquare_A1 },
	/*E1*/{ eSquare_D1, eSquare_C1, eSquare_B1, eSquare_A1 },
	/*F1*/{ eSquare_E1, eSquare_D1, eSquare_C1, eSquare_B1, eSquare_A1 },
	/*G1*/{ eSquare_F1, eSquare_E1, eSquare_D1, eSquare_C1, eSquare_B1, eSquare_A1 },
	/*H1*/{ eSquare_G1, eSquare_F1, eSquare_E1, eSquare_D1, eSquare_C1, eSquare_B1, eSquare_A1 },

	/*A2*/{ },
	/*B2*/{ eSquare_A2 },
	/*C2*/{ eSquare_B2, eSquare_A2 },
	/*D2*/{ eSquare_C2, eSquare_B2, eSquare_A2 },
	/*E2*/{ eSquare_D2, eSquare_C2, eSquare_B2, eSquare_A2 },
	/*F2*/{ eSquare_E2, eSquare_D2, eSquare_C2, eSquare_B2, eSquare_A2 },
	/*G2*/{ eSquare_F2, eSquare_E2, eSquare_D2, eSquare_C2, eSquare_B2, eSquare_A2 },
	/*H2*/{ eSquare_G2, eSquare_F2, eSquare_E2, eSquare_D2, eSquare_C2, eSquare_B2, eSquare_A2 },

	/*A3*/{ },
	/*B3*/{ eSquare_A3 },
	/*C3*/{ eSquare_B3, eSquare_A3 },
	/*D3*/{ eSquare_C3, eSquare_B3, eSquare_A3 },
	/*E3*/{ eSquare_D3, eSquare_C3, eSquare_B3, eSquare_A3 },
	/*F3*/{ eSquare_E3, eSquare_D3, eSquare_C3, eSquare_B3, eSquare_A3 },
	/*G3*/{ eSquare_F3, eSquare_E3, eSquare_D3, eSquare_C3, eSquare_B3, eSquare_A3 },
	/*H3*/{ eSquare_G3, eSquare_F3, eSquare_E3, eSquare_D3, eSquare_C3, eSquare_B3, eSquare_A3 },

	/*A4*/{ },
	/*B4*/{ eSquare_A4 },
	/*C4*/{ eSquare_B4, eSquare_A4 },
	/*D4*/{ eSquare_C4, eSquare_B4, eSquare_A4 },
	/*E4*/{ eSquare_D4, eSquare_C4, eSquare_B4, eSquare_A4 },
	/*F4*/{ eSquare_E4, eSquare_D4, eSquare_C4, eSquare_B4, eSquare_A4 },
	/*G4*/{ eSquare_F4, eSquare_E4, eSquare_D4, eSquare_C4, eSquare_B4, eSquare_A4 },
	/*H4*/{ eSquare_G4, eSquare_F4, eSquare_E4, eSquare_D4, eSquare_C4, eSquare_B4, eSquare_A4 },

	/*A5*/{ },
	/*B5*/{ eSquare_A5 },
	/*C5*/{ eSquare_B5, eSquare_A5 },
	/*D5*/{ eSquare_C5, eSquare_B5, eSquare_A5 },
	/*E5*/{ eSquare_D5, eSquare_C5, eSquare_B5, eSquare_A5 },
	/*F5*/{ eSquare_E5, eSquare_D5, eSquare_C5, eSquare_B5, eSquare_A5 },
	/*G5*/{ eSquare_F5, eSquare_E5, eSquare_D5, eSquare_C5, eSquare_B5, eSquare_A5 },
	/*H5*/{ eSquare_G5, eSquare_F5, eSquare_E5, eSquare_D5, eSquare_C5, eSquare_B5, eSquare_A5 },

	/*A6*/{ },
	/*B6*/{ eSquare_A6 },
	/*C6*/{ eSquare_B6, eSquare_A6 },
	/*D6*/{ eSquare_C6, eSquare_B6, eSquare_A6 },
	/*E6*/{ eSquare_D6, eSquare_C6, eSquare_B6, eSquare_A6 },
	/*F6*/{ eSquare_E6, eSquare_D6, eSquare_C6, eSquare_B6, eSquare_A6 },
	/*G6*/{ eSquare_F6, eSquare_E6, eSquare_D6, eSquare_C6, eSquare_B6, eSquare_A6 },
	/*H6*/{ eSquare_G6, eSquare_F6, eSquare_E6, eSquare_D6, eSquare_C6, eSquare_B6, eSquare_A6 },

	/*A7*/{ },
	/*B7*/{ eSquare_A7 },
	/*C7*/{ eSquare_B7, eSquare_A7 },
	/*D7*/{ eSquare_C7, eSquare_B7, eSquare_A7 },
	/*E7*/{ eSquare_D7, eSquare_C7, eSquare_B7, eSquare_A7 },
	/*F7*/{ eSquare_E7, eSquare_D7, eSquare_C7, eSquare_B7, eSquare_A7 },
	/*G7*/{ eSquare_F7, eSquare_E7, eSquare_D7, eSquare_C7, eSquare_B7, eSquare_A7 },
	/*H7*/{ eSquare_G7, eSquare_F7, eSquare_E7, eSquare_D7, eSquare_C7, eSquare_B7, eSquare_A7 },

	/*A8*/{ },
	/*B8*/{ eSquare_A8 },
	/*C8*/{ eSquare_B8, eSquare_A8 },
	/*D8*/{ eSquare_C8, eSquare_B8, eSquare_A8 },
	/*E8*/{ eSquare_D8, eSquare_C8, eSquare_B8, eSquare_A8 },
	/*F8*/{ eSquare_E8, eSquare_D8, eSquare_C8, eSquare_B8, eSquare_A8 },
	/*G8*/{ eSquare_F8, eSquare_E8, eSquare_D8, eSquare_C8, eSquare_B8, eSquare_A8 },
	/*H8*/{ eSquare_G8, eSquare_F8, eSquare_E8, eSquare_D8, eSquare_C8, eSquare_B8, eSquare_A8 },
};

static vector<SquareType> BISHOP_MOVE_UP_RIGHT_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ eSquare_B2, eSquare_C3, eSquare_D4, eSquare_E5, eSquare_F6, eSquare_G7, eSquare_H8 },
	/*B1*/{ eSquare_C2, eSquare_D3, eSquare_E4, eSquare_F5, eSquare_G6, eSquare_H7 },
	/*C1*/{ eSquare_D2, eSquare_E3, eSquare_F4, eSquare_G5, eSquare_H6 },
	/*D1*/{ eSquare_E2, eSquare_F3, eSquare_G4, eSquare_H5 },
	/*E1*/{ eSquare_F2, eSquare_G3, eSquare_H4 },
	/*F1*/{ eSquare_G2, eSquare_H3 },
	/*G1*/{ eSquare_H2 },
	/*H1*/{ },

	/*A2*/{ eSquare_B3, eSquare_C4, eSquare_D5, eSquare_E6, eSquare_F7, eSquare_G8 },
	/*B2*/{ eSquare_C3, eSquare_D4, eSquare_E5, eSquare_F6, eSquare_G7, eSquare_H8 },
	/*C2*/{ eSquare_D3, eSquare_E4, eSquare_F5, eSquare_G6, eSquare_H7 },
	/*D2*/{ eSquare_E3, eSquare_F4, eSquare_G5, eSquare_H6 },
	/*E2*/{ eSquare_F3, eSquare_G4, eSquare_H5 },
	/*F2*/{ eSquare_G3, eSquare_H4 },
	/*G2*/{ eSquare_H3 },
	/*H2*/{ },

	/*A3*/{ eSquare_B4, eSquare_C5, eSquare_D6, eSquare_E7, eSquare_F8 },
	/*B3*/{ eSquare_C4, eSquare_D5, eSquare_E6, eSquare_F7, eSquare_G8 },
	/*C3*/{ eSquare_D4, eSquare_E5, eSquare_F6, eSquare_G7, eSquare_H8 },
	/*D3*/{ eSquare_E4, eSquare_F5, eSquare_G6, eSquare_H7 },
	/*E3*/{ eSquare_F4, eSquare_G5, eSquare_H6 },
	/*F3*/{ eSquare_G4, eSquare_H5 },
	/*G3*/{ eSquare_H4 },
	/*H3*/{ },

	/*A4*/{ eSquare_B5, eSquare_C6, eSquare_D7, eSquare_E8 },
	/*B4*/{ eSquare_C5, eSquare_D6, eSquare_E7, eSquare_F8 },
	/*C4*/{ eSquare_D5, eSquare_E6, eSquare_F7, eSquare_G8 },
	/*D4*/{ eSquare_E5, eSquare_F6, eSquare_G7, eSquare_H8 },
	/*E4*/{ eSquare_F5, eSquare_G6, eSquare_H7 },
	/*F4*/{ eSquare_G5, eSquare_H6 },
	/*G4*/{ eSquare_H5 },
	/*H4*/{ },

	/*A5*/{ eSquare_B6, eSquare_C7, eSquare_D8 },
	/*B5*/{ eSquare_C6, eSquare_D7, eSquare_E8 },
	/*C5*/{ eSquare_D6, eSquare_E7, eSquare_F8 },
	/*D5*/{ eSquare_E6, eSquare_F7, eSquare_G8 },
	/*E5*/{ eSquare_F6, eSquare_G7, eSquare_H8 },
	/*F5*/{ eSquare_G6, eSquare_H7 },
	/*G5*/{ eSquare_H6 },
	/*H5*/{ },

	/*A6*/{ eSquare_B7, eSquare_C8 },
	/*B6*/{ eSquare_C7, eSquare_D8 },
	/*C6*/{ eSquare_D7, eSquare_E8 },
	/*D6*/{ eSquare_E7, eSquare_F8 },
	/*E6*/{ eSquare_F7, eSquare_G8 },
	/*F6*/{ eSquare_G7, eSquare_H8 },
	/*G6*/{ eSquare_H7 },
	/*H6*/{ },

	/*A7*/{ eSquare_B8 },
	/*B7*/{ eSquare_C8 },
	/*C7*/{ eSquare_D8 },
	/*D7*/{ eSquare_E8 },
	/*E7*/{ eSquare_F8 },
	/*F7*/{ eSquare_G8 },
	/*G7*/{ eSquare_H8 },
	/*H7*/{ },

	/*A8*/{ },
	/*B8*/{ },
	/*C8*/{ },
	/*D8*/{ },
	/*E8*/{ },
	/*F8*/{ },
	/*G8*/{ },
	/*H8*/{ }
};

static vector<SquareType> BISHOP_MOVE_DOWN_RIGHT_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ },
	/*B1*/{ },
	/*C1*/{ },
	/*D1*/{ },
	/*E1*/{ },
	/*F1*/{ },
	/*G1*/{ },
	/*H1*/{ },

	/*A2*/{ eSquare_B1 },
	/*B2*/{ eSquare_C1 },
	/*C2*/{ eSquare_D1 },
	/*D2*/{ eSquare_E1 },
	/*E2*/{ eSquare_F1 },
	/*F2*/{ eSquare_G1 },
	/*G2*/{ eSquare_H1 },
	/*H2*/{ },

	/*A3*/{ eSquare_B2, eSquare_C1 },
	/*B3*/{ eSquare_C2, eSquare_D1 },
	/*C3*/{ eSquare_D2, eSquare_E1 },
	/*D3*/{ eSquare_E2, eSquare_F1 },
	/*E3*/{ eSquare_F2, eSquare_G1 },
	/*F3*/{ eSquare_G2, eSquare_H1 },
	/*G3*/{ eSquare_H2 },
	/*H3*/{ },

	/*A4*/{ eSquare_B3, eSquare_C2, eSquare_D1 },
	/*B4*/{ eSquare_C3, eSquare_D2, eSquare_E1 },
	/*C4*/{ eSquare_D3, eSquare_E2, eSquare_F1 },
	/*D4*/{ eSquare_E3, eSquare_F2, eSquare_G1 },
	/*E4*/{ eSquare_F3, eSquare_G2, eSquare_H1 },
	/*F4*/{ eSquare_G3, eSquare_H2 },
	/*G4*/{ eSquare_H3 },
	/*H4*/{ },

	/*A5*/{ eSquare_B4, eSquare_C3, eSquare_D2, eSquare_E1 },
	/*B5*/{ eSquare_C4, eSquare_D3, eSquare_E2, eSquare_F1 },
	/*C5*/{ eSquare_D4, eSquare_E3, eSquare_F2, eSquare_G1 },
	/*D5*/{ eSquare_E4, eSquare_F3, eSquare_G2, eSquare_H1 },
	/*E5*/{ eSquare_F4, eSquare_G3, eSquare_H2 },
	/*F5*/{ eSquare_G4, eSquare_H3 },
	/*G5*/{ eSquare_H4 },
	/*H5*/{ },

	/*A6*/{ eSquare_B5, eSquare_C4, eSquare_D3, eSquare_E2, eSquare_F1 },
	/*B6*/{ eSquare_C5, eSquare_D4, eSquare_E3, eSquare_F2, eSquare_G1 },
	/*C6*/{ eSquare_D5, eSquare_E4, eSquare_F3, eSquare_G2, eSquare_H1 },
	/*D6*/{ eSquare_E5, eSquare_F4, eSquare_G3, eSquare_H2 },
	/*E6*/{ eSquare_F5, eSquare_G4, eSquare_H3 },
	/*F6*/{ eSquare_G5, eSquare_H4 },
	/*G6*/{ eSquare_H5 },
	/*H6*/{ },

	/*A7*/{ eSquare_B6, eSquare_C5, eSquare_D4, eSquare_E3, eSquare_F2, eSquare_G1 },
	/*B7*/{ eSquare_C6, eSquare_D5, eSquare_E4, eSquare_F3, eSquare_G2, eSquare_H1 },
	/*C7*/{ eSquare_D6, eSquare_E5, eSquare_F4, eSquare_G3, eSquare_H2 },
	/*D7*/{ eSquare_E6, eSquare_F5, eSquare_G4, eSquare_H3 },
	/*E7*/{ eSquare_F6, eSquare_G5, eSquare_H4 },
	/*F7*/{ eSquare_G6, eSquare_H5 },
	/*G7*/{ eSquare_H6 },
	/*H7*/{ },

	/*A8*/{ eSquare_B7, eSquare_C6, eSquare_D5, eSquare_E4, eSquare_F3, eSquare_G2, eSquare_H1 },
	/*B8*/{ eSquare_C7, eSquare_D6, eSquare_E5, eSquare_F4, eSquare_G3, eSquare_H2 },
	/*C8*/{ eSquare_D7, eSquare_E6, eSquare_F5, eSquare_G4, eSquare_H3 },
	/*D8*/{ eSquare_E7, eSquare_F6, eSquare_G5, eSquare_H4 },
	/*E8*/{ eSquare_F7, eSquare_G6, eSquare_H5 },
	/*F8*/{ eSquare_G7, eSquare_H6 },
	/*G8*/{ eSquare_H7 },
	/*H8*/{ }
};

static vector<SquareType> BISHOP_MOVE_DOWN_LEFT_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ },
	/*B1*/{ },
	/*C1*/{ },
	/*D1*/{ },
	/*E1*/{ },
	/*F1*/{ },
	/*G1*/{ },
	/*H1*/{ },

	/*A2*/{ },
	/*B2*/{ eSquare_A1 },
	/*C2*/{ eSquare_B1 },
	/*D2*/{ eSquare_C1 },
	/*E2*/{ eSquare_D1 },
	/*F2*/{ eSquare_E1 },
	/*G2*/{ eSquare_F1 },
	/*H2*/{ eSquare_G1 },

	/*A3*/{ },
	/*B3*/{ eSquare_A2 },
	/*C3*/{ eSquare_B2, eSquare_A1 },
	/*D3*/{ eSquare_C2, eSquare_B1 },
	/*E3*/{ eSquare_D2, eSquare_C1 },
	/*F3*/{ eSquare_E2, eSquare_D1 },
	/*G3*/{ eSquare_F2, eSquare_E1 },
	/*H3*/{ eSquare_G2, eSquare_F1 },

	/*A4*/{ },
	/*B4*/{ eSquare_A3 },
	/*C4*/{ eSquare_B3, eSquare_A2 },
	/*D4*/{ eSquare_C3, eSquare_B2, eSquare_A1 },
	/*E4*/{ eSquare_D3, eSquare_C2, eSquare_B1 },
	/*F4*/{ eSquare_E3, eSquare_D2, eSquare_C1 },
	/*G4*/{ eSquare_F3, eSquare_E2, eSquare_D1 },
	/*H4*/{ eSquare_G3, eSquare_F2, eSquare_E1 },

	/*A5*/{ },
	/*B5*/{ eSquare_A4 },
	/*C5*/{ eSquare_B4, eSquare_A3 },
	/*D5*/{ eSquare_C4, eSquare_B3, eSquare_A2 },
	/*E5*/{ eSquare_D4, eSquare_C3, eSquare_B2, eSquare_A1 },
	/*F5*/{ eSquare_E4, eSquare_D3, eSquare_C2, eSquare_B1 },
	/*G5*/{ eSquare_F4, eSquare_E3, eSquare_D2, eSquare_C1 },
	/*H5*/{ eSquare_G4, eSquare_F3, eSquare_E2, eSquare_D1 },

	/*A6*/{ },
	/*B6*/{ eSquare_A5 },
	/*C6*/{ eSquare_B5, eSquare_A4 },
	/*D6*/{ eSquare_C5, eSquare_B4, eSquare_A3 },
	/*E6*/{ eSquare_D5, eSquare_C4, eSquare_B3, eSquare_A2 },
	/*F6*/{ eSquare_E5, eSquare_D4, eSquare_C3, eSquare_B2, eSquare_A1 },
	/*G6*/{ eSquare_F5, eSquare_E4, eSquare_D3, eSquare_C2, eSquare_B1 },
	/*H6*/{ eSquare_G5, eSquare_F4, eSquare_E3, eSquare_D2, eSquare_C1 },

	/*A7*/{ },
	/*B7*/{ eSquare_A6 },
	/*C7*/{ eSquare_B6, eSquare_A5 },
	/*D7*/{ eSquare_C6, eSquare_B5, eSquare_A4 },
	/*E7*/{ eSquare_D6, eSquare_C5, eSquare_B4, eSquare_A3 },
	/*F7*/{ eSquare_E6, eSquare_D5, eSquare_C4, eSquare_B3, eSquare_A2 },
	/*G7*/{ eSquare_F6, eSquare_E5, eSquare_D4, eSquare_C3, eSquare_B2, eSquare_A1 },
	/*H7*/{ eSquare_G6, eSquare_F5, eSquare_E4, eSquare_D3, eSquare_C2, eSquare_B1 },

	/*A8*/{ },
	/*B8*/{ eSquare_A7 },
	/*C8*/{ eSquare_B7, eSquare_A6 },
	/*D8*/{ eSquare_C7, eSquare_B6, eSquare_A5 },
	/*E8*/{ eSquare_D7, eSquare_C6, eSquare_B5, eSquare_A4 },
	/*F8*/{ eSquare_E7, eSquare_D6, eSquare_C5, eSquare_B4, eSquare_A3 },
	/*G8*/{ eSquare_F7, eSquare_E6, eSquare_D5, eSquare_C4, eSquare_B3, eSquare_A2 },
	/*H8*/{ eSquare_G7, eSquare_F6, eSquare_E5, eSquare_D4, eSquare_C3, eSquare_B2, eSquare_A1 }
};

static vector<SquareType> BISHOP_MOVE_UP_LEFT_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ },
	/*B1*/{ eSquare_A2 },
	/*C1*/{ eSquare_B2, eSquare_A3 },
	/*D1*/{ eSquare_C2, eSquare_B3, eSquare_A4 },
	/*E1*/{ eSquare_D2, eSquare_C3, eSquare_B4, eSquare_A5 },
	/*F1*/{ eSquare_E2, eSquare_D3, eSquare_C4, eSquare_B5, eSquare_A6 },
	/*G1*/{ eSquare_F2, eSquare_E3, eSquare_D4, eSquare_C5, eSquare_B6, eSquare_A7 },
	/*H1*/{ eSquare_G2, eSquare_F3, eSquare_E4, eSquare_D5, eSquare_C6, eSquare_B7, eSquare_A8 },

	/*A2*/{ },
	/*B2*/{ eSquare_A3 },
	/*C2*/{ eSquare_B3, eSquare_A4 },
	/*D2*/{ eSquare_C3, eSquare_B4, eSquare_A5 },
	/*E2*/{ eSquare_D3, eSquare_C4, eSquare_B5, eSquare_A6 },
	/*F2*/{ eSquare_E3, eSquare_D4, eSquare_C5, eSquare_B6, eSquare_A7 },
	/*G2*/{ eSquare_F3, eSquare_E4, eSquare_D5, eSquare_C6, eSquare_B7, eSquare_A8 },
	/*H2*/{ eSquare_G3, eSquare_F4, eSquare_E5, eSquare_D6, eSquare_C7, eSquare_B8 },

	/*A3*/{ },
	/*B3*/{ eSquare_A4 },
	/*C3*/{ eSquare_B4, eSquare_A5 },
	/*D3*/{ eSquare_C4, eSquare_B5, eSquare_A6 },
	/*E3*/{ eSquare_D4, eSquare_C5, eSquare_B6, eSquare_A7 },
	/*F3*/{ eSquare_E4, eSquare_D5, eSquare_C6, eSquare_B7, eSquare_A8 },
	/*G3*/{ eSquare_F4, eSquare_E5, eSquare_D6, eSquare_C7, eSquare_B8 },
	/*H3*/{ eSquare_G4, eSquare_F5, eSquare_E6, eSquare_D7, eSquare_C8 },

	/*A4*/{ },
	/*B4*/{ eSquare_A5 },
	/*C4*/{ eSquare_B5, eSquare_A6 },
	/*D4*/{ eSquare_C5, eSquare_B6, eSquare_A7 },
	/*E4*/{ eSquare_D5, eSquare_C6, eSquare_B7, eSquare_A8 },
	/*F4*/{ eSquare_E5, eSquare_D6, eSquare_C7, eSquare_B8 },
	/*G4*/{ eSquare_F5, eSquare_E6, eSquare_D7, eSquare_C8 },
	/*H4*/{ eSquare_G5, eSquare_F6, eSquare_E7, eSquare_D8 },

	/*A5*/{ },
	/*B5*/{ eSquare_A6 },
	/*C5*/{ eSquare_B6, eSquare_A7 },
	/*D5*/{ eSquare_C6, eSquare_B7, eSquare_A8 },
	/*E5*/{ eSquare_D6, eSquare_C7, eSquare_B8 },
	/*F5*/{ eSquare_E6, eSquare_D7, eSquare_C8 },
	/*G5*/{ eSquare_F6, eSquare_E7, eSquare_D8 },
	/*H5*/{ eSquare_G6, eSquare_F7, eSquare_E8 },

	/*A6*/{ },
	/*B6*/{ eSquare_A7 },
	/*C6*/{ eSquare_B7, eSquare_A8 },
	/*D6*/{ eSquare_C7, eSquare_B8 },
	/*E6*/{ eSquare_D7, eSquare_C8 },
	/*F6*/{ eSquare_E7, eSquare_D8 },
	/*G6*/{ eSquare_F7, eSquare_E8 },
	/*H6*/{ eSquare_G7, eSquare_F8 },

	/*A7*/{ },
	/*B7*/{ eSquare_A8 },
	/*C7*/{ eSquare_B8 },
	/*D7*/{ eSquare_C8 },
	/*E7*/{ eSquare_D8 },
	/*F7*/{ eSquare_E8 },
	/*G7*/{ eSquare_F8 },
	/*H7*/{ eSquare_G8 },

	/*A8*/{ },
	/*B8*/{ },
	/*C8*/{ },
	/*D8*/{ },
	/*E8*/{ },
	/*F8*/{ },
	/*G8*/{ },
	/*H8*/{ }
};

static vector<SquareType> KING_MOVE_LOOKUP_ARR[eSquare_NumSquares] = {
	/*A1*/{ eSquare_A2, eSquare_B2, eSquare_B1 },
	/*B1*/{ eSquare_B2, eSquare_C2, eSquare_C1, eSquare_A1, eSquare_A2 },
	/*C1*/{ eSquare_C2, eSquare_D2, eSquare_D1, eSquare_B1, eSquare_B2 },
	/*D1*/{ eSquare_D2, eSquare_E2, eSquare_E1, eSquare_C1, eSquare_C2 },
	/*E1*/{ eSquare_E2, eSquare_F2, eSquare_F1, eSquare_D1, eSquare_D2 },
	/*F1*/{ eSquare_F2, eSquare_G2, eSquare_G1, eSquare_E1, eSquare_E2 },
	/*G1*/{ eSquare_G2, eSquare_H2, eSquare_H1, eSquare_F1, eSquare_F2 },
	/*H1*/{ eSquare_H2, eSquare_G1, eSquare_G2 },

	/*A2*/{ eSquare_A3, eSquare_B3, eSquare_B2, eSquare_B1, eSquare_A1 },
	/*B2*/{ eSquare_B3, eSquare_C3, eSquare_C2, eSquare_C1, eSquare_B1, eSquare_A1, eSquare_A2, eSquare_A3 },
	/*C2*/{ eSquare_C3, eSquare_D3, eSquare_D2, eSquare_D1, eSquare_C1, eSquare_B1, eSquare_B2, eSquare_B3 },
	/*D2*/{ eSquare_D3, eSquare_E3, eSquare_E2, eSquare_E1, eSquare_D1, eSquare_C1, eSquare_C2, eSquare_C3 },
	/*E2*/{ eSquare_E3, eSquare_F3, eSquare_F2, eSquare_F1, eSquare_E1, eSquare_D1, eSquare_D2, eSquare_D3 },
	/*F2*/{ eSquare_F3, eSquare_G3, eSquare_G2, eSquare_G1, eSquare_F1, eSquare_E1, eSquare_E2, eSquare_E3 },
	/*G2*/{ eSquare_G3, eSquare_H3, eSquare_H2, eSquare_H1, eSquare_G1, eSquare_F1, eSquare_F2, eSquare_F3 },
	/*H2*/{ eSquare_H3, eSquare_H1, eSquare_G1, eSquare_G2, eSquare_G3 },

	/*A3*/{ eSquare_A4, eSquare_B4, eSquare_B3, eSquare_B2, eSquare_A2 },
	/*B3*/{ eSquare_B4, eSquare_C4, eSquare_C3, eSquare_C2, eSquare_B2, eSquare_A2, eSquare_A3, eSquare_A4 },
	/*C3*/{ eSquare_C4, eSquare_D4, eSquare_D3, eSquare_D2, eSquare_C2, eSquare_B2, eSquare_B3, eSquare_B4 },
	/*D3*/{ eSquare_D4, eSquare_E4, eSquare_E3, eSquare_E2, eSquare_D2, eSquare_C2, eSquare_C3, eSquare_C4 },
	/*E3*/{ eSquare_E4, eSquare_F4, eSquare_F3, eSquare_F2, eSquare_E2, eSquare_D2, eSquare_D3, eSquare_D4 },
	/*F3*/{ eSquare_F4, eSquare_G4, eSquare_G3, eSquare_G2, eSquare_F2, eSquare_E2, eSquare_E3, eSquare_E4 },
	/*G3*/{ eSquare_G4, eSquare_H4, eSquare_H3, eSquare_H2, eSquare_G2, eSquare_F2, eSquare_F3, eSquare_F4 },
	/*H3*/{ eSquare_H4, eSquare_H2, eSquare_G2, eSquare_G3, eSquare_G4 },

	/*A4*/{ eSquare_A5, eSquare_B5, eSquare_B4, eSquare_B3, eSquare_A3 },
	/*B4*/{ eSquare_B5, eSquare_C5, eSquare_C4, eSquare_C3, eSquare_B3, eSquare_A3, eSquare_A4, eSquare_A5 },
	/*C4*/{ eSquare_C5, eSquare_D5, eSquare_D4, eSquare_D3, eSquare_C3, eSquare_B3, eSquare_B4, eSquare_B5 },
	/*D4*/{ eSquare_D5, eSquare_E5, eSquare_E4, eSquare_E3, eSquare_D3, eSquare_C3, eSquare_C4, eSquare_C5 },
	/*E4*/{ eSquare_E5, eSquare_F5, eSquare_F4, eSquare_F3, eSquare_E3, eSquare_D3, eSquare_D4, eSquare_D5 },
	/*F4*/{ eSquare_F5, eSquare_G5, eSquare_G4, eSquare_G3, eSquare_F3, eSquare_E3, eSquare_E4, eSquare_E5 },
	/*G4*/{ eSquare_G5, eSquare_H5, eSquare_H4, eSquare_H3, eSquare_G3, eSquare_F3, eSquare_F4, eSquare_F5 },
	/*H4*/{ eSquare_H5, eSquare_H3, eSquare_G3, eSquare_G4, eSquare_G5 },

	/*A5*/{ eSquare_A6, eSquare_B6, eSquare_B5, eSquare_B4, eSquare_A4 },
	/*B5*/{ eSquare_B6, eSquare_C6, eSquare_C5, eSquare_C4, eSquare_B4, eSquare_A4, eSquare_A5, eSquare_A6 },
	/*C5*/{ eSquare_C6, eSquare_D6, eSquare_D5, eSquare_D4, eSquare_C4, eSquare_B4, eSquare_B5, eSquare_B6 },
	/*D5*/{ eSquare_D6, eSquare_E6, eSquare_E5, eSquare_E4, eSquare_D4, eSquare_C4, eSquare_C5, eSquare_C6 },
	/*E5*/{ eSquare_E6, eSquare_F6, eSquare_F5, eSquare_F4, eSquare_E4, eSquare_D4, eSquare_D5, eSquare_D6 },
	/*F5*/{ eSquare_F6, eSquare_G6, eSquare_G5, eSquare_G4, eSquare_F4, eSquare_E4, eSquare_E5, eSquare_E6 },
	/*G5*/{ eSquare_G6, eSquare_H6, eSquare_H5, eSquare_H4, eSquare_G4, eSquare_F4, eSquare_F5, eSquare_F6 },
	/*H5*/{ eSquare_H6, eSquare_H4, eSquare_G4, eSquare_G5, eSquare_G6 },

	/*A6*/{ eSquare_A7, eSquare_B7, eSquare_B6, eSquare_B5, eSquare_A5 },
	/*B6*/{ eSquare_B7, eSquare_C7, eSquare_C6, eSquare_C5, eSquare_B5, eSquare_A5, eSquare_A6, eSquare_A7 },
	/*C6*/{ eSquare_C7, eSquare_D7, eSquare_D6, eSquare_D5, eSquare_C5, eSquare_B5, eSquare_B6, eSquare_B7 },
	/*D6*/{ eSquare_D7, eSquare_E7, eSquare_E6, eSquare_E5, eSquare_D5, eSquare_C5, eSquare_C6, eSquare_C7 },
	/*E6*/{ eSquare_E7, eSquare_F7, eSquare_F6, eSquare_F5, eSquare_E5, eSquare_D5, eSquare_D6, eSquare_D7 },
	/*F6*/{ eSquare_F7, eSquare_G7, eSquare_G6, eSquare_G5, eSquare_F5, eSquare_E5, eSquare_E6, eSquare_E7 },
	/*G6*/{ eSquare_G7, eSquare_H7, eSquare_H6, eSquare_H5, eSquare_G5, eSquare_F5, eSquare_F6, eSquare_F7 },
	/*H6*/{ eSquare_H7, eSquare_H5, eSquare_G5, eSquare_G6, eSquare_G7 },

	/*A7*/{ eSquare_A8, eSquare_B8, eSquare_B7, eSquare_B6, eSquare_A6 },
	/*B7*/{ eSquare_B8, eSquare_C8, eSquare_C7, eSquare_C6, eSquare_B6, eSquare_A6, eSquare_A7, eSquare_A8 },
	/*C7*/{ eSquare_C8, eSquare_D8, eSquare_D7, eSquare_D6, eSquare_C6, eSquare_B6, eSquare_B7, eSquare_B8 },
	/*D7*/{ eSquare_D8, eSquare_E8, eSquare_E7, eSquare_E6, eSquare_D6, eSquare_C6, eSquare_C7, eSquare_C8 },
	/*E7*/{ eSquare_E8, eSquare_F8, eSquare_F7, eSquare_F6, eSquare_E6, eSquare_D6, eSquare_D7, eSquare_D8 },
	/*F7*/{ eSquare_F8, eSquare_G8, eSquare_G7, eSquare_G6, eSquare_F6, eSquare_E6, eSquare_E7, eSquare_E8 },
	/*G7*/{ eSquare_G8, eSquare_H8, eSquare_H7, eSquare_H6, eSquare_G6, eSquare_F6, eSquare_F7, eSquare_F8 },
	/*H7*/{ eSquare_H8, eSquare_H6, eSquare_G6, eSquare_G7, eSquare_G8 },

	/*A8*/{ eSquare_B8, eSquare_B7, eSquare_A7 },
	/*B8*/{ eSquare_C8, eSquare_C7, eSquare_B7, eSquare_A7, eSquare_A8 },
	/*C8*/{ eSquare_D8, eSquare_D7, eSquare_C7, eSquare_B7, eSquare_B8 },
	/*D8*/{ eSquare_E8, eSquare_E7, eSquare_D7, eSquare_C7, eSquare_C8 },
	/*E8*/{ eSquare_F8, eSquare_F7, eSquare_E7, eSquare_D7, eSquare_D8 },
	/*F8*/{ eSquare_G8, eSquare_G7, eSquare_F7, eSquare_E7, eSquare_E8 },
	/*G8*/{ eSquare_H8, eSquare_H7, eSquare_G7, eSquare_F7, eSquare_F8 },
	/*H8*/{ eSquare_H7, eSquare_G7, eSquare_G8 }
};

namespace GameUtils {
	static SquareType findPieceOnLine(const vector<SquareType>& lineToCheckVec,
									  PieceType pieceToCheck,
									  const PieceType(&board)[eSquare_NumSquares]) {
		for (SquareType square : lineToCheckVec) {
			if (board[square] == pieceToCheck) {
				return square;
			}

			if (board[square] != ePiece_None) {
				return eSquare_None;
			}
		}

		return eSquare_None;
	}

	static void findPieceOnSquares(const vector<SquareType>& squaresToCheckVec,
								   PieceType pieceToCheck,
								   const PieceType(&board)[eSquare_NumSquares],
								   vector<SquareType>& possibleSourceSquaresVec) {
		for (SquareType sourceSquare : squaresToCheckVec) {
			if (board[sourceSquare] == pieceToCheck) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		}
	}

	static void findSquaresBishopMoveMayComeFrom(PieceType pieceToCheck, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
		SquareType sourceSquare = eSquare_None;

		sourceSquare = findPieceOnLine(BISHOP_MOVE_UP_RIGHT_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}

		sourceSquare = findPieceOnLine(BISHOP_MOVE_DOWN_RIGHT_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}

		sourceSquare = findPieceOnLine(BISHOP_MOVE_DOWN_LEFT_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}

		sourceSquare = findPieceOnLine(BISHOP_MOVE_UP_LEFT_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}
	}

	static void findSquaresRookMoveMayComeFrom(PieceType pieceToCheck, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
		SquareType sourceSquare = eSquare_None;

		sourceSquare = findPieceOnLine(ROOK_MOVE_UP_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}

		sourceSquare = findPieceOnLine(ROOK_MOVE_RIGHT_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}

		sourceSquare = findPieceOnLine(ROOK_MOVE_DOWN_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}

		sourceSquare = findPieceOnLine(ROOK_MOVE_LEFT_LOOKUP_ARR[targetSquare], pieceToCheck, board);
		if (sourceSquare != eSquare_None) {
			possibleSourceSquaresVec.emplace_back(sourceSquare);
		}
	}

	static bool isPieceOnSquares(const vector<SquareType>& squareToCheckVec,
								 PieceType pieceToCheck,
								 const PieceType(&board)[eSquare_NumSquares]) {
		for (INT8 square : squareToCheckVec) {
			if (board[square] == pieceToCheck) {
				return true;
			}
		}

		return false;
	}

	static bool isKingAttackedByKnight(SquareType pieceSquare,
									   PieceType pieceToCheck,
									   const PieceType(&board)[eSquare_NumSquares]) {
		ASSERT(0 <= pieceSquare && pieceSquare < eSquare_NumSquares);
		const vector<SquareType>& lookupVec = KNIGHT_MOVE_LOOKUP_ARR[pieceSquare];

		return isPieceOnSquares(lookupVec, pieceToCheck, board);
	}

	static bool isPieceOnLine(const vector<SquareType>& lineToCheckVec,
							  PieceType pieceToCheck,
							  const PieceType(&board)[eSquare_NumSquares]) {
		for (INT8 square : lineToCheckVec) {
			if (board[square] == pieceToCheck) {
				return true;
			}

			if (board[square] != ePiece_None) {
				break;
			}
		}

		return false;
	}

	static bool isKingAttackedByBishop(SquareType pieceSquare,
									   PieceType pieceToCheck,
									   const PieceType(&board)[eSquare_NumSquares]) {

		ASSERT(0 <= pieceSquare && pieceSquare < eSquare_NumSquares);

		const vector<SquareType>& diagUpRightLookupVec = BISHOP_MOVE_UP_RIGHT_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(diagUpRightLookupVec, pieceToCheck, board)) {
			return true;
		}

		const vector<SquareType>& diagDownRightLookupVec = BISHOP_MOVE_DOWN_RIGHT_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(diagDownRightLookupVec, pieceToCheck, board)) {
			return true;
		}

		const vector<SquareType>& diagDownLeftLookupVec = BISHOP_MOVE_DOWN_LEFT_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(diagDownLeftLookupVec, pieceToCheck, board)) {
			return true;
		}

		const vector<SquareType>& diagUpLeftLookupVec = BISHOP_MOVE_UP_LEFT_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(diagUpLeftLookupVec, pieceToCheck, board)) {
			return true;
		}

		return false;
	}

	static bool isKingAttackedByRook(SquareType pieceSquare,
									 PieceType pieceToCheck,
									 const PieceType(&board)[eSquare_NumSquares]) {
		ASSERT(0 <= pieceSquare && pieceSquare < eSquare_NumSquares);

		const vector<SquareType>& upLookupVec = ROOK_MOVE_UP_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(upLookupVec, pieceToCheck, board)) {
			return true;
		}

		const vector<SquareType>& rightLookupVec = ROOK_MOVE_RIGHT_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(rightLookupVec, pieceToCheck, board)) {
			return true;
		}

		const vector<SquareType>& downLookupVec = ROOK_MOVE_DOWN_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(downLookupVec, pieceToCheck, board)) {
			return true;
		}

		const vector<SquareType>& leftLookupVec = ROOK_MOVE_LEFT_LOOKUP_ARR[pieceSquare];
		if (isPieceOnLine(leftLookupVec, pieceToCheck, board)) {
			return true;
		}

		return false;
	}

	static bool isKingAttackedByKing(SquareType pieceSquare,
									 PieceType pieceToCheck,
									 const PieceType(&board)[eSquare_NumSquares]) {
		ASSERT(0 <= pieceSquare && pieceSquare < eSquare_NumSquares);
		const vector<SquareType>& lookupVec = KING_MOVE_LOOKUP_ARR[pieceSquare];

		return isPieceOnSquares(lookupVec, pieceToCheck, board);
	}
}

typedef bool(*IsKingAttackedByPieceFn)(SquareType, const PieceType(&)[eSquare_NumSquares]);
typedef void(*FindSquaresMoveMayComeFromFn)(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>&possibleSourceSquaresVec);
static vector<bool> PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_NumPieces] = {
	/* ePiece_WhitePawn   */{ true, false }
	/* ePiece_WhiteKnight */, { true, true, false, true }
	/* ePiece_WhiteBishop */, { true, true, false, false }
	/* ePiece_WhiteRook   */, { true, true, true, false }
	/* ePiece_WhiteQueen  */, { true, true, true, true, false }
	/* ePiece_WhiteKing   */, { true, true, true, true, true }
	/* ePiece_BlackPawn   */, { true, false }
	/* ePiece_BlackKnight */, { true, true, false, true }
	/* ePiece_BlackBishop */, { true, true, false, false }
	/* ePiece_BlackRook   */, { true, true, true, false }
	/* ePiece_BlackQueen  */, { true, true, true, true, false }
	/* ePiece_BlackKing   */, { true, true, true, true, true }
};

struct PieceTypeInfo {
	PieceType piece;
	ColorType pieceColor;
	IsKingAttackedByPieceFn isKingAttackedByPieceFn;
	FindSquaresMoveMayComeFromFn findSquaresMoveMayComeFromFn;
	vector<bool> compactPositionRepresentation;

	PieceTypeInfo(PieceType piece_, ColorType pieceColor_, IsKingAttackedByPieceFn isKingAttackedByPieceFn_, 
				  FindSquaresMoveMayComeFromFn findSquaresMoveMayComeFromFn_,
				  const vector<bool>& compactPositionRepresentation_)
		: piece(piece_)
		, pieceColor(pieceColor_)
		, isKingAttackedByPieceFn(isKingAttackedByPieceFn_)
		, findSquaresMoveMayComeFromFn(findSquaresMoveMayComeFromFn_)
		, compactPositionRepresentation(compactPositionRepresentation_) {
	}
};
static const PieceTypeInfo PIECE_TYPE_INFO[] = {
	{ ePiece_WhitePawn, eColor_White, GameUtils::isKingAttackedByWhitePawn, GameUtils::findSquaresWhitePawnMoveMayComeFrom, PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_WhitePawn] }
	, { ePiece_WhiteKnight, eColor_White, GameUtils::isKingAttackedByWhiteKnight, GameUtils::findSquaresWhiteKnightMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_WhiteKnight] }
	, { ePiece_WhiteBishop, eColor_White, GameUtils::isKingAttackedByWhiteBishop, GameUtils::findSquaresWhiteBishopMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_WhiteBishop] }
	, { ePiece_WhiteRook, eColor_White, GameUtils::isKingAttackedByWhiteRook, GameUtils::findSquaresWhiteRookMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_WhiteRook] }
	, { ePiece_WhiteQueen, eColor_White, GameUtils::isKingAttackedByWhiteQueen, GameUtils::findSquaresWhiteQueenMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_WhiteQueen] }
	, { ePiece_WhiteKing, eColor_White, GameUtils::isKingAttackedByWhiteKing, GameUtils::findSquaresWhiteKingMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_WhiteKing] }
	, { ePiece_BlackPawn, eColor_Black, GameUtils::isKingAttackedByBlackPawn, GameUtils::findSquaresBlackPawnMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_BlackPawn] }
	, { ePiece_BlackKnight, eColor_Black, GameUtils::isKingAttackedByBlackKnight, GameUtils::findSquaresBlackKnightMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_BlackKnight] }
	, { ePiece_BlackBishop, eColor_Black, GameUtils::isKingAttackedByBlackBishop, GameUtils::findSquaresBlackBishopMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_BlackBishop] }
	, { ePiece_BlackRook, eColor_Black, GameUtils::isKingAttackedByBlackRook, GameUtils::findSquaresBlackRookMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_BlackRook] }
	, { ePiece_BlackQueen, eColor_Black, GameUtils::isKingAttackedByBlackQueen, GameUtils::findSquaresBlackQueenMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_BlackQueen] }
	, { ePiece_BlackKing, eColor_Black, GameUtils::isKingAttackedByBlackKing, GameUtils::findSquaresBlackKingMoveMayComeFrom , PIECE_TO_COMPACT_POSITION_REPRESENTATION[ePiece_BlackKing] }
};

void GameUtils::pieceToCompactPositionRepresentation(PieceType piece, const vector<bool>** const representation) {
	unsigned pieceIndex = piece;
	ASSERT(pieceIndex < SZARR(PIECE_TYPE_INFO));
	const PieceTypeInfo& pieceTypeInfo = PIECE_TYPE_INFO[pieceIndex];
	*representation = &(pieceTypeInfo.compactPositionRepresentation);
}

///////////////////////////////////////////////////////////////////////////////

void toCompactedPosition(const Position& pos, CompactedPosition& compactPos) {
	static CompactPositionBuilder builder;
	builder.clear();
	builder.appendColorToMove(pos.colorToMove == eColor_Black ? eColor_White : eColor_Black);
	for (PieceType piece : pos.board) {
		builder.appendPiece(piece);
	}

	//	builder.append50MoveRuleNumHalfMoves(pos.numHalfMoves_50MoveRule);
//	builder.append50MoveRuleNumHalfMoves(MAX_HALF_MOVES_50_MOVE_RULE);
	builder.append50MoveRuleNumHalfMoves(MATCH_ANY_HALF_MOVES_50_MOVE_RULE);

//	builder.appendEnPassantFile(pos.enPassantFile);
	builder.appendEnPassantFile(eFile_NumFiles);

	builder.appendCastlingOptions(pos.whiteCanCastleQSide, pos.whiteCanCastleKSide, pos.blackCanCastleQSide, pos.blackCanCastleKSide);

	builder.toPosition(compactPos);
}

///////////////////////////////////////////////////////////////////////////////

struct MoveTypeInfo {
	MoveType moveType;
	Position::GetNextPosFn getNextPosFn;

	MoveTypeInfo(MoveType moveType_, Position::GetNextPosFn getNextPosFn_)
		: moveType(moveType_), getNextPosFn(getNextPosFn_) {
	}
};

static MoveTypeInfo MOVE_TYPE_INFO[] = {
	{ eMove_Simple, &Position::getNextPosition_SimpleMove }
	, { eMove_Capture, &Position::getNextPosition_CaptureMove }
	, { eMove_Castle, &Position::getNextPosition_CastleMove }
	, { eMove_EnPassant, &Position::getNextPosition_EnPassantMove }
	, { eMove_Promotion, &Position::getNextPosition_PromotionMove }
};

Position::GetNextPosFn getNextPosFunctionByMoveType(INT8 moveType) {
	auto begin = MOVE_TYPE_INFO;
	auto end = MOVE_TYPE_INFO + SZARR(MOVE_TYPE_INFO);

	auto it = std::find_if(begin, end, [=](const MoveTypeInfo& moveTypeInfo) {
		return moveTypeInfo.moveType == moveType;
	});

	if (it == end) {
		return nullptr;
	}

	const MoveTypeInfo& moveTypeInfo = *it;
	return moveTypeInfo.getNextPosFn;
}

///////////////////////////////////////////////////////////////////////////////

struct GameMetaDataKeyTypeInfo {
	GameMetaDataKeyType gameMetaDataKeyType;
	const char* keyTypeStr;
	GameMetaData::UpdateKeyFn updateKeyFn;

	GameMetaDataKeyTypeInfo(GameMetaDataKeyType gameMetaDataKeyType_, const char* keyTypeStr_, GameMetaData::UpdateKeyFn updateKeyFn_)
		: gameMetaDataKeyType(gameMetaDataKeyType_)
		, keyTypeStr(keyTypeStr_)
		, updateKeyFn(updateKeyFn_) {
	}
};

static GameMetaDataKeyTypeInfo GAME_METADATA_KEY_TYPE_INFO[] = {
	{ eGameMetaDataKey_Event, GAME_META_KEY_EVENT, &GameMetaData::updateEventKey }
	, { eGameMetaDataKey_Site, GAME_META_KEY_SITE, &GameMetaData::updateSiteKey }
	, { eGameMetaDataKey_GameDate, GAME_META_KEY_GAMEDATE, &GameMetaData::updateGameDateKey }
	, { eGameMetaDataKey_EventDate, GAME_META_KEY_EVENTDATE, &GameMetaData::updateEventDateKey }
	, { eGameMetaDataKey_Round, GAME_META_KEY_ROUND, &GameMetaData::updateRoundKey }
	, { eGameMetaDataKey_WhitePlayerName, GAME_META_KEY_WHITEPLAYERNAME, &GameMetaData::updateWhitePlayerNameKey }
	, { eGameMetaDataKey_BlackPlayerName, GAME_META_KEY_BLACKPLAYERNAME, &GameMetaData::updateBlackPlayerNameKey }
	, { eGameMetaDataKey_WhiteElo, GAME_META_KEY_WHITEELO, &GameMetaData::updateWhiteEloKey }
	, { eGameMetaDataKey_BlackElo, GAME_META_KEY_BLACKELO, &GameMetaData::updateBlackEloKey }
	, { eGameMetaDataKey_Result, GAME_META_KEY_RESULT, &GameMetaData::updateResultKey }
	, { eGameMetaDataKey_EcoCode, GAME_META_KEY_ECOCODE, &GameMetaData::updateEcoCodeKey }
};

GameMetaDataKeyType getGameMetaDataKeyFromString(const char* keyTypeStr) {
	auto begin = GAME_METADATA_KEY_TYPE_INFO;
	auto end = GAME_METADATA_KEY_TYPE_INFO + SZARR(GAME_METADATA_KEY_TYPE_INFO);

	auto it = std::find_if(begin, end, [=](const GameMetaDataKeyTypeInfo& info) {
		return (strncmp(info.keyTypeStr, keyTypeStr, MAX_GAME_META_KEY_LEN) == 0);
	});

	if (it == end) {
		return eGameMetaDataKey_None;
	}

	const GameMetaDataKeyTypeInfo& keyTypeInfo = *it;
	return keyTypeInfo.gameMetaDataKeyType;
}

GameMetaData::UpdateKeyFn updateMetaDataKeyByKeyType(INT8 keyType) {
	auto begin = GAME_METADATA_KEY_TYPE_INFO;
	auto end = GAME_METADATA_KEY_TYPE_INFO + SZARR(GAME_METADATA_KEY_TYPE_INFO);

	auto it = std::find_if(begin, end, [=](const GameMetaDataKeyTypeInfo& gameMetaDataKeyTypeInfo) {
		return gameMetaDataKeyTypeInfo.gameMetaDataKeyType == keyType;
	});

	if (it == end) {
		return nullptr;
	}

	const GameMetaDataKeyTypeInfo& keyTypeInfo = *it;
	return keyTypeInfo.updateKeyFn;
}

///////////////////////////////////////////////////////////////////////////////

struct PgnCharToPieceInfo {
	char pgnChar;
	ColorType sideToMove;
	PieceType piece;

	PgnCharToPieceInfo(char pgnChar_, ColorType sideToMove_, PieceType piece_)
		: pgnChar(pgnChar_), sideToMove(sideToMove_), piece(piece_) {
	}
};

static PgnCharToPieceInfo PGN_CHAR_TO_PIECE_TABLE[] = {
	PgnCharToPieceInfo('R', eColor_White, ePiece_WhiteRook)
	, PgnCharToPieceInfo('R', eColor_Black, ePiece_BlackRook)
	, PgnCharToPieceInfo('N', eColor_White, ePiece_WhiteKnight)
	, PgnCharToPieceInfo('N', eColor_Black, ePiece_BlackKnight)
	, PgnCharToPieceInfo('B', eColor_White, ePiece_WhiteBishop)
	, PgnCharToPieceInfo('B', eColor_Black, ePiece_BlackBishop)
	, PgnCharToPieceInfo('Q', eColor_White, ePiece_WhiteQueen)
	, PgnCharToPieceInfo('Q', eColor_Black, ePiece_BlackQueen)
	, PgnCharToPieceInfo('K', eColor_White, ePiece_WhiteKing)
	, PgnCharToPieceInfo('K', eColor_Black, ePiece_BlackKing)
};

PieceType GameUtils::pgnCharToPiece(
	char pgnChar						// RNBQK
	, ColorType sideToMove) {
	for (const PgnCharToPieceInfo& info : PGN_CHAR_TO_PIECE_TABLE) {
		if (info.pgnChar == pgnChar && info.sideToMove == sideToMove) {
			return info.piece;
		}
	}

	return ePiece_None;
}

FileType GameUtils::pgnCharToFile(char pgnChar) {
	if ('a' > pgnChar || pgnChar > 'h') {
		return eFile_None;
	} else {
		return static_cast<FileType>(pgnChar - 'a');
	}
}

RankType GameUtils::pgnCharToRank(char pgnChar) {
	if ('1' > pgnChar || pgnChar > '8') {
		return eRank_None;
	} else {
		return static_cast<RankType>(pgnChar - '1');
	}
}

///////////////////////////////////////////////////////////////////////////////

struct IniFileCharToPieceInfo {
	char iniFileChar;
	PieceType piece;

	IniFileCharToPieceInfo(char iniFileChar_, PieceType piece_)
		: iniFileChar(iniFileChar_), piece(piece_) {
	}
};

static IniFileCharToPieceInfo INI_FILE_CHAR_TO_PIECE_TABLE[] = {
	IniFileCharToPieceInfo('R', ePiece_WhiteRook)
	, IniFileCharToPieceInfo('r', ePiece_BlackRook)
	, IniFileCharToPieceInfo('N', ePiece_WhiteKnight)
	, IniFileCharToPieceInfo('n', ePiece_BlackKnight)
	, IniFileCharToPieceInfo('B', ePiece_WhiteBishop)
	, IniFileCharToPieceInfo('b', ePiece_BlackBishop)
	, IniFileCharToPieceInfo('Q', ePiece_WhiteQueen)
	, IniFileCharToPieceInfo('q', ePiece_BlackQueen)
	, IniFileCharToPieceInfo('K', ePiece_WhiteKing)
	, IniFileCharToPieceInfo('k', ePiece_BlackKing)
	, IniFileCharToPieceInfo('P', ePiece_WhitePawn)
	, IniFileCharToPieceInfo('p', ePiece_BlackPawn)
	, IniFileCharToPieceInfo('_', ePiece_None)
};

PieceType GameUtils::iniFileCharToPiece(
	char iniFileChar					// prnkbqkPRNBQK_
) {
	for (const IniFileCharToPieceInfo& info : INI_FILE_CHAR_TO_PIECE_TABLE) {
		if (info.iniFileChar == iniFileChar) {
			return info.piece;
		}
	}

	return ePiece_None;
}

///////////////////////////////////////////////////////////////////////////////

FileType GameUtils::getFileFromSquare(SquareType square) {
	if (square == eSquare_None) {
		return eFile_None;
	}

	static const FileType FILE_BY_SQUARE[eSquare_NumSquares] = {
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H,
		eFile_A, eFile_B, eFile_C, eFile_D, eFile_E, eFile_F, eFile_G, eFile_H
	};

	BYTE square_ = square;
	ASSERT(square_ < SZARR(FILE_BY_SQUARE));

	return FILE_BY_SQUARE[square];
}

RankType GameUtils::getRankFromSquare(SquareType square) {
	if (square == eSquare_None) {
		return eRank_None;
	}

	static const RankType RANK_BY_SQUARE[eSquare_NumSquares] = {
		eRank_1, eRank_1, eRank_1, eRank_1, eRank_1, eRank_1, eRank_1, eRank_1,
		eRank_2, eRank_2, eRank_2, eRank_2, eRank_2, eRank_2, eRank_2, eRank_2,
		eRank_3, eRank_3, eRank_3, eRank_3, eRank_3, eRank_3, eRank_3, eRank_3,
		eRank_4, eRank_4, eRank_4, eRank_4, eRank_4, eRank_4, eRank_4, eRank_4,
		eRank_5, eRank_5, eRank_5, eRank_5, eRank_5, eRank_5, eRank_5, eRank_5,
		eRank_6, eRank_6, eRank_6, eRank_6, eRank_6, eRank_6, eRank_6, eRank_6,
		eRank_7, eRank_7, eRank_7, eRank_7, eRank_7, eRank_7, eRank_7, eRank_7,
		eRank_8, eRank_8, eRank_8, eRank_8, eRank_8, eRank_8, eRank_8, eRank_8
	};

	BYTE square_ = square;
	ASSERT(square_ < SZARR(RANK_BY_SQUARE));

	return RANK_BY_SQUARE[square];
}

SquareType GameUtils::getSquare(FileType file, RankType rank) {
	BYTE file_ = file;
	BYTE rank_ = rank;
	BYTE square_ = rank_ * eFile_NumFiles + file_;
	SquareType square = static_cast<SquareType>(square_);
	return square;
}

// E.g. Nb6 or Nxb6 - Which square did the Knight come from?
SquareType GameUtils::findSquareMoveComesFrom(bool isCapture, PieceType pieceToMove, SquareType targetSquare,
											  FileType moveMustComeFromThisFile,
											  RankType moveMustComeFromThisRank,
											  const PieceType(&preMoveBoard)[eSquare_NumSquares]) {
	vector<SquareType> possibleSourceSquaresVec;
	ColorType attackingColor = getColorOfPiece(pieceToMove);

	ASSERT(pieceToMove != ePiece_None);
	ASSERT((BYTE)pieceToMove < SZARR(PIECE_TYPE_INFO));
	FindSquaresMoveMayComeFromFn findSquaresMoveMayComeFromFn = PIECE_TYPE_INFO[pieceToMove].findSquaresMoveMayComeFromFn;
	findSquaresMoveMayComeFromFn(isCapture, targetSquare, preMoveBoard, possibleSourceSquaresVec);

	SquareType squareFrom = eSquare_None;

	PieceType pieceOnTargetSquare = preMoveBoard[targetSquare];
	PieceType copyBoard[eSquare_NumSquares];
	std::copy(preMoveBoard, preMoveBoard + SZARR(preMoveBoard), copyBoard);

	for (SquareType possibleSourceSquare : possibleSourceSquaresVec) {

		if (moveMustComeFromThisFile != eFile_None) {
			FileType sourceSquareFile = GameUtils::getFileFromSquare(possibleSourceSquare);
			if (sourceSquareFile != moveMustComeFromThisFile) {
				continue;
			}
		}

		if (moveMustComeFromThisRank != eRank_None) {
			RankType sourceSquareRank = GameUtils::getRankFromSquare(possibleSourceSquare);
			if (sourceSquareRank != moveMustComeFromThisRank) {
				continue;
			}
		}

		copyBoard[possibleSourceSquare] = ePiece_None;
		copyBoard[targetSquare] = pieceToMove;

		if (!isKingAttacked(attackingColor, copyBoard)) {
			ASSERT(squareFrom == eSquare_None);
			squareFrom = possibleSourceSquare;
		}

		// Restore position for next iteration of the loop
		copyBoard[possibleSourceSquare] = pieceToMove;
		copyBoard[targetSquare] = pieceOnTargetSquare;
	}

	ASSERT(squareFrom != eSquare_None);

	return static_cast<SquareType>(squareFrom);
}

ColorType GameUtils::getColorOfPiece(PieceType piece) {
	BYTE pieceIndex = piece;
	ASSERT(pieceIndex < SZARR(PIECE_TYPE_INFO));
	return PIECE_TYPE_INFO[pieceIndex].pieceColor;
}

///////////////////////////////////////////////////////////////////////////////

void GameUtils::findSquaresWhitePawnMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	INT8 targetSquare_ = targetSquare;
	INT8 numFiles_ = eFile_NumFiles;
	INT8 numRanks_ = eRank_NumRanks;

	FileType targetFile = getFileFromSquare(targetSquare);
	if (isCapture) {
		if (targetFile == eFile_A) {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ - numFiles_ + 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		} else if (targetFile == eFile_H) {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ - numFiles_ - 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		} else {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare - numFiles_ + 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}

			sourceSquare = static_cast<SquareType>(targetSquare_ - numFiles_ - 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		}
	} else {
		RankType targetRank = getRankFromSquare(targetSquare);
		if (targetRank == eRank_5 && board[targetSquare_ + numRanks_] == ePiece_None) {
			SquareType sourceSquare = getSquare(targetFile, eRank_7);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		} else {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ + numRanks_);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		}
	}
}

void GameUtils::findSquaresWhiteKnightMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findPieceOnSquares(KNIGHT_MOVE_LOOKUP_ARR[targetSquare], ePiece_WhiteKnight, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresWhiteBishopMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findSquaresBishopMoveMayComeFrom(ePiece_WhiteBishop, targetSquare, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresWhiteRookMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findSquaresRookMoveMayComeFrom(ePiece_WhiteRook, targetSquare, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresWhiteQueenMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findSquaresBishopMoveMayComeFrom(ePiece_WhiteQueen, targetSquare, board, possibleSourceSquaresVec);
	findSquaresRookMoveMayComeFrom(ePiece_WhiteQueen, targetSquare, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresWhiteKingMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findPieceOnSquares(KING_MOVE_LOOKUP_ARR[targetSquare], ePiece_WhiteKing, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresBlackPawnMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	INT8 targetSquare_ = targetSquare;
	INT8 numFiles_ = eFile_NumFiles;
	INT8 numRanks_ = eRank_NumRanks;

	FileType targetFile = getFileFromSquare(targetSquare);

	if (isCapture) {
		if (targetFile == eFile_A) {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ + numFiles_ + 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		} else if (targetFile == eFile_H) {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ + numFiles_ - 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		} else {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ + numFiles_ + 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}

			sourceSquare = static_cast<SquareType>(targetSquare_ + numFiles_ - 1);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		}
	} else {
		RankType targetRank = getRankFromSquare(targetSquare);
		if (targetRank == eRank_5 && board[targetSquare_ + numRanks_] == ePiece_None) {
			SquareType sourceSquare = getSquare(targetFile, eRank_7);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		} else {
			SquareType sourceSquare = static_cast<SquareType>(targetSquare_ + numRanks_);
			if (board[sourceSquare] == ePiece_BlackPawn) {
				possibleSourceSquaresVec.emplace_back(sourceSquare);
			}
		}
	}
}

void GameUtils::findSquaresBlackKnightMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findPieceOnSquares(KNIGHT_MOVE_LOOKUP_ARR[targetSquare], ePiece_BlackKnight, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresBlackBishopMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findSquaresBishopMoveMayComeFrom(ePiece_BlackBishop, targetSquare, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresBlackRookMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findSquaresRookMoveMayComeFrom(ePiece_BlackRook, targetSquare, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresBlackQueenMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findSquaresBishopMoveMayComeFrom(ePiece_BlackQueen, targetSquare, board, possibleSourceSquaresVec);
	findSquaresRookMoveMayComeFrom(ePiece_BlackQueen, targetSquare, board, possibleSourceSquaresVec);
}

void GameUtils::findSquaresBlackKingMoveMayComeFrom(bool isCapture, SquareType targetSquare, const PieceType(&board)[eSquare_NumSquares], vector<SquareType>& possibleSourceSquaresVec) {
	findPieceOnSquares(KING_MOVE_LOOKUP_ARR[targetSquare], ePiece_BlackKing, board, possibleSourceSquaresVec);
}

bool GameUtils::isKingAttacked(ColorType kingColor, const PieceType(&board)[eSquare_NumSquares]) {

	for (INT8 i = 0; i < eSquare_NumSquares; ++i) {
		PieceType thisSquarePiece = board[i];

		if (thisSquarePiece == ePiece_None) {
			continue;
		}

		ColorType thisSquareColor = getColorOfPiece(board[i]);

		if (thisSquareColor == kingColor) {
			continue;
		}

		size_t index = thisSquarePiece;
		ASSERT(index < SZARR(PIECE_TYPE_INFO));
		IsKingAttackedByPieceFn isKingAttackedByThisSquarePieceFn = PIECE_TYPE_INFO[index].isKingAttackedByPieceFn;

		SquareType square = static_cast<SquareType>(i);
		if (isKingAttackedByThisSquarePieceFn(square, board)) {
			return true;
		}
	}

	return false;
}

bool GameUtils::isKingAttackedByWhitePawn(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	static vector<SquareType> lookupArr[eSquare_NumSquares] = {
		/*A1*/{ },
		/*B1*/{ },
		/*C1*/{ },
		/*D1*/{ },
		/*E1*/{ },
		/*F1*/{ },
		/*G1*/{ },
		/*H1*/{ },
		/*A2*/{ eSquare_B3 },
		/*B2*/{ eSquare_A3, eSquare_C3 },
		/*C2*/{ eSquare_B3, eSquare_D3 },
		/*D2*/{ eSquare_C3, eSquare_E3 },
		/*E2*/{ eSquare_D3, eSquare_F3 },
		/*F2*/{ eSquare_E3, eSquare_G3 },
		/*G2*/{ eSquare_F3, eSquare_H3 },
		/*H2*/{ eSquare_G3 },
		/*A3*/{ eSquare_B4 },
		/*B3*/{ eSquare_A4, eSquare_C4 },
		/*C3*/{ eSquare_B4, eSquare_D4 },
		/*D3*/{ eSquare_C4, eSquare_E4 },
		/*E3*/{ eSquare_D4, eSquare_F4 },
		/*F3*/{ eSquare_E4, eSquare_G4 },
		/*G3*/{ eSquare_F4, eSquare_H4 },
		/*H3*/{ eSquare_G4 },
		/*A4*/{ eSquare_B5 },
		/*B4*/{ eSquare_A5, eSquare_C5 },
		/*C4*/{ eSquare_B5, eSquare_D5 },
		/*D4*/{ eSquare_C5, eSquare_E5 },
		/*E4*/{ eSquare_D5, eSquare_F5 },
		/*F4*/{ eSquare_E5, eSquare_G5 },
		/*G4*/{ eSquare_F5, eSquare_H5 },
		/*H4*/{ eSquare_G5 },
		/*A5*/{ eSquare_B6 },
		/*B5*/{ eSquare_A6, eSquare_C6 },
		/*C5*/{ eSquare_B6, eSquare_D6 },
		/*D5*/{ eSquare_C6, eSquare_E6 },
		/*E5*/{ eSquare_D6, eSquare_F6 },
		/*F5*/{ eSquare_E6, eSquare_G6 },
		/*G5*/{ eSquare_F6, eSquare_H6 },
		/*H5*/{ eSquare_G6 },
		/*A6*/{ eSquare_B7 },
		/*B6*/{ eSquare_A7, eSquare_C7 },
		/*C6*/{ eSquare_B7, eSquare_D7 },
		/*D6*/{ eSquare_C7, eSquare_E7 },
		/*E6*/{ eSquare_D7, eSquare_F7 },
		/*F6*/{ eSquare_E7, eSquare_G7 },
		/*G6*/{ eSquare_F7, eSquare_H7 },
		/*H6*/{ eSquare_G7 },
		/*A7*/{ eSquare_B8 },
		/*B7*/{ eSquare_A8, eSquare_C8 },
		/*C7*/{ eSquare_B8, eSquare_D8 },
		/*D7*/{ eSquare_C8, eSquare_E8 },
		/*E7*/{ eSquare_D8, eSquare_F8 },
		/*F7*/{ eSquare_E8, eSquare_G8 },
		/*G7*/{ eSquare_F8, eSquare_H8 },
		/*H7*/{ eSquare_G8 },
		/*A8*/{ },
		/*B8*/{ },
		/*C8*/{ },
		/*D8*/{ },
		/*E8*/{ },
		/*F8*/{ },
		/*G8*/{ },
		/*H8*/{ }
	};

	ASSERT(0 <= pieceSquare && pieceSquare < eSquare_NumSquares);
	const vector<SquareType>& lookupVec = lookupArr[pieceSquare];
	ASSERT(!lookupVec.empty());

	return isPieceOnSquares(lookupVec, ePiece_BlackKing, board);
}

bool GameUtils::isKingAttackedByWhiteKnight(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByKnight(pieceSquare, ePiece_BlackKing, board);
}

bool GameUtils::isKingAttackedByWhiteBishop(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByBishop(pieceSquare, ePiece_BlackKing, board);
}

bool GameUtils::isKingAttackedByWhiteRook(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByRook(pieceSquare, ePiece_BlackKing, board);
}

bool GameUtils::isKingAttackedByWhiteQueen(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByWhiteBishop(pieceSquare, board) || isKingAttackedByWhiteRook(pieceSquare, board);
}

bool GameUtils::isKingAttackedByWhiteKing(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByKing(pieceSquare, ePiece_BlackKing, board);
}

bool GameUtils::isKingAttackedByBlackPawn(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	static vector<SquareType> lookupArr[eSquare_NumSquares] = {
		/*A1*/{ },
		/*B1*/{ },
		/*C1*/{ },
		/*D1*/{ },
		/*E1*/{ },
		/*F1*/{ },
		/*G1*/{ },
		/*H1*/{ },

		/*A2*/{ eSquare_B1 },
		/*B2*/{ eSquare_A1, eSquare_C1 },
		/*C2*/{ eSquare_B1, eSquare_D1 },
		/*D2*/{ eSquare_C1, eSquare_E1 },
		/*E2*/{ eSquare_D1, eSquare_F1 },
		/*F2*/{ eSquare_E1, eSquare_G1 },
		/*G2*/{ eSquare_F1, eSquare_H1 },
		/*H2*/{ eSquare_G1 },

		/*A3*/{ eSquare_B2 },
		/*B3*/{ eSquare_A2, eSquare_C2 },
		/*C3*/{ eSquare_B2, eSquare_D2 },
		/*D3*/{ eSquare_C2, eSquare_E2 },
		/*E3*/{ eSquare_D2, eSquare_F2 },
		/*F3*/{ eSquare_E2, eSquare_G2 },
		/*G3*/{ eSquare_F2, eSquare_H2 },
		/*H3*/{ eSquare_G2 },

		/*A4*/{ eSquare_B3 },
		/*B4*/{ eSquare_A3, eSquare_C3 },
		/*C4*/{ eSquare_B3, eSquare_D3 },
		/*D4*/{ eSquare_C3, eSquare_E3 },
		/*E4*/{ eSquare_D3, eSquare_F3 },
		/*F4*/{ eSquare_E3, eSquare_G3 },
		/*G4*/{ eSquare_F3, eSquare_H3 },
		/*H4*/{ eSquare_G3 },

		/*A5*/{ eSquare_B4 },
		/*B5*/{ eSquare_A4, eSquare_C4 },
		/*C5*/{ eSquare_B4, eSquare_D4 },
		/*D5*/{ eSquare_C4, eSquare_E4 },
		/*E5*/{ eSquare_D4, eSquare_F4 },
		/*F5*/{ eSquare_E4, eSquare_G4 },
		/*G5*/{ eSquare_F4, eSquare_H4 },
		/*H5*/{ eSquare_G4 },

		/*A6*/{ eSquare_B5 },
		/*B6*/{ eSquare_A5, eSquare_C5 },
		/*C6*/{ eSquare_B5, eSquare_D5 },
		/*D6*/{ eSquare_C5, eSquare_E5 },
		/*E6*/{ eSquare_D5, eSquare_F5 },
		/*F6*/{ eSquare_E5, eSquare_G5 },
		/*G6*/{ eSquare_F5, eSquare_H5 },
		/*H6*/{ eSquare_G5 },

		/*A7*/{ eSquare_B6 },
		/*B7*/{ eSquare_A6, eSquare_C6 },
		/*C7*/{ eSquare_B6, eSquare_D6 },
		/*D7*/{ eSquare_C6, eSquare_E6 },
		/*E7*/{ eSquare_D6, eSquare_F6 },
		/*F7*/{ eSquare_E6, eSquare_G6 },
		/*G7*/{ eSquare_F6, eSquare_H6 },
		/*H7*/{ eSquare_G6 },

		/*A8*/{ },
		/*B8*/{ },
		/*C8*/{ },
		/*D8*/{ },
		/*E8*/{ },
		/*F8*/{ },
		/*G8*/{ },
		/*H8*/{ }
	};

	ASSERT(0 <= pieceSquare && pieceSquare < eSquare_NumSquares);
	const vector<SquareType>& lookupVec = lookupArr[pieceSquare];
	ASSERT(!lookupVec.empty());

	return isPieceOnSquares(lookupVec, ePiece_WhiteKing, board);
}

bool GameUtils::isKingAttackedByBlackKnight(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByKnight(pieceSquare, ePiece_WhiteKing, board);
}

bool GameUtils::isKingAttackedByBlackBishop(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByBishop(pieceSquare, ePiece_WhiteKing, board);
}

bool GameUtils::isKingAttackedByBlackRook(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByRook(pieceSquare, ePiece_WhiteKing, board);
}

bool GameUtils::isKingAttackedByBlackQueen(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByBlackBishop(pieceSquare, board) || isKingAttackedByBlackRook(pieceSquare, board);
}

bool GameUtils::isKingAttackedByBlackKing(SquareType pieceSquare, const PieceType(&board)[eSquare_NumSquares]) {
	return isKingAttackedByKing(pieceSquare, ePiece_WhiteKing, board);
}

///////////////////////////////////////////////////////////////////////////////
