#include "SocketMulticast.h"

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
	SocketMulticast sm = SocketMulticast(0);

	while (cont < n)
	{
		cout << "el cont" << cont<< endl;
		int arr = 1 + rand() % 9;
		
    	PaqueteDatagrama p = PaqueteDatagrama((char*)&arr, sizeof(struct mensaje), argv[1], 3030);
    	int enviar= sm.enviaConfiable(p, 1, 2);
		int intentos=0;
		while(enviar < 0 && intentos<7) {
			enviar= sm.enviaConfiable(p, 1, 2);
			intentos++;
		}

	    	PaqueteDatagrama respuesta = PaqueteDatagrama(4);
	        s.recibeTimeout(respuesta, 2, 500);
	        memcpy(&res, respuesta.obtieneDatos(), 4);
	        cuenta = cuenta + arr;
			if (cuenta != res)
			{
				printf("Num: %d\nRespuesta: %d \nOriginal: sali %d\n\n", arr, res, cuenta);
				
			
			}
			printf("Num: %d\nRespuesta: %d \nOriginal: %d\n\n", arr, res, cuenta);
		
		
		
	    cont++;
	}
	cout << cont<< endl;
	return 0;
}