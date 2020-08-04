#include <iostream> 
using namespace std;

//Algoritmo Babilonico
double raiz(double x) {
	double r = x, t = 0.0;

	while(r != t) {
		t = r;
		r = ((x / r) + r) / 2.0;
	}

	return r;
}

int main() {
	double n = 0.0;
	cout << "Algoritmo Babilonico" << endl;
	cout << "Ingrese n: ";
	cin >> n;

	//Precision 4 decimales
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	cout << "Raiz de n: ";
	cout << raiz(n);
	return 0;
}