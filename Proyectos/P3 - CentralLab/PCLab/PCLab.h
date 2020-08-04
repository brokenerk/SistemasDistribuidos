#ifndef PCLAB_H_
#define PCLAB_H_
#include "SocketDatagrama.h"
#include <sys/stat.h> 
#include <sys/types.h> 
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

class PCLab{
	public:
		PCLab();
		void recibePeticion();
		void capturaPantalla();
		void enviaImagen();
	private:
		int resolucion;
		SocketDatagrama* s;
};
#endif