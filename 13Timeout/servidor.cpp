#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    Respuesta resp(7200);

    while (true) {
    	cout << "Servidor iniciado....\n";
        struct mensaje* msj = resp.getRequest();

        int n[2];
        memcpy(&n, &msj->arguments, sizeof(msj->arguments));
        printf("Datos recibidos: %d %d\n", n[0], n[1]);

        int res = n[0] + n[1];
        printf("\nEnviando respuesta: %d\n", res);
        resp.sendReply((char*) &res);
    }
}