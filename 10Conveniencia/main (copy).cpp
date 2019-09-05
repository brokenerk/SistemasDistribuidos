#include <iostream>
#include <unistd.h>
#include <thread>
#define numeroElementos 2000000000
using namespace std;
void ramuse(){
    int *arreglo, i;
    arreglo = new int[numeroElementos];
    for(i = 0; i < numeroElementos; i++)
        arreglo[i] = 0;
        for(i = 0; i < 100000000; i++){
    arreglo[rand()%numeroElementos] = rand();
    }
}
void ramuse2(){
    int *arreglo, i;
    arreglo = new int[numeroElementos];
    for(i = 0; i < numeroElementos; i++)
        arreglo[i] = 0;
        for(i = 0; i < 100000000; i++){
    arreglo[rand()%numeroElementos] = rand();
    }
}
int main() {
    thread th1(ramuse), th2(ramuse2);
    th1.join();
    th2.join();
    exit(0);
}