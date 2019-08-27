#include <stdio.h>

int main(){
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