#include "Movimiento.h"
#include <iostream>
using namespace std;
const float PI = 3.1459265;

Movimiento::Movimiento() { }

void Movimiento::inicializar(double l, double a, double p, double pv, double ph, double r) {
	longitud = l;
	amp = a;
	periodo = p;
	posv = pv;
	posh = ph;
	radio = r;
	velocidad = 9666;
}

void Movimiento::linealVertical(double x) {
	velocidad = 4666 + (double) rand() / RAND_MAX * 10666;

	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(posv, t + x);
	}

	gfx_flush();
	usleep(velocidad);	

	/*Dibujamos otro "gusano" detras del original, del mismo color del fondo de la pantalla
	para disimular el limpiado de esta, sin borrar al resto de los gusanos al unir los hilos*/
	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(posv, t + x);
	}

	gfx_flush();
}

void Movimiento::linealHorizontal(double x) {
	velocidad = 4666 + (double) rand() / RAND_MAX * 10666;

	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(t + x, posh);
	}

	gfx_flush();
	usleep(velocidad);	

	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(t + x, posh);
	}

	gfx_flush();
}

void Movimiento::linealDiagonal(double x) {
	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(t + x, t + x);
	}

	gfx_flush();
	usleep(velocidad + x);

	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(t + x, t + x);
	}

	gfx_flush();
}

void Movimiento::circularInf(double x) {
	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		if(t + x > posv + radio)
			break;
		gfx_point(- t - x + posv * 2.0, posh + sqrt(pow(radio, 2) - pow(- t - x + posv, 2)));
	}

	gfx_flush();
	usleep(velocidad + 5000);

	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		if(t + x > posv + radio)
			break;
		gfx_point(- t - x + posv * 2.0, posh + sqrt(pow(radio, 2) - pow(- t - x + posv, 2)));
	}

	gfx_flush();
}

void Movimiento::circularSup(double x) {
	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		if(t + x > posv + radio)
			break;
		gfx_point(- t - x + posv * 2.0, posh - sqrt(pow(radio, 2) - pow(- t - x + posv, 2)));
	}

	gfx_flush();
	usleep(velocidad + 5000);

	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		if(t + x > posv + radio)
			break;
		gfx_point(- t - x + posv * 2.0, posh - sqrt(pow(radio, 2) - pow(- t - x + posv, 2)));
	}

	gfx_flush();
}

void Movimiento::serpenteanteHorizontal(double x) {
	velocidad = 4666 + (double) rand() / RAND_MAX * 10666;

	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(t + x, posh + (amp * cos((t + x) * PI / periodo)));
	}

	gfx_flush();
	usleep(velocidad);	

	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(t + x, posh + (amp * cos((t + x) * PI / periodo)));
	}

	gfx_flush();
}

void Movimiento::serpenteanteVertical(double x) {
	velocidad = 4666 + (double) rand() / RAND_MAX * 10666;

	gfx_color(255, 255, 255);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(posv + (amp * sin((t + x) * PI / periodo)), t + x);
	}

	gfx_flush();
	usleep(velocidad);	

	gfx_color(0, 0, 0);
	for(double t = 0.0; t < longitud; t++) { //Longitud
		gfx_point(posv + (amp * sin((t + x) * PI / periodo)), t + x);
	}

	gfx_flush();
}