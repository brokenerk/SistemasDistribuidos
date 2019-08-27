#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

static int numVertices = 0;

static int getNumVertices(){
	return numVertices;
}

int main() {
	cout << "Usando reserve" << endl;
	vector<PoligonoIrreg> v;
	int n = 2000, m = 3000;
	int vertices = rand() % m + 1;
	v.reserve(n);

	for(int i = 0; i < n; i++) {
		PoligonoIrreg p;
		p.reservarVertices(m);
		for(int j = 0; j < vertices; j++) {
			p.anadeVertice(Coordenada(i, j));
			numVertices++;
		}
		v.push_back(p);
	}

	cout << n << " objetos creados" << endl;
	cout << "Vertices creados: " << getNumVertices() << endl;
	return 0;
}