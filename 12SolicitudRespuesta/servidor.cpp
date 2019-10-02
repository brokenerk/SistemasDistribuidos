#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    Respuesta resp(7200);

    while (true)
    {
    	cout << "Servidor iniciado....\n";
        struct mensaje* msj = resp.getRequest();

        printf("Datos recibidos: %d %d\n", msj->arguments[0], msj->arguments[1]);
        int res = msj->arguments[0] + msj->arguments[1];

        printf("\nEnviando respuesta: %d\n", res);
        resp.sendReply((char*) &res);
    }
}