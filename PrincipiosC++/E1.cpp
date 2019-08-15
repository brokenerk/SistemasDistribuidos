#include <iostream>
using namespace std;
const double PI = 3.1415926;

int main() {
	float radio;
	cout << "Ingrese el radio del circulo: ";
	cin >> radio;
	cout << "Area: " << PI * radio * radio << endl;
	return 0;
}