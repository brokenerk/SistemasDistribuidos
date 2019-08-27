#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
#include <cmath>
using namespace std;

PoligonoIrreg::PoligonoIrreg() {}

void PoligonoIrreg::imprimeVertices() {
    std::vector<Coordenada>::iterator i;
    cout<<vertices.size()<<endl;
    for (i = vertices.begin(); i != vertices.end(); i++) {
       
        Coordenada c=*i;
        double mag= c.obtenerX()*c.obtenerX()+c.obtenerY()*c.obtenerY();
        mag=sqrt(mag);
        cout << "Vertice: (" <<c.obtenerX() << "," << c.obtenerY() << ") magnitud: " << mag<< endl;
        cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);
    }
}

void PoligonoIrreg::anadeVertice(Coordenada coord) {
    vertices.push_back(coord);
}

void PoligonoIrreg::reservarVertices(int tam) {
    vertices.reserve(tam);
}

void PoligonoIrreg::anadeVerticeSinPush(Coordenada coord, int i) {
    vertices[i] = coord;
}
