#include "Queue.h"

Queue::Queue()
{
	this->first = nullptr;
	this->last = nullptr;
	this->counter = 0;
}

Queue::~Queue()
{
}

int Queue::getCounter()
{
	return this->counter;
}

void Queue::cQueue(Car* newCar)
{
	newCar->next = nullptr;

	if (getCounter() == 0)
		this->first = newCar;
	else
		this->last->next = newCar;

	this->last = newCar;
	increaseCounter();
}

void Queue::cDequeue()
{
	Car* tmp = this->first;

	if (this->first == this->last)
	{
		this->first = nullptr;
		this->last = nullptr;
	}
	else
		this->first = first->next;

	delete tmp;
	decreaseCounter();
}
