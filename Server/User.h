#pragma once
#include <string>
#include <vector>

using namespace std;

class User
{
private:
	int id;
	static int autoId;
	char login[64];
	char password[64];
	int access;
public:
	User();
	~User();
	inline void setId(int id) { this->id = id; }
	inline int getId() { return id; }
	void setAccess(int access) { this->access = access; }
	int getAccess() { return access; }
	inline void setLogin(string login) { strcpy(this->login, login.c_str()); }
	inline char* getLogin() { return login; }
	inline void setPassword(string password) { strcpy(this->password, password.c_str()); }
	inline char* getPassword() { return password; }
	void setUser(string, string, int id = 0);
	void setAutoId();
};

