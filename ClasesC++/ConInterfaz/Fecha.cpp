#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) {
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
    mes = mm;
    dia = dd;
    anio = aaaa;
    return;
}

void Fecha::muestraFecha() {
    cout << "La fecha es(dia-mes-anio): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

int Fecha::convierte() {
    int convertido = anio * 10000;
    convertido = convertido + (mes * 100);
    convertido = convertido + dia;
    return convertido;
}

bool Fecha::leapyr() {
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        return true;
    else
        return false;
}
