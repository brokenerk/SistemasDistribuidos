#include "SocketMulticast.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Forma de uso: %s ip_servidor \n", argv[0]);
		exit(0);
    }
    SocketMulticast sm = SocketMulticast(0);
    PaqueteDatagrama p = PaqueteDatagrama(100);
    sm.unirseGrupo(argv[1]);
    while(sm.recibe(p)){
        cout << "Mensaje recibido" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        cout << "Datos: " << p.obtieneDatos() << endl; 
        cout << "Longitud: " << p.obtieneLongitud() << endl;
    }
    return 0;
}