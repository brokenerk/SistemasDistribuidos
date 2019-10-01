#include "Respuesta.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    Respuesta resp(7200);
    mensaje * mensaje;
    while (true)
    {
        mensaje = resp.getRequest();
        cout << "imprimiendo" << endl;
        cout << (*mensaje).arguments << endl;
    }
}