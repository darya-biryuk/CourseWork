#include "Client.h"
#include "Authorizer.h"
#include "AdminMenu.h"
#include "UserMenu.h"



Authorizer::Authorizer()
{
}

Authorizer::~Authorizer()
{
}

void Authorizer::authMenu()
{
	int sw;
	while (1)
	{
		system("cls");
		cout << "�������� ��������\n";
		cout << "1. ���� � �������\n";
		cout << "2. �����������\n";
		cout << "3. ����� �� ���������\n";
		cin >> sw;
		Systools::checkInt(sw);
		switch (sw)
		{
		case 1:
		{
			system("cls");
			login();
			break;
		}
		case 2:
		{
			system("cls");
			signup();
			break;
		}
		case 3:
		{
			system("cls");
			return;
		}
		default:
			break;
		}
	}
}

void Authorizer::login()
{
	User user;
	memset(&user, 0, sizeof(user));
	string login;
	string password;
	cout << "����������� " << endl;  
	cout << "������� �����: ";
	cin >> login;
	strcpy(user.login, login.c_str());
	Systools::setStdEcho(false);
	cout << "������� ������: ";
	cin >> password;
	Systools::setStdEcho(true);
	strcpy(user.password, password.c_str());

	Client::getInstance().sendMessage("LOGIN", sizeof("LOGIN"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&user, sizeof(user));
	Menu *menu;
	char message[64];
	Client::getInstance().recvMessage(&message);
	if ((string)message == "ADMIN")
	{
		menu = new AdminMenu();
		menu->run();
	}
	if ((string)message == "USER")
	{
		menu = new UserMenu();
		menu->run();
	}
	else if ((string)message == "NOTFOUND")
	{
		cout << "�������� ����" << endl;
		return;
	}
}

void Authorizer::loginMenu()
{
	User user;
	memset(&user, 0, sizeof(user));
	string login;
	string password;
	cout << "�����������: ";
	cout << "������� �����: ";
	cin >> login;
	strcpy(user.login, login.c_str());
	cout << "������� ������: ";
	cin >> password;
	strcpy(user.password, password.c_str());

	Client::getInstance().sendMessage("LOGIN", sizeof("LOGIN"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&user, sizeof(user));
}

void Authorizer::signup()
{
	User newUser;
	string login, password;
	memset(&newUser, 0, sizeof(newUser));
	cout << "������� �����:\n";
	cin >> login;
	strcpy(newUser.login, login.c_str());
	cout << "������� ������:\n";
	cin >> password;
	strcpy(newUser.password, password.c_str());

	Client::getInstance().sendMessage("ADDUSER", sizeof("ADDUSER"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&newUser, sizeof(newUser));
}

