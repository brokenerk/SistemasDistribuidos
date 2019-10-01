#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("Forma de uso: %s ip_servidor\n", argv[0]);
		exit(0);
	}
	Solicitud s;
	cout << s.doOperation(argv[1], 7200, 1, "Hola jaja") << endl;
	return 0;
}