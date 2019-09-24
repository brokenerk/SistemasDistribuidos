#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
using namespace std;

SocketDatagrama::SocketDatagrama(int pto) {
	if(pto == 0)
		direccionLocal.sin_port = htons(pto);
	else
		direccionLocal.sin_port = pto;
	s = socket(AF_INET, SOCK_DGRAM, 0);
	cout << "socket creado" << endl;
}

SocketDatagrama::~SocketDatagrama() {
	memset(&direccionForanea, 0, sizeof(direccionForanea));
   	memset(&direccionLocal, 0, sizeof(direccionLocal));
   	s = 0;
}

int SocketDatagrama::recibe(PaqueteDatagrama & p) {
	/* rellena la dirección del cliente */
   	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = AF_INET;
   	direccionLocal.sin_addr.s_addr = inet_addr(p.obtieneDireccion());

   	bind(s, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));

	int i = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, NULL, NULL);

	unsigned char ip[4];
	memcpy(ip, &direccionForanea.sin_addr.s_addr, 4);
	printf("Mensaje recibido de:\n");
	printf("IP: %d.%d.%d.%d \n", ip[0], ip[1], ip[2], ip[3]);
	printf("Puerto: %d\n", direccionForanea.sin_port);
	printf("sizeof = %d\n", p.obtieneLongitud());
	return i;
}

int SocketDatagrama::envia(PaqueteDatagrama & p) {
	/* rellena la dirección del servidor */
   	bzero((char *)&direccionForanea, sizeof(direccionForanea));
   	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());

   	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
   	cout << "enviando datagrama..." << endl;

	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}