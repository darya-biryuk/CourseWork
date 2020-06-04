#pragma once
#include "Server.h"
#include <iostream>
#include <Windows.h>
#include "DataManager.h"
#include "Systools.h"

using namespace std;

class Authorizer
{
	Authorizer(Authorizer const&) = delete;
	Authorizer &operator= (Authorizer const&) = delete;
	Authorizer();
	~Authorizer();
public:
	static Authorizer &getInstance()
	{
		static Authorizer auth;
		return auth;
	}
	void login(char*, char*);
	void signup();
};

