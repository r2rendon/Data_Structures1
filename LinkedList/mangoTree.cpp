#include "mangoTree.h"
#include <string>

mangoTree::mangoTree()
{
	this->first = nullptr;
	this->last = nullptr;
	this->counter = 0;
	this->maxMangos = 0;
	this->maxWeight = 0;
}

mangoTree::mangoTree(int _maxMango, double _maxWeight)
{
	this->first = nullptr;
	this->last = nullptr;
	this->counter = 0;
	this->maxMangos = _maxMango;
	this->maxWeight = _maxWeight;
	this->weight = 0;
}

int mangoTree::getCounter()
{
	return this->counter;
}

void mangoTree::increaseCounter()
{
	this->counter++;
}

void mangoTree::decreaseCounter()
{
	this->counter--;
}

int mangoTree::addMango(mangoFruit* m)
{
	if (getCounter() < this->maxMangos && (this->weight+m->getWeight()) < this->maxWeight)
	{
		if (this->first == 0)
		{
			this->first = m;
			this->last = m;
		}
		else
		{
			this->last->next = m;
			m->prev = this->last;
			this->last = m;
		}
		increaseCounter();
		mangos.push_back(m);
		this->weight += m->getWeight();
	}

	return 5;
}

int mangoTree::insertMango(mangoFruit* m, int pos)
{
	if (getCounter() < this->maxMangos)
	{
		if (pos > (this->getCounter() + 1))
			return -1;

		else if (pos < 0)
			return -2;

		else if (pos == (this->getCounter() + 1))
		{
			this->addMango(m);
			return 0;
		}
		else if (pos == 1)
		{
			if (this->weight+m->getWeight() < this->maxWeight)
			{
				mangoFruit* tmp = this->first;

				m->prev = nullptr;
				m->next = tmp;
				tmp->prev = m;
				this->first = m;
				increaseCounter();
				this->weight += m->getWeight();
				mangos.clear();//Borramos todos los elementos para hacer el insert en el vector
				mangoFruit* tmp = this->first;
				for (int i = 0; i < getCounter(); i++)
				{
					if (i == pos - 1)
						mangos.push_back(m);
					else
					{
						mangos.push_back(tmp);
						tmp = tmp->next;
					}
				}
				return 1;
			}
			return 0;
		}
		else if (pos <= this->getCounter())
		{
			if (this->weight+m->getWeight() < this->maxWeight)
			{
				mangoFruit* tmp = this->first;
				int actualPos = 1;

				while (actualPos < pos)
				{
					actualPos++;
					tmp = tmp->next;
				}

				m->prev = tmp->prev;
				m->next = tmp;
				m->prev->next = m;
				tmp->prev = m;
				increaseCounter();
				mangoFruit* tmp = this->first;
				mangos.clear();//Borramos todos los elementos para hacer el insert en el vector
				for (int i = 0; i < getCounter(); i++)
				{
					if (i == pos - 1)
						mangos.push_back(m);
					else
					{
						mangos.push_back(tmp);
						tmp = tmp->next;
					}
				}
				return 2;
			}
			return 0;
		}

	}

	return -3;
}

int mangoTree::deleteMango(int pos)
{
	if (pos > this->getCounter())
		return -1;

	else if (pos < 0)
		return -2;

	else if (pos <= this->getCounter())
	{
		mangoFruit* tmp = this->first;
		int actualPos = 1;

		while (actualPos < pos)
		{
			actualPos++;
			tmp = tmp->next;
		}

		if (tmp == this->first)
		{
			tmp->next->prev = nullptr;
			first = first->next;
		}
		else if (tmp == this->last)
		{
			tmp->prev->next = nullptr;
			last = last->prev;
		}
		else
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}

		this->weight -= tmp->getWeight();
		delete tmp;
		mangos.clear();
		mangoFruit* tmp = this->first;
		for (int i = 0; i < getCounter(); i++)
		{
			if (i != pos-1)
			{
				mangos.push_back(tmp);
				tmp = tmp->next;
			}
		}
		decreaseCounter();
		return 0;
	}// Delete's if

}

