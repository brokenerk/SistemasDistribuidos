#include <iostream>
using namespace std;
const double PI = 3.1415926;

int main(){
	double precio = 78.7;
	cout << precio << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << precio << endl;
	return 0;
}