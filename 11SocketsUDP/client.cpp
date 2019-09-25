#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(){
    SocketDatagrama client = SocketDatagrama(0);
    PaqueteDatagrama dat = PaqueteDatagrama("Hola", 4, "127.0.0.1", 3000);

    if(client.envia(dat)){
        cout << "Mensaje enviado a:" << endl;
        cout << "IP: " << dat.obtieneDireccion() << endl;
        cout << "Puerto: " << dat.obtienePuerto() << endl;
        cout << "Datos: " << dat.obtieneDatos() << endl;
        cout << "Longitud: " << dat.obtieneLongitud() << endl;
    }

    SocketDatagrama client2 = SocketDatagrama(666);
    PaqueteDatagrama dat2 = PaqueteDatagrama("Adios", 5, "127.0.0.1", 3000);

    if(client2.envia(dat2)){
        cout << "\nMensaje enviado a:" << endl;
        cout << "IP: " << dat2.obtieneDireccion() << endl;
        cout << "Puerto: " << dat2.obtienePuerto() << endl;
        cout << "Datos: " << dat2.obtieneDatos() << endl;
        cout << "Longitud: " << dat2.obtieneLongitud() << endl;
    }
    return 0;
}