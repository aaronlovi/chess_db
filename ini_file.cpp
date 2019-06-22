///////////////////////////////////////////////////////////////////////////////

#include "ini_file.h"
#include "file_wrapper.h"
#include "exceptions.h"
#include "utils.h"

///////////////////////////////////////////////////////////////////////////////

void IniFileSection::addItem(const string& name, const string& val) {
	itemVec.emplace_back(name, val);
}

const char* IniFileSection::getItem(const char* itemName, const char* defaultVal) const {
	const auto it = find_if(itemVec.begin(), itemVec.end(), [&itemName](const IniFileItem& item) {
		return item.itemName.compare(itemName) == 0;
	});

	if (it == itemVec.end()) {
		return defaultVal;
	} else {
		const IniFileItem& item = *it;
		return item.itemVal.c_str();
	}
}

int IniFileSection::getIntVal(const char* itemName, int defaultVal) const {
	const char* val = getItem(itemName, "");
	if (!val || !*val) {
		return defaultVal;
	}

	int n = defaultVal;
	bool res = StringUtils::tryGetNextInt(val, n);
	if (res) {
		return n;
	} else {
		return defaultVal;
	}
}

///////////////////////////////////////////////////////////////////////////////

void IniFile::addSection(const string& name) {
	sectionVec.emplace_back(name);
}

void IniFile::addItem(const string& name, const string& val) {
	ASSERT(!sectionVec.empty());

	IniFileSection& section = sectionVec.back();
	section.addItem(name, val);
}

IniFileSection* IniFile::getSection(const char* name) {
	return const_cast<IniFileSection*>(static_cast<const IniFile&>(*this).getSection(name));
}

const IniFileSection* IniFile::getSection(const char* name) const {
	auto it = find_if(sectionVec.begin(), sectionVec.end(), [&name](const IniFileSection& section) {
		return section.sectionName.compare(name) == 0;
	});

	if (it == sectionVec.end()) {
		return nullptr;
	} else {
		const IniFileSection& section = *it;
		return &section;
	}
}

const char* IniFile::getItem(const char* sectionName, const char* itemName, const char* defaultVal) {
	IniFileSection* pSection = getSection(sectionName);
	if (pSection == nullptr) {
		throw Exception("IniFile::getItem(sectionName: %s, itemName: %s, defaultVal: %s) - section does not exist",
						sectionName, itemName, defaultVal);
	}

	return pSection->getItem(itemName, defaultVal);
}

///////////////////////////////////////////////////////////////////////////////

void readSettingsFromFile(FileWrapper& fileWrapper, IniFile& settings) {
	vector<string> lines;
	readLines(fileWrapper, lines);
	readSettingsFromLines(lines, settings);
}

void readSettingsFromLines(vector<string>& lines, IniFile& settings) {
	static const int STATE_START = 0;
	static const int STATE_IN_SECTION = 1;

	int state = STATE_START;

	for (const string& line : lines) {
		string s = StringUtils::trimCopy(line);

		switch (state) {
			case STATE_START:
			{
				if (StringUtils::startsWith(s, '[') && StringUtils::endsWith(s, ']')) {
					string sectionName = s.substr(1, s.length() - 2);
					StringUtils::trim(sectionName);
					settings.addSection(sectionName);

					state = STATE_IN_SECTION;
				}
				break;
			}
			case STATE_IN_SECTION:
			{
				if (StringUtils::startsWith(s, '[') && StringUtils::endsWith(s, ']')) {
					string sectionName = s.substr(1, s.length() - 2);
					settings.addSection(sectionName);
				} else if (StringUtils::startsWith(s, '#')) {
					// Comment, do nothing.
				} else if (StringUtils::startsWith(s, ';')) {
					// Comment, do nothing.
				} else {
					string::size_type equalsPos = s.find('=');
					if (equalsPos != string::npos) {
						string name = s.substr(0, equalsPos);
						StringUtils::trim(name);

						string value;
						if (s.length() - 1 > equalsPos) {
							value = s.substr(equalsPos + 1);
							StringUtils::trim(value);
						}

						settings.addItem(name, value);
					}
				}
				break;
			}
			default:
			{
				ASSERT(0);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
