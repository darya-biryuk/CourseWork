#pragma once
#include <winsock2.h>
#pragma comment(lib, "WS2_32.Lib")

#include "Structures.h"

#pragma warning(disable: 4996)

class Client
{
private:
	SOCKET Connection;
	Client(Client const&) = delete;
	Client &operator= (Client const&) = delete;
	Client();
	~Client();
public:
	static Client &getInstance()
	{
		static Client dm;
		return dm;
	}
	int recvMessage(void * msg);
	void sendMessage(char* msg, int msg_size);
	int setConnection();
	int closeConnection();
};

