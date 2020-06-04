#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

bad_alloc exept;
int check = 0;

class first : public exception
{
public:
	first(const char *s) : exception(s) {};
	const char* what() { return exception::what(); }
};

class second : public first {
public:
	second(const char *s) : first(s) {};
	const char* what() { return exception::what(); }
};