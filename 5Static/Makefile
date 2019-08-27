run: E2.cpp E3-Push.cpp E3-Reserve.cpp PoligonoIrreg.o
	g++ E2.cpp Coordenada.o PoligonoIrreg.o  -o E2
	g++ E3-Push.cpp Coordenada.o PoligonoIrreg.o -o E3-Push
	g++ E3-Reserve.cpp Coordenada.o PoligonoIrreg.o -o E3-Reserve

PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c

Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c