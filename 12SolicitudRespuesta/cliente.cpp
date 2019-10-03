#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 4) {
		printf("Forma de uso: %s ip_servidor num1 num2\n", argv[0]);
		exit(0);
	}
	int num[2];
	num[0] = atoi(argv[2]);
	num[1] = atoi(argv[3]);
	printf("Datos: %d %d\n", num[0], num[1]);
	
	Solicitud s;
	int res;
	memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&num), 4);
    printf("Respuesta: %d\n\n", res);
	return 0;
}