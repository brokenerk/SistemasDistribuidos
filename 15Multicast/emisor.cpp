#include "SocketMulticast.h"

int main(){
    SocketMulticast sm = SocketMulticast(7200);
    PaqueteDatagrama p = PaqueteDatagrama(100);
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