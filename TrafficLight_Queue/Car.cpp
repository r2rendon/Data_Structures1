#include "Car.h"

Car::Car()
{
	setCarBrand(NONE);
	setPeople(0);
}

Car::Car(int p, carBrand cb, string d)
{
	setCarBrand(cb);
	setPeople(p);
	this->driver = d;
}

void Car::setCarBrand(carBrand cb)
{
	this->cBrand = cb;
}

carBrand Car::getCarBrand()
{
	return this->cBrand;
}

void Car::setPeople(int p)
{
	this->cPeople = p;

}

int Car::getPeople()
{
	return this->cPeople;
}

string Car::getDriver()
{
	return this->driver;
}

Car::~Car()
{
}
