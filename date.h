#ifndef DATE_H
#define DATE_H

///////////////////////////////////////////////////////////////////////////////

#include "include_base.h"

///////////////////////////////////////////////////////////////////////////////

struct Date
{
	INT16 year_; // Raw year (i.e. set to 2018 for year 2018; *not* years since 1900. INT16_MAX means "unknown"
	INT8 month_; // Month of the year. January = 1. INT8_MAX means "unknown"
	INT8 date_; // Day of the month - [1, 31]. INT8_MAX means "unknown"

	Date();
	Date(int year__, int month__, int date__);

	bool isNull() const;

	void setNull();
	void setToday();
};

bool operator==(const Date& d1, const Date& d2);
bool operator<(const Date& d1, const Date& d2);

///////////////////////////////////////////////////////////////////////////////

#endif // DATE_H
