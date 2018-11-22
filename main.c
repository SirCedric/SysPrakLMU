#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
//#include "performConnection.c"



#define PORTNUMBER "1357"
#define HOSTNAME "sysprak.priv.lab.nm.ifi.lmu.de"

int main(int argc, char* argv[]){

    long gameID;
    int playercount;
    int sock;


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



    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        errno = 1;
        perror("socket");
        return -1;
    }

    struct addrinfo hints;
    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_protocol=0;
    hints.ai_flags=AI_ADDRCONFIG;
    struct addrinfo* res=0;
    int err=getaddrinfo(HOSTNAME,PORTNUMBER,&hints,&res);
    if (err!=0) {
        perror("getadrrinfo");
    }


    if(connect(sock, res->ai_addr, res->ai_addrlen) < 0){
        perror("connect");
        return -1;
    }
    freeaddrinfo(res);



    return 0;
}