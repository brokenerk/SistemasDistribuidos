#include <stdio.h>

int main(){
	char caracter = 0;
	printf("%p %p\n", &caracter, sizeof(caracter));

	int entero = 0;
	printf("%p %p\n", &entero, sizeof(entero));

	float flotante = 0;
	printf("%p %p\n", flotante, sizeof(flotante));

	long largo = 0;
	printf("%p %p\n", &largo, sizeof(largo));

	double doble = 0;
	printf("%p %p\n", doble, sizeof(doble));


	return 0;
}