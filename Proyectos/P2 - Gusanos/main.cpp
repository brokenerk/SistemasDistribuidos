#include "Gusano.h"
#include <thread>
#include <vector>
#include <ctime>
#include <atomic>
#include <iostream>
using namespace std;
int width = 600.0;
int height = 600.0;

void iniciarHilo(atomic<double> &lon) {
	Gusano g(lon);
	g.moverse(width, height);
}

int main(int argc, char* argv[]) {
	if(argc != 2) {
		cout << "Error. Forma de ejecucion: " << argv[0] << " num_gusanos" << endl;
		exit(0);
	}
	srand(time(NULL));
	gfx_open(width, height, "Animacion Gusanos");

	int n = atoi(argv[1]);
	//Vector de n hilos para n gusanos
	vector<thread> hilos;
	hilos.reserve(n);
	//Atomic para enviar parametros a funcion del hilo
	atomic<double> longitud(25.0 + (double) rand() / RAND_MAX * 10.0);
	
	for(int i = 0; i < n; i++) {
		hilos.push_back(thread(iniciarHilo, ref(longitud)));
	}

	//Join de los hilos del vector
	for(int i = 0; i < hilos.size(); i++) {
		hilos.at(i).join();
	}
	
	return 0;
}