#include <string>

using namespace std;

class SongNode
{

public:
	string songName, songArtist, genre;

	SongNode* next;

	SongNode();
	SongNode(string, string, string);
	~SongNode();
	
};

