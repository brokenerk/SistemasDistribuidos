#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>

class PoligonoIrreg
{
private:
    std::vector<Coordenada> vertices;
    static int numVertices;

public:
    void imprimeVertices();
    void anadeVertice(Coordenada coord);
    static int getNumVertices();
    PoligonoIrreg();
};
#endif