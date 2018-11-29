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


#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>

#include "config.h"

void sendToServer(int *socket, char message[BUF_SIZE]){

    memset(buf, 0, BUF_SIZE);
    strcpy(buf, message);
    
    if (write(*socket, buf, BUF_SIZE) < 0) {
        perror("Fehler beim senden!");
    }
}

char *readfromServer(int *socket){
    
    memset(buf,0,BUF_SIZE);
    
    if (read(*socket, buf, BUF_SIZE) < 0) {
        perror("Fehler beim empfangen!");
    }
    printf("!!Server: %s\n", message);
    strcpy(message, buf);
    return message;
}


int performConnection(int *socket, char gameID[BUF_SIZE]){
    
    printf("%s", gameID);
    
//    // Wenn eine Verbindung zustande kommt wird die Version gesendet.
//    if(strncmp(readfromServer(socket), "+", 1) == 0){
//        
//        printf("Verbindung zum Server hergestellt\n");
//        sendToServer(socket, "VERSION 2.0\n");
//    } else {
//        perror("Fehler bei der Verbindung!");
//        return -1;
//    }
//
//    // Wenn die Version stimmt wird die Game ID gesendet.
//    if(strncmp(readfromServer(socket), "+", 1) == 0){
//        
//        printf("Version wurde akzeptiert.\n");
//        
//        sendToServer(socket, gameID);
//    } else {
//        perror("Fehler bei der Versionsnummer!");
//        return -1;
//    }
//
//    
//    if(strncmp(readfromServer(socket), "+", 1) == 0){
//        printf("Game ID wurde akzepiert.\n");
//    } else {
//        perror("Game ID wurde nicht akzepiert!");
//        return -1;
//    }
    
    // erste Nachricht empfangen
    recv(*socket, buf, BUF_SIZE, 0);
    printf("%s", buf);
    
    // Versionsnummer schicken
    send(*socket, "VERSION 2.0\n", 12, 0);
    
    // Antwort empfangen
    recv(*socket, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Game ID senden
    send(*socket, gameID, strlen(gameID), 0);

    // Antwort empfangen
    memset(buf, 0, BUF_SIZE);
    recv(*socket, buf, BUF_SIZE, 0);
    printf("%s", buf);
    
    
    // Antwort empfangen
    memset(buf, 0, BUF_SIZE);
    recv(*socket, buf, BUF_SIZE, 0);
    printf("%s", buf);
    
    // Spieler senden
    memset(buf, 0, BUF_SIZE);
    strcpy(buf, "PLAYER 1\n");
    send(*socket, buf, strlen(buf), 0);
    
    // Antwort empfangen
    memset(buf, 0, BUF_SIZE);
    recv(*socket, buf, BUF_SIZE, 0);
    printf("%s", buf);

    return 0;
}