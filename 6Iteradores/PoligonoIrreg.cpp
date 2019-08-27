#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

PoligonoIrreg::PoligonoIrreg() {}

void PoligonoIrreg::imprimeVertices() {
    std::vector<Coordenada>::iterator i;

    for (i = vertices.begin(); i != vertices.end(); i++) {
        Coordenada c = *i;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        cout << "Vertice: (" << c.obtenerX() << "," << c.obtenerY() << ") Magnitud: " << c.obtenerMag() << endl;
    }
}

void PoligonoIrreg::anadeVertice(Coordenada coord) {
    vertices.push_back(coord);
}

void PoligonoIrreg::reservarVertices(int tam) {
    vertices.reserve(tam);
}

void PoligonoIrreg::ordenaA() {
    sort(vertices.begin(), vertices.end(), [](Coordenada &lhs, Coordenada &rhs) {
        return lhs.obtenerMag() < rhs.obtenerMag();
    });
}