#include "Car.h"

Car::Car()
{
	setCarBrand(NONE);
	setPeople(0);
}

Car::Car(int p, carBrand cb)
{
	setCarBrand(cb);
	setPeople(p);
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

Car::~Car()
{
}
