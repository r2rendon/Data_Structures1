#pragma once
#include <iostream>
#include "mangoFruit.h"

using namespace std;

class mangoTree 
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	mangoFruit* first;
	mangoFruit* last;

	mangoTree();
	int addMango(mangoFruit* m);
	int insertMango(mangoFruit* m, int position);
	int deleteMango(int position);
	void printMangoTree();

	int getCounter();

};