#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0) { }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer) { }
Rectangulo::Rectangulo(Coordenada,Coordenada){}

void Rectangulo::imprimeEsq()
{
	cout << "Para la esquina superior izquierda.\n";
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
	cout << "Para la esquina inferior derecha.\n";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

Coordenada Rectangulo::obtieneSupIzq() {
	return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer() {
	return inferiorDer;
}
double Rectangulo::obtieneArea(double h, double t){
	return h*t;
}
