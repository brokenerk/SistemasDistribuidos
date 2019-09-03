Outs.o: Semaforo.cpp
	g++ Semaforo.cpp -c 

run: main.cpp Semaforo.o 
	g++ -std=c++11 main.cpp Semaforo.o -o main.o -lpthread  && ./main.o

clean: 
	rm *.o