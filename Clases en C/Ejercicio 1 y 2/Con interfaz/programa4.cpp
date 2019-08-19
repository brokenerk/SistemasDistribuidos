#include "Fecha.h"
#include <iostream>
using namespace std;
int main()
{
    Fecha a, b, c(21, 9, 2016);
    b.inicializaFecha(1, 4 ,2014);
    a.muestraFecha();

    b.muestraFecha();
    if(b.leapyr())
        cout << "Es bisiesto" << endl;
    else
        cout << "No es bisiesto" << endl;

    c.muestraFecha();
    if(c.leapyr())
        cout << "Es bisiesto" << endl;
    else
        cout << "No es bisiesto" << endl;
}