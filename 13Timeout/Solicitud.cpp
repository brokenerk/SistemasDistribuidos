#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char* Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments) {
	struct mensaje sms;
	sms.messageType = 0;
	sms.requestId = 0;
	sms.operationId = operationId;
    memcpy(sms.arguments, arguments, sizeof(arguments));
    
	PaqueteDatagrama p = PaqueteDatagrama((char*)&sms, sizeof(sms), IP, puerto);
	cout << "Direccion: " << p.obtieneDireccion() << endl;
	cout << "Puerto: " << p.obtienePuerto() << endl;
	socketlocal->envia(p);

	PaqueteDatagrama p1 = PaqueteDatagrama(4000);
    int tam = socketlocal->recibe(p1);
    if (tam == -1) {
      perror("Recvfrom failed");
    }
    cout << "\nMensaje recibido" << endl;
    cout << "Direccion: " << p1.obtieneDireccion() << endl;
    cout << "Puerto: " << p1.obtienePuerto() << endl;
	struct mensaje* msj = (struct mensaje *)p1.obtieneDatos();
    return (char *) msj->arguments;
}