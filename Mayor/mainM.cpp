#include <iostream>

using namespace std;

void parOimpar(int n)
{
	if (n % 2 == 0)
		printf("\n   ES PAR");
	else
		printf("\n   ES IMPAR");
}

int main()
{
	int num = 0;

	cout << "Ingrese el numero a revisar: ";
	cin >> num;
	cout << endl;

	parOimpar(num);
	cout << endl;

	system("pause");
	
}