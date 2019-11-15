//Programa para crear registros de votos [celular, CURP, partido, separador], con el campo "celular" como clave 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "Solicitud.h"
#include <sys/time.h>
#include <unistd.h>
#include <iostream> 
using namespace std; 

struct registro GenerarVoto(char * telefono){
	srand(time(NULL));
	char curp[19], t[11], sexo;
	int i, n, destino, j, opcion, inicial, elemento;
	struct registro reg1;
	//Partidos disponibles 2018
	char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE", "MVC", "MOR", "PES", "PNL"};
	//Entidades federativas
	char const entidad[32][3] =  {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};
	//Obtiene un elemento aleatorio de la lista de telefonos y lo elimina de la lista para evitar la repeticion
	strcpy(reg1.celular, telefono);
	if(rand()%2 == 0)
		sexo = 77;
	else
		sexo = 72;
	i = rand()%32;
	sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c%c", 65 + rand()%25 , 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, rand()%10 + 48, 
	sexo, entidad[i], 65 + rand()%25, 65 + rand()%25, 65 + rand()%25, rand()%10 + 48, rand()%10 + 48);
	strcpy(reg1.CURP, curp);
	i = rand()%9;
	strcpy(reg1.partido, partidos[i]);
	return reg1;
}

int main(int argc, char *argv[]){
	if (argc != 3)
	{
		printf("Forma de uso: %s telefono ip_servidor\n", argv[0]);
		exit(0);
	}
	registro r = GenerarVoto(argv[1]);
	Solicitud s;
	timeval res;
	memcpy(&res, s.doOperation(argv[2], 7200, 1,(char *)&r),sizeof(timeval));
	cout << res.tv_sec << endl;
	cout << res.tv_usec << endl;
	return 0;
}
