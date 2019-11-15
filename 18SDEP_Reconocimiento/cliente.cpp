#include "Solicitud.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Forma de uso: %s ip_servidor n\n", argv[0]);
		exit(0);
	}
	int n = atoi(argv[2]);
	int cont = 0;
	string s = "rm registroCliente.txt &&./generador "+to_string(n)+" registroCliente.txt";
	cout<<s<<endl;
	system(s.c_str());
	string line;
	std::ifstream infile("registroCliente.txt");
	while (getline(infile, line))
	{
		Solicitud s;
		int res=0;
		char *cstr = new char[line.length() + 1];
		strcpy(cstr, line.c_str());
		memcpy(&res, s.doOperation(argv[1], 7200, 1,cstr),4);
		if(res==1){
			cout<<"Acuse recibido"<<endl;
		}else{
			cout<<"Error en recepcion"<<endl;
		}
	}
	return 0;
}