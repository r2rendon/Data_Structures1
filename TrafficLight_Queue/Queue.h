#include "Car.h"

class Queue
{
private:
	int counter;
	void increaseCounter();
	void decreaseCounter();

public:
	Queue();
	~Queue();

	Car* first;
	Car* last;

	int getCounter();

	void cQueue(Car*);
	void cDequeue();
};

