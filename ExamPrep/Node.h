enum OperationType
{
	CSERVICE = 0, PAY, OTHERS, NONE, CENTINEL = 5
};

class Node
{
public:
	OperationType oT;
	double aproxTime;

	Node * next;

	Node();
	Node(OperationType, double);
	~Node();
};

