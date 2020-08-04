#ifndef CENTRAL_H_
#define CENTRAL_H_
#include "SocketDatagrama.h"
#include <sys/stat.h> 
#include <sys/types.h> 
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

class Central{
	public:
		Central();
		void inicializaResolucion(char* resol);
		char* calcularRangoIP(char* ip);
		int obtieneUltIP();
		int enviaPeticion(char* ip);
		void guardaImagen(string ip);
	private:
		int resolucion;
		int ultIP;
		int tamImagen;
		SocketDatagrama* cl;
};
#endif