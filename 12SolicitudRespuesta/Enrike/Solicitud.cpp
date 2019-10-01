#include "Solicitud.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char* Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
	PaqueteDatagrama p = PaqueteDatagrama(arguments, 4000, IP, puerto);
	socketlocal->envia(p);
	return "ok";
}