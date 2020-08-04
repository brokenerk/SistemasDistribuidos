#include "Coordenada.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
#include <iostream>
using namespace std;

int main() {
	Ortoedro ortoedro;
	int origenX, origenY, origenZ, lejosX, lejosY, lejosZ;
	cout << "Ingrese las coordenadas para el vertice mas cercano al origen:" << endl;
	cout << "X: ";
	cin  >> origenX;
	cout << "Y: ";
	cin  >> origenY;
	cout << "Z: ";
	cin  >> origenZ;

	cout << "Ingrese las coordenadas para el vertice mas lejano al origen:" << endl;
	cout << "X: ";
	cin  >> lejosX;
	cout << "Y: ";
	cin  >> lejosY;
	cout << "Z: ";
	cin  >> lejosZ;

	ortoedro.inicializar(Coordenada(origenX, origenY, origenZ), Coordenada(lejosX, lejosY, lejosZ));
	cout << "Vertices del ortoedro en un plano cartesiano de tres dimensiones:\n";
	ortoedro.obtieneVertices();
	cout << "El area de la superficie del ortoedro es = " << ortoedro.obtieneArea() << endl;
	cout << "El volumen del ortoedro es = " << ortoedro.obtieneVolumen() << endl;
	return 0;
}