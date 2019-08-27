#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

static int numVertices = 0;

static int getNumVertices(){
	return numVertices;
}

int main() {
	//srand(time(NULL));
	cout << "Sin usar push_back" << endl;
	vector<PoligonoIrreg> v;
	int n = 2000;
	int m = 3000;
	int vertices = rand() % m + 1;
	v.reserve(m);


	for(int i = 0; i < n; i++) {
		PoligonoIrreg p;
		p.reservarVertices(vertices);
		for(int j = 0; j < vertices; j++) {
			p.anadeVerticeSinPush(Coordenada(i, j), i);
			numVertices++;
		}
		v[i] = p;
	}

	cout << n << " objetos creados" << endl;
	cout << "Vertices creados: " << getNumVertices() << endl;
	return 0;
}