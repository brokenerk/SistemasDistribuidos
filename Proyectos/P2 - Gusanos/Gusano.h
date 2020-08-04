#ifndef GUSANO_H_
#define GUSANO_H_
#include "Movimiento.h"
#include <cstdlib>

class Gusano {
	private:
		double longitud;
		int direccion; // 0 = Derecha/Abajo, 1 = Izquierda/Arriba
		int tipoMov;
		Movimiento mov;
	public:
		Gusano(double = 0.0);
		void moverse(int, int);
};
#endif