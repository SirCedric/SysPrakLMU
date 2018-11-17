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
    long gameID;
    int playercount;


// Verarbeitung der Kommandozeilenparameter
    
  if(argc != 5 || strcmp(argv[1], "-g") != 0 || strcmp(argv[3], "-p") != 0) {
    printf("Error: Arguments\n");
    return -1;
}
  
  gameID = atol(argv[2]);
  playercount = atoi(argv[4]);

  // "Falls gameID keine 13-stellige Zahl"
  if((double)gameID/1000000000000 < 1 || (double)gameID/9999999999999 > 1){
    printf("Error: GameID\n");
    return -1;
  }

  if(playercount != 1 && playercount != 2){
    printf("Error: Playercount\n");
    return -1;
  }

    return 0;
}
