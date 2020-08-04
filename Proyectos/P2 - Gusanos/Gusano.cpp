#include "Gusano.h"
#include <iostream>
using namespace std;

Gusano::Gusano(double l) { 
	tipoMov = rand() % 7;
	direccion = rand() % 2;
	longitud = l;
}

void Gusano::moverse(int w, int h) {
	double amp = 2.0 + (double) rand() / RAND_MAX * 4.0;
	double periodo = 10.0 + (double) rand() / RAND_MAX * 10.0;
	double posv = 30.0 + (double) rand() / RAND_MAX * (w - 60.0);
	double posh = 30.0 + (double) rand() / RAND_MAX * (h - 60.0);
	double radio = 35.0 + (double) rand() / RAND_MAX * 25.0;

	mov.inicializar(longitud, amp, periodo, posv, posh, radio);
	//Recorremos toda la pantalla
	while(1) {
		switch(tipoMov) {
			case 0: {
				if(direccion == 0) {
					for(double x = 0.0; x < h - 30.0; x++)
						mov.linealVertical(x);
				}
				else {
					for(double x = h - 30.0; x > 0.0; x--)
						mov.linealVertical(x);
				}
				break;
			}
			case 1: {
				if(direccion == 0) {
					for(double x = 0.0; x < w - 30.0; x++)
						mov.linealHorizontal(x);
				}
				else {
					for(double x = w - 30.0; x > 0.0; x--)
						mov.linealHorizontal(x);
				}
				break;
			}
			case 2: {
				if(direccion == 0) {
					for(double x = 0.0; x < sqrt(pow(w, 2) + pow(h, 2)) - 270.0; x++)
						mov.linealDiagonal(x);
				}
				else {
					for(double x = sqrt(pow(w, 2) + pow(h, 2)) - 270.0; x > 0.0; x--)
						mov.linealDiagonal(x);
				}
				break;
			}
			case 3: {
				if(direccion == 0) {
					for(double x = 0.0; x < h - 30.0; x++)
						mov.serpenteanteVertical(x);
				}
				else {
					for(double x = h - 30.0; x > 0.0; x--)
						mov.serpenteanteVertical(x);
				}
				break;
			}
			case 4: {
				if(direccion == 0) {
					for(double x = 0.0; x < w - 30.0; x++)
						mov.serpenteanteHorizontal(x);
				}
				else {
					for(double x = w - 30.0; x > 0.0; x--)
						mov.serpenteanteHorizontal(x);
				}
				break;
			}
			case 5: {
				if(direccion == 0) {
					for(double x = posv - radio; x < posv + radio; x++)
						mov.circularInf(x);
				}
				else {
					for(double x = posv + radio; x > posv - radio; x--)
						mov.circularInf(x);
				}
				break;
			}
			case 6: {
				if(direccion == 0) {
					for(double x = posv - radio; x < posv + radio; x++)
						mov.circularSup(x);
				}
				else {
					for(double x = posv + radio; x > posv - radio; x--)
						mov.circularSup(x);
				}
				break;
			}
		}
		/*Cambiamos la direccion cuando se llegue al final o borde
		de la pantalla generando un efecto de rebote*/
		if(direccion == 0)
			direccion = 1;
		else
			direccion = 0;
	}
}