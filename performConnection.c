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

void sendToServer(int *socket, char message[BUF_SIZE]){

    memset(buf, 0, BUF_SIZE);
    strcpy(buf, message);
    
    if (write(*socket, buf, strlen(buf)) < 0) {
        perror("Fehler beim senden!");
    } else {
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

void printBoard(char *board){
    
    char step1[500] = "";
    char step2[500] = "";
        
    sscanf(board, "%*[^8,8]8,8\n%[^Y]s", step1);

    for (int i = 0;i<500;i++) {
        if (step1[i] == 'w' || step1[i] == '*' || step1[i] == 'b') {
            char cToStr[2];
            cToStr[0] = step1[i];
            cToStr[1] = '\0';
            strcat(step2, cToStr);
        }
    }
    
    // create board array
    char boardArray[8][8];
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            boardArray[i][j] = step2[counter];
            counter++;
        }
    }
    
    // print board array
    printf(" +-----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%i| ", (8-i));
        for (int j = 0; j < 8; j++) {
            printf("%c ", boardArray[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------+\n");
    printf("   A B C D E F G H\n");
}


int performConnection(int *socket, char gameID[BUF_SIZE]){

    ssize_t size;
    char *word, *brkt;
    char *sep = "\n";
    bool gameover = false;

do{

    memset(buf, 0, BUF_SIZE);

    size = recv(*socket, buf, BUF_SIZE, 0);

    for (word = strtok_r(buf, sep, &brkt); word; word = strtok_r(NULL, sep, &brkt)){

        if (strncmp(word, "+ MNM Gameserver", 14) == 0) {
            printf("Bitte Version schicken\n");
            strcpy(message, "VERSION 2.2\n");
            send(*socket, message, strlen(message), 0);
            printf("Client: %s", message);
            memset(message, 0, BUF_SIZE);
        }
        if (strncmp(word, "+ Client version accepted", 24) == 0) {
            printf("Bitte GameID senden\n");
            send(*socket, gameID, strlen(gameID), 0);
            printf("%s", gameID);
        }
        if (strncmp(word, "+ Game", 6) == 0) {
            printf("Bitte Spielernummer senden\n");
            strcpy(message, "PLAYER\n");
            send(*socket, message, strlen(message), 0);
            printf("%s", message);
            memset(message, 0, BUF_SIZE);
        }
        if (strncmp(word, "+ WAIT", 6) == 0) {
            printf("Bitte warten Sie einen Moment\n");
            strcpy(message, "OKWAIT\n");
            send(*socket, message, strlen(message), 0);
            printf("Warte...\n");
            memset(message, 0, BUF_SIZE);
        }
        if (strncmp(word, "+ ENDBOARD", 10) == 0 && !gameover) {
            printf("Bitte senden Sie einen Spielzug\n");
            strcpy(message, "THINKING\n");
            send(*socket, message, strlen(message), 0);
            printf("Berechne den Spielzug...");
            memset(message, 0, BUF_SIZE);
        }
        if (strncmp(word, "+ OKTHINK", 9) == 0) {
            // TODO Thinker ansteuern
        }
        if(strncmp(word, "+ GAMEOVER", 10) == 0){
            printf("Das Spiel ist vorbei\n");
            gameover = true;
        }
        if (strncmp(word, "+ ENDBOARD", 10) == 0 && gameover) {

        }
        //if(strncmp(token, ) == 0){
        //
        //}
        if (strncmp(word, "- No free player", 16) == 0) {
            printf("Es ist ein Fehler aufgetreten: Kein freier Spieler!\n");
        }
        if (strncmp(word, "- TIMEOUT", 9) == 0) {
            printf("Hoppla, die Antwort hat zu lange gedautert: TIMEOUT\n");
        }
    }

}while(strncmp(word, "+ QUIT", 6) != 0);
printf("Exit while()\n");

    return 0;
}