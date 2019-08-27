#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <cstdlib>
#include <vector>
#include <time.h> 
#include <iostream>

using namespace std;



int main() {
	srand(time(NULL));
	//cout << "Sin usar push_back" << endl;
	int m=2000;
	PoligonoIrreg pIn;
	int vertices = rand() % m + 50;
	pIn.reservarVertices(vertices);

		for(int j = 0; j < vertices; j++) {
			float x =(float)rand()/RAND_MAX ;
			x=-100.0 +x *(100+100); 
			
			float y =(float)rand()/RAND_MAX ;
			y=-100.0 +y *(100+100); 
			
			
			pIn.anadeVertice(Coordenada(x, y));
			
		}
pIn.imprimeVertices();
	
	

	return 0;
}