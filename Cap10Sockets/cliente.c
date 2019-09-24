#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

int puerto = 7200;

int main(int argc, char* argv[])
{
	if(argc != 2) {
		printf("Forma de uso: %s ip_servidor\n", argv[0]);
		exit(0);
	}

	struct sockaddr_in msg_to_server_addr, client_addr;
	int s, res;

	s = socket(AF_INET, SOCK_DGRAM, 0);
	/* rellena la dirección del servidor */
	bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
	msg_to_server_addr.sin_family = AF_INET;
	msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	msg_to_server_addr.sin_port = htons(puerto);

	/* rellena la direcciòn del cliente*/
	bzero((char *)&client_addr, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = INADDR_ANY;

	/*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
	client_addr.sin_port = 666;
	bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));

	int i;
	char msj[65507];
	/*rellena el mensaje */
	for(i = 0; i < 65507; i++){
		msj[i] = i;
	}

	sendto(s, (char *)msj, 65507 * sizeof(char), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
	/* se bloquea esperando respuesta */
	recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);

	unsigned char ip[4];
	memcpy(ip, &msg_to_server_addr.sin_addr.s_addr, 4);

	printf("Mensaje recibido de:\n");
	printf("IP: %d.%d.%d.%d \n", ip[0], ip[1], ip[2], ip[3]);
	printf("Puerto: %d\n", msg_to_server_addr.sin_port);
	printf("sizeof = %lu\n", sizeof(msj));
	printf("Ok = %d\n", res);

	close(s);
}
