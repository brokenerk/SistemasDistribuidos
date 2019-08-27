run: E1.cpp E2.cpp PoligonoIrreg.o
	g++ E1.cpp Coordenada.o PoligonoIrreg.o -o E1
	g++ E2.cpp Coordenada.o PoligonoIrreg.o -o E2

PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
