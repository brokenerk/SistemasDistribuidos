#include "Numero.h"
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<Numero> cribaEratostenes(int N) {
	vector<Numero> numeros;
	numeros.reserve(N + 1);

	for (int k = 0; k <= N; k++)
		numeros.push_back(Numero(k, true));

	numeros.at(0).setPrimo(false);
	numeros.at(1).setPrimo(false);

	for (int i = 2; i <= sqrt(N); i++){
		if(numeros.at(i).getPrimo()) {
			for (int j = i; j <= N / i; j++)
				numeros.at(i * j).setPrimo(false);
		}
	}

	return numeros;
}

int main() {
	int N;
	cout << "\nCriba de Eratostenes" << endl;
	cout << "Introduce N: ";
	cin >> N;

	vector<Numero> numeros = cribaEratostenes(N);
	std::vector<Numero>::iterator i;

	cout << "Numeros primos hasta el " << N << endl;
	for (i = numeros.begin(); i != numeros.end(); i++){
	 	Numero n = *i;
	 	if(n.getPrimo())
	 		cout << n.getNum() << " ";
	}

	return 0;
}