#include <iostream>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;

int PoligonoIrreg::numVertices = 0;

int PoligonoIrreg::getNumVertices(){
	return numVertices;
}

PoligonoIrreg::PoligonoIrreg() {}

void PoligonoIrreg::imprimeVertices()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << "Vertice: (" << vertices.at(i).obtenerX() << "," << vertices.at(i).obtenerY() << ")" << endl;
    }
}

void PoligonoIrreg::anadeVertice(Coordenada coord)
{
    vertices.push_back(coord);
    numVertices++;
}


