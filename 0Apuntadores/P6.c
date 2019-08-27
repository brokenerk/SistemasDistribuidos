#include <stdio.h> 
#include <string.h>

int main() {
    char caracter = 0; 
    int entero = 0;
    float flotante = 0; 
    long largo = 0; 
    double doble = 0; 

    printf(" char =   %p %ld\n", &caracter, sizeof(caracter));
    printf(" int =    %p %ld\n", &entero, sizeof(int));
    printf(" float =  %p %ld\n", &flotante, sizeof(float));
    printf(" long =   %p %ld\n", &largo, sizeof(long));
    printf(" double = %p %ld\n", &doble, sizeof(double));

    char cadena [] = "ESCOM - IPN";
    int i = 0, length = strlen(cadena); 

    for(i = 0; i < length+1; i++){
        printf("cadena [%d] %c %.2X = %p\n", i, cadena[i], cadena[i], &cadena[i]);
    }

    printf("\n%c\n", cadena + 4);
    return 0;
}