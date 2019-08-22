#ifndef RECTANGULO_H_
#define RECTANGULO_H_

class Rectangulo {
	private:
		Coordenada superiorIzq;
		Coordenada inferiorDer;
	public: 
		Rectangulo();
		Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
		Rectangulo(Coordenada c1,Coordenada c2);
		void imprimeEsq();
		Coordenada obtieneSupIzq();
		Coordenada obtieneInfDer();
		double obtieneArea(double x,double y);
};
#endif
