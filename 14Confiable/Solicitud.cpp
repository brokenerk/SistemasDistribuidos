#include "Solicitud.h"
#include <iostream>
#include <cstring>
using namespace std;
int contRequest = 0;

Solicitud::Solicitud() {
	socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
	struct mensaje sms;
	sms.messageType = 0;
	printf("ContRequest: %u\n", contRequest);
	sms.requestId = contRequest;
	sms.operationId = operationId;
	memcpy(sms.arguments, arguments, sizeof(arguments));
	PaqueteDatagrama p = PaqueteDatagrama((char *)&sms, sizeof(sms), IP, puerto);
	cout << "Direccion: " << p.obtieneDireccion() << endl;
	cout << "Puerto: " << p.obtienePuerto() << endl;
	socketlocal->envia(p);
	PaqueteDatagrama p1 = PaqueteDatagrama(65000);
	int tam = socketlocal->recibeTimeout(p1, 2, 500);
	int n = 1;

	while (tam == -1 && n < 7)
	{
		socketlocal->envia(p);
		tam = socketlocal->recibeTimeout(p1, 2, 500);
		n++;
	}

	if (tam == -1 && n >= 7)
	{
		cout << "Servidor no esta disponible, intente mas tarde." << endl;
		exit(0);
	}
	else
	{
		cout << "\nMensaje recibido" << endl;
		cout << "Direccion: " << p1.obtieneDireccion() << endl;
		cout << "Puerto: " << p1.obtienePuerto() << endl;
		struct mensaje *msj = (struct mensaje *)p1.obtieneDatos();
		contRequest++;
		return (char *)msj->arguments;
	}
}