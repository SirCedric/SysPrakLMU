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
    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);


    if (send(socket, "VERSION 2.3\n", BUF_SIZE, 0) < 0){
        perror("ERROR writing to socket");
        return -1;
        }

    if((size = recv(socket, buf, BUF_SIZE, 0)) < 0){
        perror("ERROR recieving message!\n");
        return -1;
    }
    printf("%s\n", buf);


    return 0;
}