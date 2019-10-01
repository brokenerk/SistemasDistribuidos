#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    Respuesta resp(7200);

    while (true)
    {
        struct mensaje* msj = resp.getRequest();
        //cout << "Datos recibidos:" << endl;
        printf("%d %d\n", msj->arguments[0], msj->arguments[1]);
        int res = msj->arguments[0] + msj->arguments[1];
        //cout << "Enviando.." << endl;
        printf("%d\n", res);
        resp.sendReply((char*) &res);
    }
}