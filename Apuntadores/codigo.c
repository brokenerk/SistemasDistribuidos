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

	printf("--------------- Punto 5 \n");

	char *pcaracter;
	printf("%p tam: %i\n", &pcaracter, sizeof(pcaracter));

	int *pentero;
	printf("%p tam: %i\n", &pentero, sizeof(pentero));

	float *pflotante;
	printf("%p tam: %i\n", &pflotante, sizeof(pflotante));

	long *plargo;
	printf("%p tam: %i\n", &plargo, sizeof(plargo));

	double *pdoble; 
	printf("%p tam: %i\n", &pdoble, sizeof(pdoble));



	return 0;
}