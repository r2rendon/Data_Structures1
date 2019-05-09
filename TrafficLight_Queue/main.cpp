#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	bool exit = false;
	int option, people, cB;
	carBrand cBrand = NONE;
	string dName;

	Queue traffic;

	while (!exit)
	{
		cout << "\n\n==> T R A F F I C  L I G H T <==";
		cout << "\n1. Add car to the queue";
		cout << "\n2. Remove a car from the queue";
		cout << "\n3. Exit";

		cout << "\nPlease type the option's number: ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "\n\n=> QUEUE CAR <=";
			cout << "\nPlease type the amount of people in the car: ";
			cin >> people;

			cout << "\nPlease type the driver's name: ";
			cin >> dName;

			cout << "\n1. Toyota";
			cout << "\n2. Kia";
			cout << "\n3. Tesla";
			cout << "\n4. Nissan";
			cout << "\n5. Lamborghini";
			cout << "\n6. Honda";
			cout << "\n7. Mitsubishi";
			cout << "\n8. Maserati";
			cout << "\nPlease type the car's brand: ";
			cin >> cB;

			switch (cB)
			{
			case 1:
				cBrand = TOYOTA;
				break;

			case 2:
				cBrand = KIA;
				break;

			case 3:
				cBrand = TESLA;
				break;

			case 4:
				cBrand = NISSAN;
				break;

			case 5:
				cBrand = LAMBORGHINI;
				break;

			case 6:
				cBrand = HONDA;
				break;

			case 7:
				cBrand = MITSUBISHI;
				break;

			case 8:
				cBrand = MASERATI;
				break;
			}

			Car* newCar = new Car(people, cBrand, dName);
			traffic.cQueue(newCar);
			break;
		}

		case 2:
			cout << "\n\n=> DEQUEUE CAR <=";
			cout << "\n"+traffic.first->getDriver()+" has been dequeued!!";
			traffic.cDequeue();
			break;

		case 3:
			exit = true;
			break;

		default:
			cout << "Typed option not valid.";
			break;
		}
	}
}