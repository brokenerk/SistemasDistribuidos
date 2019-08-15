#include <iostream>
using namespace std;
const double PI = 3.1415926;

int main(){
	float radio;
	cin >> radio;
	cout << PI*radio*radio << endl;
	PI = 2;
	cout << PI*radio*radio << endl;
	return 0;
}