#include "PaqueteDatagrama.h"
#include <iostream>
#include <netinet/in.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	if(pto == 0)
		direccionLocal.sin_port = htons(pto);
	else
		direccionLocal.sin_port = pto;

	s = socket(AF_INET, SOCK_DGRAM, 0);
}

SocketDatagrama::~SocketDatagrama() {
	delete s;
	delete direccionLocal;
	delete direccionForaneo;
}

SocketDatagrama::recibe(PaqueteDatagrama & p) {
	
}

SocketDatagrama::envia(PaqueteDatagrama & p) {
	/* rellena la dirección del servidor */
   	bzero((char *)&direccionForaneo, sizeof(direccionForaneo));
   	direccionForaneo.sin_family = AF_INET;
   	direccionForaneo.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForaneo.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLonguitud(), 0, (struct sockaddr *) &direccionForaneo, sizeof(direccionForaneo));
}
