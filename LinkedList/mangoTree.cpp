#include "mangoTree.h"

mangoTree::mangoTree()
{
	this->first = nullptr;
	this->last = nullptr;
	this->counter = 0;
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
	return 0;
}

int mangoTree::insertMango(mangoFruit* m, int pos)
{
	if (pos > (this->getCounter()+1))
		return -1;

	else if (pos < 0)
		return -2;

	else if(pos == (this->getCounter()+1))
	{
		this->addMango(m);
		return 0;
	}
	else if(pos <= this->getCounter())
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
		return 0;
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

		delete tmp;
		decreaseCounter();
		return 0;
	}// Delete's if

}