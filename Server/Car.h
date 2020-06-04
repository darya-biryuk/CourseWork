#pragma once
#include "BaseEntity.h"


class Car: public BaseEntity
{
private:
	char code[64];
	char bodyType[64];
	int qOfDoors;
	int qOfSeats;
	int luggageVolume;
	int power;
	int mark1;
	int mark2;
	int mark3;
	static int autoId;
public:
	Car();
	~Car();
	inline void setCode(string code) { strcpy(this->code, code.c_str()); }
	inline string getCode() { return code; }
	inline void setBodyType(string bodyType) { strcpy(this->bodyType, bodyType.c_str()); }
	string getBodyType() { return bodyType; }
	void setQuantityOfDoors(int qOfDoors) { this->qOfDoors = qOfDoors; }
	int getQuantityOfDoors() { return qOfDoors; }
	void setQuantityOfSeats(int qOfSeats) { this->qOfSeats = qOfSeats; }
	int getQuantityOfSeats() { return qOfSeats; }
	void setLuggageVolume(int luggageVolume) { this->luggageVolume = luggageVolume; }
	int getLuggageVolume() { return luggageVolume; }
	void setPower(int power) { this->power = power; }
	int getPower() { return power; }
	void setMark1(int mark1) { this->mark1 = mark1; }
	int getMark1() { return mark1; }
	void setMark2(int mark2) { this->mark2 = mark2; }
	int getMark2() { return mark2; }
	void setMark3(int mark3) { this->mark3 = mark3; }
	int getMark3() { return mark3; }
	void setCar(string, string, int, int, int, int, int, int, int, int);
	void setAutoId(); 
};

