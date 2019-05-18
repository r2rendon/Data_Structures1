#include <iostream>
#include "SongQueue.h"

using namespace std;

int main()
{
	SongQueue sQueue;
	string n = "Adictiva", a = "DY", g = "Reggaeton";

	SongNode* songNode = new SongNode(n, a, g);

	sQueue.queue(songNode);

	n = "Swing";
	a = "Danny Ocean";
	g = "Reggaeton";
	songNode = new SongNode(n, a, g);
	sQueue.queue(songNode);

	n = "Shiver";
	a = "Coldplay";
	g = "Alternative Rock";
	songNode = new SongNode(n, a, g);
	sQueue.queue(songNode);

	sQueue.dequeue();

	return 0;
}