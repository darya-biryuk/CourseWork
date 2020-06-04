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
		cout << "ДОБРО ПОЖАЛОВАТЬ В РЕЖИМ АДМИНИСТРАТОРА\n";
		cout << "1.Просмотр данных.\n";
		cout << "2.Добавление данных.\n";
		cout << "3.Удаление.\n";
		cout << "4.Редактирование.\n";
		cout << "5.Выход.\n";
		cout << ">>";
		try {
			cin >> ch;
			if (ch > 4 || ch <= 0) throw first("\nБыл вызван обработчик класса first для проверки чисел.");
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
		default: cout << "Неверный выбор. Повторите попытку.\n";
			break;
		}
	}
}

void AdminMenu::print(vector<Car> cars, vector<Team> teams, vector<User> users)
{
	while (1)
	{
		int sw;
		cout << "1.Просмотр автомобилей.\n";
		cout << "2.Просмотр бригад.\n";
		cout << "3.Просмотр пользователей.\n";
		cout << "4.Назад.\n";
		cout << ">>";
		try {
			cin >> sw;
			if (sw > 4 || sw <= 0) throw first("\nБыл вызван обработчик класса first для проверки чисел.");
		}
		catch (first ob) {
			cout << "\nНет такого номера!" << ob.what() << endl;
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
		default: cout << "Неверный выбор. Повторите попытку.\n";
			break;
		}
	}
}

