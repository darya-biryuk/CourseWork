#include "DataManager.h"

using namespace std;

DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

bool DataManager::userIdIsValid(int id)
{
	for (auto i : users)
	{
		if (i.getId() == id) return false;
	}
	return true;
}

void DataManager::addTeam(Team newTeam)
{
	fstream teamFile;
	teamFile.open(TEAMS_FILE, ios::app);
	if (teamFile.is_open())
	{
		teamFile << "[Team]" << endl;
		teamFile << "code=" << newTeam.getCode() << endl;
		teamFile << "qpeople=" << newTeam.getQuantityOfPeople() << endl;
		teamFile << "qhours=" << newTeam.getQuantityOfHours() << endl;
		teamFile << "salary=" << newTeam.getSalary() << endl;
		teamFile << "empday=" << newTeam.getEmploymentDay() << endl;
		teamFile << "empmonth=" << newTeam.getemploymentMonth() << endl;
		teamFile << "empyear=" << newTeam.getemploymentYear() << endl;
		teamFile << "[End]" << endl;
	}
	teamFile.close();
	refreshTeams();
}

void DataManager::addCar(Car newCar)
{
	fstream carsFile;
	carsFile.open(CARS_FILE, ios::app);
	if (carsFile.is_open())
	{
		carsFile << "[Car]" << endl;
		carsFile << "id=" << newCar.getId() << endl;
		carsFile << "code=" << newCar.getCode() << endl;
		carsFile << "body=" << newCar.getBodyType() << endl;
		carsFile << "qdoors=" << newCar.getQuantityOfDoors() << endl;
		carsFile << "qseats=" << newCar.getQuantityOfSeats() << endl;
		carsFile << "luggage=" << newCar.getLuggageVolume() << endl;
		carsFile << "power=" << newCar.getPower() << endl;
		carsFile << "mark1=" << newCar.getMark1() << endl;
		carsFile << "mark2=" << newCar.getMark2() << endl;
		carsFile << "mark3=" << newCar.getMark3() << endl;
		carsFile << "[End]" << endl;
	}
	carsFile.close();
	refreshCars();
}

void DataManager::addUser(User newUser)
{
	fstream userFile;
	userFile.open(USERS_FILE, ios::app);
	if (userFile.is_open())
	{
		userFile << "[User]" << endl;
		userFile << "id=" << newUser.getId() << endl;
		userFile << "login=" << newUser.getLogin() << endl;
		userFile << "password=" << newUser.getPassword() << endl;
		userFile << "access=2" << endl;
		userFile << "[End]" << endl;
	}
	userFile.close();
	refreshUsers();
}

void DataManager::loadTeams()
{
	fstream teamFile;
	teamFile.open(TEAMS_FILE, ios::in);
	if (!teamFile) cout << "ERROR: can't open " << TEAMS_FILE << endl;
	string line;
	while (getline(teamFile, line))
	{
		if (line == "[Team]")
		{
			Team team;
			while (getline(teamFile, line))
			{
				vector<string> result;
				result = Systools::getTokens(line, "=");
				if (line == "[End]")
					break;
				else if (result.size() <= 1) continue;
				else if (result[0] == "code")
				{
					team.setCode(result[1]);
				}
				else if (result[0] == "qpeople")
				{
					team.setQuantityOfPeople(stoi(result[1]));
				}
				else if (result[0] == "qhours")
				{
					team.setQuantityOfHours(stoi(result[1]));
				}
				else if (result[0] == "salary")
				{
					team.setSalary(stoi(result[1]));
				}
				else if (result[0] == "empday")
				{
					team.setEmploymentDay(stoi(result[1]));
				}
				else if (result[0] == "empmonth")
				{
					team.setEmploymentMonth(stoi(result[1]));
				}
				else if (result[0] == "empyear")
				{
					team.setEmploymentYear(stoi(result[1]));
				}
			}
			teams.push_back(team);
			memset(&team, 0, sizeof(team));
		}
	}
	teamFile.close();
}

void DataManager::loadCars()
{
	fstream carsFile;
	carsFile.open(CARS_FILE, ios::in);
	if (!carsFile) cout << "ERROR: can't open " << CARS_FILE << endl;
	string line;
	while (getline(carsFile, line))
	{
		if (line == "[Car]")
		{
			Car car;
			while (getline(carsFile, line))
			{
				vector<string> result;
				result = Systools::getTokens(line, "=");
				if (line == "[End]")
					break;
				else if (result.size() <= 1) continue;
				else if (result[0] == "code")
				{
					car.setCode(result[1]);
				}
				else if (result[0] == "body")
				{
					car.setBodyType(result[1]);
				}
				else if (result[0] == "qdoors")
				{
					car.setQuantityOfDoors(stoi(result[1]));
				}
				else if (result[0] == "qseats")
				{
					car.setQuantityOfSeats(stoi(result[1]));
				}
				else if (result[0] == "luggage")
				{
					car.setLuggageVolume(stoi(result[1]));
				}
				else if (result[0] == "power")
				{
					car.setPower(stoi(result[1]));
				}
				else if (result[0] == "mark1")
				{
					car.setMark1(stoi(result[1]));
				}
				else if (result[0] == "mark2")
				{
					car.setMark2(stoi(result[1]));
				}
				else if (result[0] == "mark3")
				{
					car.setMark3(stoi(result[1]));
				}
				else if (result[0] == "id")
				{
					car.setId(stoi(result[1]));
				}
			}
			cars.push_back(car);
			memset(&car, 0, sizeof(car));
		}
	}
	carsFile.close();
}

