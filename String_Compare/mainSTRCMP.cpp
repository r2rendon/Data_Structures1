#include <iostream>

int str_compare(const char * s1, const char * s2) {
	int i = 0;
	while (s1[i] || s2[i]) {
		if (s1[i] < s2[i])
			return -1; // La cadena 1 es menor que la 2
		else if (s1[i] > s2[i])
			return 1; // La cadena 1 es mayor que la 2
		i++;
	}
	return 0; // Las cadenas son iguales
}

int main()
{
	int a = str_compare("Hola", "Hola");
	std::cout << a << std::endl;
	system("pause");
}