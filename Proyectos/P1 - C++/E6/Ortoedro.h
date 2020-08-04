#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_

class Ortoedro {  
	private:  
		Rectangulo caraSup;
		Rectangulo caraInf;
		Rectangulo caraIzq;
		Rectangulo caraDer;
		Rectangulo caraTras;
		Rectangulo caraFront;
	public:
		Ortoedro();
		void inicializar(Coordenada c1, Coordenada c2);
		void obtieneVertices();
		double obtieneArea();
		double obtieneVolumen();
};
#endif