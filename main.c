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
#include <time.h>
#include <locale.h>

#include "config.h"


void think(){
    if(!globalData->flag) printf("Signal recieved, but not from Connector.\n");
    else printf("Signal from Connector recieved.\n");

    char boardArray[globalData->boardSize][globalData->boardSize];

    char tmpstr[500];
    strcpy(tmpstr, globalData->board);

    char move[BUF_SIZE];
    int player = globalData->playerData.num;
    int boardSize = globalData->boardSize;
    int i = 0;
    int j = 0;
    int k = 0;
    while (tmpstr[i] != '\0' && k < globalData->boardSize)
    {
        if (tmpstr[i] == 'w' || tmpstr[i] == 'W' || tmpstr[i] == '*' || tmpstr[i] == 'b' || tmpstr[i] == 'B')
        {
            boardArray[k][j] = tmpstr[i];
            j++;
        }
        if (j == globalData->boardSize)
        {
            k++;
            j = 0;
        }
        i++;
    }

    // print board array
    printf(" +----------------+\n");
    for (i = 0; i < boardSize; i++)
    {
        printf("%i|", (boardSize-i));
        for (j = 0; j < boardSize; j++)
        {
            if (boardArray[i][j] == 'b')
            { // black man
                //printf("\u26c0 ");
                printf("b ");
            }
            else if (boardArray[i][j] == 'B')
            { // black king
                //printf("\u26c1 ");
                printf("B ");
            }
            else if (boardArray[i][j] == 'w')
            { // white man
                //printf("\u26c2 ");
                printf("w ");
            }
            else if (boardArray[i][j] == 'W')
            { // white king
                //printf("\u26c3 ");
                printf("W ");
            }
            else
            {
                if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
                {
                    // white field
                    printf("--");
                }
                else
                {
                    // black field
                    printf("**");
                }
            }
        }
        printf("|\n");
    }

    printf(" +----------------+\n");
    printf("  A B C D E F G H\n");


    // first run through to check if stones can be taken from the opposing player
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            if (player == 0 && boardArray[i][j] == 'w' && i != 0) 
            {   
                // Could possibly take a stone
                if (boardArray[i-1][j+1] == 'b' && i-1 >= 0 && j+1 < boardSize) 
                {
                    // check possibility
                    if (boardArray[i-1-1][j+1+1] == '*' && i-1-1 >= 0 && j+1+1 < boardSize)
                    {
                        printf("MOVE: SR");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1+1, 8-i+1+1);
                        goto DONE;
                    }
                }
                // Could possibly take a stone
                else if (boardArray[i-1][j-1] == 'b' && i-1 >= 0 && j-1 >= 0)
                {
                    // check possibility
                    if (boardArray[i-1-1][j-1-1] == '*' && i-1-1 >= 0 && j-1-1 >= 0)
                    {
                        printf("MOVE: SL");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1-1, 8-i+1+1);
                        goto DONE;
                    }
                }
            }
            else if (player == 1 && boardArray[i][j] == 'b' && i != boardSize-1)
            {
                // Could possibly take a stone
                if (boardArray[i+1][j-1] == 'w' && i+1 < boardSize && j-1 >= 0)
                {
                    // check possibility
                    if (boardArray[i+1+1][j-1-1] == '*' && i+1+1 < boardSize && j-1-1 >= 0)
                    {  
                        printf("MOVE: SL");
                        printf(move, "c%i:%c%i\n", 65+j, 8-i, 65+j-1-1, 8-i-1-1);
                        goto DONE;
                    }
                }
                // Could possibly take a stone
                else if (boardArray[i+1][j+1] == 'w' && i-1 >= 0 && j+1 < boardSize) 
                {
                    // check possibility
                    if (boardArray[i+1+1][j+1+1] == '*' && i+1+1 < boardSize && j+1+1 < boardSize)
                    {   
                        printf("MOVE: SR");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1+1, 8-i-1-1);
                        goto DONE;
                    }
                }
            } 
        }
    }

    // Second run through if no stones can be taken
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            if (player == 0 && boardArray[i][j] == 'w' && i != 0) 
            {   
                if (boardArray[i-1][j+1] == '*' && i-1 >= 0 && j+1 < boardSize) 
                {
                    printf("MOVE: R");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1, 8-i+1);
                    goto DONE;
                }
                else if (boardArray[i-1][j-1] == '*' && j-1 >= 0 && i-1 >= 0) 
                {
                    printf("MOVE: L");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1, 8-i+1);
                    goto DONE;
                }
            }
            else if (player == 1 && boardArray[i][j] == 'b' && i != boardSize-1)
            {
                if (boardArray[i+1][j+1] == '*' && i+1 < boardSize && j+1 < boardSize) 
                {
                    printf("MOVE: R");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1, 8-i-1);
                    goto DONE;
                }
                else if (boardArray[i+1][j-1] == '*' && i+1 < boardSize && j-1 >= 0) 
                {
                    printf("MOVE: L");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1, 8-i-1);
                    goto DONE;
                }
            } 
        }
    }
