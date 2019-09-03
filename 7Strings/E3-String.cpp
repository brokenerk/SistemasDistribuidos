#include <iostream>
#include <time.h>
#include <string>
using namespace std;

string randomString() {
	string alfabeto("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string palabra = "";

	for(int i = 0; i < 3; i++) {
		int aleat = rand() % 25;
		palabra.insert(i, 1, alfabeto.at(aleat));
	}
	palabra.insert(3, 1, ' ');
	return palabra;
}

int search(string cad, string pat) {
	int veces = 0;
	size_t pos = cad.find(pat);

	while(pos != string::npos) {
		pos = cad.find(pat, pos + 1);
		veces++;
	}

	return veces;
}

int main() {
	srand(time(NULL));
	int n = 0;

    cout << "Teclea n: ";
    cin >> n;
    string cadenota = "";

    for (int i = 0; i < n; i++)
    	cadenota.insert(4 * i, randomString());

    //cout << "Cadenota: " << cadenota << endl;

    string sub("IPN");
    cout << "Subcadena '" << sub << "'' encontrada: " << search(cadenota, sub) << " veces" << endl;
    return 0;
}