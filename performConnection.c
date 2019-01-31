#include "config.h"


void sendToServer(int *socket, char message[BUF_SIZE], bool print){

    memset(buf, 0, BUF_SIZE);
    strcpy(buf, message);

    if (write(*socket, buf, strlen(buf)) < 0) {
        perror("Fehler beim senden!");
    } else if (print){
        printf("Client: %s", buf);
    }

}

char *readfromServer(int *socket, bool print){

    memset(buf,0,BUF_SIZE);

    if (read(*socket, buf, BUF_SIZE) < 0) {
        perror("Fehler beim empfangen!");
    } else {
        strcpy(message, buf);

        if(print == true)printf("Server: %s", buf);
    }
    return message;
}


void printEndBoard(char **board, int boardSize){

  // print board array
  printf(" +----------------+\n");
  for (int i = 0; i < boardSize; i++)
  {
      printf("%i|", (boardSize-i));
      for (int j = 0; j < boardSize; j++)
      {
          if (board[i][j] == 'b')
          { // black man
              printf("\u26c0 ");
          }
          else if (board[i][j] == 'B')
          { // black king
              printf("\u26c1 ");
          }
          else if (board[i][j] == 'w')
          { // white man
              printf("\u26c2 ");
          }
          else if (board[i][j] == 'W')
          { // white king
              printf("\u26c3 ");
          }
          else
          {
              if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
              {
                  // white field
                  printf("--");
              }
              else
              {
                  // black field
                  printf("**");
              }
          }
      }
      printf("|\n");
  }

  printf(" +----------------+\n");
  printf("  A B C D E F G H\n");

}

