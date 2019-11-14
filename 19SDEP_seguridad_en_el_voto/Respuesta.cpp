#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;

PaqueteDatagrama p = PaqueteDatagrama(65000);

Respuesta::Respuesta(int pl) {
    socketlocal = new SocketDatagrama(pl);
    contRequest = 0;
}


struct registro{
	char celular[11];
	char CURP[19];
	char partido[4];
	string toString()
	{
		return string(celular)+string(CURP)+string(partido);
	}
};

struct mensaje *Respuesta::getRequest(void)
{
    int tam = socketlocal->recibe(p);
    if (tam == -1){
        perror("Recvfrom failed");
    }
    cout << "\nMensaje recibido" << endl;
    cout << "Direccion: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;
    struct mensaje* sms = (struct mensaje*)p.obtieneDatos();
    unsigned int reqId = 0;
    memcpy(&reqId, &sms->requestId, sizeof(sms->requestId));
        return (struct mensaje*)sms;
}

void Respuesta::sendReply(char *respuesta)
{
    struct mensaje sms;
    sms.messageType = 1;
    sms.operationId = 0;
    sms.requestId = 0;
    memcpy(sms.arguments, respuesta, sizeof(registro));
    p.inicializaDatos((char *)&sms);
    cout << "\nMensaje enviado" << endl;
    cout << "Direccion: " << p.obtieneDireccion() << endl;
    cout << "Puerto: " << p.obtienePuerto() << endl;
    socketlocal->envia(p);
}