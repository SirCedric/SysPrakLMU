#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "config.h"

int main(int argc, char* argv[]){

    char gameID[BUF_SIZE];
    int playercount;
    int sock;
    void *ptr;
    char addrstr[100];
    
    // auslesen von client.conf
    struct parameters config = getConfig("client.conf");


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

    
    if(strlen(argv[2]) != 13){
      errno = 22;
      perror("GameID");
      return -1;
    }
    

    strncpy(gameID, "", sizeof(buf));
    strcpy(gameID, "ID ");
    strcat(gameID, argv[2]);
    strcat(gameID, "\n");
        
    if(atoi(argv[4]) != 1 && atoi(argv[4]) != 2){
        errno = 22;
        perror("Playercount");
        return -1;
    }
    
    playercount = atoi(argv[4]);


    // Creates Socket IPv4
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        errno = 1;
        perror("socket");
        return -1;
    }


    // connect to server with getaddrinfo
    struct addrinfo hints;
    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_protocol=0;
    hints.ai_flags=AI_ADDRCONFIG;
    struct addrinfo* res=0;
    int err=getaddrinfo(config.hostName,config.portNr,&hints,&res);
    if (err!=0) {
        perror("getadrrinfo");
        return -1;
    }


    if(connect(sock, res->ai_addr, res->ai_addrlen) < 0){
        perror("connect");
        return -1;
    }
    ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
    inet_ntop (res->ai_family, ptr, addrstr, 100);
    printf ("IPv%d address: %s\n", res->ai_family,
            addrstr);

    if(performConnection(&sock, gameID) != 0){
        perror("performConnection");
        return -1;
    }

    freeaddrinfo(res);
    close(sock);


    return 0;
}
