#include <iostream>
#include "mangoTree.h"

using namespace std;

int main()
{
	mangoFruit* fruit1 = new mangoFruit(20.5);
	mangoFruit* fruit2 = new mangoFruit(10.5);

	fruit1->next = fruit2;
	fruit2->prev = fruit1;

	cout << fruit2->prev->getWeight();

	system("pause");
}