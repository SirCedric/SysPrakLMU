


#include "config.h"




int main(int argc, char* argv[]){

    char gameID[BUF_SIZE];
    char playerCount[BUF_SIZE];
    int sock;
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
    freeaddrinfo(res);

    if((shmID = shmget(key, sizeof(struct shmData), IPC_CREAT | 0666)) < 0){
        perror("shmget");
        return -1;
    }


    ////////// Initialize paddedBoardArray invalid fields //////////
    paddedBoard[0] = -1;
    paddedBoard[1] = -1;
    paddedBoard[2] = -1;
    paddedBoard[3] = -1;
    paddedBoard[4] = -1;
    paddedBoard[9] = -1;
    paddedBoard[18] = -1;
    paddedBoard[27] = -1;
    paddedBoard[36] = -1;
    paddedBoard[41] = -1;
    paddedBoard[42] = -1;
    paddedBoard[43] = -1;
    paddedBoard[44] = -1;
    paddedBoard[45] = -1;
    paddedBoard[46] = -1;
    paddedBoard[47] = -1;

    ///////// Initialize String Field for paddedArray //////////////
    strcpy(paddedToString[5], "A1");
    strcpy(paddedToString[6], "C1");
    strcpy(paddedToString[7], "E1");
    strcpy(paddedToString[8], "G1");
    strcpy(paddedToString[10], "B2");
    strcpy(paddedToString[11], "D2");
    strcpy(paddedToString[12], "F2");
    strcpy(paddedToString[13], "H2");
    strcpy(paddedToString[14], "A3");
    strcpy(paddedToString[15], "C3");
    strcpy(paddedToString[16], "E3");
    strcpy(paddedToString[17], "G3");
    strcpy(paddedToString[19], "B4");
    strcpy(paddedToString[20], "D4");
    strcpy(paddedToString[21], "F4");
    strcpy(paddedToString[22], "H4");
    strcpy(paddedToString[23], "A5");
    strcpy(paddedToString[24], "C5");
    strcpy(paddedToString[25], "E5");
    strcpy(paddedToString[27], "G5");
    strcpy(paddedToString[28], "B6");
    strcpy(paddedToString[29], "D6");
    strcpy(paddedToString[30], "F6");
    strcpy(paddedToString[31], "H6");
    strcpy(paddedToString[32], "A7");
    strcpy(paddedToString[33], "C7");
    strcpy(paddedToString[34], "E7");
    strcpy(paddedToString[35], "G7");
    strcpy(paddedToString[37], "B8");
    strcpy(paddedToString[38], "D8");
    strcpy(paddedToString[39], "F8");
    strcpy(paddedToString[40], "H8");




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
