#include "SocketMulticast.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Forma de uso: %s ip_servidor puerto \n", argv[0]);
		exit(0);
    }

    SocketMulticast sm = SocketMulticast(atoi(argv[2]));
    PaqueteDatagrama p = PaqueteDatagrama(100);
    sm.unirseGrupo(argv[1]);

    while(sm.recibe(p)) {
        cout << "\nMensaje recibido" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        //cout << "Datos: " << p.obtieneDatos() << endl; 
        int n[2];
        memcpy(&n , p.obtieneDatos(), 8);
        int resul= n[0]+n[1]; 
        cout <<"resultado " << resul << endl;
        cout << "Longitud: " << p.obtieneLongitud() << endl;
    }
    return 0;
}