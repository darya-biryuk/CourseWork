#include "Systools.h"


Systools::Systools()
{

}

vector<string> Systools::getTokens(string str, string delimiter)
{
	vector<string> token_v;
	size_t start = str.find_first_not_of(delimiter), end = start;

	while (start != std::string::npos) {
		// Find next occurence of delimiter
		end = str.find(delimiter, start);
		// Push back the token found into vector
		token_v.push_back(str.substr(start, end - start));
		// Skip all occurences of the delimiter to find new start
		start = str.find_first_not_of(delimiter, end);
	}

	return token_v;
}


void Systools::checkInt(int value)
{
	while (cin.fail() || cin.get() != '\n' || value < 0)
	{
		cout << "ERROR! Enter the NUMBER\n";
		cin.clear();
		rewind(stdin);
		cin >> value;
	}
}


void Systools::setStdEcho(bool value)
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	if (value) SetConsoleMode(hStdin, mode | (ENABLE_ECHO_INPUT));
	else SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
}


Systools::~Systools()
{

}
