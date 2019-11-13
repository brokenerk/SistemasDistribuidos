#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_
#include "PaqueteDatagrama.h"
#include <errno.h>
#include <netinet/in.h>
#include <sys/time.h>

class SocketDatagrama
{
public:
	SocketDatagrama(int);
	~SocketDatagrama();
	//Recibe un paquete tipo datagrama proveniente de este socket
	int recibe(PaqueteDatagrama &p);
	//Envía un paquete tipo datagrama desde este socket
	int envia(PaqueteDatagrama &p);
	int recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);

private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s; //ID socket
	struct timeval timeout;
};
#endif