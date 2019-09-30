#include <string.h>
#include <cstdlib>
#include "PaqueteDatagrama.h"
PaqueteDatagrama::PaqueteDatagrama(char * data,unsigned int datatam, char * dir,int port){
    datos=new char[datatam];
    memcpy(datos,&data,datatam);
    memcpy(ip,&dir,16);
    longitud=datatam;
    puerto=port;
}
PaqueteDatagrama::PaqueteDatagrama(unsigned int tam){
    longitud=tam;
    datos = new char[tam];
}
PaqueteDatagrama::~PaqueteDatagrama(){
    delete datos;
}

char * PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char * PaqueteDatagrama::obtieneDatos(){
    return datos;
}
void PaqueteDatagrama::inicializaPuerto(int port){
    puerto=port;
}
void PaqueteDatagrama::inicializaIp(char * dir){
    memcpy(ip,&dir,16);
}
void PaqueteDatagrama::inicializaDatos(char * data){
    if(longitud>0){
        memcpy(datos,&data,longitud);
    }else{
        memcpy(datos,&data,65507);
    }
}
