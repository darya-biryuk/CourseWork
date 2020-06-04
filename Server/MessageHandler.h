#pragma once
#include "Server.h"
#include <iostream>
#include <map>

#define MESSAGE_ADDCAR "ADDCAR"
#define MESSAGE_ADDTEAM "ADDTEAM"
#define MESSAGE_ADDUSER "ADDUSER"

#define MESSAGE_EDITCAR "EDITCAR"
#define MESSAGE_EDITTEAM "EDITTEAM"
#define MESSAGE_EDITUSER "EDITUSER"

#define MESSAGE_REMOVEONECAR "REMOVEONECAR"
#define MESSAGE_REMOVEALLCARS "REMOVEALLCARS"

#define MESSAGE_REMOVEONETEAM "REMOVEONETEAM"
#define MESSAGE_REMOVEALLTEAMS "REMOVEALLTEAMS"

#define MESSAGE_REMOVEONEUSER "REMOVEONEUSER"

#define MESSAGE_PRINTCARS "PRINTCARS"
#define MESSAGE_PRINTTEAMS "PRINTTEAMS"
#define MESSAGE_PRINTUSERS "PRINTUSERS"

#define MESSAGE_LOGIN "LOGIN"
#define MESSAGE_SIGNUP "SIGNUP"

#define MESSAGE_TASK "TASK"
 
using namespace std;

class MessageHandler
{
private:
	map<string, void(MessageHandler::*)()> commandMap
	{
		{MESSAGE_ADDCAR, &MessageHandler::runAddCar},
		{MESSAGE_ADDTEAM, &MessageHandler::runAddTeam},
		{MESSAGE_ADDUSER, &MessageHandler::runAddUser},
		{MESSAGE_EDITCAR, &MessageHandler::runEditCar},
		{MESSAGE_EDITTEAM, &MessageHandler::runEditTeam},
		{MESSAGE_EDITUSER, &MessageHandler::runEditUser},
		{MESSAGE_REMOVEONECAR, &MessageHandler::runRemoveCarById},
		{MESSAGE_REMOVEALLCARS, &MessageHandler::runRemoveAllCars},
		{MESSAGE_REMOVEONETEAM, &MessageHandler::runRemoveTeamByCode},
		{MESSAGE_REMOVEALLTEAMS, &MessageHandler::runRemoveAllTeams},
		{MESSAGE_REMOVEONEUSER, &MessageHandler::runRemoveUserById},
		{MESSAGE_PRINTCARS, &MessageHandler::runPrintCars},
		{MESSAGE_PRINTTEAMS, &MessageHandler::runPrintTeams},
		{MESSAGE_PRINTUSERS, &MessageHandler::runPrintUsers},
		{MESSAGE_LOGIN, &MessageHandler::runLogin},
		{MESSAGE_TASK, &MessageHandler::runTask}
	};
	void(MessageHandler::*callback)();
	MessageHandler(MessageHandler const&) = delete;
	MessageHandler &operator= (MessageHandler const&) = delete;
	MessageHandler();
	~MessageHandler();
public:
	static MessageHandler &getInstance()
	{
		static MessageHandler dm;
		return dm;
	}
	void runAddCar();
	void runAddTeam();
	void runAddUser();

	void runEditCar();
	void runEditTeam();
	void runEditUser();

	void runRemoveCarById();
	void runRemoveAllCars();

	void runRemoveTeamByCode();
	void runRemoveAllTeams();

	void runRemoveUserById();

	void runPrintCars();
	void runPrintTeams();
	void runPrintUsers();

	void runLogin();

	void runTask();

	void executeCommand(string);
};

