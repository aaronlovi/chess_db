///////////////////////////////////////////////////////////////////////////////

#include "logger.h"
#include "utils.h"
#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////////

/*static*/ LogBehaviourType Logger::behaviour = eLogBehaviour_None;
/*static*/ string Logger::fileNamePrefix;
/*static*/ string Logger::prevFullFileName;
/*static*/ time_t Logger::lastConsoleWriteEvent = (time_t) -1;
/*static*/ time_t Logger::lastFileWriteEvent = (time_t) -1;
/*static*/ FileWrapper Logger::logFile;

/*static*/
void Logger::init()
{
	Logger::logFile.~FileWrapper();

	behaviour = eLogBehaviour_None;
	fileNamePrefix = "Default.log";
	lastConsoleWriteEvent = (time_t) -1;
	lastFileWriteEvent = (time_t) -1;
}

/*static*/
void Logger::log(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	log(format, args);
	va_end(args);
}

/*static*/
void Logger::log(const char* format, va_list args)
{
	if (behaviour & eLogBehaviour_ToConsole)
	{
		logToConsole(format, args);
	}

	if (behaviour & eLogBehaviour_ToFile)
	{
		logToFile(format, args);
	}
}

/*static*/ 
void Logger::logToConsole(const char* format, va_list args)
{
	time_t rawNow = time(nullptr);

	if (rawNow != lastConsoleWriteEvent)
	{
		lastConsoleWriteEvent = rawNow;

		tm* now = localtime(&rawNow);
		printf("[%4d/%02d/%02d %02d:%02d:%02d]\n",
			now->tm_year + 1900, now->tm_mon + 1, now->tm_mday,
			now->tm_hour, now->tm_min, now->tm_sec);
	}

	vprintf(format, args);
	printf("\n");
}

/*static*/ 
void Logger::logToFile(const char* format, va_list args)
{
	time_t rawNow = time(nullptr);

	if (!TimeUtils::isSameToTheDay(lastFileWriteEvent, rawNow) || logFile.file == nullptr)
	{
		auto padLeftFn = [](int numToPad, ostringstream& os) {
			if (numToPad < 10) {
				os << '0';
			}
		};

		tm* now = localtime(&rawNow);
		ostringstream os;
		os << fileNamePrefix;
		os << ".log.";
		os << (now->tm_year + 1900);
		padLeftFn(now->tm_mon + 1, os);
		os << now->tm_mon + 1;
		padLeftFn(now->tm_mday, os);
		os << now->tm_mday;

		string fullFileName = os.str();
		logFile.file = fopen(fullFileName.c_str(), "a");
	}

	if (lastFileWriteEvent != rawNow)
	{
		lastFileWriteEvent = rawNow;

		tm* now = localtime(&rawNow);

		ASSERT(logFile.file != nullptr);
		fprintf(logFile.file, "[%4d/%02d/%02d %02d:%02d:%02d]\n",
			now->tm_year + 1900, now->tm_mon + 1, now->tm_mday,
			now->tm_hour, now->tm_min, now->tm_sec);
	}

	ASSERT(logFile.file != nullptr);
	vfprintf(logFile.file, format, args);
	fprintf(logFile.file, "\n");
}

///////////////////////////////////////////////////////////////////////////////

void log(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	Logger::log(format, args);
	va_end(args);
}

void log(const char* format, va_list args)
{
	Logger::log(format, args);
}

///////////////////////////////////////////////////////////////////////////////
