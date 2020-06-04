#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable: 4996)
using namespace std;


class Server
{
private:
	SOCKET newConnection;
	Server(Server const&) = delete;
	Server &operator= (Server const&) = delete;
	Server();
	~Server();

	int port;
public:
	static Server &getInstance()
	{
		static Server dm;
		return dm;
	}
	int recvMessage(void* msg);
	void sendMessage(const char* msg, int msg_size);
	int setConnection();
	int closeConnection();
};

