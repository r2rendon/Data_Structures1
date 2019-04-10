#include <iostream>

using namespace std;

int leedato()
{
	int n;
	cin >> n;
	return n;
}

void fibonacci()
{

	int n, i = 0, a = 1, b = 1, c = 0;
	do
	{
		cout << "Ingrese el numero de la cadena: ";
		n = leedato();
	} while (n < 2);

	cout << a << endl; cout << b << endl;
	while (i < n - 2)
	{
		c = a + b;
		cout << c << endl;
		a = b; b = c;
		i++;
	}
}

int main()
{
	fibonacci();
}