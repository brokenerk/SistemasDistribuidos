#include "SocketMulticast.h"

int main(int argc, char *argv[]) {
	if(argc != 3) {
        printf("Forma de uso: %s ip_servidor puerto \n", argv[0]);
		exit(0);
    }

    SocketMulticast sm = SocketMulticast(0);
    PaqueteDatagrama p = PaqueteDatagrama(100);
    p.inicializaIp(argv[1]);
    p.inicializaPuerto(atoi(argv[2]));
    p.inicializaDatos("Hola mundo");

    while((sm.envia(p,10)) > 0) {
        cout << "\nMensaje enviado" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        cout << "Datos: " << p.obtieneDatos() << endl; 
        cout << "Longitud: " << p.obtieneLongitud() << endl;
    }
    return 0;
}