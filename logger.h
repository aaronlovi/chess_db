#ifndef LOGGER_H
#define LOGGER_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"
#include "file_wrapper.h"

///////////////////////////////////////////////////////////////////////////////

enum LogBehaviourType : INT8
{
	eLogBehaviour_None = 0,
	eLogBehaviour_ToConsole = 1,
	eLogBehaviour_ToFile = 2,

	eLogBehaviour_Default = eLogBehaviour_ToConsole | eLogBehaviour_ToFile
};

struct Logger
{
	static LogBehaviourType behaviour;
	static string fileNamePrefix;
	static string prevFullFileName;
	static time_t lastConsoleWriteEvent;
	static time_t lastFileWriteEvent;
	static FileWrapper logFile;

	static void init();
	static void log(const char* format, ...);
	static void log(const char* format, va_list args);

private:
	static void logToConsole(const char* format, va_list args);
	static void logToFile(const char* format, va_list args);
};

void log(const char* format, ...);
void log(const char* format, va_list args);

///////////////////////////////////////////////////////////////////////////////

#endif // LOGGER_H
