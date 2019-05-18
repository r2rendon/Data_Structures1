#include "Node.h"

Node::Node()
{
	this->aproxTime = 0;
	this->next = 0;
	this->oT = NONE;
}

Node::Node(OperationType ot, double a)
{
	this->oT = ot;
	this->aproxTime = a;
	this->next = 0;
}

Node::~Node()
{
}
