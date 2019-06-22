///////////////////////////////////////////////////////////////////////////////

#include "file_wrapper.h"
#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////////

FileWrapper::FileWrapper()
	: file(nullptr) {

}

FileWrapper::~FileWrapper() {
	if (file != nullptr) {
		fclose(file);
		file = nullptr;
	}
}

///////////////////////////////////////////////////////////////////////////////

void readLines(FileWrapper& fileWrapper, vector<string>& lines) {
	static const int BUF_LEN = 1024;

	FILE* pFile = fileWrapper.file;
	ASSERT(pFile);

	char buf[BUF_LEN];

	while (!feof(pFile)) {
		char* pBuf = fgets(buf, BUF_LEN, pFile);

		if (pBuf == nullptr && ferror(pFile)) {
			throw Exception("Error: readIniFile - error reading from ini file");
		} else if (pBuf == nullptr) {
			break;
		} else {
		
			for (char& c : buf) {
				
				if (c == '\n') {
					c = '\0';
					break;
				}

			}

			lines.push_back(buf);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
