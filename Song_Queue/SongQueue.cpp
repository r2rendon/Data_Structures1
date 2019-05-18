#include "SongQueue.h"

SongQueue::SongQueue()
{
	this->first = 0;
	this->last = 0;
}

void SongQueue::queue(SongNode* newSong)
{
	if (first == 0)
		this->first = newSong;
	else
		this->last->next = newSong;

	this->last = newSong;
}

void SongQueue::dequeue()
{
	SongNode* tmp = first;
	this->first = this->first->next;
	delete tmp;
}
