#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
using namespace std;

int main()
{
	PoligonoIrreg poligono;
	poligono.anadeVertice(Coordenada(0, 1));
	poligono.anadeVertice(Coordenada(0, 2));
	poligono.anadeVertice(Coordenada(1, 1));
	poligono.anadeVertice(Coordenada(1, 2));
	poligono.imprimeVertices();
}