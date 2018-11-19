#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>

#define GAMEKINDNAME "Checkers"
#define PORTNUMBER 1375
#define HOSTNAME "sysprak.priv.lab.nm.ifi.lmu.de"

int main(int argc, char* argv[]){

    long gameID;
    int playercount;
    
    
    // Verarbeitung der Kommandozeilenparameter
    
    if(argc != 5){
        errno = 22;
        perror("argc");
        return -1;
    }
    
    if(strcmp(argv[1], "-g") != 0 || strcmp(argv[3], "-p") != 0){
        errno = 22;
        perror("Flags");
        return -1;
    }
    
    gameID = atol(argv[2]);
    playercount = atoi(argv[4]);
    
    // "Falls gameID keine 13-stellige Zahl"
    if((double)gameID/1000000000000 < 1 || (double)gameID/9999999999999 > 1){
        errno = 22;
        perror("GameID");
        return -1;
    }
    
    if(playercount != 1 && playercount != 2){
        errno = 22;
        perror("Playercount");
        return -1;
    }

    struct addrinfo hints, *res, *p;
    int errcode;
    char ipstr[INET6_ADDRSTRLEN];

    memset (&hints, 0, sizeof (hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    errcode = getaddrinfo (HOSTNAME, PORTNUMBER, &hints, &res);
    if (errcode != 0)
    {
        perror ("getaddrinfo");
        return -1;
    }

    printf ("Host: %s\n", HOSTNAME);

    for(p = res; p != NULL; p = p->ai_next) {
        void *addr;
        char *ipver;

        // Hole den Pointer zu der Adresse
        // Verschiedene Felder für IPv4 und IPv6
        if (p->ai_family == AF_INET) { //IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { //IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // Konvertiere die IP in einen String und printe es
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf(" %s: %s\n", ipver, ipstr);
    }

    freeaddrinfo(res);
    
    return 0;
}
