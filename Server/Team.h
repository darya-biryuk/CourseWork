#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

class Team
{
private:
	char code[64];
	int qOfPeople;
	int qOfHours;
	int salary;
	Date employmentDate;
public:
	Team();
	~Team();
	inline void setCode(string code) { strcpy(this->code, code.c_str()); }
	inline string getCode() { return code; }
	inline void setQuantityOfPeople(int qOfPeople) { this->qOfPeople = qOfPeople; }
	inline int getQuantityOfPeople() { return qOfPeople; }
	inline void setQuantityOfHours(int qOfHours) { this->qOfHours = qOfHours; }
	inline int getQuantityOfHours() { return qOfHours; }
	inline void setSalary(int salary) { this->salary = salary; }
	inline int getSalary() { return salary; }
	void setEmploymentDate(int, int, int);
	void setEmploymentDay(int day) { employmentDate.setDay(day); }
	void setEmploymentMonth(int month) { employmentDate.setDay(month); }
	void setEmploymentYear(int year) { employmentDate.setDay(year); }
	inline int getEmploymentDay() { return employmentDate.getDay(); }
	inline int getemploymentMonth() { return employmentDate.getMonth(); }
	inline int getemploymentYear() { return employmentDate.getYear(); }

};

