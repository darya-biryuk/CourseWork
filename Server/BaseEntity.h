#pragma once
#include <iostream>

using namespace std;

class BaseEntity
{
protected:
	int id;
public:
	inline void setId(int id) { this->id = id; }
	inline int getId() { return id; }
	BaseEntity();
	~BaseEntity();
};

