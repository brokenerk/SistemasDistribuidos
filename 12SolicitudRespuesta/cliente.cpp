#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 4) {
		printf("Forma de uso: %s ip_servidor num1 num2\n", argv[0]);
		exit(0);
	}

	char num[2];
	num[0] = atoi(argv[2]);
	num[1] = atoi(argv[3]);
	printf("Datos: %d %d\n", num[0], num[1]);

	Solicitud s;
	cout << s.doOperation(argv[1], 7200, 1, num) << endl;

	struct mensaje* msj = s.getResponse();
	int res;
	memcpy(&res, msj->arguments, 4);
    printf("Respuesta: %d\n\n", res);
	return 0;
}