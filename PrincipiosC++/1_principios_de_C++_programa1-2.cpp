#include <iostream> 
#include <string> 

using namespace std;
float sqr(float );
int main(){
    string nombre;
    float n;
    float b;
    cout << "Cual es tu nombre?" << endl;
    //cin >> nombre;
    //cout << "Hola " << nombre << endl;
    cout << "Ingrese valor a calcular" << endl;
    cin >> n;
    b = sqr(n);
    cout << b << endl;

    return 0; 
}
float sqr(float x){
    float b = x, h = 0;

    while (b != h) {
        b = (h + b) / 2;
        h = x / b;
    }
    return b;
}
