#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

PaqueteDatagrama p = PaqueteDatagrama(4000);

Respuesta::Respuesta(int pl){
    socketlocal = new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(void){
    int tam = socketlocal->recibe(p);
    if (tam == -1) {
      perror("Recvfrom failed");
    }
    cout << "\nMensaje recibido" << endl;
    cout << "Direccion: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;
    return (struct mensaje*) p.obtieneDatos();
}

void Respuesta::sendReply(char *respuesta){
    struct mensaje sms;
    sms.messageType = 1;
    sms.operationId = 0;
    sms.requestId = 0;
    memcpy(sms.arguments, respuesta, sizeof(respuesta));

    p.inicializaDatos((char*)&sms);
    socketlocal->envia(p);
    cout << "Direccion: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;
    if(socketlocal->envia(p))
        cout << "Mensaje enviado" << endl;
    else
        cout << "Error" << endl;
}