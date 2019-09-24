#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	if(pto!=0){
		direccionLocal.sin_family = AF_INET;
		direccionLocal.sin_addr.s_addr = INADDR_ANY;
		direccionLocal.sin_port = htons(pto);
		if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)) < 0 ) 
		{ 
			perror("bind failed"); 
			exit(EXIT_FAILURE); 
		} 
	}
}

SocketDatagrama::~SocketDatagrama() {
	direccionLocal;
	direccionForanea;
}

int SocketDatagrama::recibe(PaqueteDatagrama & p) {
	return recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0,(struct sockaddr *)p.obtieneDireccion(),(unsigned int*)p.obtieneDireccion());
}

int SocketDatagrama::envia(PaqueteDatagrama & p) {
   	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}