#include <iostream>

int Mcd(int a, int b) {
	if (a <= 0 || b <= 0)
		return -1; // Retorna -1 si alguno de los numeros es menor o igual a 0
	while (a != b)
		if (a < b)
			b = b - a;
		else
			a = a - b;
	return a; // Al final el mcd está en a y en b (a == b)
}

int main()
{
	int a = Mcd(2, 8);
	std::cout << a << std::endl;
	system("pause");
}