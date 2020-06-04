#include "Client.h"
#include <string>


Client::Client()
{
}


Client::~Client()
{
}

int Client::recvMessage(void* msg)
{
	int msg_size;
	recv(Connection, (char*)&msg_size, sizeof(int), NULL);
	memset(msg, 0, msg_size);
	recv(Connection, (char*)msg, msg_size, NULL);
	return msg_size;
}

void Client::sendMessage(char * msg, int msg_size)
{
	send(Connection, (char*)&msg_size, sizeof(int), NULL);
	send(Connection, msg, msg_size, NULL);
}

int Client::setConnection()
{
	int port;
	string ip_addr;

	cout << "Enter server address: ";
	cin >> ip_addr;

	cout << "Port: ";
	cin >> port;


	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		return 1; // Error: failed connect to server
	}
	return 0;
}

int Client::closeConnection()
{
	return closesocket(Connection);
}
