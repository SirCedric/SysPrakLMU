
#define BUF_SIZE 500

struct parameters{
	char hostName[BUF_SIZE];
	char portNr[BUF_SIZE];
	char gameType[BUF_SIZE];
};

struct parameters getConfig(char filename[BUF_SIZE]);

int performConnection(int Socket);
