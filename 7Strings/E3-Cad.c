#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

    printf("Teclea n: ");
    scanf("%d", &n);
    char* cadenota = NULL;

    for (int i = 0; i < n; i++) {
    	cadenota = (char*)realloc(cadenota, (i + 1) * 4);
    	char* a = randomString();
		memcpy(cadenota + 4 * i, a, 4);
    }

    char sub[] = "IPN";
    printf("Subcadena encontrada: %d veces\n", search(cadenota,sub));
    return 0;
}

