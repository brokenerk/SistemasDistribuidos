#include <iostream>
#include <unistd.h>
#include <thread>
#include <cmath> 
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
void useCPU(){
    double m = 120760000.0;
    double i = 0.0;
	double seno1 = 0.0;
	double cos1 = 0.0;
	double tan1 = 0.0;
	double log1 = 0.0;
	double raiz1 = 0.0;
	while(i < m) {
		seno1 += sin(i);
		cos1 += cos(i);
		tan1 += tan(i);
		log1 += log(i);
		raiz1 += sqrt(i);
		i += 1;
	}
}
void useCPU2(){
    double m = 120760000.0;
    double i = 0.0;
	double seno1 = 0.0;
	double cos1 = 0.0;
	double tan1 = 0.0;
	double log1 = 0.0;
	double raiz1 = 0.0;
	while(i < m) {
		seno1 += sin(i);
		cos1 += cos(i);
		tan1 += tan(i);
		log1 += log(i);
		raiz1 += sqrt(i);
		i += 1;
	}
}
int main() {
    thread th1(ramuse), th2(useCPU2);
    th1.join();
    th2.join();
    exit(0);
}