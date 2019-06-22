///////////////////////////////////////////////////////////////////////////////

#include "compacted_position.h"
#include "logger.h"
#include "compact_position_builder.h"
#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////////

CompactedPosition::CompactedPosition()
	: B1(0)
	, B2(0)
	, B3(0)
	, B4(0) {

}

CompactedPosition::CompactedPosition(const CompactPositionBuilder& builder) 
	: B1(0)
	, B2(0)
	, B3(0)
	, B4(0) {

	int bitNum = 0;
	int wordNum = 0;
	INT64* curWord = &(B1);

	for (const auto& val : builder.bits) {

		if (val) {
			*curWord |= (ONE64 << bitNum);
		}

		++bitNum;

		if (bitNum == 64) {
			bitNum = 0;
			++wordNum;

			switch (wordNum) {
				case 1: curWord = &(B2); break;
				case 2: curWord = &(B3); break;
				case 3: curWord = &(B4); break;
				default: ASSERT(0);
			}
		}
	}

}

bool operator< (const CompactedPosition& pos1, const CompactedPosition& pos2) {
	if (pos1.B1 < pos2.B1) {
		return true;
	} else if (pos1.B1 > pos2.B1) {
		return false;
	}

	// B1 are equal

	if (pos1.B2 < pos2.B2) {
		return true;
	} else if (pos1.B2 > pos2.B2) {
		return false;
	}

	// B2 are equal

	if (pos1.B3 < pos2.B3) {
		return true;
	} else if (pos1.B3 > pos2.B3) {
		return false;
	}

	// B3 are equal

	if (pos1.B4 < pos2.B4) {
		return true;
	} else if (pos1.B4 > pos2.B4) {
		return false;
	}

	// B4 are equal

	// All fields are equal

	return false;
}

bool operator== (const CompactedPosition& pos1, const CompactedPosition& pos2) {
	return pos1.B1 == pos2.B1
		&& pos1.B2 == pos2.B2
		&& pos1.B3 == pos2.B3
		&& pos1.B4 == pos2.B4;
}

///////////////////////////////////////////////////////////////////////////////

CompactedPositionInfo::CompactedPositionInfo() 
	: B1(0), B2(0), B3(0), B4(0) {

}

CompactedPositionInfo::CompactedPositionInfo(const CompactedPosition& compactPos_)
	: B1(compactPos_.B1), B2(compactPos_.B2), B3(compactPos_.B3), B4(compactPos_.B4) {

}

bool operator< (const CompactedPositionInfo& pos1, const CompactedPositionInfo& pos2) {
	if (pos1.B1 < pos2.B1) {
		return true;
	} else if (pos1.B1 > pos2.B1) {
		return false;
	}

	// B1 are equal

	if (pos1.B2 < pos2.B2) {
		return true;
	} else if (pos1.B2 > pos2.B2) {
		return false;
	}

	// B2 are equal

	if (pos1.B3 < pos2.B3) {
		return true;
	} else if (pos1.B3 > pos2.B3) {
		return false;
	}

	// B3 are equal

	if (pos1.B4 < pos2.B4) {
		return true;
	} else if (pos1.B4 > pos2.B4) {
		return false;
	}

	// B4 are equal

	// All fields are equal

	return false;
}

bool operator== (const CompactedPositionInfo& pos1, const CompactedPositionInfo& pos2) {
	return pos1.B1 == pos2.B1
		&& pos1.B2 == pos2.B2
		&& pos1.B3 == pos2.B3
		&& pos1.B4 == pos2.B4;
}

///////////////////////////////////////////////////////////////////////////////
