#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    SocketDatagrama client = SocketDatagrama(0);
    char* msj = (char*)malloc(4 * sizeof(char));
    strcpy(msj, "Hola");
    char* ip = (char*)malloc(4 * sizeof(char));
    strcpy(ip, "127.0.0.1");
    PaqueteDatagrama dat = PaqueteDatagrama(msj, 4, ip, 3000);
    client.envia(dat);
}