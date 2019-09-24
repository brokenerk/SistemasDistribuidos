#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

class SocketDatagrama {
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket
	public:
		SocketDatagrama(int);
		~SocketDatagrama();
		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama & p);
		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama & p);
};
#endif