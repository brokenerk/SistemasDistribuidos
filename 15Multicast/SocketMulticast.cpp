#include "SocketMulticast.h"

SocketMulticast::SocketMulticast(int pto){
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(pto);
	if (::bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
}

SocketMulticast::~SocketMulticast(){
    close(s);
}

int SocketMulticast::recibe(PaqueteDatagrama &p){
    unsigned int len = sizeof(direccionForanea);
	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &len);
	unsigned char ip[4];
	memcpy(ip, &direccionForanea.sin_addr.s_addr, 4);
	string ip1 = to_string(ip[0]);
	string ip2 = to_string(ip[1]);
	string ip3 = to_string(ip[2]);
	string ip4 = to_string(ip[3]);
	ip1.append(".");
	ip1.append(ip2);
	ip1.append(".");
	ip1.append(ip3);
	ip1.append(".");
	ip1.append(ip4);
	char dirIp[16];
	strcpy(dirIp, ip1.c_str());
	p.inicializaIp(dirIp);
	p.inicializaPuerto(direccionForanea.sin_port);
	return rec;
}

int SocketMulticast::envia(PaqueteDatagrama &p,unsigned char ttl){
    direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = p.obtienePuerto();
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

void SocketMulticast::unirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s,IPPROTO_IP,IP_ADD_MEMBERSHIP,&multicast,sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s,IPPROTO_IP,IP_DROP_MEMBERSHIP,&multicast,sizeof(multicast));
}