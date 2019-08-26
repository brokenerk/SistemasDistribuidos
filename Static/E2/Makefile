run: E2.cpp PoligonoIrreg.o
	g++ Coordenada.o PoligonoIrreg.o E2.cpp -o E2

PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c