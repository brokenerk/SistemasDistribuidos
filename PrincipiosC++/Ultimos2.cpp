#include <iostream>
using namespace std;

int main() {
    double segundos = 0.0;
    double gravedad = 9.81;
    cout << "Escribe el tiempo." << endl;
    cin >> segundos;
    cout << "Altura: " << gravedad * (segundos * segundos) * .5 << " metros" << endl;
    return 0;
}
