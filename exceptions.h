#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"

///////////////////////////////////////////////////////////////////////////////

struct Exception
{
	Exception(const char* format, ...);
	Exception(const char* format, va_list args);

	const char* getMessage() const
	{
		return what.c_str();
	}

	string what;
};

///////////////////////////////////////////////////////////////////////////////

#define ASSERT(COND) \
if (!(COND)) \
{ \
	throw Exception(#COND " in " __FILE__ ": %d", __LINE__); \
}

///////////////////////////////////////////////////////////////////////////////

#endif // EXCEPTIONS_H
