#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include "Car.h"
#include "Team.h"
#include "User.h"
#include "Systools.h"
#include "Weight.h"

using namespace std;

#define TEAMS_FILE "data\\teams.txt"
#define CARS_FILE "data\\cars.txt"
#define USERS_FILE "data\\users.txt"
#define WEIGHT_FILE "data\\weight.txt"


class DataManager
{
private:
	vector<Team> teams;
	vector<Car> cars;
	vector<User> users;
	DataManager(DataManager const&) = delete;
	DataManager &operator= (DataManager const&) = delete;
	DataManager();
	~DataManager();
public:
	static DataManager &getInstance()
	{
		static DataManager dm;
		return dm;
	}
	bool userIdIsValid(int id);

	void addTeam(Team);
	void addCar(Car);
	void addUser(User);

	void loadTeams();
	void loadCars();
	void loadUsers();

	void saveTeams();
	void saveCars();
	void saveUsers();

	void removeAllTeams();
	void removeAllCars();
	void removeAllUsers();

	void refreshTeams();
	void refreshCars();
	void refreshUsers();

	void editCar(int, Car);
	void editUser(int, User);
	void editTeam(string, Team);

	bool removeCar(int);
	bool removeUser(int);
	bool removeTeam(string);

	vector<Team> getTeams() { return teams; }
	vector<Car> getCars() { return cars; }
	vector<User> getUsers() { return users; }
//	vector<Weight> getWeight() { return weight; }
	User getUserById(int uid);

	vector<Weight> preferenceMethod(int, int, int);
	bool carIdIsValid(int id);
};

