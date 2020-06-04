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

//string Systools::encryptData(std::string input)
//{
//	string line;
//	DES des(std::bitset<9>(SECURITY_KEY));
//	std::vector<bitset<12>> e;
//	e = des.Encrypt(input);
//
//	stringstream ss;
//	for (auto l : e)
//		ss << l;
//	ss << endl;
//	return ss.str();
//}

//string Systools::decryptData(std::string input)
//{
//	std::string line;
//	std::vector<bitset<12>> o;
//	std::vector<bitset<12>> result;
//
//	for (int i = 0; i < input.size() / 12; i++) {
//		o.push_back(std::bitset<12>(input.substr(i * 12, 12)));
//	}
//
//	DES des(std::bitset<9>(SECURITY_KEY));
//	result = des.Decrypt(o);
//
//	stringstream ss;
//	for (auto l : result)
//	{
//		ss << (char)(l.to_ulong() >> 4);
//	}
//
//	return ss.str();
//}

Systools::~Systools()
{
}
