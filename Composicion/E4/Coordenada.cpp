#include "Coordenada.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define degToRad(angleInDegrees) ((angleInDegrees)*M_PI / 180.0)
using namespace std;

Coordenada::Coordenada(double xx, double yy)
{
	x = xx * sin(degToRad(yy));
	y = xx * cos(degToRad(yy));
}

double Coordenada::obtenerX()
{
	return x;
}

double Coordenada::obtenerY()
{
	return y;
}