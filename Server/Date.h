#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	~Date();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();
};
