#include <iostream> 
using namespace std;
const double g = 9.81;

int main() {
	double tiempo = 0.0;
	cout << "Altura edificio" << endl;
	cout << "Ingrese el tiempo: ";
	cin >> tiempo;
	//Formula MRUA
	cout << "Altura = " << (g * tiempo * tiempo) / 2 << " m" << endl;
}