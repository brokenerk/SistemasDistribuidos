#include <iostream>
using namespace std;

int main() {
	int entrada = 0, minutos = 0, segundos = 0, horas = 0;
	cin >> entrada;

	if(entrada >= 3600) {
		horas = entrada / 3600;
		entrada = entrada % 3600;
	}

	if(entrada >= 60) {
		minutos = entrada / 60;
		segundos = entrada % 60;
	}
	else
		segundos = entrada;

	cout << horas << " horas " << minutos << " minutos " << segundos << " segundos" << endl;
	return 0;
}