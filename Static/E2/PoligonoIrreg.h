#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
using namespace std;

class PoligonoIrreg {
	private:
	    vector<Coordenada> vertices;

	public:
	    void imprimeVertices();
	    void anadeVertice(Coordenada coord);
	    PoligonoIrreg();
};
#endif