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
        perror("ERROR recieving message!");
        return -1;
    }
    printf("%s\n", buf);

    if(strcmp(buf, "+ MNM Gameserver 2.3 accepting connections") == 0) {
        printf("Send Client Version")
        if (send(socket, "VERSION 2.0", BUF_SIZE, 0) < 0){
            perror("ERROR writing to socket");
            return -1;
        }
    }


    return 0;
}