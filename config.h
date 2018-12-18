#include <sys/types.h>

#ifndef CONFIG
#define CONFIG config
#endif

#define BUF_SIZE 500
#define ZEILENLÄNGE 100

char buf[BUF_SIZE];
char message[BUF_SIZE];
char line[BUF_SIZE];

struct parameters{
	char hostName[BUF_SIZE];
	char portNr[BUF_SIZE];
	char gameType[BUF_SIZE];
};

struct player{
		char name[BUF_SIZE];
		int num;
		int ready;
		int registered;
};


struct shmData{
	int sem;
	char gameName[BUF_SIZE];
	char gameID[BUF_SIZE];
	char playerCount[BUF_SIZE];
	pid_t childID;
	pid_t parentID;
	struct player playerData;
};



struct parameters getConfig(char filename[BUF_SIZE]);

int performConnection(int *socket, char gameID[BUF_SIZE]);
