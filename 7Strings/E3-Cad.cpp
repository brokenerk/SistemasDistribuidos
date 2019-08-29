#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

char* randomString() {
	char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char palabra[4];

	for(int i = 0; i < 3; i++) {
		int aleat = rand() % 25;
		palabra[i] = alfabeto[aleat];
	}

	palabra[3] = ' ';
	return palabra;
}

int search(char* cad, char* pat) {
	int veces = 0;
	int M = strlen(pat);
	int N = strlen(cad);
	
	for(int i = 0; i <= N - M; i++) {
		int j;

		for(j = 0; j < M; j++)
			if(cad[i + j] != pat[j])
				break;

		if(j == M)
			veces++;
	}

	return veces;
}

int main() {
	srand(time(NULL));
	int n = 0;

    cout << "Teclea n: ";
    cin >> n;
    char* cadenota = NULL;

    for (int i = 0; i < n; i++) {
    	cadenota = (char*)realloc(cadenota, i * 4 + 4);
    	char* a = randomString();
		strcat(cadenota, a);
    }

    cout << "Cadenota: ";
    for(int i = 0; i < strlen(cadenota); i++) {
    	cout << cadenota[i];
    }
    cout << endl;

    char sub[] = "IPN";
    cout << "Subcadena '" << sub << "'' encontrada: " << search(cadenota, sub) << " veces" << endl;
    return 0;
}

