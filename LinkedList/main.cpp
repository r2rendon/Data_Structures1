#include <iostream>
#include "mangoTree.h"
#include "mangoFruit.h"

using namespace std;

int main()
{
	bool exit = false;
	mangoTree mTree;
	int option = 0, test = 0, pos = 0;
	double weight = 0;

	while (!exit)
	{
		cout << "\n\n\n--> M A N G O  T R E E <--";
		cout << "\n\n1. Add a Mango Fruit to the tree";
		cout << "\n2. Insert a Mango Fruit to the tree";
		cout << "\n3. Delete a Mango Fruit from the tree";
		cout << "\n4. Exit";

		cout << "\n\nPlease type the desired option: ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			cout << "-> Add Mango <-";
			cout << "\nInsert the weight of the mango to insert: ";
			cin >> weight;

			mangoFruit* mAdd = new mangoFruit(weight);
			test = mTree.addMango(mAdd);

			if (test == 5)
			{
				cout << "\t\tMango added!!";
			}
		}
			break;

		case 2:
		{
			cout << "-> Insert Mango <-";
			cout << "\nInsert the weight of the mango to insert: ";
			cin >> weight;

			cout << "\nInsert the position to insert the fruit in the tree: ";
			cin >> pos;

			mangoFruit* mInsert = new mangoFruit(weight);
			test = mTree.insertMango(mInsert, pos);

			switch (test)
			{
			case (-1):
				cout << "\t\tThe position inserted doesn't exist in the tree.";
				break;

			case (-2):
				cout << "\t\tThe position inserted is negative, therefore it doesn't exist in the tree.";
				break;

			case 0:
				cout << "\t\tMango added to the tree through add.";
				break;

			case (-3):
				cout << "\t\tMango couldn't be added to the tree";
				break;

			case 1:
				cout << "\t\tMango inserted successfully";
				break;

			default:
				cout << "\t\tPosition or weight inserted not valid.";
				break;
			}
		}
			break;

		case 3:

			break;

		case 4:
			exit = true;
			break;

		default:
			cout << "The option entered is not valid.";
			break;
		}

	}

	system("pause");
}