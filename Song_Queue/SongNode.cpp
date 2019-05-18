#include "SongNode.h"

SongNode::SongNode()
{
	this->songName = "";
	this->songArtist = "";
	this->genre = "";
	this->next = 0;
}

SongNode::SongNode(string n, string a, string g)
{
	this->songName = n;
	this->songArtist = a;
	this->genre = g;
	this->next = 0;
}

SongNode::~SongNode()
{
}
