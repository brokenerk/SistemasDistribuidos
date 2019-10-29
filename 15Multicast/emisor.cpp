#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[]) {
	if(argc != 3) {
        printf("Forma de uso: %s ip_servidor puerto \n", argv[0]);
		exit(0);
    }
    int  n[2];
    n[0]=2;
    n[1]=1;

    SocketMulticast sm = SocketMulticast(0);
    PaqueteDatagrama p = PaqueteDatagrama(100);
    p.inicializaIp(argv[1]);
    p.inicializaPuerto(atoi(argv[2]));
    p.inicializaDatos((char *) n );

    while((sm.envia(p,10)) > 0) {
        cout << "\nMensaje enviado" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        cout << "Datos: " << p.obtieneDatos() << endl; 
        cout << "Longitud: " << p.obtieneLongitud() << endl;
         SocketDatagrama  sr = SocketDatagrama(7200);
         PaqueteDatagrama respuesta = PaqueteDatagrama(4);
         sr.recibe(respuesta);
         int resul=0;
         memcpy(&resul , respuesta.obtieneDatos(), 4);
         cout << "resul: " << resul <<endl;   
        
    }
    return 0;
}