void AdminMenu::add()
{
	while (1)
	{
		int sw;
		cout << "1.Добавление автомобиля.\n";
		cout << "2.Добавление бригады.\n";
		cout << "3.Добавление пользователя.\n";
		cout << "4.Назад.\n";
		cout << ">>";
		try {
			cin >> sw;
			if (sw > 4 || sw <= 0) throw first("\nБыл вызван обработчик класса first для проверки чисел.");
		}
		catch (first ob) {
			cout << "\nНет такого номера!" << ob.what() << endl;
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
		default: cout << "Неверный выбор. Повторите попытку.\n";
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
	cout << "ВВОД ДАННЫХ:\n";
	cout << "Код:\n";
	cin >> code;
	strcpy(newCar.code, code.c_str());
	cout << "Тип кузова (закрытый, открытый, грузо-пассажирский):\n";
	cin >> bodyType;
	try {
		if (strcmp(bodyType.c_str(), "закрытый") != 0 && strcmp(bodyType.c_str(), "открытый") != 0 && strcmp(bodyType.c_str(), "грузо-пассажирский") != 0) {
			check++;
			throw second("\nБыл вызван обработчик класса second для проверки текстовой информации.");
		}
	}
	catch (second ob) { cout << "\nНеверный ввод!" << ob.what() << endl; return; }
	strcpy(newCar.bodyType, bodyType.c_str());
	cout << "Количество дверей:\n";
	cin >> qOfDoors;
	Systools::checkInt(qOfDoors);
	newCar.qOfDoors = qOfDoors;
	cout << "Количество мест:\n";
	cin >> qOfSeats;
	Systools::checkInt(qOfSeats);
	newCar.qOfSeats = qOfSeats;
	cout << "Объем багажа:\n";
	cin >> luggageVolume;
	newCar.luggageVolume = luggageVolume;
	cout << "Мощность двигателя:\n";
	cin >> power;
	newCar.power = power;
	cout << "Эксперт 1:\n";
	do
	{
		cin >> mark1;
	} while (mark1 > 3 || mark1 < 1);
	newCar.mark1 = mark1;
	cout << "Эксперт 2:\n";
	do
	{
		cin >> mark2;
	} while (mark2 > 3 || mark2 < 1);
	newCar.mark2 = mark2;
	cout << "Эксперт 3:\n";
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
	cout << "ВВОД ДАННЫХ:\n";
	cout << "Код:\n";
	cin >> code;
	strcpy(newTeam.code, code.c_str());
	cout << "Количество человек:\n";
	cin >> qOfPeople;
	newTeam.qOfPeople = qOfPeople;
	cout << "Количество часов в неделю:\n";
	cin >> qOfHours;
	newTeam.qOfHours = qOfHours;
	cout << "Заработная плата на бригаду:\n";
	cin >> salary;
	newTeam.salary = salary;
	cout << "Дата приёма:\n";
	cout << "день:\n";
	cin >> day;
	newTeam.employmentDate.day = day;
	cout << "месяц:\n";
	cin >> month;
	newTeam.employmentDate.month = month;
	cout << "год:\n";
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
	cout << "Введите login:\n";
	cin >> login;
	strcpy(newUser.login, login.c_str());
	cout << "Введите пароль:\n";
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
			cout << "РЕДАКТИРОВАНИЕ\nВыберите, что необходимо отредактировать:\n";
			cout << "1.Автомобиль\n";
			cout << "2.Бригада\n";
			cout << "3.Пользователь\n";
			cout << "4.НАЗАД\n";
			cout << ">>";
			try {
				cin >> ch;
				if (ch > 4 || ch <= 0) throw first("\nБыл вызван обработчик класса first для проверки чисел.");
			}
			catch (first ob) {
				cout << "\nНет такого номера!" << ob.what() << endl;
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
			default: cout << "Некорректный выбор. Повторите попытку\n";
				break;
			}
		}
}

void AdminMenu::editCarMenu()
{
	int id;
		cout << "Введите id автомобиля: ";
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
			cout << "Код автомобиля: ";
			cin >> code;
			if (Systools::checkNoLetters(code))
			{
				strcpy(editCar.code, code.c_str());
				break;
			}
			else
				cout << "Некорректный ввод. Повторите попытку.\n";
		} while (1);
		do {
			cout << "Тип кузова (закрытый, открытый, грузо-пассажирский):\n";
			cin >> bodyType;
			try {
				if (strcmp(bodyType.c_str(), "закрытый") != 0 && strcmp(bodyType.c_str(), "открытый") != 0 && strcmp(bodyType.c_str(), "грузо-пассажирский") != 0) {
					check++;
					throw second("\nБыл вызван обработчик класса second для проверки текстовой информации.");
				}
			}
			catch (second ob) { cout << "\nНеверный ввод!" << ob.what() << endl; return; }
			if (Systools::checkNoNumbers(bodyType))
			{
				strcpy(editCar.bodyType, bodyType.c_str());
				break;
			}
			else
				cout << "Некорректный ввод. Повторите попытку.\n";
		} while (1);
		cout << "Количество дверей:\n";
		cin >> qOfDoors;
		Systools::checkInt(qOfDoors);
		editCar.qOfDoors = qOfDoors;
		cout << "Количество мест:\n";
		cin >> qOfSeats;
		Systools::checkInt(qOfDoors);
		editCar.qOfSeats = qOfSeats;
		cout << "Объем багажа:\n";
		cin >> luggageVolume;
		Systools::checkInt(luggageVolume);
		editCar.luggageVolume = luggageVolume;
		cout << "Мощность двигателя:\n";
		cin >> power;
		Systools::checkInt(power);
		editCar.power = power;
		cout << "Эксперт 1:\n";
		cin >> mark1;
		Systools::checkInt(mark1);
		editCar.mark1 = mark1;
		cout << "Эксперт 2:\n";
		cin >> mark2;
		Systools::checkInt(mark2);
		editCar.mark2 = mark2;
		cout << "Эксперт 3:\n";
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
		cout << "Код бригады: ";
		cin >> code;
		if (Systools::checkNoLetters(code))
		{
			strcpy(editTeam.code, code.c_str());
			break;
		}
		else
			cout << "Некорректный ввод. Повторите попытку.\n";
	} while (1);
	cout << "Количество человек:\n";
	cin >> qOfPeople;
	Systools::checkInt(qOfPeople);
	editTeam.qOfPeople = qOfPeople;
	cout << "Количество часов в неделю:\n";
	cin >> qOfHours;
	Systools::checkInt(qOfHours);
	editTeam.qOfHours = qOfHours;
	cout << "Заработная плата на бригаду:\n";
	cin >> salary;
	Systools::checkInt(salary);
	editTeam.salary = salary;
	cout << "Дата приёма:\n";
	cout << "день:\n";
	cin >> day;
	Systools::checkInt(day);
	editTeam.employmentDate.day = day;
	cout << "месяц:\n";
	cin >> month;
	Systools::checkInt(month);
	editTeam.employmentDate.month = month;
	cout << "год:\n";
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
	cout << "Введите id пользователя: ";
	cin >> id;
	Systools::checkInt(id);
	cout << "Введите login:\n";
	cin >> login;
	strcpy(editUser.login, login.c_str());
	cout << "Введите пароль:\n";
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
		cout << "УДАЛЕНИЕ\nВыберите, что необходимо удалить:\n";
		cout << "1.Автомобиль\n";
		cout << "2.Бригада\n";
		cout << "3.Пользователь\n";
		cout << "4.Назад\n";
		cout << ">>";
		try {
			cin >> ch;
			if (ch > 4 || ch <= 0) throw first("\nБыл вызван обработчик класса first для проверки чисел.");
		}
		catch (first ob) {
			cout << "\nНет такого номера!" << ob.what() << endl;
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
		default: cout << "Некорректный выбор. Повторите попытку\n";
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
		cout << "УДАЛЕНИЕ\nВыберите, что необходимо удалить:\n";
		cout << "1.Удалить 1 автомобиль\n";
		cout << "2.Удалить все автомобили\n";
		cout << "3.Назад\n";
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
		default: cout << "Некорректный выбор. Повторите попытку\n";	break;
		}
	}
}

void AdminMenu::removeCarById()
{
	int id;
	Car Car;
	memset(&Car, 0, sizeof(Car));
	cout << "Введите ID автомобиля" << endl;
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
		cout << "УДАЛЕНИЕ\nВыберите, что необходимо удалить:\n";
		cout << "1.Удалить 1 бригаду\n";
		cout << "2.Удалить все бригады\n";
		cout << "3.Назад\n";
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
		default: cout << "Некорректный выбор. Повторите попытку\n";	break;
		}
	}
}

void AdminMenu::removeTeamByCode()
{
	string code;
	Team team;
	memset(&team, 0, sizeof(team));
	cout << "Введите код бригады" << endl;
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
	cout << "Введите ID пользователя" << endl;
	cin >> id;
	Systools::checkInt(id);
	user.id = id;
	Client::getInstance().sendMessage("REMOVEONEUSER", sizeof("REMOVEONEUSER"));
	Sleep(100);
	Client::getInstance().sendMessage((char*)&user, sizeof(user));
}



