#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>


#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>

#include "config.h"

void sendToServer(int *socket, char message[BUF_SIZE], bool print){

    memset(buf, 0, BUF_SIZE);
    strcpy(buf, message);

    if (write(*socket, buf, strlen(buf)) < 0) {
        perror("Fehler beim senden!");
    } else if (print){
        printf("Client: %s", buf);
    }

}

char *readfromServer(int *socket, bool print){

    memset(buf,0,BUF_SIZE);

    if (read(*socket, buf, BUF_SIZE) < 0) {
        perror("Fehler beim empfangen!");
    } else {
        strcpy(message, buf);

        if(print == true)printf("Server: %s", buf);
    }
    return message;
}


void printBoard(char *board, int boardSize)
{
	
    char boardArray[boardSize][boardSize];
    
    char tmpstr[500];
    strcpy(tmpstr, board);
    
    int i = 0;
    int j = 0;
    int k = 0;
    while (tmpstr[i] != '\0' && k < boardSize) 
    {
        if (tmpstr[i] == 'w' || tmpstr[i] == '*' || tmpstr[i] == 'b') 
        {
            boardArray[k][j] = tmpstr[i];
            j++;
        }
        if (j == boardSize)
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
                    printf("\u26c0 ");
            }
            else if (boardArray[i][j] == 'B')
            { // black king
                    printf("\u26c1 ");
            }
            else if (boardArray[i][j] == 'w')
            { // white man
                    printf("\u26c2 ");
            }
            else if (boardArray[i][j] == 'W')
            { // white king
                    printf("\u26c3 ");
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
}

int performConnection(int *socket, char gameID[BUF_SIZE], char playerCount[BUF_SIZE], struct shmData *gameData){

    char *word, *brkt;
    char *sep = "\n";

    // Booleans
    bool gameover = false;
    bool quit = false;
    bool isReady = false;
    bool readGameName = false;
    bool getBoard;

    // Spielerdaten
    int hisNumber = 0;
    int myNumber = 0;
    char hisName[ZEILENLAENGE] = "";
    char myName[ZEILENLAENGE] = "";
    char gameName[ZEILENLAENGE] = "";
    int totalPlayers = 0;

    int player;
    char playerName[ZEILENLAENGE] = "";
    int ready;
    int time;

    // Board data
    int BoardX = 0;
    int BoardY = 0;
    char board[BUF_SIZE] = "";
    char boardLine[ZEILENLAENGE];

    do{

        memset(buf, 0, BUF_SIZE);

        recv(*socket, buf, BUF_SIZE, 0);

        for (word = strtok_r(buf, sep, &brkt); word; word = strtok_r(NULL, sep, &brkt)){


            if (strncmp(word, "+ MNM Gameserver", 14) == 0) {
                printf("Bitte Version schicken\n");
                strcpy(message, "VERSION 2.2\n");
                send(*socket, message, strlen(message), 0);
                printf("Client: %s", message);
                memset(message, 0, BUF_SIZE);
            }
            if (strncmp(word, "+ Client version accepted", 24) == 0) {
                printf("Ihre Version wurde akzeptiert\n");
                printf("Bitte GameID senden\n");
                send(*socket, gameID, strlen(gameID), 0);
                printf("%s", gameID);
            }
            if(strncmp(word, "+ MOVE", 6) == 0){
                sscanf(word, "%*c %*s %i", &time);
                time /= 1000;
                printf("Sie haben %i Sekunden um einen Zug zu schicken!\n", time);
            }
            if(readGameName){
                sscanf(word, "%*c %[^\n]s", gameName);
                printf("Der Spielname lautet: %s\n", gameName);
                strcpy(gameData -> gameName, gameName);
                printf("Bitte Spielernummer senden\n");
                send(*socket, playerCount, strlen(playerCount), 0);
                printf("%s", playerCount);
                memset(message, 0, BUF_SIZE);
                readGameName = false;
            }
            if(strncmp(word, "+ PLAYING", 9) == 0){
                char gamekindname[8];
                char playing[7];
                sscanf(word, "%*c %s %s", playing, gamekindname);
                if(strcmp(gamekindname, "Checkers") != 0){
                    fprintf(stderr, "Es tut mir leid, aber dieser Client kann nur Dame spielen! Ihr ausgewähltes Spiel ist jedoch: %s.\nDie Sitzung wird beendet!\n", gamekindname);
                    return -1;
                }
                printf("Sie spielen das Spiel: \"%s\"\n", gamekindname);
                readGameName = true;
            }
            if(strncmp(word, "+ YOU", 5) == 0){
                sscanf(word, "%*c %*s %i %s", &myNumber, myName);
                if(myNumber == 0){
                    hisNumber = 1;
                    printf("Sie, %s, sind Spieler %i und spielen mit den hellen Figuren.\nSie müssen den ersten Zug machen!\n", myName, myNumber);
                    strcpy(gameData -> playerData.name, myName);
                    gameData -> playerData.num = myNumber;
                }
                if(myNumber == 1){
                    hisNumber = 0;
                    printf("Sie, %s sind Spieler %i und spielen mit den dunklen Figuren.\nIhr Gegner muss den ersten Zug machen!\n", myName, myNumber);
                    strcpy(gameData -> playerData.name, myName);
                    gameData -> playerData.num = myNumber;
                }
            }
            if(isReady){
                sscanf(word, "%*c %i %s %i", &player, playerName, &ready);
                if(player == hisNumber){
                    strcpy(hisName, playerName);
                    if(ready == 0){
                        printf("Ihr Mitspieler: %s ist noch nicht bereit!\n", playerName);
                    }
                    if(ready == 1){
                        printf("Ihr Mitspieler: %s ist bereit zu spielen!\n", playerName);
                    }
                }
                isReady = false;
            }
            if(strncmp(word, "+ TOTAL", 7) == 0){
                sscanf(word, "%*c %*s %i", &totalPlayers);
                printf("Es sind insgesamt %i Spieler verbunden\n", totalPlayers);
                isReady = true;
            }
            if(getBoard){
                if(strncmp(word, "+ ENDBOARD", 10) == 0){
                    getBoard = false;
                    printBoard(board);
                }else {
                    sscanf(word, "%*c %[^\n]s", boardLine);
                    strcat(board, boardLine);
                    strcat(board, "\n");
                    //printf("%s", board);
                }
            }
            if(strncmp(word, "+ BOARD", 7) == 0){
                sscanf(word, "%*c %*s %i,%i", &BoardX, &BoardY);
                printf("Das Board ist %i x %i groß\n", BoardX, BoardY);
                getBoard = true;
                strcpy(board, "");
            }
            if (strncmp(word, "+ ENDBOARD", 10) == 0 && !gameover) {
                printf("Bitte senden Sie einen Spielzug\n");
                strcpy(message, "THINKING\n");
                send(*socket, message, strlen(message), 0);
                printf("Berechne den Spielzug...\n");
                memset(message, 0, BUF_SIZE);
            }
            if (strncmp(word, "+ WAIT", 6) == 0) {
                printf("Bitte warten Sie einen Moment\n");
                strcpy(message, "OKWAIT\n");
                send(*socket, message, strlen(message), 0);
                printf("Warte...\n");
                memset(message, 0, BUF_SIZE);
            }
            if (strncmp(word, "+ OKTHINK", 9) == 0) {
                // TODO Thinker ansteuern
                printf("Sag dem Hirn bescheid!\n");
            }
            if(strncmp(word, "+ GAMEOVER", 10) == 0){
                printf("Das Spiel ist vorbei\n");
                gameover = true;
            }
            if (strncmp(word, "+ ENDBOARD", 10) == 0 && gameover) {
                printf("%s\n", buf);
            }
            if (strncmp(word, "- No free player", 16) == 0) {
                printf("Es ist ein Fehler aufgetreten: Kein freier Spieler!\n");
                quit = true;
            }
            if (strncmp(word, "- TIMEOUT", 9) == 0) {
                printf("Hoppla, die Antwort hat zu lange gedautert: TIMEOUT\n");
                quit = true;
            }
            if (strncmp(word, "+ QUIT", 6) == 0) {
                quit = true;
            }
        }
    }while(!quit);

    return 0;
}
