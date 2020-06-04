#include "UserMenu.h"



UserMenu::UserMenu()
{
}


UserMenu::~UserMenu()
{
}

void UserMenu::run()
{
	int ch;
	while (1)
	{
		system("cls");
		cout << "ДОБРО ПОЖАЛОВАТЬ В РЕЖИМ ПОЛЬЗОВАТЕЛЯ\n";
		cout << "1.Просмотр данных.\n";
		cout << "2.Решение задачи.\n";
		cout << "3.Выход.\n";
		cout << ">>";
		cin >> ch;
		Systools::checkInt(ch);
		switch (ch)
		{
		case 1:
		{
			system("cls");
			print(downloadCarData(), downloadTeamData());
			break;
		}
		case 2:
		{
			system("cls");
			printCars(downloadCarData());
			taskMenu(downloadCarData());
			break;
		}		
		case 3:
		{
			system("cls");
			return;
		}
		default: cout << "Неверный выбор. Повторите попытку.\n";
			break;
		}
	}
}

void UserMenu::print(vector<Car> cars, vector<Team> teams)
{
	while (1)
	{
		system("cls");
		int sw;
		cout << "1.Просмотр автомобилей.\n";
		cout << "2.Просмотр бригад.\n";
		cout << "3.Назад.\n";
		cout << ">>";
		cin >> sw;
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
			return;
		}
		default: cout << "Неверный выбор. Повторите попытку.\n";
			break;
		}
	}
}

void UserMenu::taskMenu(vector<Car> cars)
{
	Car Car1;
	memset(&Car1, 0, sizeof(Car1));
	Car Car2;
	memset(&Car2, 0, sizeof(Car2));
	Car Car3;
	memset(&Car3, 0, sizeof(Car3));
	int id[3];
	cout << "Выберите автомобили для решения задачи:" << endl;
	cout << "id 1: ";
	cin >> id[0];
	Car1.id = id[0];
	cout << "id 2: ";
	cin >> id[1];
	Car2.id = id[1];
	cout << "id 3: ";
	cin >> id[2];
	Car3.id = id[2];
	Client::getInstance().sendMessage("TASK", sizeof("TASK"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&Car1, sizeof(Car1));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&Car2, sizeof(Car2));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&Car3, sizeof(Car3));

	Weight weights[32];
	vector<Weight> weight;
	int size = Client::getInstance().recvMessage(&weights) / sizeof(Weight);
	for (int i = 0; i < size; i++)
	{
		weight.push_back(weights[i]);
	}

	if (weight.empty())
	{
		cout << "Список пуст.\n";
		return;
	}

	VariadicTable<int, double> vt({"id автомобиля", "Вес цели"});

	for (int i = 0; i < weight.size(); i++)
	{
			vt.addRow({ id[i], weight[i].w });
	}

	vt.print(std::cout);
	system("pause");
}
