#include <string>

enum carBrand
{
	NONE=0, TOYOTA, KIA, TESLA, NISSAN, LAMBORGHINI, HONDA, MITSUBISHI, MASERATI
};

class Car
{
private:
	int cPeople;
	carBrand cBrand;

public:
	Car();
	Car(int, carBrand);
	~Car();

	Car* next;

	void setPeople(int);
	int getPeople();

	void setCarBrand(carBrand);
	carBrand getCarBrand();
};

