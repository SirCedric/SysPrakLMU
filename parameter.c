
#include "config.h"


// returns struct parameter with parameters from specified config file
struct parameters getConfig(char filename[BUF_SIZE]){
	
	struct parameters result;
	
	FILE *config = fopen(filename, "r");
		
	char paraName[BUF_SIZE];
	char paraVal[BUF_SIZE];
	char lineBUF_SIZE[BUF_SIZE];
	
	

	while (fgets(lineBUF_SIZE, BUF_SIZE, config) != NULL) {
		
		sscanf(lineBUF_SIZE, " %s = %s", paraName, paraVal);
		
		if (lineBUF_SIZE[0] == '#'||(lineBUF_SIZE[0] == '/' && lineBUF_SIZE[1] == '/')) {
			strcpy(paraName, "null");
		}
		
		// reminder:
		//	Wenn strings gleich sind gibt strcmp() 0 zurück!
		if (strcmp(paraName, "hostname") == 0) {
			strcpy(result.hostName, paraVal);
		}
		else if ((strcmp(paraName, "portnumber") == 0)) {
			strcpy(result.portNr, paraVal);
		}
		else if ((strcmp(paraName, "gametype") == 0)) {
			strcpy(result.gameType, paraVal);
		}
	}

	fclose(config);

	return result;
}
