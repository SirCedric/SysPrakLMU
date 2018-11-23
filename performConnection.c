#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 500

int performConnection(int socket){
    char buf[BUF_SIZE];


    ssize_t size;
    printf("Methode aufgerufen\n");

    do{
    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);


    if (send(socket, "VERSION 2.0\n", BUF_SIZE, 0) < 0){
        perror("ERROR writing to socket");
        return -1;
        }

    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);

    if(send(socket, "ID 3n4hroe2iqxdx\n", BUF_SIZE, 0) < 0){
        perror("ERROR sending message!\n");
        return -1;
    }

    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0 ){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);

    }while(strcmp(buf, "+ ENDPLAYERS") != 0);




    return 0;
}