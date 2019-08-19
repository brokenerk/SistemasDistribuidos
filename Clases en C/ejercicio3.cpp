#include <iostream>
using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha (int= 3 , int= 4, int =2014);
        void inicializaFecha (int, int , int);
        void muestraFecha();
        int convierte();
};
Fecha::Fecha (int dd, int mm, int aaaa)
{
    mes=mm;
    dia=dd;
    anio=aaaa;
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
    anio=aaaa;
    mes=mm;
    dia=dd;
    return;
}
void Fecha::muestraFecha()
{
    cout << "La fecha es (dia-mes-año):" <<dia << "=" <<mes << "=" << anio << endl;
    return;
}
int Fecha::convierte()
{
    int convertido = anio*10000;
    convertido=convertido + (mes*100);
    convertido=convertido + dia;
    return convertido;
}
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