void DataManager::loadUsers()
{
	fstream usersFile;
	usersFile.open(USERS_FILE, ios::in);
	if (!usersFile) cout << "ERROR: can't open " << USERS_FILE << endl;
	string line;
	while (getline(usersFile, line))
	{
		if (line == "[User]")
		{
			User user;
			while (getline(usersFile, line))
			{
				vector<string> result;
				result = Systools::getTokens(line, "=");
				if (line == "[End]")
					break;
				else if (result.size() <= 1) continue;
				else if (result[0] == "id")
				{
					user.setId(stoi(result[1]));
				}
				else if (result[0] == "login")
				{
					user.setLogin(result[1]);
				}
				else if (result[0] == "password")
				{
					user.setPassword(result[1]);
				}
				else if (result[0] == "access")
				{
					user.setAccess(stoi(result[1]));
				}
			}
			users.push_back(user);
			memset(&user, 0, sizeof(user));
		}
	}
	usersFile.close();
}

void DataManager::saveTeams()
{
	fstream teamFile;
	teamFile.open(TEAMS_FILE, ios::out);
	if (teamFile.is_open())
	{
		for (auto i : teams)
		{
			teamFile << "[Team]" << endl;
			teamFile << "code=" << i.getCode() << endl;
			teamFile << "qpeople=" << i.getQuantityOfPeople() << endl;
			teamFile << "qhours=" << i.getQuantityOfHours() << endl;
			teamFile << "salary=" << i.getSalary() << endl;
			teamFile << "empday=" << i.getEmploymentDay() << endl;
			teamFile << "empmonth=" << i.getemploymentMonth() << endl;
			teamFile << "empyear=" << i.getemploymentYear() << endl;
			teamFile << "[End]" << endl;
		}
	}
	teamFile.close();
	refreshTeams();
}

void DataManager::saveCars()
{
	fstream carsFile;
	carsFile.open(CARS_FILE, ios::out);
	if (carsFile.is_open())
	{
		for (auto i : cars)
		{
			carsFile << "[Car]" << endl;
			carsFile << "id=" << i.getId() << endl;
			carsFile << "code=" << i.getCode() << endl;
			carsFile << "body=" << i.getBodyType() << endl;
			carsFile << "qdoors=" << i.getQuantityOfDoors() << endl;
			carsFile << "qseats=" << i.getQuantityOfSeats() << endl;
			carsFile << "luggage=" << i.getLuggageVolume() << endl;
			carsFile << "power=" << i.getPower() << endl;
			carsFile << "mark1=" << i.getMark1() << endl;
			carsFile << "mark2=" << i.getMark2() << endl;
			carsFile << "mark3=" << i.getMark3() << endl;
			carsFile << "[End]" << endl;
		}
	}
	carsFile.close();
	refreshCars();
}

void DataManager::saveUsers()
{
	fstream userFile;
	userFile.open(USERS_FILE, ios::out);
	if (userFile.is_open())
	{
		for (auto i : users)
		{
			userFile << "[User]" << endl;
			userFile << "id=" << i.getId() << endl;
			userFile << "login=" << i.getLogin() << endl;
			userFile << "password=" << i.getPassword();
			userFile << "access=" << i.getAccess() << endl;
			userFile << "[End]" << endl;
		}
	}
	userFile.close();
	refreshUsers();
}

void DataManager::removeAllTeams()
{
	fstream teamFile;
	teamFile.open(TEAMS_FILE, ios::out);
	teamFile.close();
	refreshTeams();
}

void DataManager::removeAllCars()
{
	fstream carsFile;
	carsFile.open(CARS_FILE, ios::out);
	carsFile.close();
	refreshCars();
}

void DataManager::removeAllUsers()
{
	fstream usersFile;
	usersFile.open(USERS_FILE, ios::out);
	usersFile.close();
	refreshUsers();
}

void DataManager::refreshTeams()
{
	teams.clear();
	loadTeams();
}

void DataManager::refreshCars()
{
	cars.clear();
	loadCars();
}

void DataManager::refreshUsers()
{
	users.clear();
	loadUsers();
}

void DataManager::editCar(int id, Car editCar)
{
	refreshCars();
	cout << "Processing edit car request...";
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].getId() == id)
		{
			cars.erase(cars.begin() + i);
			cars.push_back(editCar);
			saveCars();
		}
	}
	cout << "OK" << endl;
}

void DataManager::editUser(int id, User editUser)
{
	cout << "Processing edit user request...";
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getId() == id)
		{
			users.erase(users.begin() + i);
			users.push_back(editUser);
			saveUsers();
		}
	}
	cout << "OK" << endl;
}

