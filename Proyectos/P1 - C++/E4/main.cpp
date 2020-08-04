#include "Temperatura.h"
#include <iostream>
using namespace std;

int main() {
	Temperatura t;
	double grados;
	int op, escala = 1, rep = 1;

	do {
		cout << "\n\nSeleccione una opcion" << endl;
		cout << "1.- Ingresar Temperatura" << endl;
		cout << "2.- Mostrar Temperatura" << endl;
		cin >> op;

		cout << "\nSelecciona la escala" << endl;
		cout << "1.- Kelvin" << endl;
		cout << "2.- Farenheit" << endl;
		cout << "3.- Celsius" << endl;
		cin >> escala;

		if(op == 1) {
			cout << "Ingrese los grados: ";
			cin >> grados;

			if(escala == 1){
				t.setTempKelvin(grados);
				t.mostrarKelvin();
			}
			else if(escala == 2){
				t.setTempFarenheit(grados);
				t.mostrarFarenheit();
			}
			else{
				t.setTempCelsius(grados);
				t.mostrarCelsius();
			}
		}
		else {
			if(escala == 1)
				t.mostrarKelvin();
			else if(escala == 2)
				t.mostrarFarenheit();
			else
				t.mostrarCelsius();
		}

		cout << "\nSalir? No = 1 / Si = 0" << endl;
		cin >> rep;

	} while(rep == 1);

	return 0;
}