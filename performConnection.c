#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "config.h"

int performConnection(int socket, char* gameID){
    
    char buf[BUF_SIZE];

    ssize_t size;
    printf("Methode aufgerufen\n");


    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);


    if (send(socket, "VERSION 2.0\n", BUF_SIZE, 0) < 0){
        perror("ERROR writing to socket");
        return -1;
        }

    // buffer leeren
    strncpy(buf, "", sizeof(buf));
    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);


    // buffer leeren und mit Game ID vorbereiten
    strncpy(buf, "", sizeof(buf));
    strcpy(buf, "ID ");
    strcat(buf, gameID);
    strcat(buf, "\n");
    printf("Client: %s", buf);
    
    if(send(socket, buf, BUF_SIZE, 0) < 0){
        perror("ERROR sending message!\n");
        return -1;
    }
    
    // buffer leeren
    strncpy(buf, "", sizeof(buf));
    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0 ){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);

    




    return 0;
}