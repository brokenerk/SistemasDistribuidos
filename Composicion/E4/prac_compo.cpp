#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

int main()
{
	Rectangulo rectangulo1(Coordenada(3.61, 56.31), Coordenada(5.1, 11.31));
	double ancho, alto;
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
	rectangulo1.imprimeEsq();
	alto = rectangulo1.obtieneSupIzq().obtenerY() - rectangulo1.obtieneInfDer().obtenerY();
	ancho = rectangulo1.obtieneInfDer().obtenerX() - rectangulo1.obtieneSupIzq().obtenerX();
	cout << "El área del rectángulo es = " << rectangulo1.obtieneArea(alto, ancho) << endl;
	return 0;
}