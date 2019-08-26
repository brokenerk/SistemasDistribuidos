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
	srand(time(NULL));
	vector<PoligonoIrreg> v;
	int n = 2000;
	int m = 3000;
	int vertices = rand() % m + 1;
	v.reserve(n);

	for(int i = 0; i < n; i++) {
		PoligonoIrreg p;
		for(int j = 0; j < vertices; j++) {
			p.anadeVertice(Coordenada(0, 1));
			numVertices++;
		}
		v[i] = p;
		
	}

	cout << n << " objetos creados" << endl;
	cout << "Vertices creados: " << getNumVertices() << endl;
	return 0;
}