#include "Coordenada.h"
#include <iostream>
#include <cmath>
using namespace std;

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {
   mag= x*x+y*y;
        mag=sqrt(mag);
 }

double Coordenada::obtenerX() {
	return x;
}
double Coordenada::obtenerMag() {
	return mag;
}

double Coordenada::obtenerY() {
	return y;
}
