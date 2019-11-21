run: servidor.cpp Respuesta.o SocketDatagrama.o PaqueteDatagrama.o
	g++ servidor.cpp Respuesta.o SocketDatagrama.o PaqueteDatagrama.o -o server
	
Respuesta.o: Respuesta.cpp SocketDatagrama.o PaqueteDatagrama.o Respuesta.h
	g++ Respuesta.cpp -c 	

SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c 

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c