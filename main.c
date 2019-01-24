


#include "config.h"




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
                if(atoi(optarg) < 1 || atoi(optarg) > 2){
                    errno = 22;
                    perror("PlayerCount");
                    return -1;
                } else{
                    if(atoi(optarg) == 1){
                        strcpy(playerCount, "PLAYER 0\n");
                    }
                    if(atoi(optarg) == 2){
                        strcpy(playerCount, "PLAYER 1\n");
                    }
                }
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
