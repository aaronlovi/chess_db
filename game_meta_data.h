#ifndef GAME_META_DATA_H
#define GAME_META_DATA_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"
#include "date.h"
#include "constants.h"

///////////////////////////////////////////////////////////////////////////////

struct GameMetaData
{
	string event;
	string site;
	Date gameDate;
	Date eventDate;
	string round; // Example "7" or "15.38"
	string whitePlayerName;
	string blackPlayerName;
	INT32 whiteElo;
	INT32 blackElo;
	INT8 result;
	string ecoCode; // Example "A30"

	GameMetaData();

	void clear();
	void updateKey(GameMetaDataKeyType keyType, const char* str);

	void updateEventKey(const char* str);
	void updateSiteKey(const char* str);
	void updateGameDateKey(const char* str);
	void updateEventDateKey(const char* str);
	void updateRoundKey(const char* str);
	void updateWhitePlayerNameKey(const char* str);
	void updateBlackPlayerNameKey(const char* str);
	void updateWhiteEloKey(const char* str);
	void updateBlackEloKey(const char* str);
	void updateResultKey(const char* str);
	void updateEcoCodeKey(const char* str);

	typedef void(GameMetaData::*UpdateKeyFn)(const char* str);
};

///////////////////////////////////////////////////////////////////////////////

#endif // GAME_META_DATA_H
