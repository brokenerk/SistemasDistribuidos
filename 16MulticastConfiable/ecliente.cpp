#include "SocketMulticast.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Forma de uso: %s ip_emisor n num_receptores\n", argv[0]);
		exit(0);
	}
	srand(time(NULL));
	int n = atoi(argv[2]);
	int cont = 0;
	int cuenta = 0;
	int num_receptores = atoi(argv[3]);
	SocketDatagrama s = SocketDatagrama(7200);
	SocketMulticast sm = SocketMulticast(0);

	while (cont < n)
	{
		int arr = 1 + rand() % 9;
		cuenta = cuenta + arr;
    	PaqueteDatagrama p = PaqueteDatagrama((char*)&arr, sizeof(struct mensaje), argv[1], 3030);
    	int enviar = sm.enviaConfiable(p, 1, num_receptores);
    	int intentos = 1;

		while(enviar < 0 && intentos < 7) {
			cout << "Reintentando" << endl;
			enviar = sm.enviaConfiable(p, 1, num_receptores);
			intentos++;
		}

		if(intentos == 7){
			cout << "Algun receptor no da respuesta" << endl;
			exit(0);
		}
		
		printf("Num: %d\nOriginal: %d\n", arr, cuenta);
		/*
		int cont2 = 0;
		while(cont2 < num_receptores) {
			PaqueteDatagrama respuesta = PaqueteDatagrama(4);
	        s.recibeTimeout(respuesta, 5, 500);
	        int res = 0;
	        memcpy(&res, respuesta.obtieneDatos(), 4);
			if (cuenta != res)
			{
				printf("Respuesta receptor %d: %d  ip: ", cont2 + 1, res);
				cout<< respuesta.obtieneDireccion()<<endl;
				//exit(0);
			}
			printf("Respuesta receptor %d: %d   ip:", cont2 + 1, res);
			cout<< respuesta.obtieneDireccion()<<endl;
			cont2++;
		}
		*/
	    cont++;
	}
	return 0;
}