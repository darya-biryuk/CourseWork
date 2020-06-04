#include "AdminMenu.h"
#include "Exeptions.h"



AdminMenu::AdminMenu()
{
}


AdminMenu::~AdminMenu()
{
}

void AdminMenu::run()
{
	int ch;
	while (1)
	{
		system("cls");
		cout << "����� ���������� � ����� ��������������\n";
		cout << "1.�������� ������.\n";
		cout << "2.���������� ������.\n";
		cout << "3.��������.\n";
		cout << "4.��������������.\n";
		cout << "5.�����.\n";
		cout << ">>";
		try {
			cin >> ch;
			if (ch > 4 || ch <= 0) throw first("\n��� ������ ���������� ������ first ��� �������� �����.");
		}
		catch (first ob) {
			cout << ob.what() << endl;
		}
		Systools::checkInt(ch);
		switch (ch)
		{
		case 1:
		{
			system("cls");
			print(downloadCarData(), downloadTeamData(), downloadUserData());
			break;
		}
		case 2:
		{
			system("cls");
			add();
			break;
		}
		case 3:
		{
			system("cls");
			removeMenu();
			break;
		}
		case 4:
		{
			system("cls");
			edit();
		}
		case 5:
		{
			system("cls");
			return;
		}
		default: cout << "�������� �����. ��������� �������.\n";
			break;
		}
	}
}

void AdminMenu::print(vector<Car> cars, vector<Team> teams, vector<User> users)
{
	while (1)
	{
		int sw;
		cout << "1.�������� �����������.\n";
		cout << "2.�������� ������.\n";
		cout << "3.�������� �������������.\n";
		cout << "4.�����.\n";
		cout << ">>";
		try {
			cin >> sw;
			if (sw > 4 || sw <= 0) throw first("\n��� ������ ���������� ������ first ��� �������� �����.");
		}
		catch (first ob) {
			cout << "\n��� ������ ������!" << ob.what() << endl;
		}
		Systools::checkInt(sw);
		switch (sw)
		{
		case 1:
		{
			system("cls");
			printCars(cars);
			break;
		}
		case 2:
		{
			system("cls");
			printTeams(teams);
			break;
		}
		case 3:
		{
			system("cls");
			printUser(users);
			break;
		}
		case 4:
		{
			system("cls");
			return;
		}
		default: cout << "�������� �����. ��������� �������.\n";
			break;
		}
	}
}

void AdminMenu::add()
{
	while (1)
	{
		int sw;
		cout << "1.���������� ����������.\n";
		cout << "2.���������� �������.\n";
		cout << "3.���������� ������������.\n";
		cout << "4.�����.\n";
		cout << ">>";
		try {
			cin >> sw;
			if (sw > 4 || sw <= 0) throw first("\n��� ������ ���������� ������ first ��� �������� �����.");
		}
		catch (first ob) {
			cout << "\n��� ������ ������!" << ob.what() << endl;
		}
		Systools::checkInt(sw);
		switch (sw)
		{
		case 1:
		{
			addCarMenu();
			break;
		}
		case 2:
		{
			addTeamMenu();
			break;
		}
		case 3:
		{
			addUserMenu();
			break;
		}
		case 4:
		{
			system("cls");
			return;
		}
		default: cout << "�������� �����. ��������� �������.\n";
			break;
		}
	}
}

