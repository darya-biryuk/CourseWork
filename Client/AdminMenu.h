#pragma once
#include "Menu.h"


class AdminMenu:public Menu
{
public:
	AdminMenu();
	~AdminMenu();
	void run();
	void print(vector<Car> cars, vector<Team> teams, vector<User> users);
	void add();
	void addCarMenu();
	void addTeamMenu();
	void addUserMenu();

	void edit();
	void editCarMenu();
	void editTeamMenu();
	void editUserMenu();

	void removeMenu();

	void removeCarMenu();
	void removeCarById();

	void removeTeamMenu();
	void removeTeamByCode();

	void removeUserById();


};