void createBoardArray(char *board, int boardSize){

    char **boardArray = (char**) calloc(boardSize, sizeof(char*));

    // allocate memory for field
    for (int i = 0; i < boardSize; i++)
    {
        boardArray[i] = (char*) calloc(boardSize, sizeof(char));
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (board[i] != '\0' && k < boardSize)
    {
        if ((board[i] == 'w') | (board[i] == 'W') | (board[i] == '*') | (board[i] == 'b') | (board[i] == 'B'))
        {
            boardArray[k][j] = board[i];

            j++;
        }
        if (j == boardSize)
        {
            k++;
            j = 0;
        }
        i++;
    }
    printEndBoard(boardArray, boardSize);
    freeList(boardArray, boardSize);
  }




int performConnection(int *socket, char gameID[BUF_SIZE], char playerCount[BUF_SIZE], struct shmData *gameData){

    char *word, *brkt;
    char *sep = "\n";

    // Booleans
    bool gameover = false;
    bool quit = false;
    bool isReady = false;
    bool readGameName = false;
    bool getBoard = false;
    bool boardSizeSent = false;

    // Spielerdaten
    int hisNumber = 0;
    int myNumber = 0;
    char hisName[ZEILENLAENGE] = "";
    char myName[ZEILENLAENGE] = "";
    char gameName[ZEILENLAENGE] = "";
    int totalPlayers = 0;

    int player = 0;
    char playerName[ZEILENLAENGE] = "";
    int ready = 0;
    int time = 0;

    char won[4] = "";

    // Board data
    int boardX = 0;
    int boardY = 0;
    char board[BUF_SIZE] = "";
    char boardLine[ZEILENLAENGE] = "";

    fd_set myFDs;
    int maxFD=0;


    do{

        // Set up set of file descriptors for select()
        FD_ZERO(&myFDs);
        FD_SET(*socket, &myFDs);
        FD_SET(gameData->pipeFd[0], &myFDs);

        // Set fd with bigger ID as maxFD
        if (*socket > gameData->pipeFd[0]) maxFD = *socket;
        else maxFD = gameData->pipeFd[0];

        select(maxFD+1, &myFDs, NULL, NULL, NULL);

        if (FD_ISSET(gameData->pipeFd[0], &myFDs)) //Something was sent through the pipe
        {
            read(gameData->pipeFd[0], message, sizeof(message));
            send(*socket, message, strlen(message), 0);
            //printf("Zug %s wird gesendet.\n", message);
        }
        if (FD_ISSET(*socket, &myFDs)) // New message from server
        {


            recv(*socket, buf, BUF_SIZE, 0);

            for (word = strtok_r(buf, sep, &brkt); word; word = strtok_r(NULL, sep, &brkt)){


                if (strncmp(word, "+ MNM Gameserver", 14) == 0) {
                    printf("Bitte Version schicken\n");
                    strcpy(message, "VERSION 2.4\n");
                    send(*socket, message, strlen(message), 0);
                    printf("Client: %s", message);
                    memset(message, 0, BUF_SIZE);
                }
                if (strncmp(word, "+ Client version accepted", 24) == 0) {
                    printf("Ihre Version wurde akzeptiert\n");
                    printf("Bitte GameID senden\n");
                    send(*socket, gameID, strlen(gameID), 0);
                    printf("%s", gameID);
                }
                if(strncmp(word, "+ MOVE", 6) == 0){
                    sscanf(word, "%*c %*s %i", &time);
                    time /= 1000;
                    printf("Sie haben %i Sekunden um einen Zug zu schicken!\n", time);
                }
                if(readGameName){
                    sscanf(word, "%*c %[^\n]s", gameName);
                    printf("Der Spielname lautet: %s\n", gameName);
                    strcpy(gameData -> gameName, gameName);
                    printf("Bitte Spielernummer senden\n");
                    send(*socket, playerCount, strlen(playerCount), 0);
                    printf("%s", playerCount);
                    memset(message, 0, BUF_SIZE);
                    readGameName = false;
                }
                if(strncmp(word, "+ PLAYING", 9) == 0){
                    char gamekindname[8];
                    char playing[7];
                    sscanf(word, "%*c %s %s", playing, gamekindname);
                    if(strcmp(gamekindname, "Checkers") != 0){
                        fprintf(stderr, "Es tut mir leid, aber dieser Client kann nur Dame spielen! Ihr ausgewähltes Spiel ist jedoch: %s.\nDie Sitzung wird beendet!\n", gamekindname);
                        return -1;
                    }
                    printf("Sie spielen das Spiel: \"%s\"\n", gamekindname);
                    readGameName = true;
                }
                if(strncmp(word, "+ YOU", 5) == 0){
                    sscanf(word, "%*c %*s %i %s", &myNumber, myName);
                    if(myNumber == 0){
                        hisNumber = 2;
                        printf("Sie, %s, sind Spieler %i und spielen mit den hellen Figuren.\nSie müssen den ersten Zug machen!\n", myName, (myNumber+1));
                        strcpy(gameData -> playerData.name, myName);
                        gameData -> playerData.num = (myNumber+1);
                    }
                    if(myNumber == 1){
                        hisNumber = 1;
                        printf("Sie, %s sind Spieler %i und spielen mit den dunklen Figuren.\nIhr Gegner muss den ersten Zug machen!\n", myName, (myNumber+1));
                        strcpy(gameData -> playerData.name, myName);
                        gameData -> playerData.num = (myNumber+1);
                    }
                }
                if(isReady){
                    sscanf(word, "%*c %i %s %i", &player, playerName, &ready);
                    if(player+1 == hisNumber){
                        strcpy(hisName, playerName);
                        if(ready == 0){
                            printf("Ihr Mitspieler: %s ist noch nicht bereit!\n", playerName);
                        }
                        if(ready == 1){
                            printf("Ihr Mitspieler: %s ist bereit zu spielen!\n", playerName);
                        }
                    }
                    isReady = false;
                }
                if(strncmp(word, "+ TOTAL", 7) == 0){
                    sscanf(word, "%*c %*s %i", &totalPlayers);
                    printf("Es sind insgesamt %i Spieler verbunden\n", totalPlayers);
                    isReady = true;
                }
                if(getBoard){
                    if(strncmp(word, "+ ENDBOARD", 10) == 0){
                        getBoard = false;
                        gameData->boardSize = boardX;
                        strcpy(gameData->board, board);
                        createBoardArray(board, boardX);
                    }else {
                        sscanf(word, "%*c %*i %[^\n]s", boardLine);
                        strcat(board, boardLine);
                        strcat(board, "\n");
                    }
                }
                if(strncmp(word, "+ BOARD", 7) == 0){
                    sscanf(word, "%*c %*s %i,%i", &boardX, &boardY);
                    if(!boardSizeSent){
                      printf("Das Board ist % i  x %i groß\n", boardX, boardY);
                      boardSizeSent = true;
                    }
                    getBoard = true;
                    strcpy(board, "");
                }
                if (strncmp(word, "+ ENDBOARD", 10) == 0 && !gameover) {
                    printf("Bitte senden Sie einen Spielzug\n");
                    strcpy(message, "THINKING\n");
                    send(*socket, message, strlen(message), 0);
                    printf("Berechne den Spielzug...\n");
                    memset(message, 0, BUF_SIZE);
                }
                if (strncmp(word, "+ WAIT", 6) == 0) {
                    printf("Bitte warten Sie einen Moment\n");
                    strcpy(message, "OKWAIT\n");
                    send(*socket, message, strlen(message), 0);
                    printf("Warte...\n");
                    memset(message, 0, BUF_SIZE);
                }
                if (strncmp(word, "+ OKTHINK", 9) == 0) {
                    gameData -> flag = 1;
                    kill(gameData -> parentID, SIGUSR1);
                    printf("Sag dem Hirn bescheid!\n");
                }
                if(strncmp(word, "+ GAMEOVER", 10) == 0){
                    printf("Das Spiel ist vorbei\n");
                    gameover = true;
                }
                /*
                if (strncmp(word, "+ ENDBOARD", 10) == 0 && gameover) {

                }
                */
                if(strncmp(word, "+ MOVEOK", 8) == 0){
                    printf("Der Zug war erfolgreich\n");
                }
                if(strncmp(word, "+ PLAYER0WON", 12) == 0){
                  printf("%s\n", word);
                    sscanf(word, "%*c %*s %s", won);
                    if(strncmp(won, "Yes", 3) == 0){
                        if(myNumber == 1) {
                            printf("%s hat gewonnen!\n", myName);
                        }
                        if(hisNumber == 1){
                            printf("%s hat gewonnen!\n", hisName);
                        }
                    }
                    if(strncmp(won, "No", 2) == 0){
                        if(myNumber == 1) {
                            printf("%s hat verloren!\n", myName);
                        }
                        if(hisNumber == 1){
                            printf("%s hat verloren!\n", hisName);
                        }
                    }
                }
                if(strncmp(word, "+ PLAYER1WON", 12) == 0){
                  printf("%s\n", word);
                  sscanf(word, "%*c %*s %s", won);
                    if(strncmp(won, "Yes", 3) == 0){
                        if(myNumber == 2) {
                            printf("%s hat gewonnen!\n", myName);
                        }
                        if(hisNumber == 2){
                            printf("%s hat gewonnen!\n", hisName);
                        }
                    }
                    if(strncmp(won, "No", 2) == 0){
                        if(myNumber == 2) {
                            printf("%s hat verloren!\n", myName);
                        }
                        if(hisNumber == 2){
                            printf("%s hat verloren!\n", hisName);
                        }
                    }
                }
                if (strncmp(word, "- No free player", 16) == 0) {
                    printf("Es ist ein Fehler aufgetreten: Kein freier Spieler!\n");
                    quit = true;
                }
                if (strncmp(word, "- TIMEOUT", 9) == 0) {
                    printf("Hoppla, die Antwort hat zu lange gedautert: TIMEOUT\n");
                    quit = true;
                }
                if (strncmp(word, "+ QUIT", 6) == 0) {
                    printf("Die Sitzung wird beendet!\n");
                    quit = true;
                }
                if (strncmp(word, "- Invalid", 9) == 0) {
                    printf("Zug wird nicht akzeptiert: %s\n", word);
                    quit = true;
                }
            } memset(buf, 0, BUF_SIZE);
        }

    } while(!quit);


    return 0;
}
