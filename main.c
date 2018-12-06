#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>


#include "config.h"

int main(int argc, char* argv[]){

    char gameID[BUF_SIZE];
    int playerCount;
    int sock;
    void *ptr;
    char addrstr[100];
    int status;
    pid_t pid;
    key_t key = IPC_PRIVATE;
        
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
        perror("playerCount");
        return -1;
    }
    
    playerCount = atoi(argv[4]);


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


    if((pid = fork()) < 0){
        perror("Fehler bei fork()\n");
        return -1;
    }
    else if (pid == 0){
        printf("Connector: performConnection()\n");
        if(performConnection(&sock, gameID) != 0){
            perror("performConnection");
            return -1;
        }
        
        struct shmData connectorData;
        struct shmData *shmptr = malloc(sizeof(struct shmData));
        
        // bitte noch ändern!
        strcpy(connectorData.gameName, "Checkers");
        strcpy(connectorData.shmGameID, gameID);
        connectorData.shmPlayerCount = playerCount;

        int shmConnector;
        
        if((shmConnector = shmget(key, sizeof(struct shmData), IPC_CREAT | IPC_EXCL)) < 0){
          perror("shmConnector");
          return -1;
        }
        if((shmptr = (struct shmData*) shmat(key, 0, 0)) < 0){
          perror("shmat");
          return -1;
        }
        
        // copy struct connectorData into shared memory
        strcpy(shmptr->gameName, connectorData.gameName);
        strcpy(shmptr->shmGameID, connectorData.shmGameID);
        shmptr->shmPlayerCount = connectorData.shmPlayerCount;
      
        printf("Connector done!\n");
        
        
    }
    else{
        if (wait(&status) != pid){
            perror("wait()\n");
            return -1;
        }
        
        struct shmData thinkerData;
        struct shmData *shmptr = malloc(sizeof(struct shmData));
        
        int shmThinker;
        
        if((shmThinker = shmget(key, sizeof(struct shmData), 0)) < 0){
          perror("shmThinker");
          return -1;
        }
        if((shmptr = (struct shmData*) shmat(key, 0, 0)) < 0){
          perror("shmat");
          return -1;
        }
        
        sleep(5);
        printf("Thinker tries to get struct:\n");
        // copy struct connectorData into shared memory
        strcpy(thinkerData.gameName, shmptr->gameName);
        strcpy(thinkerData.shmGameID, shmptr->gameName);
        thinkerData.shmPlayerCount = shmptr->shmPlayerCount ;
                
        printf("Playercount: %i", thinkerData.shmPlayerCount);
    }
    
    
//
//    if(performConnection(&sock, gameID) != 0){
//        perror("performConnection");
//        return -1;
//    }


    freeaddrinfo(res);
    close(sock);


    return 0;
}
