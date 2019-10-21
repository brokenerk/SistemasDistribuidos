#include "SocketMulticast.h"

int main(int argc, char *argv[]){
    SocketMulticast sm = SocketMulticast(atoi(argv[2]));
    PaqueteDatagrama p = PaqueteDatagrama(100);
    sm.unirseGrupo(argv[1]);
    p.inicializaDatos("Hola mundo");
    while(sm.envia(p,(unsigned char)1)){
        cout << "Mensaje enviado" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        cout << "Datos: " << p.obtieneDatos() << endl; 
        cout << "Longitud: " << p.obtieneLongitud() << endl;
    }
    return 0;
}