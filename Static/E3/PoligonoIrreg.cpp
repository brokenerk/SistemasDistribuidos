#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
using namespace std;

PoligonoIrreg::PoligonoIrreg() {}

void PoligonoIrreg::imprimeVertices() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << "Vertice: (" << vertices.at(i).obtenerX() << "," << vertices.at(i).obtenerY() << ")" << endl;
    }
}

void PoligonoIrreg::anadeVertice(Coordenada coord) {
    vertices.push_back(coord);
}
