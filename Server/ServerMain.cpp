#include "Server.h"
#include <iostream>
#include "DataManager.h"
#include "MessageHandler.h"

using namespace std;

void run()
{
	while (true)
	{
		int msg_size;
		char msg[1024];
		if (Server::getInstance().recvMessage(msg) < 0)
		{
			Server::getInstance().closeConnection();
			break;
		}
		MessageHandler::getInstance().executeCommand(msg);
	}
}

int main(int argc, char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	DataManager::getInstance().loadCars();
	DataManager::getInstance().loadTeams();
	DataManager::getInstance().loadUsers();

	while (true)
	{
		Server::getInstance().setConnection();
		run();
	}

	system("pause");
	return 0;
}