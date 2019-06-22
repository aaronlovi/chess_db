#ifndef CHESS_DB_SETTINGS_H
#define CHESS_DB_SETTINGS_H

///////////////////////////////////////////////////////////////////////////////

struct IniFile;

///////////////////////////////////////////////////////////////////////////////

struct ChessDbSettingsHelper
{
	ChessDbSettingsHelper(IniFile& iniFile_)
		: iniFile(iniFile_)
	{ }

	const char* getPgnFile() const;

	IniFile& iniFile;
};


///////////////////////////////////////////////////////////////////////////////

#endif // CHESS_DB_SETTINGS_H
