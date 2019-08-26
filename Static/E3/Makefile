run: E3-1.cpp E3-2.cpp PoligonoIrreg.o
	g++ E3-1.cpp Coordenada.o PoligonoIrreg.o -o E3-1
	g++ E3-2.cpp Coordenada.o PoligonoIrreg.o -o E3-2

PoligonoIrreg.o: PoligonoIrreg.cpp PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c