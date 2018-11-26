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

    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("Server: %s\n", buf);


    // buffer leeren und mit Version vorbereiten
    strncpy(buf, "", sizeof(buf));
    strcpy(buf, "VERSION 2.0\n");

    if (send(socket, buf, BUF_SIZE, 0) < 0){
        perror("ERROR writing to socket");
        return -1;
    } else {
        printf("Client: %s\n", buf);
    }


    // buffer leeren
    strncpy(buf, "", sizeof(buf));
    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    } else {
        printf("Server: %s\n", buf);
    }
    

    // buffer leeren und mit Game ID vorbereiten
    strncpy(buf, "", sizeof(buf));
    strcpy(buf, "ID ");
    strcat(buf, gameID);
    strcat(buf, "\n");
    
    if(send(socket, buf, BUF_SIZE, 0) < 0){
        perror("ERROR sending message!\n");
        return -1;
    } else {
        printf("Client: %s\n", buf);
    }
    
    
    // buffer leeren
    strncpy(buf, "", sizeof(buf));
    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0 ){
        perror("ERROR recieving message!\n");
        return -1;
    } else {
        printf("Server: %s\n", buf);
    }
    



    return 0;
}