#include "Node.h"

class Queue
{
public:
	Queue();
	Node* first;
	Node* last;
	
	void enQueue(Node*);
	void deQueue();

	OperationType maxRep();
	double totalTime();
};

