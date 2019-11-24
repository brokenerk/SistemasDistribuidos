#include "Respuesta.h"
#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
using namespace std;

int main(int argc,char * argv[]) {
    if (argc != 2) {
        printf("Forma de uso: %s puerto\n", argv[0]);
        exit(0);
    }
    Respuesta resp(atoi(argv[1]));
    int cont = 0;
    cout << "Servidor Tiempo iniciado....\n";
    while(true) {
        struct mensaje *msj = resp.getRequest();
        if(msj != NULL) {
            struct timeval actual;
            gettimeofday(&actual,NULL);
            cout << actual.tv_sec << endl;
            cout << actual.tv_usec << endl;
            resp.sendReply((char *)&actual);
            cont++;
            cout << cont << endl;
        }
    }
}