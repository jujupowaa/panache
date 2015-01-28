#include <string.h>
#include "socket.h"
int main()
{
/* Arnold Robbins in the LJ of February ’95 , describing RCS
if (argc > 1 && strcmp(argv[1], " - advice " ) == 0) {
	printf ("Don't Panic !\n");
	return 42;
}
	printf ("Need an advice ?\n");
	return 0;
}*/
int socket_client;
char *buf = malloc(50);
int socket_serveur = creer_serveur(8080);
socket_client = accept(socket_serveur,NULL,NULL);
if(socket_client == -1) {
	perror("accept");
	return -1;
}

	const char *message_bienvenue = "Bonjour, bienvenue sur mon serveur\n";
	write(socket_client, message_bienvenue, strlen(message_bienvenue));
	while(1) {
		read(socket_client, buf, 50);
		write(socket_client, buf, strlen(buf));
	}
	return 0;
}
