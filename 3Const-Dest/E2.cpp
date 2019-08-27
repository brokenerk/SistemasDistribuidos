#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

class Fecha {
	public:
		int dia;
	    int mes;
	    int anio;
	    Fecha(int = 3, int = 4, int = 2014);
	    void inicializaFecha(int, int, int);
	    void muestraFecha();
	    char bytes[10000];
};

Fecha::Fecha(int dd, int mm, int aaaa) {
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}

void Fecha::muestraFecha() {
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

int masVieja(Fecha fecha1, Fecha fecha2) {
	if(fecha1.anio > fecha2.anio)
		return 1;
	else if(fecha1.anio == fecha2.anio) {
		if(fecha1.mes > fecha2.mes)
			return 1;
		else if(fecha1.mes == fecha2.mes) {
			if(fecha1.dia > fecha2.dia)
				return 1;
			else if(fecha1.dia == fecha2.dia)
				return 0;
			else
				return -1;
		}
		else
			return -1;
	}
	else
		return -1;	
}

int main() {
	srand (time(NULL));

    for(int i = 0; i <100000; i++) {
    	int anio1 = rand() % 40000000 + 1;
    	int mes1 = rand() % 12 + 1;
    	int dia1 = rand() % 30 + 1;

    	int anio2 = rand() % 40000000 + 1; 
    	int mes2 = rand() % 12 + 1;
    	int dia2 = rand() % 30 + 1;

    	Fecha a(dia1, mes1, anio1), b(dia2, mes2, anio2); 
    	masVieja(a, b);
   	} 
}
