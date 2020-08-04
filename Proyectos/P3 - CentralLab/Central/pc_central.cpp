#include "Central.h"
#include "ServidorWeb.h"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <mutex>
using namespace std;

string ip1 = "";
int ult1 = 0, ult2 = 0, segs = 0, totalPC = 0;
Central c;
mutex m;

void clienteUDP() {
	while(true) {
		int contIP = 0;
		while(contIP < totalPC){
			string ipAux = ip1 + to_string(contIP + ult1);
			cout << "\nEnviando peticion a: " + ipAux << endl;

			if(c.enviaPeticion((char*)ipAux.c_str()) == - 1){
				contIP++;
				continue;
			}
			m.lock();
			c.guardaImagen(ipAux);
			m.unlock();
			contIP++;
		}
		sleep(segs);
	}
}

void servidorWeb() {
	ServidorWeb web(".", "8000");
	web.inicializaDatos((char*)ip1.c_str(), ult1, segs);
	web.escuchar();
}

int main(int argc, char* argv[]) {
	if(argc != 5) {
		printf("Forma de uso: %s ip1 ip2 resolucion segs\n", argv[0]);
		exit(0);
	}

	c.inicializaResolucion(argv[3]);
	segs = atoi(argv[4]);

	ip1 = c.calcularRangoIP(argv[1]);
	ult1 = c.obtieneUltIP();
	string ip2(c.calcularRangoIP(argv[2]));
	ult2 = c.obtieneUltIP();

	totalPC = ult2 - ult1 + 1;
	if(totalPC > 30) {
		cout << "El rango de IPs ingresado supera el limite de computadoras, que es de 30." << endl;
		exit(0);
	}

	if(ult1 >= 226 && ult2 < 226) {
		cout << "Rango fuera del bloque de la direccion IP" << endl;
		exit(0);
	}

	thread th1(clienteUDP), th2(servidorWeb);
	th1.join();
    th2.join();

	return 0;
}