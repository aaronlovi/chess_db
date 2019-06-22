#ifndef INCLUDE_BASE_H
#define INCLUDE_BASE_H

#include <algorithm>
#include <cstdint>
#include <cstdarg>
#include <ctime>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef int_least8_t INT8;
typedef int_least16_t INT16;
typedef int_least32_t INT32;
typedef int_least64_t INT64;
typedef uint_least8_t BYTE;
typedef uint_least16_t UINT16;
typedef uint_least32_t UINT32;
typedef uint_least64_t UINT64;

#define BYTE_MAX (UINT_LEAST8_MAX)

#define ONE64 ((INT64)1)

template<class T, size_t N>
size_t SZARR(T(&)[N])
{
	return N;
}

#endif // INCLUDE_BASE_H
