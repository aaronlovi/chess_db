#ifndef STRING_UTILS_H
#define STRING_UTILS_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"
#include "constants.h"
#include <locale>

///////////////////////////////////////////////////////////////////////////////

struct StringUtils {
	static bool tryGetNextInt(const char* (&p), int& n);

	static void ltrim(string& s);
	static void rtrim(string& s);
	static void trim(string& s);
	static string ltrimCopy(string s);
	static string rtrimCopy(string s);
	static string trimCopy(string s);

	static bool startsWith(const string& s, char c);
	static bool startsWith(const string& s, const string& prefix);
	static bool endsWith(const string& s, char c);
	static bool endsWith(const string& s, const string& suffix);

	static void chomp(string& s);
	static void chomp(char* s);

	template<class Pred>
	static void transformString(const string& sIn, string& sOut, Pred predFn) {
		std::transform(sIn.begin(), sIn.end(), sOut.begin(), predFn);
	}
	static void tolower(const string& sIn, string& sOut) {
		transformString(sIn, sOut, ::tolower);
	}
	static void toupper(const string& sIn, string& sOut) {
		transformString(sIn, sOut, ::toupper);
	}

};

///////////////////////////////////////////////////////////////////////////////

struct TimeUtils {
	static bool isSameToTheDay(time_t t1, time_t t2);
};

///////////////////////////////////////////////////////////////////////////////

#endif // STRING_UTILS_H
