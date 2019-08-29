#include <string>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string cadena("ESCOM");
    cout << cadena[4] << endl;

    char acString [5];
    strcpy(acString, cadena.c_str());
    cout << acString[0] << endl;
}