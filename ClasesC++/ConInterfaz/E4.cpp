#include "Fecha.h"
#include <iostream>
using namespace std;

int main() {
    Fecha a, b, c(21, 9, 2016);
    b.inicializaFecha(1, 4 ,2014);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();

    int cont = 0;
    for(int i = 1; i <= 2019; i++) {
        Fecha t(1,1,i);
        if(t.leapyr())
            cont++;       
    }

    cout << cont << endl;
}