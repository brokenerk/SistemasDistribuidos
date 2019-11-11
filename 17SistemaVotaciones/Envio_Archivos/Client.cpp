#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "FileOpener.h"
#include <string.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
    //argv[1] Ruta archivo
    SocketDatagrama client = SocketDatagrama(0);
    PaqueteDatagrama listener = PaqueteDatagrama(3);
    //1 IP
    //2 Puerto
    //3 Archivo
    listener.inicializaIp(argv[1]);
    listener.inicializaPuerto(atoi(argv[2]));
        int n =0;
        if(n=(client.envia(listener))){
            if(client.recibe(listener)==3){
                cout<<"Enviando"<<endl;
                FileOpener f = FileOpener();
                vector <char> datos = f.getInfo(argv[3]);
                int paq_to_send = datos.size()/60000;
                int customs = datos.size()%60000;
                char * buffer = datos.data();
                if(customs>0){
                    paq_to_send++;
                }
                for(int i = 0;i<paq_to_send;i++){
                    if(i==paq_to_send-1){
                        char buf[customs];
                        memcpy(buf,buffer+i*60000,customs);
                        PaqueteDatagrama dat = PaqueteDatagrama(customs);
                        dat.inicializaIp(listener.obtieneDireccion());
                        dat.inicializaPuerto(listener.obtienePuerto());
                        dat.inicializaDatos(buf);
                        client.envia(dat);
                    }else{
                        char buf[60000];
                        memcpy(buf,buffer+i*60000,60000);
                        PaqueteDatagrama dat = PaqueteDatagrama(60000);
                        dat.inicializaIp(listener.obtieneDireccion());
                        dat.inicializaPuerto(listener.obtienePuerto());
                        dat.inicializaDatos(buf);
                        client.envia(dat);
                    }
                    cout<<"Paquete "<<i<<endl;
                    sleep(1);
                }
                char * buf="A";
                PaqueteDatagrama dat = PaqueteDatagrama(1);
                dat.inicializaIp(listener.obtieneDireccion());
                dat.inicializaPuerto(listener.obtienePuerto());
                dat.inicializaDatos(buf);
                client.envia(dat);
            }
        }
    return 0;
}