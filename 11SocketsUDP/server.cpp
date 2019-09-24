#include "SocketDatagrama.h"
#include <iostream>
using namespace std;
int main(){
    SocketDatagrama server = SocketDatagrama(3000);
    PaqueteDatagrama paquete = PaqueteDatagrama(3000);
    while(true){
        server.recibe(paquete);
        cout<<paquete.obtieneDatos()<<endl;
    }
}