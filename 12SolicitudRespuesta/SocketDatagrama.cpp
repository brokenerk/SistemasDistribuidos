#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	direccionLocal.sin_port = htons(pto);
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	bind(s,(struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama() {
	direccionLocal;
	direccionForanea;
}

int SocketDatagrama::recibe(PaqueteDatagrama & p){
	recvfrom(s, (char *)num, 65507 * sizeof(char), 0, (struct sockaddr *)&direccionForanea,(unsigned int *)sizeof(direccionForanea));
}

int SocketDatagrama::envia(PaqueteDatagrama & p) {
	/* rellena la dirección del servidor */
   	bzero((char *)&direccionForanea, sizeof(direccionForanea));
   	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());
   	if(bind(s, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea))){
		printf("BIND ERROR \n");
		exit(0);
	}
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}