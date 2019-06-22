///////////////////////////////////////////////////////////////////////////////

#include "logger.h"
#include "exceptions.h"
#include "ini_file.h"
#include "file_wrapper.h"
#include "game_parser.h"
#include "function_timer.h"
#include "compact_position_builder.h"
#include "ini_file_utils.h"

///////////////////////////////////////////////////////////////////////////////
// GLOBALS

static IniFile settings;
static IniFile positionsFile;

///////////////////////////////////////////////////////////////////////////////
// STATICS

static void initLogger(const char* logFilePrefix) {
	Logger::init();
	Logger::behaviour = eLogBehaviour_Default;
	Logger::fileNamePrefix = logFilePrefix;

	log("Logger initialized");
}

static void checkCommandLine(int argc) {
	log("checkCommandLine(argc: %d)", argc);

	if (argc < 3) {
		throw Exception("Format: chess_db settings.ini positions.ini");
	}
}

static void readSettingsFile(const char* iniFilePath) {
	log("readSettingsFile(iniFilePath: %s)", iniFilePath);

	FileWrapper configFile;
	configFile.file = fopen(iniFilePath, "r");

	if (configFile.file == nullptr) {
		throw Exception("Settings file inaccessible, aborting");
	}

	log("Opened settings file");

	readSettingsFromFile(configFile, settings);
}

static void readPositionsFile(const char* iniFilePath) {
	log("readPositionsFile(iniFilePath: %s)", iniFilePath);

	FileWrapper configFile;
	configFile.file = fopen(iniFilePath, "r");

	if (configFile.file == nullptr) {
		throw Exception("Positions file inaccessible, aborting");
	}

	log("Opened positions file");

	readSettingsFromFile(configFile, positionsFile);
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
	int retVal = 0;

	try {
		initLogger(DEFAULT_LOG_FILE_PREFIX);

		checkCommandLine(argc);
		readSettingsFile(argv[1]);
		readPositionsFile(argv[2]);

		const char* dbFile = settings.getItem("settings", "db_file", "");
		FileWrapper dbFileWrapper;
		dbFileWrapper.file = fopen(dbFile, "r");
		ASSERT(dbFileWrapper.file);

		GameParser gameParser(dbFileWrapper);
		gameParser.parse();

		vector<CompactedPosition> posVec;
		getPositionsFromIniFile(positionsFile, posVec);

		vector<unique_ptr<CompactedPositionInfo>>& libraryPosVec = gameParser.compactedPositionInfoVec;
		auto libraryBegin = libraryPosVec.begin();
		auto libraryEnd = libraryPosVec.end();
		for (const CompactedPosition& pos : posVec) {

			CompactedPositionInfo info(pos);
			auto it = lower_bound(libraryBegin, libraryEnd, info, [](const unique_ptr<CompactedPositionInfo> & libraryPos, const CompactedPositionInfo & posInfo) {
				return *libraryPos < posInfo;
			});

			if (it == libraryEnd) {
				log("Warning - failed to find position");
				continue;
			}

			const unique_ptr<CompactedPositionInfo>& libraryInfoPtr = *it;
			const CompactedPositionInfo& libraryInfo = *libraryInfoPtr;
			const vector<int>& gameIndices = libraryInfo.gameIndices;

			int numWhiteWin = 0;
			int numBlackWin = 0;
			int numDraw = 0;
			int numOtherResult = 0;

			for (int gameIndex : gameIndices) {
				const unique_ptr<Game>& gamePtr = gameParser.gameVec[gameIndex];
				const Game& game = *gamePtr;
				const GameMetaData& metaData = game.metaData;
				ResultType result = static_cast<ResultType>(metaData.result);
				switch (result) {
					case eResult_WhiteWon: ++numWhiteWin; break;
					case eResult_BlackWon: ++numBlackWin; break;
					case eResult_Draw: ++numDraw; break;
					case eResult_Other: ++numOtherResult; break;
					default:
					{
						log("Warning - invalid result found (gameIndex: %d, result: %d)", gameIndex, result);
						break;
					}
				}
			}

			int numTotalGames = gameIndices.size();

			double numWhiteWin_ = numWhiteWin;
			double numBlackWin_ = numBlackWin;
			double numDraw_ = numDraw;
			double numOtherResult_ = numOtherResult;
			double numTotalGames_ = numTotalGames;

			double whiteWinPct = 0;
			double blackWinPct = 0;
			double drawPct = 0;
			double otherResultPct = 0;

			if (numTotalGames_ != 0) {
				whiteWinPct = 100.0 * numWhiteWin_ / numTotalGames_;
				blackWinPct = 100.0 * numBlackWin_ / numTotalGames_;
				drawPct = 100.0 * numDraw_ / numTotalGames_;
				otherResultPct = 100.0 * numOtherResult_ / numTotalGames_;
			}

			log("=====================================================================");
			log("+%d/=%d/-%d/*%d -- (+%g/=%g/-%g/*%g)",
				numWhiteWin, numDraw, numBlackWin, numOtherResult,
				whiteWinPct, drawPct, blackWinPct, otherResultPct
			);
			log("=====================================================================");
		}

		log("done");

		FunctionTimerBoard::log();
	} catch (const Exception & ex) {
		log("Error: %s", ex.getMessage());
		retVal = 1;
	} catch (...) {
		log("Error: unknown error type");
		retVal = 2;
	}

	return retVal;
}

///////////////////////////////////////////////////////////////////////////////
