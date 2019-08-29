#include <iostream>
#include <time.h>
#include <string>
using namespace std;
int veces = 0;

string randomString() {
	string alfabeto("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string palabra = "";

	for(int i = 0; i < 3; i++) {
		int aleat = rand() % 25;
		palabra = palabra + alfabeto.at(aleat);
	}

	return palabra + " ";
}

void search(string cad, string pat, size_t pos) {
	size_t nuevaPos = cad.find(pat, pos);

	if(nuevaPos != string::npos){
		veces++;
		search(cad, pat, nuevaPos + 1);
	}
}

int main() {
	srand(time(NULL));
	int n = 0;

    cout << "Teclea n: ";
    cin >> n;
    string cadenota;

    for (int i = 0; i < n; i++)
    	cadenota = cadenota + randomString();

    cout << "Cadenota: " << cadenota << endl;

    string sub("IPN");
    search(cadenota, sub, 0);
    cout << "Subcadena '" << sub << "'' encontrada: " << veces << " veces" << endl;
    return 0;
}