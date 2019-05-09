#include "Node.h"

Node::Node()
{
	this->value = 0;
	this->next = nullptr;
}

Node::Node(int v)
{
	this->value = v;
	this->next = nullptr;
}
