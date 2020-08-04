run: main.cpp gfx.o Gusano.o Movimiento.o
	g++ -std=c++11 main.cpp gfx.o Gusano.o Movimiento.o -o main -lX11 -lpthread

Gusanos.o: Gusano.cpp Gusano.h Movimiento.o
	g++ Gusano.cpp -c

Movimiento.o: Movimiento.cpp Movimiento.h gfx.o
	g++ Movimiento.cpp -c

gfx.o: gfx.c gfx.h
	gcc gfx.c -c