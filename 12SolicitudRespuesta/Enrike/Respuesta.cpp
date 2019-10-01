#include "Respuesta.h"
#include <string.h>
#include <iostream>
using namespace std;
Respuesta::Respuesta(int pl){
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje * Respuesta::getRequest(void){
    SocketDatagrama  * aux = socketlocal;
    struct mensaje sms;
    PaqueteDatagrama paquete = PaqueteDatagrama(4000);
    int tam = aux->recibe(paquete);
    if (tam == -1) {
      perror("Recvfrom failed");
    }
    char * datos = paquete.obtieneDatos();
    memcpy(sms.arguments,datos,tam);
    cout<<datos<<endl;
    return &sms;
}

void Respuesta::sendReply(char *respuesta){
    struct mensaje sms;
    sms.messageType=1;
    sms.operationId=0;
    sms.requestId=0;
    memcpy(sms.arguments,respuesta,strnlen(respuesta,4000));
    PaqueteDatagrama paquete= PaqueteDatagrama(4000);
    paquete.inicializaDatos(respuesta);
    SocketDatagrama aux = *socketlocal;
    aux.envia(paquete);
}