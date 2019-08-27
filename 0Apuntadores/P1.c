#include <stdio.h>

int main(){
	printf("--------------- Punto 1\n");
	
	char caracter = 0;
	printf("%p tam: %i\n", &caracter, sizeof(caracter));

	int entero = 0;
	printf("%p tam: %i\n", &entero, sizeof(entero));

	float flotante = 0;
	printf("%p tam: %i\n", &flotante, sizeof(flotante));

	long largo = 0;
	printf("%p tam: %i\n", &largo, sizeof(largo));

	double doble = 0;
	printf("%p tam: %i\n",&doble, sizeof(doble));

	return 0;
}