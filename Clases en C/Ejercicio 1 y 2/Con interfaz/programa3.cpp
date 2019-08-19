#include "Fecha.h"
#include <iostream>
using namespace std;
int main()
{
    Fecha a ,b , c(21, 9,1973);
    b.inicializaFecha(1, 4 ,2014);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
    int convertir=b.convierte();
    cout    << "el valor convertido: " << convertir << endl; 

}