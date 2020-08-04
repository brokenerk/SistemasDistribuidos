#include "Temperatura.h"
#include <iostream>
using namespace std;

Temperatura::Temperatura(double kelvin) {
    kelvin = kelvin;
}

void Temperatura::setTempKelvin(double kelvin) {
	kelvin = kelvin;
	return;
}

void Temperatura::setTempFarenheit(double farenheit) {
	kelvin = (farenheit - 32.0) * 5.0/9.0 + 273.15;
	return;
}

void Temperatura::setTempCelsius(double celsius) {
	kelvin = celsius + 273.15;
	return;
}

void Temperatura::mostrarKelvin() {
	cout << "Temperatura grados Kelvin: " << kelvin << endl;
	return;
}

void Temperatura::mostrarFarenheit() {
	cout << "Temperatura grados Farenheit: " << (kelvin - 273.15) * 9.0/5.0 + 32.0 << endl;
	return;
}

void Temperatura::mostrarCelsius() {
	cout << "Temperatura grados Celsius: " << (kelvin - 273.15) << endl;
	return;
}