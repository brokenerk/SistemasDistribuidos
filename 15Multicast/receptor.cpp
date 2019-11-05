#include "SocketMulticast.h"
#include "SocketDatagrama.h"


int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Forma de uso: %s ip_servidor\n", argv[0]);
		exit(0);
    }

    SocketMulticast sm = SocketMulticast(3030);
    PaqueteDatagrama p = PaqueteDatagrama(8);
    sm.unirseGrupo(argv[1]);
    int cont = 0;

    while(sm.recibe(p)) {
        cout << "\nMensaje " << cont << " recibido" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        int n[2];
        memcpy(&n , p.obtieneDatos(), 8);
        int resul[1];
        resul[0] = n[0] + n[1]; 
       
        cout << "numero 1: " << n[0] << endl;
        cout << "numero 2: " << n[1] << endl;
        cout << "Longitud: " << p.obtieneLongitud() << endl;
        cout << "Enviando resultado: " << resul[0] << endl;

        PaqueteDatagrama respuesta = PaqueteDatagrama(4);
        respuesta.inicializaIp(p.obtieneDireccion());
        respuesta.inicializaDatos((char*)resul);
        respuesta.inicializaPuerto(7200);
        SocketDatagrama s = SocketDatagrama(0);
        s.envia(respuesta);
        cont++;
    }

    return 0;
}