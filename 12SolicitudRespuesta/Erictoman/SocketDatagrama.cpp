#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("cannot create socket");
	}
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_port = htons(pto);
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	int tam = sizeof(direccionLocal);
	if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)) < 0) {
		perror("bind failed");
	}
}

SocketDatagrama::~SocketDatagrama() {
	direccionLocal;
	direccionForanea;
}

int SocketDatagrama::recibe(PaqueteDatagrama & p){
	socklen_t tam = sizeof(direccionForanea);
	return recvfrom(s, (char *)p.obtieneDatos(), 65507, 0, (struct sockaddr *)&direccionForanea,&tam);
}

int SocketDatagrama::envia(PaqueteDatagrama & p) {
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