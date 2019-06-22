///////////////////////////////////////////////////////////////////////////////

#include "date.h"
#include "exceptions.h"

///////////////////////////////////////////////////////////////////////////////

Date::Date()
{
	setNull();
}

Date::Date(int year__, int month__, int date__)
	: year_(year__)
	, month_(month__)
	, date_(date__)
{

}

// January 1, year 0.
bool Date::isNull() const
{
	return year_ == 0
		&& month_ == 1
		&& date_ == 1;
}

// January 1, year 0.
void Date::setNull()
{
	year_ = 0;
	month_ = 1;
	date_ = 1;
}

void Date::setToday()
{
	time_t now = time(nullptr);
	tm* pTime = localtime(&now);
	ASSERT(pTime != nullptr);

	tm& curTime = *pTime;

	year_ = curTime.tm_year + 1900;
	month_ = curTime.tm_mon + 1;
	date_ = curTime.tm_mday;
}

bool operator==(const Date& d1, const Date& d2)
{
	return d1.year_ == d2.year_
		&& d1.month_ == d2.month_
		&& d1.date_ == d2.date_;
}

bool operator<(const Date& d1, const Date& d2)
{
	if (d1.year_ < d2.year_)
	{
		return true;
	}
	else if (d1.year_ > d2.year_)
	{
		return false;
	}
	
	// year_ are equal

	if (d1.month_ < d2.month_)
	{
		return true;
	}
	else if (d1.month_ > d2.month_)
	{
		return false;
	}
	
	// month_ are equal

	if (d1.date_ < d2.date_)
	{
		return true;
	}
	else if (d1.date_ > d2.date_)
	{
		return false;
	}
	
	// date_ are equal

	// All fields equal

	return false;
}

///////////////////////////////////////////////////////////////////////////////
