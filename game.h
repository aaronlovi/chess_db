#ifndef GAME_H
#define GAME_H

///////////////////////////////////////////////////////////////////////////////

#include "game_meta_data.h"
#include "move.h"
#include "compacted_position.h"

///////////////////////////////////////////////////////////////////////////////

struct Game
{
	GameMetaData metaData;
	vector<unique_ptr<Move>> moveVec;
	vector<unique_ptr<CompactedPosition>> compactedPositionVec;

	void clear();
};

///////////////////////////////////////////////////////////////////////////////

#endif // GAME_H
