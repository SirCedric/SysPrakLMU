#ifndef CONFIG
#define CONFIG config
#endif

#define BUF_SIZE 500

char buf[BUF_SIZE];
char message[BUF_SIZE];

struct parameters{
	char hostName[BUF_SIZE];
	char portNr[BUF_SIZE];
	char gameType[BUF_SIZE];
};

struct parameters getConfig(char filename[BUF_SIZE]);

int performConnection(int Socket, char gameID[BUF_SIZE]);