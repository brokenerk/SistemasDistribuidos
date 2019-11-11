run: Server.cpp SocketDatagrama.o PaqueteDatagrama.o FileSaver.o
	g++ Server.cpp SocketDatagrama.o PaqueteDatagrama.o FileSaver.o -o Server
	
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

FileSaver.o: FileSaver.cpp FileSaver.h
	g++ FileSaver.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c