#include "Coordenada.h"
#include "Rectangulo.h"
#include "PoligonoIrreg.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h> 

using namespace std;

int main() {
	srand(time(NULL));
	vector<PoligonoIrreg> v;
	int n = 20;
	int m = 30;
	int vertices = rand() * m - 1;

	for(int i = 0; i < n; i++) {
		PoligonoIrreg p;
		for(int j = 0; j < vertices; j++) {
			p.anadeVertice(Coordenada(0, 1));
		}
		cout << "Vertices: " << p.getNumVertices() << endl;
		v.push_back(p);
	}



	return 0;
}