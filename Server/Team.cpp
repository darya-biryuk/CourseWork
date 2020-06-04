#include "Team.h"


Team::Team()
{

}


Team::~Team()
{

}


void Team::setEmploymentDate(int day, int month, int year)
{
	this->employmentDate.setDay(day);
	this->employmentDate.setMonth(month);
	this->employmentDate.setYear(year);
}