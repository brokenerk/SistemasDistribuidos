#include "SocketMulticast.h"

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Forma de uso: %s ip_emisor\n", argv[0]);
        exit(0);
    }
    SocketMulticast sm = SocketMulticast(3030);
    PaqueteDatagrama p = PaqueteDatagrama(sizeof(struct mensaje*));
    sm.unirseGrupo(argv[1]);
    cout << "Servidor iniciado....\n";
    int nbd[1];
    nbd[0] = 0;
    SocketDatagrama s = SocketDatagrama(0);
    while (true) {
        if(sm.recibeConfiable(p) != -1) {
            int n = 0;
            memcpy(&n, p.obtieneDatos(), 4);
            nbd[0] = nbd[0] + n;
            printf("Recibido: %d \nNBD: %d\n\n", n, nbd[0]);
            /*
            PaqueteDatagrama respuesta = PaqueteDatagrama(4);
            respuesta.inicializaIp(p.obtieneDireccion());
            respuesta.inicializaDatos((char*)nbd);
            respuesta.inicializaPuerto(7200);
            s.envia(respuesta);
            cout<<"enviado"<<endl;
            */
		}
    }
}