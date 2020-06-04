#pragma once
#include "Client.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Structures.h"
#include "SysTools.h"
#include "Table.h"



#define MSG_ADDCAR "ADDCAR"

using namespace std;

class Menu
{
protected:
	int loggedUserId;
public:
	Menu();
	~Menu();
	
	void printCars(vector<Car> cars);
	void printTeams(vector<Team> teams);
	void printUser(vector<User> users);

	vector<Car> downloadCarData();
	vector<Team> downloadTeamData();
	vector<User> downloadUserData();
		//void loginMenu();

	//void sortName(vector<Client> clients);
	virtual void run() = 0;
	//friend ostream& operator<<(ostream& out, Car& obj);
	friend ostream& operator<<(ostream& out, Team& obj);
	friend ostream& operator<<(ostream& out, User& obj);
};