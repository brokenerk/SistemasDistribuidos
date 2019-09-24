#include "SocketDatagrama.h"
#include <iostream>
using namespace std;
int main(){
    SocketDatagrama client = SocketDatagrama(0);
    PaqueteDatagrama dat = PaqueteDatagrama("Hola",4,"127.0.0.1",3000);
    if(client.envia(dat)){
        cout<<"Mensaje enviado"<<endl;
    }
}