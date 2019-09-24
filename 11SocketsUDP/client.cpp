#include "SocketDatagrama.h"
#include <iostream>
int main(){
    SocketDatagrama client = SocketDatagrama(3000);
    PaqueteDatagrama dat = PaqueteDatagrama("Hola",4,"127.0.0.1",3000);
    client.envia(dat);
}