run: Client.cpp SocketDatagrama.o PaqueteDatagrama.o FileOpener.o
	g++ Client.cpp SocketDatagrama.o PaqueteDatagrama.o FileOpener.o -o Client
	
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c

FileOpener.o: FileOpener.cpp FileOpener.h
	g++ FileOpener.cpp -c