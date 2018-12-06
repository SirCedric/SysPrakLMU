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

struct shmData{
	char gameName[BUF_SIZE];
	char shmGameID[BUF_SIZE];
	int shmPlayerCount;
	pid_t thinkerID;
	pid_t connectorID;
//	struct player spieler;
};

struct player {
		char name[BUF_SIZE];
		int num;
		int ready;
		int registered;
};

struct parameters getConfig(char filename[BUF_SIZE]);

int performConnection(int *socket, char gameID[BUF_SIZE]);