run: cliente.cpp Solicitud.o
	g++ cliente.cpp SocketDatagrama.o PaqueteDatagrama.o Solicitud.o -o cliente

Solicitud.o: Solicitud.cpp PaqueteDatagrama.o SocketDatagrama.o Solicitud.h
	g++ Solicitud.cpp -c 

SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c 

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c