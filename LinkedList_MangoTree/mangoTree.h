#pragma once
#include <iostream>
#include "mangoFruit.h"

using namespace std;

class mangoTree 
{
public:
	mangoFruit* first;
	mangoFruit* last;

	mangoTree();
	int addMango(mangoFruit m);
	int insertMango(mangoFruit m, int position);
	int deleteMango(int position);
	void printMangoTree();

};