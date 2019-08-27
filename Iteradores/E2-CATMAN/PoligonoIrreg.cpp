#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
#include <algorithm>
using namespace std;

PoligonoIrreg::PoligonoIrreg() {}

void PoligonoIrreg::imprimeVertices()
{
    std::vector<Coordenada>::iterator i;
    cout << vertices.size() << endl;
    for (i = vertices.begin(); i != vertices.end(); i++)
    {

        Coordenada c = *i;

        cout << "Vertice: (" << c.obtenerX() << "," << c.obtenerY() << ") magnitud: " << c.obtenerMag() << endl;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
    }
}

void PoligonoIrreg::anadeVertice(Coordenada coord)
{
    vertices.push_back(coord);
}

void PoligonoIrreg::reservarVertices(int tam)
{
    vertices.reserve(tam);
}

void PoligonoIrreg::anadeVerticeSinPush(Coordenada coord, int i)
{
    vertices[i] = coord;
}

void PoligonoIrreg::ordenaA()
{
    sort(vertices.begin(), vertices.end(), [](Coordenada &lhs, Coordenada &rhs) {
        return lhs.obtenerMag() < rhs.obtenerMag();
    });
}