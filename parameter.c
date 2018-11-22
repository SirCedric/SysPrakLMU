#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 256

struct parameters{
	char hostName[BUFFER];
	char portNr;
	char gameType[BUFFER];
};


// returns struct parameter with parameters from specified config file
struct parameters getConfig(char filename[BUFFER]){
	
	struct parameters result;
	
	FILE *config = fopen(filename, "r");
		
		char paraName[BUFFER];
		char paraVal[BUFFER];
		char lineBuffer[BUFFER];
		
		

		while (fgets(lineBuffer, BUFFER, config) != NULL) {
			
			sscanf(lineBuffer, "%s = %s", paraName, paraVal);
			
			if (lineBuffer[0] == '#'||(lineBuffer[0] == '/' && lineBuffer[1] == '/')) {
				strcpy(paraName, "null");
				printf("test\n");
			}
			
			// reminder:
			//	Wenn strings gleich sind gibt strcmp() 0 zurück!
			if (strcmp(paraName, "hostname") == 0) {
				strcpy(result.hostName, paraVal);
//				printf("hostname: %s\n", result.hostName);
			}
			else if ((strcmp(paraName, "portnumber") == 0)) {
				strcpy(result.portNr, paraVal);
//				printf("portnumber: %i\n", result.portNr);
			}
			else if ((strcmp(paraName, "gametype") == 0)) {
				strcpy(result.gameType, paraVal);
//				printf("game type: %s\n", result.gameType);
			}

		}

		fclose(config);

	
	
	return result;
}



/*
// main function for testing
int main() {
	
	
	struct parameters config = getConfig("client.conf");
	
	printf("hostname: %s\nport number: %i\ngame type: %s", config.hostName, config.portNr, config.gameType);
	
	
}
*/