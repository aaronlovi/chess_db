///////////////////////////////////////////////////////////////////////////////

#include "utils.h"
#include <cctype>
#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////////

/*static*/
bool StringUtils::tryGetNextInt(const char* (&p), int& n) {
	if (!p || !*p) {
		return false;
	}

	static const int STATE_START = 0;
	static const int STATE_FOUND_NEG = 1;
	static const int STATE_IN_NUMBERS = 2;
	static const int STATE_FINISHED = 256;

	int state = STATE_START;

	int sign = 1;
	int result = 0;
	const char* pStartNumbers = nullptr;
	const char* pEndNumbers = nullptr;

	for (const char* p1 = p; p1 && state != STATE_FINISHED; ++p1) {
		char c = *p1;
		switch (state) {
			case STATE_START:
			{
				if (c == '-') {
					sign = -1;
					state = STATE_FOUND_NEG;
				} else if ('0' <= c && c <= '9') {
					pStartNumbers = p1;
					result = c - '0';
					state = STATE_IN_NUMBERS;
				} else if (c == '\0') {
					return false;
				}

				break;
			}
			case STATE_FOUND_NEG:
			{
				if (c == '-') {
					// Do nothing
				} else if ('0' <= c && c <= '9') {
					pStartNumbers = p1;
					result = c - '0';
					state = STATE_IN_NUMBERS;
				} else if (c == '\0') {
					return false;
				} else {
					state = STATE_START;
				}

				break;
			}
			case STATE_IN_NUMBERS:
			{
				if ('0' <= c && c <= '9') {
					result *= 10;
					result += (c - '0');
					pEndNumbers = p1;
				} else if (c == '\0') {
					pEndNumbers = p1;
					state = STATE_FINISHED;
				} else {
					pEndNumbers = p1;
					state = STATE_FINISHED;
				}

				break;
			}
			default:
			{
				return false;
			}
		}
	}

	if (pStartNumbers != nullptr && pEndNumbers == nullptr) {
		return false;
	}

	if (pStartNumbers == nullptr) {
		return false;
	}

	if (sign == -1) {
		result *= sign;
	}

	p = pEndNumbers;
	n = result;
	return true;
}

/*static*/
void StringUtils::ltrim(string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

/*static*/
void StringUtils::rtrim(string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

/*static*/
void StringUtils::trim(string& s) {
	ltrim(s);
	rtrim(s);
}

/*static*/
string StringUtils::ltrimCopy(string s) {
	ltrim(s);
	return s;
}

/*static*/
string StringUtils::rtrimCopy(string s) {
	rtrim(s);
	return s;
}

/*static*/
string StringUtils::trimCopy(string s) {
	trim(s);
	return s;
}

/*static*/
bool StringUtils::startsWith(const string& s, char c) {
	string::size_type len = s.length();
	if (len == 0) {
		return false;
	}

	return c == s.at(0);
}

/*static*/
bool StringUtils::startsWith(const string& s, const string& prefix) {
	string::size_type lenStr = s.length();
	string::size_type lenPrefix = prefix.length();

	if (lenStr < lenPrefix) {
		return false;
	}

	for (string::size_type i = 0; i < lenPrefix; ++i) {
		if (s.at(i) != prefix.at(i)) {
			return false;
		}
	}

	return true;
}

/*static*/
bool StringUtils::endsWith(const string& s, char c) {
	string::size_type len = s.length();
	if (len == 0) {
		return false;
	}

	return s.at(len - 1) == c;
}

/*static*/
bool StringUtils::endsWith(const string& s, const string& suffix) {
	string::size_type lenStr = s.length();
	string::size_type lenSuffix = suffix.length();

	if (lenStr < lenSuffix) {
		return false;
	}

	for (string::size_type i = lenStr - 1, j = lenSuffix - 1; i >= 0 && j >= 0; --i, --j) {
		if (s.at(i) != suffix.at(j)) {
			return false;
		}
	}

	return true;
}

/*static*/
void StringUtils::chomp(string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return ch == '\n';
	}).base(), s.end());
}

/*static*/
void StringUtils::chomp(char* s) {
	char* p = s;

	if (p == nullptr) {
		return;
	}

	while (*p) {
		++p;
	}

	if (*p != '\0') {
		return;
	}

	do {
		--p;
		if (*p == '\n') {
			*p = '\0';
		} else {
			return;
		}
	} while (p != s);
}

///////////////////////////////////////////////////////////////////////////////

/*static*/
bool TimeUtils::isSameToTheDay(time_t t1, time_t t2) {
	tm* tFirst = localtime(&t1);
	tm* tSecond = localtime(&t2);

	if (tFirst == nullptr || tSecond == nullptr) {
		return false;
	}

	return tFirst->tm_year == tSecond->tm_year
		&& tFirst->tm_mon == tSecond->tm_mon
		&& tFirst->tm_mday == tSecond->tm_mday;
}

///////////////////////////////////////////////////////////////////////////////
