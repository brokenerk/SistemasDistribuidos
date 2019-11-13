#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
class Respuesta{
	public:
	 	Respuesta(int pl);
	 	struct mensaje *getRequest(void);
		void sendReply(char *respuesta);
	private:
	    SocketDatagrama *socketlocal;
	    unsigned int contRequest;
};