#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <vector>
#include <time.h>
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	int n = 10;
	PoligonoIrreg pIr;
	pIr.reservarVertices(n);

	for(int i = 0; i < n; i++) {
		double x = (double) rand() / RAND_MAX ;
		x = -100.0 + x * (100 + 100); 
		
		double y = (double) rand() / RAND_MAX ;
		y = -100.0 + y * (100 + 100); 
		
		pIr.anadeVertice(Coordenada(x, y));
	}
	
	pIr.imprimeVertices();
	pIr.ordenaA();
	cout << endl << "Ordenado por magnitud" << endl;
	pIr.imprimeVertices();
	return 0;
}