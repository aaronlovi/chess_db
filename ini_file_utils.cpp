#include "ini_file_utils.h"
#include "ini_file.h"
#include "compacted_position.h"
#include "compact_position_builder.h"
#include "logger.h"
#include "utils.h"
#include "exceptions.h"
#include "game_utils.h"

///////////////////////////////////////////////////////////////////////////////

static const char* POSITION_SECTION_NAME = "POSITIONS";
static const char* POSITION_SECTION_POSITION_ITEM_NAME = "position";

static const char* POS_SECTION_COLOR_TO_MOVE_ITEM_NAME = "color_to_move";
static const char* POS_SECTION_RANK_1_ITEM_NAME = "rank_1";
static const char* POS_SECTION_RANK_2_ITEM_NAME = "rank_2";
static const char* POS_SECTION_RANK_3_ITEM_NAME = "rank_3";
static const char* POS_SECTION_RANK_4_ITEM_NAME = "rank_4";
static const char* POS_SECTION_RANK_5_ITEM_NAME = "rank_5";
static const char* POS_SECTION_RANK_6_ITEM_NAME = "rank_6";
static const char* POS_SECTION_RANK_7_ITEM_NAME = "rank_7";
static const char* POS_SECTION_RANK_8_ITEM_NAME = "rank_8";
static const char* POS_SECTION_50_MOVE_RULE_NUM_HALF_MOVES_ITEM_NAME = "50_move_rule_num_half_moves";
static const char* POS_SECTION_EN_PASSANT_FILE_ITEM_NAME = "en_passant_file";
static const char* POS_SECTION_CAN_WHITE_CASTLE_QSIDE_ITEM_NAME = "can_white_castle_qside";
static const char* POS_SECTION_CAN_WHITE_CASTLE_KSIDE_ITEM_NAME = "can_white_castle_kside";
static const char* POS_SECTION_CAN_BLACK_CASTLE_QSIDE_ITEM_NAME = "can_black_castle_qside";
static const char* POS_SECTION_CAN_BLACK_CASTLE_KSIDE_ITEM_NAME = "can_black_castle_kside";

static const char* const POS_SECTION_RANKS_ARR[] = {
	POS_SECTION_RANK_1_ITEM_NAME
	, POS_SECTION_RANK_2_ITEM_NAME
	, POS_SECTION_RANK_3_ITEM_NAME
	, POS_SECTION_RANK_4_ITEM_NAME
	, POS_SECTION_RANK_5_ITEM_NAME
	, POS_SECTION_RANK_6_ITEM_NAME
	, POS_SECTION_RANK_7_ITEM_NAME
	, POS_SECTION_RANK_8_ITEM_NAME
};

///////////////////////////////////////////////////////////////////////////////

static void getPositionFromIniSection(const IniFileSection& section, vector<CompactedPosition>& compactPosVec) {
	CompactPositionBuilder builder;
	
	int colorToMove = section.getIntVal(POS_SECTION_COLOR_TO_MOVE_ITEM_NAME, eColor_White);
	builder.appendColorToMove(colorToMove);

	for (const auto& POS_SECTION_RANK_NAME : POS_SECTION_RANKS_ARR) {
		string val = section.getItem(POS_SECTION_RANK_NAME, "");
		StringUtils::trim(val);
		ASSERT(val.length() == eFile_NumFiles);

		for (const char& c : val) {
			PieceType piece = GameUtils::iniFileCharToPiece(c);
			builder.appendPiece(piece);
		}
	}

	int fiftyMoveRuleNumHalfMoves = section.getIntVal(POS_SECTION_50_MOVE_RULE_NUM_HALF_MOVES_ITEM_NAME, 0);
	builder.append50MoveRuleNumHalfMoves(fiftyMoveRuleNumHalfMoves);

	int enPassantFile_ = section.getIntVal(POS_SECTION_EN_PASSANT_FILE_ITEM_NAME, eFile_None);
	FileType enPassantFile = static_cast<FileType>(enPassantFile_);
	builder.appendEnPassantFile(enPassantFile);

	bool canWhiteCastleQSide = section.getIntVal(POS_SECTION_CAN_WHITE_CASTLE_QSIDE_ITEM_NAME, 0) == 1 ? true : false;
	bool canWhiteCastleKSide = section.getIntVal(POS_SECTION_CAN_WHITE_CASTLE_KSIDE_ITEM_NAME, 0) == 1 ? true : false;
	bool canBlackCastleQSide = section.getIntVal(POS_SECTION_CAN_BLACK_CASTLE_QSIDE_ITEM_NAME, 0) == 1 ? true : false;
	bool canBlackCastleKSide = section.getIntVal(POS_SECTION_CAN_BLACK_CASTLE_KSIDE_ITEM_NAME, 0) == 1 ? true : false;

	builder.appendCastlingOptions(canWhiteCastleQSide, canWhiteCastleKSide, canBlackCastleQSide, canBlackCastleKSide);

	compactPosVec.emplace_back(builder);
}

///////////////////////////////////////////////////////////////////////////////

void getPositionsFromIniFile(const IniFile& iniFile, vector<CompactedPosition>& compactPosVec) {
	// CompactPositionBuilder builder;
	const IniFileSection* pSection = iniFile.getSection(POSITION_SECTION_NAME);
	
	if (!pSection) {
		log("Warning - " __FUNCTION__ " - [%s] section missing", POSITION_SECTION_NAME);
		return;
	}

	const IniFileSection& section = *pSection;
	for (const IniFileItem& item : section.itemVec) {
		const string& itemName = item.itemName;
		const string& itemVal = item.itemVal;
		
		string itemName_ = itemName;
		StringUtils::tolower(itemName, itemName_);

		if (itemName_.compare(POSITION_SECTION_POSITION_ITEM_NAME) != 0) {
			continue;
		}

		const IniFileSection* pPositionSection = iniFile.getSection(itemVal.c_str());

		if (!pPositionSection) {
			log("Warning - " __FUNCTION__ " - [%s] section missing", itemVal.c_str());
			return;
		}

		const IniFileSection& positionSection = *pPositionSection;
		getPositionFromIniSection(positionSection, compactPosVec);
	}
}

///////////////////////////////////////////////////////////////////////////////
