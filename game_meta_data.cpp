///////////////////////////////////////////////////////////////////////////////

#include "game_meta_data.h"
#include "game_utils.h"
#include "exceptions.h"
#include "utils.h"

///////////////////////////////////////////////////////////////////////////////

GameMetaData::GameMetaData() {
	clear();
}

void GameMetaData::clear() {
	event.clear();
	site.clear();
	gameDate.setNull();
	eventDate.setNull();
	round.clear();
	whitePlayerName.clear();
	blackPlayerName.clear();
	whiteElo = 0;
	blackElo = 0;
	result = eResult_None;
	ecoCode.clear();
}

void GameMetaData::updateKey(GameMetaDataKeyType keyType, const char* str) {
	UpdateKeyFn updateKeyFn = updateMetaDataKeyByKeyType(keyType);
	ASSERT(updateKeyFn != nullptr);

	(this->*updateKeyFn)(str);
}

void GameMetaData::updateEventKey(const char* str) {
	event = str;
}

void GameMetaData::updateSiteKey(const char* str) {
	site = str;
}

void GameMetaData::updateGameDateKey(const char* str) {
	gameDate.setNull();

	const char* p = str;
	int year = 0;
	int month = 0;
	int date = 0;

	bool res = StringUtils::tryGetNextInt(p, year);
	res = res && StringUtils::tryGetNextInt(p, month);
	res = res && StringUtils::tryGetNextInt(p, date);

	if (res) {
		gameDate.year_ = year;
		gameDate.month_ = month;
		gameDate.date_ = date;
	}
}

void GameMetaData::updateEventDateKey(const char* str) {
	eventDate.setNull();

	const char* p = str;
	int year = 0;
	int month = 0;
	int date = 0;

	bool res = StringUtils::tryGetNextInt(p, year);
	res = res && StringUtils::tryGetNextInt(p, month);
	res = res && StringUtils::tryGetNextInt(p, date);

	if (res) {
		eventDate.year_ = year;
		eventDate.month_ = month;
		eventDate.date_ = date;
	}
}

void GameMetaData::updateRoundKey(const char* str) {
	round = str;
}

void GameMetaData::updateWhitePlayerNameKey(const char* str) {
	whitePlayerName = str;
}

void GameMetaData::updateBlackPlayerNameKey(const char* str) {
	blackPlayerName = str;
}

void GameMetaData::updateWhiteEloKey(const char* str) {
	int elo = 0;
	const char* p = str;
	bool res = StringUtils::tryGetNextInt(p, elo);

	if (res) {
		whiteElo = elo;
	}
}

void GameMetaData::updateBlackEloKey(const char* str) {
	int elo = 0;
	const char* p = str;
	bool res = StringUtils::tryGetNextInt(p, elo);

	if (res) {
		blackElo = elo;
	}
}

void GameMetaData::updateResultKey(const char* str) {
	if (strncmp(str, GAME_RESULT_WHITE_WON, MAX_GAME_RESULT_LEN) == 0) {
		result = eResult_WhiteWon;
	} else if (strncmp(str, GAME_RESULT_BLACK_WON, MAX_GAME_RESULT_LEN) == 0) {
		result = eResult_BlackWon;
	} else if (strncmp(str, GAME_RESULT_DRAW, MAX_GAME_RESULT_LEN) == 0) {
		result = eResult_Draw;
	} else if (strncmp(str, GAME_RESULT_OTHER, MAX_GAME_RESULT_LEN) == 0) {
		result = eResult_Other;
	} else {
		result = eResult_None;
	}

}

void GameMetaData::updateEcoCodeKey(const char* str) {
	ecoCode = str;
}

///////////////////////////////////////////////////////////////////////////////
