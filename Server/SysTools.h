#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
//#include "Des.h"

//#define SECURITY_KEY "110011010"

using namespace std;
//using namespace encryption;

class Systools
{
public:
	Systools();
	~Systools();
	//static string encryptData(std::string input);
	//static string decryptData(std::string input);
	static vector<string> getTokens(string str, string delimiter);
	static void checkInt(int value);
	static void setStdEcho(bool);
	static bool checkNoLetters(string str1)
	{
		int p = str1.size();
		for (int i = 0; i < p; i++)
			if (!(str1[i] >= 'a' && str1[i] <= 'z') && !(str1[i] >= 'A' && str1[i] <= 'Z')
				&& !(str1[i] >= 'à' && str1[i] <= 'ÿ') && !(str1[i] >= 'À' && str1[i] <= 'ß'))
			{
				continue;
			}
			else return false;
			return true;
	}
	static bool checkNoNumbers(string str1)
	{
		int p = str1.size();
		for (int i = 0; i < p; i++)
			if (!(str1[i] >= '0' && str1[i] <= '9'))
			{
				continue;
			}
			else return false;
			return true;
	}
};