void DataManager::editTeam(string code , Team editTeam)
{
	cout << "Processing edit team request...";
	int size;
	size = teams.size();
	for (int i = 0; i < teams.size(); i++)
	{
		if (teams[i].getCode() == code)
		{
			teams.erase(teams.begin() + i);
			teams.push_back(editTeam);
			saveTeams();
		}
	}
	cout << "OK" << endl;
}

bool DataManager::removeCar(int id)
{
	for (int i = 0; i < cars.size(); i++)
	{
		if (id == cars[i].getId())
		{
			cars.erase(cars.begin() + i);
			saveCars();
			return true;
		}
	}
	return false;
}

bool DataManager::removeUser(int id)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (id == users[i].getId())
		{
			users.erase(users.begin() + i);
			saveUsers();
			return true;
		}
	}
	return false;
}

bool DataManager::removeTeam(string code)
{
	for (int i = 0; i < teams.size(); i++)
	{
		if (code == teams[i].getCode())
		{
			teams.erase(teams.begin() + i);
			saveTeams();
			return true;
		}
	}
	return false;
}

User DataManager::getUserById(int uid)
{
	for (auto i : users)
	{
		if (i.getId() == uid)
			return i;
	}
	return User();
}

vector<Weight> DataManager::preferenceMethod(int id1, int id2, int id3)
{
	vector<Weight> weight;
	int z11 = 0, z12 = 0, z13 = 0, z21 = 0, z22 = 0, z23 = 0, z31 = 0, z32 = 0, z33 = 0;
	for (auto i : cars)
	{
		if (i.getId() == id1)
		{
			z11 = i.getMark1();
			z12 = i.getMark2();
			z13 = i.getMark3();
		}
		if (i.getId() == id2)
		{
			z21 = i.getMark1();
			z22 = i.getMark2();
			z23 = i.getMark3();
		}
		if (i.getId() == id3)
		{
			z31 = i.getMark1();
			z32 = i.getMark2();
			z33 = i.getMark3();
		}
	}

	fstream weightFile;
	weightFile.open(WEIGHT_FILE, ios::out);
	weightFile << "-------Матрица оценок экспертов-------" << endl;
	weightFile << "--------------------------------------" << endl;
	weightFile << "- Эксперт 1 - Эксперт 2 - Эксперт 3 - " << endl;
	weightFile << "------ " << z11 << " -------- " << z12 << " -------- " << z13 << " ------ " << endl;
	weightFile << "------ " << z21 << " -------- " << z22 << " -------- " << z23 << " ------ " << endl;
	weightFile << "------ " << z31 << " -------- " << z32 << " -------- " << z33 << " ------ " << endl;
	weightFile << "--------------------------------------" << endl;
	weightFile << endl;

	if (z11 == 0 || z12 == 0 || z13 == 0 || z21 == 0 || z22 == 0 || z23 == 0 || z31 == 0 || z32 == 0 || z33 == 0)
	{
		cout << "Error: client specified incorrect id" << endl;
	}
	else
	{
		z11 = 3 - z11;
		z12 = 3 - z12;
		z13 = 3 - z13;
		z21 = 3 - z21;
		z22 = 3 - z22;
		z23 = 3 - z23;
		z31 = 3 - z31;
		z32 = 3 - z32;
		z33 = 3 - z33;

		weightFile << "Матрица нормированных оценок экспертов" << endl;
		weightFile << "--------------------------------------" << endl;
		weightFile << "- Эксперт 1 - Эксперт 2 - Эксперт 3 - " << endl;
		weightFile << "------ " << z11 << " -------- " << z12 << " -------- " << z13 << " ------ " << endl;
		weightFile << "------ " << z21 << " -------- " << z22 << " -------- " << z23 << " ------ " << endl;
		weightFile << "------ " << z31 << " -------- " << z32 << " -------- " << z33 << " ------ " << endl;
		weightFile << "--------------------------------------" << endl;
		weightFile << endl;

		int K1 = z11 + z12 + z13;
		int K2 = z21 + z22 + z23;
		int K3 = z31 + z32 + z33;

		int summ = K1 + K2 + K3;

		float W1 = (float)K1 / summ;
		float W2 = (float)K2 / summ;
		float W3 = (float)K3 / summ;

		weightFile << "Веса целей: " << endl;
		weightFile << "Автомобиль 1: " << W1 << endl;
		weightFile << "Автомобиль 2: " << W2 << endl;
		weightFile << "Автомобиль 3: " << W3 << endl;
		weightFile.close();
		
		Weight w1, w2, w3;
		w1.setWeight(W1);
		w2.setWeight(W2);
		w3.setWeight(W3);
	
		weight.push_back(w1);
		weight.push_back(w2);
		weight.push_back(w3);
		
		cout << "W1 = " << W1 << endl;
		cout << "W2 = " << W2 << endl;
		cout << "W3 = " << W3 << endl;
	}
	
	return weight;
}

bool DataManager::carIdIsValid(int id)
{
	for (auto i : cars)
	{
		if (i.getId() == id) return false;
	}
	return true;
}
