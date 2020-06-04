#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}



void Menu::printCars(vector<Car> cars)
{
	if (cars.empty())
	{
		cout << "������ ����.\n";
		return;
	}

	VariadicTable<int, string, string, int, int, int, int, int, int, int> vt({ "ID", "���", "��� ������", "���-�� ������", "���-�� ����", "����� ������", "�������� ���������", "������ �������� 1", "������ �������� 2", "������ �������� 3" });

	for (auto i : cars)
	{
		vt.addRow({ i.id , i.code, i.bodyType , i.qOfDoors, i.qOfSeats, i.luggageVolume, i.power, i.mark1, i.mark2, i.mark3 });
	}

	vt.print(std::cout);
	system("pause");
}

void Menu::printTeams(vector<Team> teams)
{
	if (teams.empty())
	{
		cout << "������ ����.\n";
		return;
	}

	VariadicTable<string, int, int, int, string> vt({ "���", "���������� �������", "���������� ����� � ������", "�/� �� �������", "���� ����� �� ������" });

		for (auto i : teams)
		{
			std::stringstream ss_evi;
			ss_evi << std::setfill('0') << std::setw(3) << std::to_string(i.employmentDate.day) + ".";
			ss_evi << std::setfill('0') << std::setw(3) << std::to_string(i.employmentDate.month) + ".";
			ss_evi << std::setfill('0') << std::setw(4) << std::to_string(i.employmentDate.year);
			vt.addRow({ i.code , i.qOfPeople, i.qOfHours , i.salary, ss_evi.str()});
		}

	vt.print(std::cout);
}

void Menu::printUser(vector<User> users)
{
	if (users.empty())
	{
		cout << "������ ����.\n";
		return;
	}
	for (auto i : users)
	{
		cout << i;
		cout << endl;
	}
}

vector<Car> Menu::downloadCarData()
{	
	Client::getInstance().sendMessage("PRINTCARS", sizeof("PRINTCARS"));
	Sleep(100);
	Car cars[32];
	vector<Car> car;
	int size = Client::getInstance().recvMessage(&cars) / sizeof(Car);
	for (int i = 0; i < size; i++)
	{
		car.push_back(cars[i]);
	}
	return car;
}

vector<Team> Menu::downloadTeamData()
{
	Client::getInstance().sendMessage("PRINTTEAMS", sizeof("PRINTTEAMS"));
	Sleep(100);
	Team teams[32];
	vector<Team> team;
	int size = Client::getInstance().recvMessage(&teams) / sizeof(Team);
	for (int i = 0; i < size; i++)
	{
		team.push_back(teams[i]);
	}
	return team;
}

vector<User> Menu::downloadUserData()
{
	Client::getInstance().sendMessage("PRINTUSERS", sizeof("PRINTUSERS"));
	Sleep(100);
	User users[32];
	vector<User> user;
	int size = Client::getInstance().recvMessage(&users) / sizeof(User);
	for (int i = 0; i < size; i++)
	{
		user.push_back(users[i]);
	}
	return user;
}




ostream & operator<<(ostream & out, Team & obj)
{
	out << "���: " << obj.code << endl;
	out << "���������� �������: " << obj.qOfPeople << endl;
	out << "���������� ����� ������: " << obj.qOfHours << endl;
	out << "���������� �����(�� ��� �������): " << obj.salary << endl;
	out << "���� ������������ � ������: " << obj.employmentDate.day << "." << obj.employmentDate.month << "." << obj.employmentDate.year << endl;
	return out;
}

ostream & operator<<(ostream & out, User & obj)
{
	out << "id: " << obj.id << endl;
	out << "login: " << obj.login << endl;
	out << "password: " << obj.password << endl;
	return out;
}
