#include <iostream>
#include <stdlib.h>
using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha(int = 3, int = 4, int = 2014);
    void inicializaFecha(int, int, int);
    void muestraFecha();
    int convierte();
    bool leapyr();
};

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa)
{
    if (dd < 1 || dd > 31)
    {
        cout << "Dia erroneo" << endl;
        exit(0);
    }
    if (mm < 1 || mm > 12)
    {
        cout << "Mes erroneo" << endl;
        exit(0);
    }
    if (aaaa < 0 || aaaa > 2019)
    {
        cout << "Anio erroneo" << endl;
        exit(0);
    }
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
    if (dd < 1 || dd > 31)
    {
        cout << "Dia erroneo" << endl;
        exit(0);
    }
    if (mm < 1 || mm > 12)
    {
        cout << "Mes erroneo" << endl;
        exit(0);
    }
    if (aaaa < 0 || aaaa > 2019)
    {
        cout << "Anio erroneo" << endl;
        exit(0);
    }
    mes = mm;
    dia = dd;
    anio = aaaa;
    return;
}

void Fecha::muestraFecha()
{
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

int Fecha::convierte()
{
    int convertido = anio * 10000;
    convertido = convertido + (mes * 100);
    convertido = convertido + dia;
    return convertido;
}

bool Fecha::leapyr()
{
    bool bisiesto = false;
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    {
        bisiesto = true;
    }
    return bisiesto;
}