void mangoTree::printMangoTree()
{
	mangoFruit* tmp = this->first;

	while (tmp != nullptr)
	{
		cout << "["+to_string(tmp->getWeight())+"] ";
		tmp = tmp->next;
	}

}

void mangoTree::mergeTrees(mangoTree* L2)
{
	this->maxMangos += L2->maxMangos;
	this->maxWeight += L2->maxWeight;
	this->counter += L2->counter;
	this->weight += L2->weight;
	mangoFruit* tmp = L2->first;

	while (tmp->next != 0)
	{
		this->addMango(tmp);
		mangos.push_back(tmp);
		tmp = tmp->next;
	}

	L2->mangos.clear();

}

void mangoTree::menu(mangoTree &tree, mangoTree& tree2, bool &tener2arboles) {
	bool* dosArboles = &tener2arboles;
	mangoTree* arbol1 = &tree;
	mangoTree* arbol2 = &tree2;
	//mangoFruit le agregue = int x , int y, y (double,int,int)

	//mangotree le agregue = mangos(es un vector);
	while (true)
	{
		cout << "Que desea hacer?" << endl;
		cout << "1. Agregar Mango" << endl;
		cout << "2. Insertar Mango" << endl;
		cout << "3. Eliminar Mango" << endl;
		cout << "4. Activar segundo Arbol" << endl;
		cout << "5. Desactivar segundo Arbol" << endl;
		cout << "6. Unir Arboles" << endl;
		int opcion;
		cin >> opcion;


		switch (opcion)
		{
		case 1:
		{
			if (*dosArboles)
			{
				cout << "En que arbol desea poner el nuevo mango?" << endl;
				cout << "1. Arbol #1" << endl;
				cout << "2. Arbol #2" << endl;
				int arbol;
				cin >> arbol;
				switch (arbol)
				{
				case 1:
				{
					cout << "Ingrese el peso del mango";
					int peso;
					cin >> peso;
					mangoFruit* mango = new mangoFruit();
					mango->setWeight(peso);
					mango->x = (rand() % 300) + 100;
					mango->y = (rand() % 300) + 50;
					arbol1->addMango(mango);
					break;
				}
				case 2:
				{
					cout << "Ingrese el peso del mango";
					int peso2;
					cin >> peso2;
					mangoFruit* mango2 = new mangoFruit();
					mango2->setWeight(peso2);
					mango2->x = (rand() % 300) + 550;
					mango2->y = (rand() % 300) + 50;
					arbol2->addMango(mango2);
					break;
				}

				}

			}
			else {
				cout << "Ingrese el peso del mango";
				int peso;
				cin >> peso;
				mangoFruit* mango = new mangoFruit();
				mango->setWeight(peso);
				mango->x = (rand() % 300) + 100;
				mango->y = (rand() % 300) + 50;
				arbol1->addMango(mango);
			}
			break;
		}
		case 2:
		{
			//CODIGO DE INSERTAR MANGO
			cout << "\nIngrese el peso del mango";
			int peso;
			cin >> peso;
			cout << "\nIngrese la posicion deseada a donde insertar el mango: ";
			int pos;
			cin >> pos;
			mangoFruit* mango = new mangoFruit();
			mango->setWeight(peso);
			mango->x = (rand() % 300) + 100;
			mango->y = (rand() % 300) + 50;
			arbol1->insertMango(mango, pos);
			break;
		}

		case 3:
		{
			//CODIGO DE ELIMINAR MANGO
			cout << "\nIngrese la posicion deseada a donde borrar el mango: ";
			int pos;
			cin >> pos;
			arbol1->deleteMango(pos);
			break;
		}

		case 4:
			(*dosArboles) = true;
			break;
		case 5:
			(*dosArboles) = false;
			break;

		case 6:
		{
			//CODIGO PARA UNIR MANGOS
			arbol1->mergeTrees(arbol2);
			break;
		}
		}



	}
}

