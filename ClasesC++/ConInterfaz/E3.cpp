#include "Fecha.h"
#include <iostream>
using namespace std;

int main() {
    Fecha a, b, c(21, 9, 2030);
    b.inicializaFecha(17, 6, 2000);
    a.muestraFecha();
    cout << "Convertido: " << a.convierte() << endl;
    b.muestraFecha();
    cout << "Convertido: " << b.convierte() << endl;
    c.muestraFecha();
    cout << "Convertido: " << c.convierte() << endl;
}
