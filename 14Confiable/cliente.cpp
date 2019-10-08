#include "Solicitud.h"
#include <string.h>
#include <iostream>
using namespace std;
int randNum();
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Forma de uso: %s ip_servidor n\n", argv[0]);
		exit(0);
	}
	int n = atoi(argv[2]);
	int cont = 0;
	int res[64999];
	int cuenta = 0;
	while (cont < n)
	{

		int arr[64999];
		Solicitud s;
		arr[0] = randNum();
		memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&arr), 64999);
		cuenta = cuenta + arr[0];
		if (cuenta != res[0])
		{
			cout << "entro al if" << endl;
			printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", cont, cuenta, res[0]);
			exit(0);
		}
		cont++;
		printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", cont, cuenta, res[0]);
	}
	return 0;
}

int randNum()
{
	return rand() % 9 + 1;
}