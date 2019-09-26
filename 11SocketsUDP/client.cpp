#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2) {
		printf("Forma de uso: %s ip_servidor\n", argv[0]);
		exit(0);
	}
	char num[2];
	num[0] = 21;
	num[1] = 3;

    SocketDatagrama client = SocketDatagrama(0);
    PaqueteDatagrama dat = PaqueteDatagrama(num, 4, argv[1], 7200);
    if(client.envia(dat)){
        cout << "Mensaje enviado a:" << endl;
        cout << "IP: " << dat.obtieneDireccion() << endl;
        cout << "Puerto: " << dat.obtienePuerto() << endl;
        cout << "Longitud: " << dat.obtieneLongitud() << endl;
    }

    PaqueteDatagrama res = PaqueteDatagrama(4);
    if(client.recibe(res)){
        cout << "\nMensaje recibido de:" << endl;
        cout << "IP: " << res.obtieneDireccion() << endl;
        cout << "Puerto: " << res.obtienePuerto() << endl;
        int res2;
		memcpy(&res2, res.obtieneDatos(), 4);
        printf("Respuesta: %d\n", res2);
        cout << "Longitud: " << res.obtieneLongitud() << endl;
    }
    return 0;
}