#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string line;

	cin >> n;
	//cin.ignore();
	getline(cin, line);

	//getline(cin, line);
	//cin >> n;
	
	cout << "String: " << line << endl;
	cout << "Int: " << n << endl;
	return 0;
}

//Link: https://es.stackoverflow.com/questions/20097/ayuda-con-funci%C3%B3n-cin-getline-c