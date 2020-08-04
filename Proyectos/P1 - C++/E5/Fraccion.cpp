#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion(int num, int deno) {
    numerador = num;
    denominador = deno;
}

void Fraccion::inicializar(int num, int deno) {
    numerador = num;
    denominador = deno;
    return;
}

void Fraccion::mostrar() {
    cout << numerador << "/" << denominador << endl;
    return;
}

double Fraccion::calcular() {
    return numerador * 1.0 / denominador * 1.0;
}

void Fraccion::minExpresion() {
    int i = 2;
    int num = numerador, deno = denominador;

    while(i <= deno && i <= num) {
        if(num % i == 0 && deno % i == 0) {
            num = num / i;
            deno = deno / i;
        }
        else 
            i++;
    }
    cout << num << "/" << deno << endl;
    return;
}