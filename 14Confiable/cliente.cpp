#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
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
	srand(time(NULL));
	int n = atoi(argv[2]);
	int cont = 0;
	int res = 0;
	int cuenta = 0;
	while (cont < n)
	{
		int arr = 1 + rand() % 9;
		Solicitud s;

		memcpy(&res, s.doOperation(argv[1], 7200, 1, (char *)&arr), 4);
		cuenta = cuenta + arr;
		if (cuenta != res)
		{
			printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", arr, res, cuenta);
			exit(0);
		}
		printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", arr, res, cuenta);
		cont++;
	}
	return 0;
}