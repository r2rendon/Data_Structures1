#pragma once
#include <iostream>
#include "mangoFruit.h"
#include <vector>

using namespace std;

class mangoTree 
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	vector<mangoFruit*> mangos;
	mangoFruit* first;
	mangoFruit* last;
	int maxMangos;
	double maxWeight;
	double weight;

	mangoTree();
	mangoTree(int, double);
	int addMango(mangoFruit* m);
	int insertMango(mangoFruit* m, int position);
	int deleteMango(int position);
	void printMangoTree();
	void mergeTrees(mangoTree*);
	void menu(mangoTree&, mangoTree&, bool&);

	int getCounter();

};