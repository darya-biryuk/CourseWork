#include "Car.h"
#include "DataManager.h"

int Car::autoId = 1;

void Car::setAutoId()
{
	if (DataManager::getInstance().carIdIsValid(autoId))
	{
		id = autoId++;
	}
	else
	{
		autoId++;
		setAutoId();
	}
}

Car::Car()
{
}


Car::~Car()
{
}

void Car::setCar(string code, string bodyType, int qOfDoors, int qOfSeats, int luggageVolume, int power, int mark1, int mark2, int mark3, int id = 0)
{
	setId(id);
	setCode(code);
	setBodyType(bodyType);
	setQuantityOfDoors(qOfDoors);
	setQuantityOfSeats(qOfSeats);
	setLuggageVolume(luggageVolume);
	setPower(power);
	setMark1(mark1);
	setMark2(mark2);
	setMark3(mark3);	
}


