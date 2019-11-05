#include "SocketMulticast.h"
#include "SocketDatagrama.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Forma de uso: %s ip_servidor n\n", argv[0]);
		exit(0);
	}
	srand(time(NULL));
	int n = atoi(argv[2]);
	int cont = 0;
	int res = 0;
	int cuenta = 0;
	SocketDatagrama s = SocketDatagrama(7200);

	while (cont < n)
	{
		int arr = 1 + rand() % 9;
		SocketMulticast sm = SocketMulticast(0);
    	PaqueteDatagrama p = PaqueteDatagrama((char*)&arr, 4, argv[1], 3030);
    	if((sm.enviaConfiable(p, 1,1)) > 0) {
	        PaqueteDatagrama respuesta = PaqueteDatagrama(4);
	        s.recibeTimeout(respuesta, 2, 500);
	        memcpy(&res, respuesta.obtieneDatos(), 4);
	        cuenta = cuenta + arr;
			if (cuenta != res)
			{
				printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", arr, res, cuenta);
				exit(0);
			}
			printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", arr, res, cuenta);
			//s->~SocketDatagrama();
    	}
    	cont++;
	}
	return 0;
}