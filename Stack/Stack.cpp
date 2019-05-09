#include "Stack.h"

Stack::Stack()
{
	this->top = 0;
	this->counter = 0;
	this->size = 5;
}

void Stack::increaseCounter()
{
	this->counter++;

}

void Stack::decreaseCounter()
{
	this->counter--;
}

bool Stack::push(Node* newNode)
{
	if (top == 0)
	{
		this->top = newNode;
		increaseCounter();
		return true;
	}
	else
	{
		if (this->counter < this->size)
		{
			newNode->next = top;
			top = newNode;
			counter++;
			return false;
		}

	}

	return false;

}

Node* Stack::pop()
{
	if (top == 0)
		return nullptr;
	else
	{
		Node* tmp = top;
		top = tmp->next;
		tmp->next = nullptr;
		decreaseCounter();
		return tmp;
	}

}
