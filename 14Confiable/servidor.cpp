#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    Respuesta resp(7200);
    int nbd = 0;
    while (true)
    {
        cout << "Servidor iniciado....\n";
        struct mensaje *msj = resp.getRequest();
        int n[64999];
        memcpy(&n, &msj->arguments, sizeof(msj->arguments));
        int res = n[0];
        nbd = nbd + res;
        n[0] = nbd;
        resp.sendReply((char *)&n);
    }
}