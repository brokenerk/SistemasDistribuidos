#include "Fraccion.h"
#include <iostream>
using namespace std;

int main() {
	Fraccion f1, f2(10, 2);
	f1.inicializar(121, 99);

	cout << "Fraccion 1: ";
	f1.mostrar();
	cout << "Calcular: " << f1.calcular() << endl;
	cout << "Min Expresion: ";
	f1.minExpresion();

	cout << "\nFraccion 2: ";
	f2.mostrar();
	cout << "Calcular: " << f2.calcular() << endl;
	cout << "Min Expresion: ";
	f2.minExpresion();

	return 0;
}