void AdminMenu::addCarMenu()
{
	Car newCar;
	string code;
	string bodyType;
	int qOfDoors;
	int qOfSeats;
	int luggageVolume;
	int power;
	int mark1;
	int mark2;
	int mark3;
	memset(&newCar, 0, sizeof(newCar));
	cout << "���� ������:\n";
	cout << "���:\n";
	cin >> code;
	strcpy(newCar.code, code.c_str());
	cout << "��� ������ (��������, ��������, �����-������������):\n";
	cin >> bodyType;
	try {
		if (strcmp(bodyType.c_str(), "��������") != 0 && strcmp(bodyType.c_str(), "��������") != 0 && strcmp(bodyType.c_str(), "�����-������������") != 0) {
			check++;
			throw second("\n��� ������ ���������� ������ second ��� �������� ��������� ����������.");
		}
	}
	catch (second ob) { cout << "\n�������� ����!" << ob.what() << endl; return; }
	strcpy(newCar.bodyType, bodyType.c_str());
	cout << "���������� ������:\n";
	cin >> qOfDoors;
	Systools::checkInt(qOfDoors);
	newCar.qOfDoors = qOfDoors;
	cout << "���������� ����:\n";
	cin >> qOfSeats;
	Systools::checkInt(qOfSeats);
	newCar.qOfSeats = qOfSeats;
	cout << "����� ������:\n";
	cin >> luggageVolume;
	newCar.luggageVolume = luggageVolume;
	cout << "�������� ���������:\n";
	cin >> power;
	newCar.power = power;
	cout << "������� 1:\n";
	do
	{
		cin >> mark1;
	} while (mark1 > 3 || mark1 < 1);
	newCar.mark1 = mark1;
	cout << "������� 2:\n";
	do
	{
		cin >> mark2;
	} while (mark2 > 3 || mark2 < 1);
	newCar.mark2 = mark2;
	cout << "������� 3:\n";
	do
	{
		cin >> mark3;
	} while (mark3 > 3 || mark3 < 1);
	newCar.mark3 = mark3;

	Client::getInstance().sendMessage("ADDCAR", sizeof("ADDCAR"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&newCar, sizeof(newCar));

}

void AdminMenu::addTeamMenu()
{
	Team newTeam;
	memset(&newTeam, 0, sizeof(newTeam));
	string code;
	int qOfPeople;
	int qOfHours;
	int salary;
	int day, month, year;
	cout << "���� ������:\n";
	cout << "���:\n";
	cin >> code;
	strcpy(newTeam.code, code.c_str());
	cout << "���������� �������:\n";
	cin >> qOfPeople;
	newTeam.qOfPeople = qOfPeople;
	cout << "���������� ����� � ������:\n";
	cin >> qOfHours;
	newTeam.qOfHours = qOfHours;
	cout << "���������� ����� �� �������:\n";
	cin >> salary;
	newTeam.salary = salary;
	cout << "���� �����:\n";
	cout << "����:\n";
	cin >> day;
	newTeam.employmentDate.day = day;
	cout << "�����:\n";
	cin >> month;
	newTeam.employmentDate.month = month;
	cout << "���:\n";
	cin >> year;
	newTeam.employmentDate.year = year;

	Client::getInstance().sendMessage("ADDTEAM", sizeof("ADDTEAM"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&newTeam, sizeof(newTeam));
}

void AdminMenu::addUserMenu()
{
	User newUser;
	string login, password;
	memset(&newUser, 0, sizeof(newUser));
	cout << "������� login:\n";
	cin >> login;
	strcpy(newUser.login, login.c_str());
	cout << "������� ������:\n";
	cin >> password;
	strcpy(newUser.password, password.c_str());

	Client::getInstance().sendMessage("ADDUSER", sizeof("ADDUSER"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&newUser, sizeof(newUser));
}

void AdminMenu::edit()
{
	int ch;
		while (1)
		{
			system("cls");
			cout << "��������������\n��������, ��� ���������� ���������������:\n";
			cout << "1.����������\n";
			cout << "2.�������\n";
			cout << "3.������������\n";
			cout << "4.�����\n";
			cout << ">>";
			try {
				cin >> ch;
				if (ch > 4 || ch <= 0) throw first("\n��� ������ ���������� ������ first ��� �������� �����.");
			}
			catch (first ob) {
				cout << "\n��� ������ ������!" << ob.what() << endl;
			}
			Systools::checkInt(ch);
			switch (ch)
			{
			case 1:
			{
				system("cls");
				editCarMenu();
				break;
			}
			case 2:
			{
				system("cls");
				editTeamMenu();
				break;
			}
			case 3:
			{
				system("cls");
				editUserMenu();
				break;
			}
			case 4:
			{
				system("cls");
				return;
			}
			default: cout << "������������ �����. ��������� �������\n";
				break;
			}
		}
}

void AdminMenu::editCarMenu()
{
	int id;
		cout << "������� id ����������: ";
		cin >> id;
		Systools::checkInt(id);
		Car editCar;
		string code, bodyType;
		int qOfDoors, qOfSeats, luggageVolume, power;
		int mark1;
		int mark2;
		int mark3;
		memset(&editCar, 0, sizeof(editCar));
		editCar.id = id;
		do {
			cout << "��� ����������: ";
			cin >> code;
			if (Systools::checkNoLetters(code))
			{
				strcpy(editCar.code, code.c_str());
				break;
			}
			else
				cout << "������������ ����. ��������� �������.\n";
		} while (1);
		do {
			cout << "��� ������ (��������, ��������, �����-������������):\n";
			cin >> bodyType;
			try {
				if (strcmp(bodyType.c_str(), "��������") != 0 && strcmp(bodyType.c_str(), "��������") != 0 && strcmp(bodyType.c_str(), "�����-������������") != 0) {
					check++;
					throw second("\n��� ������ ���������� ������ second ��� �������� ��������� ����������.");
				}
			}
			catch (second ob) { cout << "\n�������� ����!" << ob.what() << endl; return; }
			if (Systools::checkNoNumbers(bodyType))
			{
				strcpy(editCar.bodyType, bodyType.c_str());
				break;
			}
			else
				cout << "������������ ����. ��������� �������.\n";
		} while (1);
		cout << "���������� ������:\n";
		cin >> qOfDoors;
		Systools::checkInt(qOfDoors);
		editCar.qOfDoors = qOfDoors;
		cout << "���������� ����:\n";
		cin >> qOfSeats;
		Systools::checkInt(qOfDoors);
		editCar.qOfSeats = qOfSeats;
		cout << "����� ������:\n";
		cin >> luggageVolume;
		Systools::checkInt(luggageVolume);
		editCar.luggageVolume = luggageVolume;
		cout << "�������� ���������:\n";
		cin >> power;
		Systools::checkInt(power);
		editCar.power = power;
		cout << "������� 1:\n";
		cin >> mark1;
		Systools::checkInt(mark1);
		editCar.mark1 = mark1;
		cout << "������� 2:\n";
		cin >> mark2;
		Systools::checkInt(mark2);
		editCar.mark2 = mark2;
		cout << "������� 3:\n";
		cin >> mark3;
		Systools::checkInt(mark3);
		editCar.mark2 = mark2;

		Client::getInstance().sendMessage("EDITCAR", sizeof("EDITCAR"));
		Sleep(100);
		Client::getInstance().sendMessage((char*)&editCar, sizeof(editCar));
}

void AdminMenu::editTeamMenu()
{
	Team editTeam;
	memset(&editTeam, 0, sizeof(editTeam));
	string code;
	int qOfPeople;
	int qOfHours;
	int salary;
	int day, month, year;
	do {
		cout << "��� �������: ";
		cin >> code;
		if (Systools::checkNoLetters(code))
		{
			strcpy(editTeam.code, code.c_str());
			break;
		}
		else
			cout << "������������ ����. ��������� �������.\n";
	} while (1);
	cout << "���������� �������:\n";
	cin >> qOfPeople;
	Systools::checkInt(qOfPeople);
	editTeam.qOfPeople = qOfPeople;
	cout << "���������� ����� � ������:\n";
	cin >> qOfHours;
	Systools::checkInt(qOfHours);
	editTeam.qOfHours = qOfHours;
	cout << "���������� ����� �� �������:\n";
	cin >> salary;
	Systools::checkInt(salary);
	editTeam.salary = salary;
	cout << "���� �����:\n";
	cout << "����:\n";
	cin >> day;
	Systools::checkInt(day);
	editTeam.employmentDate.day = day;
	cout << "�����:\n";
	cin >> month;
	Systools::checkInt(month);
	editTeam.employmentDate.month = month;
	cout << "���:\n";
	cin >> year;
	Systools::checkInt(year);
	editTeam.employmentDate.year = year;

	Client::getInstance().sendMessage("EDITTEAM", sizeof("EDITTEAM"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&editTeam, sizeof(editTeam));
}

void AdminMenu::editUserMenu()
{
	User editUser;
	string login, password;
	int id;
	memset(&editUser, 0, sizeof(editUser));
	cout << "������� id ������������: ";
	cin >> id;
	Systools::checkInt(id);
	cout << "������� login:\n";
	cin >> login;
	strcpy(editUser.login, login.c_str());
	cout << "������� ������:\n";
	cin >> password;
	strcpy(editUser.password, password.c_str());

	Client::getInstance().sendMessage("EDITUSER", sizeof("EDITUSER"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&editUser, sizeof(editUser));
}

void AdminMenu::removeMenu()
{
	int ch;
	while (1)
	{
		system("cls");
		cout << "��������\n��������, ��� ���������� �������:\n";
		cout << "1.����������\n";
		cout << "2.�������\n";
		cout << "3.������������\n";
		cout << "4.�����\n";
		cout << ">>";
		try {
			cin >> ch;
			if (ch > 4 || ch <= 0) throw first("\n��� ������ ���������� ������ first ��� �������� �����.");
		}
		catch (first ob) {
			cout << "\n��� ������ ������!" << ob.what() << endl;
		}
		Systools::checkInt(ch);
		switch (ch)
		{
		case 1:
		{
			system("cls");
			removeCarMenu();
			break;
		}
		case 2:
		{
			system("cls");
			removeTeamMenu();
			break;
		}
		case 3:
		{
			system("cls");
			removeUserById();
			break;
		}
		case 4:
		{
			system("cls");
			return;
		}
		default: cout << "������������ �����. ��������� �������\n";
			break;
		}
	}
}

void AdminMenu::removeCarMenu()
{
	int sw;
	while (1)
	{
		system("cls");
		cout << "��������\n��������, ��� ���������� �������:\n";
		cout << "1.������� 1 ����������\n";
		cout << "2.������� ��� ����������\n";
		cout << "3.�����\n";
		cout << ">>";
		cin >> sw;
		Systools::checkInt(sw);
		switch (sw)
		{
		case 1:
		{
			system("cls");
			removeCarById();
			break;
		}
		case 2:
		{
			system("cls");
			Car Car;
			memset(&Car, 0, sizeof(Car));
			Client::getInstance().sendMessage("REMOVEALLCARS", sizeof("REMOVEALLCARS"));
			Sleep(100);
			Client::getInstance().sendMessage((char*)&Car, sizeof(Car));
			break;
		}
		case 3:
		{
			system("cls");
			return;
		}
		default: cout << "������������ �����. ��������� �������\n";	break;
		}
	}
}

void AdminMenu::removeCarById()
{
	int id;
	Car Car;
	memset(&Car, 0, sizeof(Car));
	cout << "������� ID ����������" << endl;
	cin >> id;
	Systools::checkInt(id);
	Car.id = id;
	Client::getInstance().sendMessage("REMOVEONECAR", sizeof("REMOVEONECAR"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&Car, sizeof(Car));
}

void AdminMenu::removeTeamMenu()
{
	int sw;
	while (1)
	{
		system("cls");
		cout << "��������\n��������, ��� ���������� �������:\n";
		cout << "1.������� 1 �������\n";
		cout << "2.������� ��� �������\n";
		cout << "3.�����\n";
		cout << ">>";
		cin >> sw;
		Systools::checkInt(sw);
		switch (sw)
		{
		case 1:
		{
			system("cls");
			removeTeamByCode();
			break;
		}
		case 2:
		{
			system("cls");
			Team team;
			memset(&team, 0, sizeof(team));
			Client::getInstance().sendMessage("REMOVEALLTEAMS", sizeof("REMOVEALLTEAMS"));
			Sleep(100);
			Client::getInstance().sendMessage((char*)&team, sizeof(team));
			break;
		}
		case 3:
		{
			system("cls");
			return;
		}
		default: cout << "������������ �����. ��������� �������\n";	break;
		}
	}
}

void AdminMenu::removeTeamByCode()
{
	string code;
	Team team;
	memset(&team, 0, sizeof(team));
	cout << "������� ��� �������" << endl;
	cin >> code;
	strcpy(team.code, code.c_str());
	Client::getInstance().sendMessage("REMOVEONETEAM", sizeof("REMOVEONETEAM"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&team, sizeof(team));
}

void AdminMenu::removeUserById()
{
	int id;
	User user;
	memset(&user, 0, sizeof(user));
	cout << "������� ID ������������" << endl;
	cin >> id;
	Systools::checkInt(id);
	user.id = id;
	Client::getInstance().sendMessage("REMOVEONEUSER", sizeof("REMOVEONEUSER"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&user, sizeof(user));
}



