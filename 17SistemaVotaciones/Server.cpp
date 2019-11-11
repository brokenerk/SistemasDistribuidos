#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <vector>
#include "FileSaver.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    //1 Puerto
    //2 path
    SocketDatagrama server = SocketDatagrama(atoi(argv[1]));
    PaqueteDatagrama init = PaqueteDatagrama(3);
    if(server.recibe(init)==3){
        cout << "Server iniciado" << endl;
        server.envia(init);
        int i=0;
        string nombre;
        vector <PaqueteDatagrama> paquetes;
        while(i==0) {
            PaqueteDatagrama paquete = PaqueteDatagrama(60000);
            int n;
            if((n=server.recibe(paquete))>0) {
                cout << "\nMensaje recibido de:" << endl;
                cout << "IP: " << paquete.obtieneDireccion() << endl;
                cout << "Puerto: " << paquete.obtienePuerto() << endl;
                cout << "Longitud: " << n << endl;
                if(n==1){
                    i=1;
                }else{
                    PaqueteDatagrama aux = PaqueteDatagrama(n);
                    aux.inicializaDatos(paquete.obtieneDatos());
                    paquetes.push_back(aux);
                }
            }
            nombre=paquete.obtieneDireccion();
        }
        FileSaver f = FileSaver();
        f.saveFile(string(argv[2]).c_str(),paquetes);
    }
}