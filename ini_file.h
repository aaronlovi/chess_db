#ifndef INI_FILE_H
#define INI_FILE_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"

struct FileWrapper;

///////////////////////////////////////////////////////////////////////////////

struct IniFileItem
{
	string itemName;
	string itemVal;

	IniFileItem(const string& name, const string& val)
		: itemName(name), itemVal(val)
	{ }
};

///////////////////////////////////////////////////////////////////////////////

struct IniFileSection
{
	string sectionName;
	vector<IniFileItem> itemVec;

	IniFileSection(const string& name)
		: sectionName(name)
	{ }

	void addItem(const string& name, const string& val);
	const char* getItem(const char* itemName, const char* defaultVal) const;
	int getIntVal(const char* itemName, int defaultVal) const;
};

///////////////////////////////////////////////////////////////////////////////

struct IniFile
{
	vector<IniFileSection> sectionVec;

	void addSection(const string& name);
	void addItem(const string& name, const string& val);
	IniFileSection* getSection(const char* name);
	const IniFileSection* getSection(const char* name) const;
	const char* getItem(const char* sectionName, const char* itemName, const char* defaultVal);
};

///////////////////////////////////////////////////////////////////////////////

void readSettingsFromFile(FileWrapper& fileWrapper, IniFile& settings);
void readSettingsFromLines(vector<string>& lines, IniFile& settings);

///////////////////////////////////////////////////////////////////////////////

#endif // INI_FILE_H
