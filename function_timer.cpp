///////////////////////////////////////////////////////////////////////////////

#include "function_timer.h"
#include "logger.h"
#include <Windows.h>

///////////////////////////////////////////////////////////////////////////////

/*static*/
vector<FunctionTimeResult> FunctionTimerBoard::functionTimesVec;

///////////////////////////////////////////////////////////////////////////////

FunctionTimeResult::FunctionTimeResult(const char* name_, INT64 totalMS_, long numFnCalls_)
	: name(name_), totalMS(totalMS_), numFnCalls(numFnCalls_) {

}

///////////////////////////////////////////////////////////////////////////////

/* static */
void FunctionTimerBoard::appendTime(const string& name, const INT64 numMS) {
	auto begin = FunctionTimerBoard::functionTimesVec.begin();
	auto end = FunctionTimerBoard::functionTimesVec.end();
	auto it = find_if(begin, end, [&name](const FunctionTimeResult & res) {
		return name.compare(res.name) == 0;
	});

	if (it == end) {
		FunctionTimerBoard::functionTimesVec.emplace_back(name.c_str(), numMS, 1);
	} else {
		FunctionTimeResult& result = *it;
		++result.numFnCalls;
		result.totalMS += numMS;
	}
}

/* static */
void FunctionTimerBoard::log() {
	::log(__FUNCTION__);

	for (const FunctionTimeResult& res : FunctionTimerBoard::functionTimesVec) {

		if (res.numFnCalls != 0) {
			double totalMS_ = res.totalMS;
			double numCalls_ = res.numFnCalls;
			double timePerCall = totalMS_ / numCalls_;

			::log("time(name: %s, numMS: %lld, numCalls: %ld, timePerCall: %f",
				res.name.c_str(), res.totalMS, res.numFnCalls, timePerCall);
		} else {
			::log("time(name: %s, numMS: %lld, numCalls: %ld, timePerCall: ???",
				res.name.c_str(), res.totalMS, res.numFnCalls);
		}
	}

	::log("#" __FUNCTION__);
}

///////////////////////////////////////////////////////////////////////////////

FunctionTimer::FunctionTimer(const char* name_)
	: name(name_)
	, numMS()
	, t0()
	, t1() {
	t0 = high_resolution_clock::now();
}

FunctionTimer::~FunctionTimer() {
	try {
		t1 = high_resolution_clock::now();
		numMS = duration_cast<milliseconds>(t1 - t0);
		FunctionTimerBoard::appendTime(name, numMS.count());
	} catch (...) {

	}
}

///////////////////////////////////////////////////////////////////////////////
