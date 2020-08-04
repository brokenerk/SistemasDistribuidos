#include "Coordenada.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Ortoedro::Ortoedro() { 
	caraSup = Rectangulo();
	caraInf = Rectangulo();
	caraIzq = Rectangulo();
	caraDer = Rectangulo();
	caraTras = Rectangulo();
	caraFront = Rectangulo();
}

void Ortoedro::inicializar(Coordenada vOrigen, Coordenada vLejos){
	Coordenada supIzqFront = Coordenada(vOrigen.obtenerX(), vLejos.obtenerY(), 0);
	Coordenada infDerFront = Coordenada(vLejos.obtenerX(), vOrigen.obtenerY(), 0);
	caraFront = Rectangulo(supIzqFront, infDerFront);
	caraTras = Rectangulo(supIzqFront, infDerFront);

	Coordenada supIzqSup = Coordenada(vOrigen.obtenerX(), vLejos.obtenerZ(), 0);
	Coordenada infDerSup = Coordenada(vLejos.obtenerX(), vOrigen.obtenerZ(), 0);
	caraSup = Rectangulo(supIzqSup, infDerSup);
	caraInf = Rectangulo(supIzqSup, infDerSup);

	Coordenada supIzqIzq = Coordenada(vOrigen.obtenerZ(), vLejos.obtenerY(), 0);
	Coordenada infDerIzq = Coordenada(vLejos.obtenerZ(), vOrigen.obtenerY(), 0);
	caraIzq = Rectangulo(supIzqIzq, infDerIzq);
	caraDer = Rectangulo(supIzqIzq, infDerIzq);
}

void Ortoedro::obtieneVertices() {
	cout << "Para el vertice mas cercano al origen.\n";
	Coordenada origenX = caraFront.obtieneSupIzq();
	Coordenada origenY = caraFront.obtieneInfDer();
	Coordenada origenZ = caraSup.obtieneInfDer();
	cout << "x = " << origenX.obtenerX() << " y = " << origenY.obtenerY() << " z = " << origenZ.obtenerY() << endl;
	
	Coordenada lejosZ = caraSup.obtieneSupIzq();
	cout << "Para el vertice mas lejano al origen.\n";
	cout << "x = " << origenY.obtenerX() << " y = " << origenX.obtenerY() << " z = " << lejosZ.obtenerY() << endl;
}

double Ortoedro::obtieneArea(){
	return caraSup.obtieneArea();
}

double Ortoedro::obtieneVolumen(){
	double profundo = caraFront.obtieneSupIzq().obtenerY() - caraFront.obtieneInfDer().obtenerY();
	return caraSup.obtieneArea() * profundo;
}