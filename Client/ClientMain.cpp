#include "Structures.h"
#include "Authorizer.h"
#include "Client.h"
#include "AdminMenu.h"
#include <cerrno>


int main(int argc, char* argv[]) 
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	if (Client::getInstance().setConnection() != 0)
	{
		std::cout << "Error: failed connect to server.\n";
		system("pause");
		return 1;
	}

	Authorizer::getInstance().authMenu();

	if (Client::getInstance().closeConnection() != 0)
	{
		std::cout << "Close connection error " << errno << ": " << std::strerror(errno) << std::endl;
	} 
	else
	{
		std::cout << "Connection closed" << std::endl;
	}

	system("pause");
	return 0;
}