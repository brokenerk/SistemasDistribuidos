#include "Respuesta.h"
#include <string.h>
#include <iostream>
using namespace std;
Respuesta::Respuesta(int pl){
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje * Respuesta::getRequest(void){
    struct mensaje * sms;
    PaqueteDatagrama p = PaqueteDatagrama(4000);
    int tam = socketlocal->recibe(p);
    if (tam == -1) {
      perror("Recvfrom failed");
    }
    sms = (mensaje*) p.obtieneDatos();
    return sms;
}

void Respuesta::sendReply(char *respuesta){
    struct mensaje sms;
    sms.messageType = 1;
    sms.operationId = 0;
    sms.requestId = 0;
    memcpy(sms.arguments, respuesta, strnlen(respuesta,4000));
    PaqueteDatagrama paquete = PaqueteDatagrama(4000);
    paquete.inicializaDatos(respuesta);
    socketlocal->envia(paquete);
}