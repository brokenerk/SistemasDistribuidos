#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura {
	private:
		double kelvin;
	public:
		Temperatura(double = 273.15);
		void setTempKelvin(double);
		void setTempFarenheit(double);
		void setTempCelsius(double);
		void mostrarKelvin();
		void mostrarFarenheit();
		void mostrarCelsius();
};
#endif
