#include "Date.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getDay()
{
	return day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

int Date::getMonth()
{
	return month;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear()
{
	return year;
}

Date::~Date()
{
}
