///////////////////////////////////////////////////////////////////////////////

#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////////

Exception::Exception(const char* format, ...)
{
	static const int BUF_LEN = 2048;
	static char buf[2048];

	va_list args;
	va_start(args, format);
	vsnprintf_s(buf, BUF_LEN, format, args);
	va_end(args);
	what = buf;
}

Exception::Exception(const char* format, va_list args)
{
	static const int BUF_LEN = 2048;
	static char buf[2048];

	vsnprintf_s(buf, BUF_LEN, format, args);
	what = buf;
}

///////////////////////////////////////////////////////////////////////////////
