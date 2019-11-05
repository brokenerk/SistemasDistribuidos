#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[]) {
	if(argc != 4) {
        printf("Forma de uso: %s ip_servidor n1 n2 \n", argv[0]);
		exit(0);
    }

    int n[2];
    n[0] = atoi(argv[2]);
    n[1] = atoi(argv[3]);

    SocketMulticast sm = SocketMulticast(0);
    PaqueteDatagrama p = PaqueteDatagrama((char*)&n, 8, argv[1], 3030);
    int cont = 0;

    while((sm.envia(p, 1)) > 0) {
        cout << "\nMensaje " << cont << " enviado" << endl;
        cout << "IP: " << p.obtieneDireccion() << endl;
        cout << "Puerto: " << p.obtienePuerto() << endl;
        cout << "Longitud: " << p.obtieneLongitud() << endl;
        SocketDatagrama  s = SocketDatagrama(7200);
        PaqueteDatagrama respuesta = PaqueteDatagrama(4);
        s.recibeTimeout(respuesta, 2, 500);
        int resul = 0;
        memcpy(&resul , respuesta.obtieneDatos(), 4);
        cout << "Mensaje recibido" << endl;
        cout << "IP: " << respuesta.obtieneDireccion() << endl;
        cout << "Resultado: " << resul <<endl;  
        cont++; 
    }
    return 0;
}