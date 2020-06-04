#include "MessageHandler.h"
#include "Authorizer.h"
#include "DataManager.h"
#include "Car.h"


void MessageHandler::runAddCar()
{
	cout << "Adding car..." << endl;
	Car car;
	Server::getInstance().recvMessage(&car);
	car.setAutoId();
	DataManager::getInstance().addCar(car);
}

void MessageHandler::runAddTeam()
{
	cout << "Adding team..." << endl;
	Team team;
	Server::getInstance().recvMessage(&team);
	DataManager::getInstance().addTeam(team);
}

void MessageHandler::runAddUser()
{
	cout << "Adding user..." << endl;
	User user;
	Server::getInstance().recvMessage(&user);
	user.setAutoId();
	DataManager::getInstance().addUser(user);
}

void MessageHandler::runEditCar()
{
	cout << "Editing car..." << endl;
	Car editCar;
	Server::getInstance().recvMessage(&editCar);
	int id;
	id = editCar.getId();
	DataManager::getInstance().refreshCars();
	DataManager::getInstance().editCar(id, editCar);
}

void MessageHandler::runEditTeam()
{
	cout << "Editing team..." << endl;
	Team editTeam;
	Server::getInstance().recvMessage(&editTeam);
	DataManager::getInstance().refreshTeams();
	DataManager::getInstance().editTeam(editTeam.getCode(), editTeam);
}

void MessageHandler::runEditUser()
{
	cout << "Editing user..." << endl;
	User editUser;
	Server::getInstance().recvMessage(&editUser);
	DataManager::getInstance().refreshUsers();
	DataManager::getInstance().editUser(editUser.getId(), editUser);
}

void MessageHandler::runRemoveCarById()
{
	Car car;
	Server::getInstance().recvMessage(&car);
	cout << "Removing car " << car.getCode() << "..." << endl;
	DataManager::getInstance().removeCar(car.getId());
}

void MessageHandler::runRemoveAllCars()
{
	Car car;
	Server::getInstance().recvMessage(&car);
	cout << "Removing all cars" << endl;
	DataManager::getInstance().removeAllCars();
}

void MessageHandler::runRemoveTeamByCode()
{
	Team team;
	Server::getInstance().recvMessage(&team);
	cout << "Removing team " << team.getCode() << "..." << endl;
	DataManager::getInstance().removeTeam(team.getCode());
}

void MessageHandler::runRemoveAllTeams()
{
	Team team;
	Server::getInstance().recvMessage(&team);
	cout << "Removing all teams" << endl;
	DataManager::getInstance().removeAllTeams();
}

void MessageHandler::runRemoveUserById()
{
	User user;
	Server::getInstance().recvMessage(&user);
	cout << "Removing user " << user.getLogin() << "..." << endl;
	DataManager::getInstance().removeUser(user.getId());
}

void MessageHandler::runPrintCars()
{
	const char* msg = reinterpret_cast<const char *>(DataManager::getInstance().getCars().data());
	Server::getInstance().sendMessage(msg, DataManager::getInstance().getCars().size() * sizeof(Car));
}

void MessageHandler::runPrintTeams()
{
	const char* msg = reinterpret_cast<const char *>(DataManager::getInstance().getTeams().data());
	Server::getInstance().sendMessage(msg, DataManager::getInstance().getTeams().size() * sizeof(Team));
}

void MessageHandler::runPrintUsers()
{
	const char* msg = reinterpret_cast<const char *>(DataManager::getInstance().getUsers().data());
	Server::getInstance().sendMessage(msg, DataManager::getInstance().getUsers().size() * sizeof(User));
}

void MessageHandler::runLogin()
{
	cout << "Login..." << endl;
	User user;
	Server::getInstance().recvMessage(&user);
	Authorizer::getInstance().login(user.getLogin(), user.getPassword());
}

void MessageHandler::runTask()
{
	cout << "Calculating task..." << endl;
	Car car1, car2, car3;
	Server::getInstance().recvMessage(&car1);
	Server::getInstance().recvMessage(&car2);
	Server::getInstance().recvMessage(&car3);
	cout << car1.getId() << endl;
	cout << car2.getId() << endl;
	cout << car3.getId() << endl;
	vector<Weight> weight = DataManager::getInstance().preferenceMethod(car1.getId(), car2.getId(), car3.getId());
	const char* msg = reinterpret_cast<const char *>(weight.data());
	Server::getInstance().sendMessage(msg, weight.size() * sizeof(Weight));
}

void MessageHandler::executeCommand(string message)
{
	auto result = commandMap.find(message);
	if (result == commandMap.end())
	{
		//обработать неопознанную команду
		cout << "Error: Invalid command" << endl;
		return;
	}

	cout << "Executing " << result->first << " command" << endl;
	callback = result->second;
	(this->*callback)();
}

MessageHandler::MessageHandler()
{

}


MessageHandler::~MessageHandler()
{
}
