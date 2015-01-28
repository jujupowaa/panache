#include "socket.h"

int creer_serveur(int port) {
	int socket_serveur;
	int optval = 1;
	socket_serveur = socket(AF_INET, SOCK_STREAM, 0);
	
	if (socket_serveur == -1) {
		perror("socket_serveur");
		return -1;
	}
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;/* Socket ipv4 */
	saddr.sin_port = htons(port); /* Port d'ecoute*/
	saddr.sin_addr.s_addr = INADDR_ANY; /* ecoute sur toutes les interfaces*/
	
	if(setsockopt(socket_serveur, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
		perror("Can not set SO_REUSEADDR option");
		return -1;
	}

	if( bind(socket_serveur, (struct sockaddr *) &saddr,sizeof(saddr))==-1) {
		perror("bind socket_serveur");
		/*traitement de l'erreur*/
		return -1;
	}
	
	if(listen(socket_serveur, 10)== -1) {
		perror("listen socket_serveur");
		return -1;
		/*traitement d'erreur*/
	}
	return socket_serveur;
}
