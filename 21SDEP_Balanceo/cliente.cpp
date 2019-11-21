//Programa para crear registros de votos [celular, CURP, partido, separador], con el campo "celular" como clave 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "Solicitud.h"
#include <sys/time.h>
#include <unistd.h>
#include <iostream> 
#include <list> 
#include <thread>  
#include <iterator> 
using namespace std;
int n = 0;
list <int> lista;
list<int>::iterator itr;

struct registro GenerarVoto(int j){
	char telefono[11], curp[19], t[11], sexo;
	int i, destino, opcion, elemento;
	struct registro reg1;
	//Partidos disponibles 2018
	char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE", "MVC", "MOR", "PES", "PNL"};
	//Entidades federativas
	char const entidad[32][3] =  {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};
	//Obtiene un elemento aleatorio de la lista de telefonos y lo elimina de la lista para evitar la repeticion
	i = n - j;
	elemento = rand()%i;		
	itr = lista.begin();
	for(int k = 0; k < elemento; k++)
		++itr;
	elemento = *itr;
	lista.erase(itr);
	sprintf(telefono, "5%9d", elemento);
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

void enviar(char * ip,int puerto,registro r,Solicitud s){
	timeval res;
	memcpy(&res, s.doOperation(ip, puerto, 1, (char *)&r),sizeof(timeval));
	cout << res.tv_sec << endl;
	cout << res.tv_usec << endl;
}

struct Servidor{
	char * ip;
	int port;
};

int main(int argc, char *argv[]){
	
	if (argc != 8)
	{
		//7 IP PORT IP PORT IP PORT
		printf("Forma de uso: %s ip_servidor n\n", argv[0]);
		exit(0);
	}
	Servidor s1;
	Servidor s2;
	Servidor s3;
	s1.ip=argv[1];
	s1.port=atoi(argv[2]);
	s2.ip=argv[3];
	s2.port=atoi(argv[4]);
	s3.ip=argv[5];
	s3.port=atoi(argv[6]);
	srand(time(NULL));
	n = atoi(argv[7]);
	int cont = 0;

	//Llena una lista con numeros telefonicos de 9 digitos secuenciales creibles
	int inicial = 500000000 + rand()%100000000;
	for (int i = inicial; i < inicial + n; i++) 
	{ 
		lista.push_back(i);
	}

	Solicitud s;
	while(cont < n) {
		int port;
		struct registro r = GenerarVoto(cont);
		string lastc =string(r.celular);
		lastc=lastc.back();
		int lastN = atoi(lastc.c_str());
		switch (lastN)
		{
			case 0:{
				thread t(enviar,s1.ip,s1.port,r,s);
				t.detach();
				break;
			}
			case 1:{
				thread t(enviar,s1.ip,s1.port,r,s);
				t.detach();
				break;
			}
			case 2:{
				thread t(enviar,s1.ip,s1.port,r,s);
				t.detach();
				break;
			}
			case 3:{
				thread t(enviar,s1.ip,s1.port,r,s);
				t.detach();
				break;
			}
			case 4:{
				thread t(enviar,s2.ip,s2.port,r,s);
				t.detach();
				break;
			}
			case 5:{
				thread t(enviar,s2.ip,s2.port,r,s);
				t.detach();
				break;
			}
			case 6:{
				thread t(enviar,s2.ip,s2.port,r,s);
				t.detach();
				break;
			}
			case 7:{
				thread t(enviar,s3.ip,s3.port,r,s);
				t.detach();
				break;
			}
			case 8:{
				thread t(enviar,s3.ip,s3.port,r,s);
				t.detach();
				break;
			}
			case 9:{
				thread t(enviar,s3.ip,s3.port,r,s);
				t.detach();
				break;
			}
		}
		usleep(1000);
		cont++;
	}
	cout<<cont<<endl;
	cout<<n<<endl;
	return 0;
}