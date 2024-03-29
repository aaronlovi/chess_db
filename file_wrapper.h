#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include "include_base.h"

///////////////////////////////////////////////////////////////////////////////

struct FileWrapper
{
	FILE* file;

	FileWrapper();
	virtual ~FileWrapper();
};

///////////////////////////////////////////////////////////////////////////////

void readLines(FileWrapper& fileWrapper, vector<string>& lines);

///////////////////////////////////////////////////////////////////////////////

#endif // FILE_WRAPPER_H
