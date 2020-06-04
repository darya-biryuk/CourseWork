#pragma once
class Authorizer
{
	Authorizer(Authorizer const&) = delete;
	Authorizer &operator= (Authorizer const&) = delete;
	Authorizer();
	~Authorizer();
public:
	static Authorizer &getInstance()
	{
		static Authorizer auth;
		return auth;
	}
	void authMenu();
	void login();
	void loginMenu();
	void signup();
};

