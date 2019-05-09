#include <string>

using namespace std;

enum carBrand
{
	NONE=0, TOYOTA, KIA, TESLA, NISSAN, LAMBORGHINI, HONDA, MITSUBISHI, MASERATI
};

class Car
{
private:
	int cPeople;
	carBrand cBrand;
	string driver;

public:
	Car();
	Car(int, carBrand, string);
	~Car();

	Car* next;

	void setPeople(int);
	int getPeople();

	void setCarBrand(carBrand);
	carBrand getCarBrand();

	string getDriver();
};

