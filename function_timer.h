#ifndef FUNCTION_TIMER_H
#define FUNCTION_TIMER_H

#include <chrono>
#include "include_base.h"

using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////////

struct FunctionTimeResult {
	string name;
	INT64 totalMS;
	long numFnCalls;

	FunctionTimeResult() : totalMS(0), numFnCalls(0) { }
	FunctionTimeResult(const char* name_, INT64 totalMS_, long numFnCalls_);
};

///////////////////////////////////////////////////////////////////////////////

struct FunctionTimerBoard {
	static vector<FunctionTimeResult> functionTimesVec;

	static void appendTime(const string& name, const INT64 numMS);
	static void log();
};

///////////////////////////////////////////////////////////////////////////////

struct FunctionTimer {
	string name;
	milliseconds numMS;
	high_resolution_clock::time_point t0;
	high_resolution_clock::time_point t1;

	FunctionTimer(const char* name_);
	virtual ~FunctionTimer();
};

///////////////////////////////////////////////////////////////////////////////

#endif // FUNCTION_TIMER_H
