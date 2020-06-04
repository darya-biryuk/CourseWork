#pragma once

#include "Menu.h"


class UserMenu : public Menu
{
public:
	UserMenu();
	~UserMenu();
	void run();
	void print(vector<Car>, vector<Team>);
	void taskMenu(vector<Car> cars);
	//void taskMenu();
};

