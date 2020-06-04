#pragma once
#include <iostream>

using namespace std;

struct Car
{
	int id;
	char code[64];
	char bodyType[64];
	int qOfDoors;
	int qOfSeats;
	int luggageVolume;
	int power;
	int mark1;
	int mark2;
	int mark3;
};

struct Date
{
	int day;
	int month;
	int year;
};

struct Team
{
	char code[64];;
	int qOfPeople;
	int qOfHours;
	int salary;
	Date employmentDate;
};

struct User
{
	int id;
	char login[64];
	char password[64];
	int access;
};

struct Weight
{
	float w;
};