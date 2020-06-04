#include "Authorizer.h"



Authorizer::Authorizer()
{
}


Authorizer::~Authorizer()
{
}

void Authorizer::login(char* login, char* password)
{
	cout << "Authorization: login request" << endl;
	for (auto i : DataManager::getInstance().getUsers())
	{
		if (!strcmp(login, i.getLogin()) && !strcmp(password, i.getPassword()))
		{
			if (i.getAccess() == 1)
			{
				cout << "Client logged as administrator" << endl;
				Server::getInstance().sendMessage("ADMIN", sizeof("ADMIN"));
			}
			else
			{
				cout << "Client logged in user mode" << endl;
				Server::getInstance().sendMessage("USER", sizeof("USER"));
			}
			return;
		}
	}
	Server::getInstance().sendMessage("NOTFOUND", sizeof("NOTFOUND"));
	Sleep(2000);
	return;
}


