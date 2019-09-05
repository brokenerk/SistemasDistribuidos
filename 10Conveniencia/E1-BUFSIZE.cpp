#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string>
#include <cstring>
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

char buffer[BUFSIZ];

int main(int argc, char *argv[]){
	srand(time(NULL));
	int n = 1757600;

	int destino;
	string linea = "";

	if(argc != 2){
		cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
		exit(0);
	}
	
    for (int i = 0; i < n; i++)
    	linea.insert(4 * i, randomString());

	
	if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
		perror(argv[1]);
		exit(-1);
	}
	int i = 0, j = 0;

	while (i < linea.length()) {
		strncpy(buffer, linea.c_str() + i + 1, BUFSIZ);//Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
	 	write(destino, buffer, strlen(buffer));
        i += BUFSIZ;
        memset(buffer, 0, sizeof(buffer));
    }

	fsync(destino);
	close(destino);
}