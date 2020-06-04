#include "Server.h"



Server::Server()
{
	port = 9900;
	cout << "Server is running on localhost:" << port << endl;
}


Server::~Server()
{
}

int Server::recvMessage(void* msg)
{
	int msg_size;
	int result = recv(newConnection, (char*)&msg_size, sizeof(int), NULL);
	if (result == 0)
	{
		std::cout << "Client was disconnected." << std::endl;
		return -1;
	} 
	else if (result < 0)
	{
		std::cout << "Receive error " << errno << ": " << std::strerror(errno) << std::endl;
		return -1;
	}

	memset(msg, 0, msg_size);

	result = recv(newConnection, (char*)msg, msg_size, NULL);
	if (result == 0)
	{
		std::cout << "Client was disconnected." << std::endl;
		return -1;
	}
	else if (result < 0)
	{
		std::cout << "Receive error " << errno << ": " << std::strerror(errno) << std::endl;
		return -1;
	}

	return msg_size;
}

void Server::sendMessage(const char * msg, int msg_size)
{
	send(newConnection, (char*)&msg_size, sizeof(int), NULL);
	send(newConnection, msg, msg_size, NULL);
}

int Server::closeConnection()
{
	closesocket(newConnection);
	WSACleanup();

	return 0;
}

int Server::setConnection()
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	cout << "Listening for a new client..." << endl;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

	if (newConnection == 0) {
		std::cout << "Error #2\n";
	}
	else {
		std::cout << "Client Connected!\n";
	}
	return 0;
}
