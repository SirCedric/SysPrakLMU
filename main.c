#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define GAMEKINDNAME "Checkers"
#define PORTNUMBER 1375
#define HOSTNAME "sysprak.priv.lab.nm.ifi.lmu.de"

int main(int argc, char** argv[]){
    
    int sock = socket(gethostbyname(HOSTNAME), AF_INET, 0);
}
