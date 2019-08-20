#ifndef PROGRAMA4_H_
#define PROGRAMA4_H_

class NumerosRand {
    private:
        int *arreglo;
        unsigned int numeroElementos;
    public:
        NumerosRand(unsigned int num);
        void inicializaNumerosRand(void);
        ~NumerosRand(); //Destructor
};
#endif