DONE:
    printf("\n");
    char result[BUF_SIZE] = "PLAY ";
    strcat(result, move);
    write(globalData->pipeFd[1], result, strlen(result));
    globalData->flag = 1;

}

int main(int argc, char* argv[]){

    char gameID[BUF_SIZE];
    char playerCount[BUF_SIZE];
    int sock;
    void *ptr;
    char addrstr[100];
    int status;
    pid_t pid;

    int fd[2];
    pipe(fd);

    int shmID;
    key_t key = IPC_PRIVATE;
    ////////// auslesen von client.conf /////////
    struct parameters config = getConfig("client.conf");


    ////////// Verarbeitung der Kommandozeilenparameter ////////
    int flag;
    while((flag = getopt(argc, argv, "g:p:")) != -1){
        switch(flag){
            case 'g':
                if(strlen(optarg) != 13){
                    errno = 22;
                    perror("GameID");
                    return -1;
                } else strcpy(gameID, optarg);
                break;
            case 'p' :
                if(atoi(optarg) < 0 || atoi(optarg) > 2){
                    errno = 22;
                    perror("PlayerCount");
                    return -1;
                } else strcpy(playerCount, optarg);
                break;
            default:
                errno = 22;
                perror("args");
                return -1;
        }
    }

    strncpy(gameID, "", sizeof(buf));
    strcpy(gameID, "ID ");
    strcat(gameID, argv[2]);
    strcat(gameID, "\n");


    strncpy(playerCount, "", sizeof(buf));
    strcpy(playerCount, "PLAYER ");
    strcat(playerCount, argv[4]);
    strcat(playerCount, "\n");

    // setzt, die Formatausgabe so, dass wir nachher
    // Unicode Symbole verwednen können.
    // (möglicherweise unnötig, muss nochmal testen -max)
    setlocale(LC_ALL, "en_US.UTF-8");


    ////////// Connect to server //////////

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


    if((shmID = shmget(key, sizeof(struct shmData), IPC_CREAT | 0666)) < 0){
        perror("shmget");
        return -1;
    }



    ////////// Split into Connector and Thinker Process ///////////
    if((pid = fork()) < 0){
        perror("Fehler bei fork()\n");
        return -1;
    }
    else if (pid == 0){ //Kindprozess

        // Schreibseite der pipe schließen
        close(fd[1]);

        ////////// Attach shared memory //////////

        struct shmData *gameData, *ptr;

        if((ptr = (struct shmData*) shmat(shmID, 0, 0)) == (struct shmData*) -1){
            perror("shmat child");
            return -1;
        }

        gameData = ptr;

        strcpy(gameData->gameID, gameID);
        strcpy(gameData->gameName, "Checkers");
        strcpy(gameData->playerCount, playerCount);
        gameData->childID = getpid();
        gameData->parentID = getppid();
        gameData->pipeFd[0] = fd[0];

        // Nun dürfen die Daten vom Elternprozess gelesen werden.
        gameData->sem = 1;



        printf("Connector: performConnection()\n");
        if(performConnection(&sock, gameID, playerCount, gameData) != 0){
            perror("performConnection(): ");
        }

        freeaddrinfo(res);
        close(sock);

    }
    else{ // Elterprozess

        // close read side of pipe
        close(fd[0]);

        struct shmData *gameData, *ptr;


        if((ptr = (struct shmData*) shmat(shmID, 0, 0)) == (struct shmData*) -1){
            perror("shmat parent");
            return -1;
        }

        gameData = ptr;
        globalData = gameData;

        while(!gameData->sem) usleep(100);

        printf("Parent process reading shmData.\n");
        printf("ParentID: %i, ChildID: %i\n", gameData->parentID, gameData->childID);
        printf("GameName: %s, gameID: %s, playerCount: %s", gameData -> gameName, gameData -> gameID, gameData->playerCount);


        gameData->sem = 0;
        gameData->pipeFd[1] = fd[1];


        signal(SIGUSR1, think);


        if (wait(&status) != pid){
            perror("wait()");
            return -1;
        }

        shmdt(ptr);
        shmctl(shmID, IPC_RMID, 0);

    }


    return 0;
}
