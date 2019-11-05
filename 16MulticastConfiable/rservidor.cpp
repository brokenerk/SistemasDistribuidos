#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Forma de uso: %s ip_servidor\n", argv[0]);
        exit(0);
    }

    SocketMulticast sm = SocketMulticast(3030);
    PaqueteDatagrama p = PaqueteDatagrama(4);
    sm.unirseGrupo(argv[1]);
    cout << "Servidor iniciado....\n";
    int nbd[1];
    nbd[0] = 0;

    SocketDatagrama s = SocketDatagrama(0);

    while (true) {
        if(sm.recibe(p)) {
            int n = 0;
            memcpy(&n , p.obtieneDatos(), 4);
            nbd[0] = nbd[0] + n;
            printf("\nRecibido: %d \nNBD: %d\n", n, nbd[0]);

            PaqueteDatagrama respuesta = PaqueteDatagrama(4);
            respuesta.inicializaIp(p.obtieneDireccion());
            respuesta.inicializaDatos((char*)nbd);
            respuesta.inicializaPuerto(7200);
            s.envia(respuesta);
        }
    }
}