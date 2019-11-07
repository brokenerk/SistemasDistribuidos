#include "SocketMulticast.h"
#include <iostream>
using namespace std;

SocketMulticast::SocketMulticast(int pto){
	contMessage = 0;
	lastMessage = 0;
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	if ((s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	int reuse = 1;
	if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
		printf("Error al llamar a la función setsockopt\n");
		exit(0);
	} 

	direccionLocal.sin_family = PF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(pto);
	if (bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal)) < 0)
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

int SocketMulticast::recibeConfiable(PaqueteDatagrama &p){
    unsigned int len = sizeof(direccionForanea);
	int rec = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &len);
	if(rec == -1){
		return rec;
	}

	int id = 0;
    struct mensaje* m = (struct mensaje*) p.obtieneDatos();
    memcpy(&id, &m->idMessage, 4);
    printf("\nLastMessage: %u SMS->idMessage: %d", lastMessage, id);

    if(id < lastMessage){
    	cout << "\nPaquete repetido. Desechando.." << endl;
        return -1;
    }
    else {
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
		p.inicializaDatos((char*)&m->arguments);
		p.inicializaPuerto(direccionForanea.sin_port);
		lastMessage++;
		return rec;
    }
}

int SocketMulticast::envia(PaqueteDatagrama &p, unsigned char ttl){
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&ttl, sizeof(ttl));
    direccionForanea.sin_family = PF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketMulticast::enviaConfiable(PaqueteDatagrama &p, unsigned char ttl, int num_receptores){
	contMessage++;
	struct mensaje m;
	m.idMessage = contMessage;
	memcpy(m.arguments, p.obtieneDatos(), 4);
	printf("\nidMessage: %d\n", contMessage);
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&ttl, sizeof(ttl));
    direccionForanea.sin_family = PF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)&m, sizeof(m), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

void SocketMulticast::unirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void*)&multicast, sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *multicastIP){
    multicast.imr_multiaddr.s_addr = inet_addr(multicastIP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void*)&multicast, sizeof(multicast));
}