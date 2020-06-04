#include "User.h"
#include "DataManager.h"

int User::autoId = 1;

User::User()
{
}

void User::setAutoId()
{
	if (DataManager::getInstance().userIdIsValid(autoId))
	{
		id = autoId++;
	}
	else
	{
		autoId++;
		setAutoId();
	}
}

User::~User()
{
}

void User::setUser(string login, string password, int id)
{
	if (!id)
	{
		setAutoId();
	}
	else
	{
		setId(id);
	}
	setLogin(login);
	setPassword(password);
}
