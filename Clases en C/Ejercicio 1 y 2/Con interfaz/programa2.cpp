#include "Fecha.h"
#include <iostream>
using namespace std;
int main()
{
    Fecha a, b, c(21, 9, 2030);
    b.inicializaFecha(17, 6, 2000);
    a.muestraFecha();
    b.muestraFecha();
    c.muestraFecha();
}
