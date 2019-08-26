#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>

class PoligonoIrreg
{
private:
    std::vector<Coordenada> vertices;

public:
    void imprimeVertices();
    void anadeVertice(Coordenada coord);
    PoligonoIrreg();
};
#endif