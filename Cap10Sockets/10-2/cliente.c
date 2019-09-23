#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int puerto = 7200;

int main(int argc, char* argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
  
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
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   int i;
   for(i = 65507; i < 70000; i++){
      
      char mal[i];
      sendto(s, (char *)mal, i * sizeof(char), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
      /* se bloquea esperando respuesta */
      recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);

      unsigned char ip[4];
      memcpy(ip, &msg_to_server_addr.sin_addr.s_addr, 4);

      printf("Mensaje recibido de:\n");
      printf("IP: %d.%d.%d.%d \n", ip[0], ip[1], ip[2], ip[3]);
      printf("Puerto: %d\n", msg_to_server_addr.sin_port);
      printf("sizeof =%d\n",i);
      printf("2 + 5 = %d\n", res);
      
   }
   close(s);
}
