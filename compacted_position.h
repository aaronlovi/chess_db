#ifndef COMPACTED_POSITION_H
#define COMPACTED_POSITION_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"

struct CompactPositionBuilder;

///////////////////////////////////////////////////////////////////////////////

// https://en.wikipedia.org/wiki/Board_representation_(chess)
// Max 204 bits (i.e. 26 bytes or 4-INT64s)
//
// Board Representation
// ================================
// Empty square = 0
// Pawn = 10c
// Bishop = 1100c
// Knight = 1101c
// Rook = 1110c
// Queen = 11110c
// King = 11111c
// Where c is a bit representing the color of the piece (1 = WHITE, 0 = BLACK).
//
// Trailing empty squares are omitted, i.e. After a trailing sequence of "00", parser can go on to "Additional Bits".
//
// Additional Bits
// ================================
// 50-move rule (7 bits): Always used. Number of half-moves in the past that a pawn move or piece exchange occurred. Max val is 100.
// En-passant column (3 bits): One of files a-h. Only used if any pawn for the opposite side is on the 4th rank.
// Color to move(1 bit): Always used
// Castling options (4 bits): 
//		b1 - White can still castle Q-side. Only used if White K and QR on apparently original squares
//		b2 - White can still castle K-side. Only used if White K and KR on apparently original squares
//		b3 - Black can still castle Q-side. Only used if Black K and QR on apparently original squares
//		b4 - Black can still castle K-side. Only used if Black K and KR on apparently original squares

struct CompactedPosition {
	INT64 B1;
	INT64 B2;
	INT64 B3;
	INT64 B4;

	CompactedPosition();
	CompactedPosition(const CompactPositionBuilder& builder);
};

bool operator< (const CompactedPosition& pos1, const CompactedPosition& pos2);
bool operator== (const CompactedPosition& pos1, const CompactedPosition& pos2);

///////////////////////////////////////////////////////////////////////////////

struct CompactedPositionInfo {
	INT64 B1;
	INT64 B2;
	INT64 B3;
	INT64 B4;
	vector<int> gameIndices;

	CompactedPositionInfo();
	CompactedPositionInfo(const CompactedPosition& compactPos_);
};

bool operator< (const CompactedPositionInfo& pos1, const CompactedPositionInfo& pos2);
bool operator== (const CompactedPositionInfo& pos1, const CompactedPositionInfo& pos2);

///////////////////////////////////////////////////////////////////////////////

#endif // COMPACTED_POSITION_H
