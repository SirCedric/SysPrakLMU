#include <sys/types.h>
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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdbool.h>



#ifndef CONFIG
#define CONFIG config
#endif

#define BUF_SIZE 500
#define ZEILENLAENGE 100

char buf[BUF_SIZE];
char message[BUF_SIZE];
char line[BUF_SIZE];

struct parameters{
    char hostName[BUF_SIZE];
    char portNr[BUF_SIZE];
    char gameType[BUF_SIZE];
};

struct player{
    char name[BUF_SIZE];
    int num;
    int ready;
    int registered;
};


struct shmData{
    int flag;
    int sem;
    int pipeFd[2];
    int boardSize;
    char gameName[BUF_SIZE];
    char gameID[BUF_SIZE];
    char playerCount[BUF_SIZE];
    char board[BUF_SIZE];
    pid_t childID;
    pid_t parentID;
    struct player playerData;
};

struct shmData *globalData;





struct parameters getConfig(char filename[BUF_SIZE]);

int performConnection(int *socket, char gameID[BUF_SIZE], char playerCount[BUF_SIZE], struct shmData *gameData);

void think();

int queenBashIndex;
int queenMoveIndex;
int bashIndex;
int moveIndex;

int paddedBoard[48];

int moveNumber;


char possibleMoves[12][24];

char paddedToString[48][3];



void makePaddedBoard(char **boardArray, int boardSize);

int checkMoveLeftBlack(int position);
int checkMoveLeftWhite(int position);

int checkMoveRightBlack(int position);
int checkMoveRightWhite(int position);

int checkBashLeftBlack(int position);
int checkBashLeftWhite(int position);

int checkBashRightBlack(int position);
int checkBashRightWhite(int position);