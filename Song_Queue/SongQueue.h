#include "SongNode.h"

class SongQueue
{
public:
	SongQueue();
	
	SongNode* first,* last;

	void queue(SongNode*);
	void dequeue();
};

