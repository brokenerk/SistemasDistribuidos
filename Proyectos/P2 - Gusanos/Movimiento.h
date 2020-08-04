#ifndef MOVIMIENTO_H_
#define MOVIMIENTO_H_
#include "gfx.h"
#include <cmath>
#include <unistd.h>

class Movimiento {
	private:
		double longitud;
		double posv;
		double posh;
		double amp;
		double periodo;
		double radio;
		double velocidad;
	public:
		Movimiento();
		void inicializar(double, double, double, double, double, double);
		void linealVertical(double);
		void linealHorizontal(double);
		void linealDiagonal(double);
		void serpenteanteVertical(double);
		void serpenteanteHorizontal(double);
		void circularInf(double);
		void circularSup(double);
};
#endif