#include "PCLab.h"
#include <iostream>
using namespace std;

int main(){
    PCLab pc;
    cout << "Servidor iniciado....\n";

    while (true) {
        pc.recibePeticion();
        pc.capturaPantalla();
        pc.enviaImagen();
    }
}