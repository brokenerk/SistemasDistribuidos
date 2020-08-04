#include "Numero.h"
#include <iostream>
using namespace std;

Numero::Numero(int n, bool prim) : num(n), primo(prim) { }

int Numero::getNum() {
    return num;
}

bool Numero::getPrimo() {
    return primo;
}

void Numero::setPrimo(bool prim) {
    primo = prim;
}