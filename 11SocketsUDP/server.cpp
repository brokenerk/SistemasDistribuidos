#include "SocketDatagrama.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    SocketDatagrama server = SocketDatagrama(3000);
    cout<<"Server iniciado"<<endl;
    while(true){
        PaqueteDatagrama paquete = PaqueteDatagrama(65507);
        int len =0;
        if(len = server.recibe(paquete)>0){
            cout<<"Mensaje recibido--->len: "<<len<<endl;
            cout<<"IP:"<<(int)paquete.obtieneDireccion()[0]<<"."<<(int)paquete.obtieneDireccion()[1]<<"."<<(int)paquete.obtieneDireccion()[2]<<"."<<(int)paquete.obtieneDireccion()[3]<<endl;
            cout<<"Puerto: "<<paquete.obtienePuerto()<<endl;
            cout<<"Datos:"<<paquete.obtieneDatos()<<endl;
        }
    }
}