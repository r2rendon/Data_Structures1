#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue Cola;

	Node * newNode = new Node(CSERVICE, 12);
	Cola.enQueue(newNode);

	newNode = new Node(CSERVICE, 21);
	Cola.enQueue(newNode);

	newNode = new Node(OTHERS, 5);
	Cola.enQueue(newNode);

	newNode = new Node(OTHERS, 82);
	Cola.enQueue(newNode);

	newNode = new Node(OTHERS, 23);
	Cola.enQueue(newNode);

	/*newNode = new Node(PAY, 2);
	Cola.enQueue(newNode);

	newNode = new Node(PAY, 3);
	Cola.enQueue(newNode);

	newNode = new Node(PAY, 4);
	Cola.enQueue(newNode);

	newNode = new Node(PAY, 5);
	Cola.enQueue(newNode);*/

	OperationType maxOT = Cola.maxRep();
	double tTime = Cola.totalTime();

	return 0;
}