/*
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
*/
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




int performConnection(int *socket, char gameID[BUF_SIZE], char playerCount[BUF_SIZE], struct shmData *gameData){

    char *word, *brkt;
    char *sep = "\n";

    // Booleans
    bool gameover = false;
    bool quit = false;
    bool isReady = false;
    bool readGameName = false;
    bool getBoard = false;

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

    char won[3];

    // Board data
    int boardX = 0;
    int boardY = 0;
    char board[BUF_SIZE] = "";
    char boardLine[ZEILENLAENGE];

    fd_set myFDs;
    int maxFD;


    do{

        // Set up set of file descriptors for select()
        FD_ZERO(&myFDs);
        FD_SET(*socket, &myFDs);
        FD_SET(gameData->pipeFd[0], &myFDs);

        // Set fd with bigger ID as maxFD
        if (*socket > gameData->pipeFd[0]) maxFD = *socket;
        else maxFD = gameData->pipeFd[0];

        select(maxFD+1, &myFDs, NULL, NULL, NULL);
        
        if (FD_ISSET(gameData->pipeFd[0], &myFDs)) //Something was sent through the pipe
        {
            read(gameData->pipeFd[0], message, sizeof(message));
            send(*socket, message, strlen(message), 0);
            printf("Zug %s wird gesendet.\n", message);
        }
        if (FD_ISSET(*socket, &myFDs)) // New message from server
        {


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
                        hisNumber = 2;
                        printf("Sie, %s, sind Spieler %i und spielen mit den hellen Figuren.\nSie müssen den ersten Zug machen!\n", myName, myNumber+1);
                        strcpy(gameData -> playerData.name, myName);
                        gameData -> playerData.num = myNumber+1;
                    }
                    if(myNumber == 1){
                        hisNumber = 1;
                        printf("Sie, %s sind Spieler %i und spielen mit den dunklen Figuren.\nIhr Gegner muss den ersten Zug machen!\n", myName, myNumber+1);
                        strcpy(gameData -> playerData.name, myName);
                        gameData -> playerData.num = myNumber+1;
                    }
                }
                if(isReady){
                    sscanf(word, "%*c %i %s %i", &player, playerName, &ready);
                    if(player+1 == hisNumber){
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
                        gameData->boardSize = boardX;
                        strcpy(gameData->board, board);
                    }else {
                        sscanf(word, "%*c %*i %[^\n]s", boardLine);
                        strcat(board, boardLine);
                        strcat(board, "\n");
                    }
                }
                if(strncmp(word, "+ BOARD", 7) == 0){
                    sscanf(word, "%*c %*s %i,%i", &boardX, &boardY);
                    printf("Das Board ist %i x %i groß\n", boardX, boardY);
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
                    gameData -> flag = 1;
                    kill(gameData -> parentID, SIGUSR1);
                    printf("Sag dem Hirn bescheid!\n");
                }
                if(strncmp(word, "+ GAMEOVER", 10) == 0){
                    printf("Das Spiel ist vorbei\n");
                    gameover = true;
                }
                if (strncmp(word, "+ ENDBOARD", 10) == 0 && gameover) {
                    printf("%s\n", buf);
                }
                if(strncmp(word, "+ MOVEOK", 8) == 0){
                    printf("Der Zug war erfolgreich\n");
                }
                if(strncmp(word, "+ PLAYER0WON", 12) == 0){
                    sscanf(word, "%*c %*s %s", won);
                    if(strncmp(won, "Yes", 3) == 0){
                        if(myNumber == 0) {
                            printf("%s hat gewonnen!\n", myName);
                        }
                        if(hisNumber == 0){
                            printf("%s hat gewonnen!\n", hisName);
                        }
                    }
                    if(strncmp(won, "No", 2) == 0){
                        if(myNumber == 0) {
                            printf("%s hat verloren!\n", myName);
                        }
                        if(hisNumber == 0){
                            printf("%s hat verloren!\n", hisName);
                        }
                    }
                }
                if(strncmp(word, "+ PLAYER1WON", 12) == 0){
                    sscanf(word, "%*c %*s %s", won);
                    if(strncmp(won, "Yes", 3) == 0){
                        if(myNumber == 1) {
                            printf("%s hat gewonnen!\n", myName);
                        }
                        if(hisNumber == 1){
                            printf("%s hat gewonnen!\n", hisName);
                        }
                    }
                    if(strncmp(won, "No", 2) == 0){
                        if(myNumber == 1) {
                            printf("%s hat verloren!\n", myName);
                        }
                        if(hisNumber == 1){
                            printf("%s hat verloren!\n", hisName);
                        }
                    }
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
                    printf("Die Sitzung wird beendet!\n");
                    quit = true;
                }
                if (strncmp(word, "- Invalid", 9) == 0) {
                    printf("Zug wird nicht akzeptiert: %s\n", word);
                    quit = true;
                }
            } memset(buf, 0, BUF_SIZE);
        }

    } while(!quit);


    return 0;
}
