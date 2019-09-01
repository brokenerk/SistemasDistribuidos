#include <iostream>
using namespace std;

int main() {
    double c = 20;
    double f;

    f = (9 / 5) * c + 32;
	cout << "Farenheit: " << f << endl;

    f = (9.0 / 5.0) * c + 32.0;
    cout << "Farenheit: " << f << endl;;
	return 0;
}
