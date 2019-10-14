#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    Respuesta resp(7200);
    cout << "Servidor iniciado....\n";
    int nbd = 0;
    while (true) {
        struct mensaje *msj = resp.getRequest();
        
        if(msj != NULL) {
        	int n = 0;
	        memcpy(&n, &msj->arguments, 4);
	        nbd = nbd + n;
	        printf("\nRecibido: %d \nNBD: %d\n", n, nbd);
	        resp.sendReply((char *)&nbd);
        }
        
    }
}