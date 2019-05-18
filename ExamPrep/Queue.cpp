#include "Queue.h"

Queue::Queue()
{
	this->first = 0;
	Node* c = new Node(CENTINEL, 0);
	this->last = c;
}

void Queue::enQueue(Node* newNode)
{
	Node* tmp = first;

	if (first == 0)
	{
		this->first = newNode;
		this->first->next = last;
	}
	else
	{
		int x = 0;
		
		while(tmp->next->oT != CENTINEL)
		{
			tmp = tmp->next;
			x++;
		}

		if (x == 0)
		{
			this->first->next = tmp;
		}

		newNode->next = last;
		tmp->next = newNode;
		
	}

}

void Queue::deQueue()
{
	Node* tmp = first;
	this->first = tmp->next;
	delete tmp;
}

OperationType Queue::maxRep()
{
	OperationType MaxOT = NONE;
	Node* tmp = first;
	int cs = 0, p = 0, o = 0;

	while (tmp->oT != CENTINEL)
	{
		
		if (tmp->oT == CSERVICE)
			cs++;
		else if (tmp->oT == PAY)
			p++;
		else if (tmp->oT == OTHERS)
			o++;

		tmp = tmp->next;
	}

	if (cs > p && cs > o)
		MaxOT = CSERVICE;
	else if (p > cs && p > o)
		MaxOT = PAY;
	else
		MaxOT = OTHERS;

	return MaxOT;
}

double Queue::totalTime()
{
	double sum = 0, c = 0;
	Node* tmp = first;

	while (tmp->oT != CENTINEL)
	{
		sum += tmp->aproxTime;
		c++;
		tmp = tmp->next;
	}

	return sum / c;
}
