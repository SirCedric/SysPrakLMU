#include "config.h"



// Gets char array pointer and prints out formated board
void printBoard(char **board, int boardSize)
{

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


// function with thinks of the ext best move
void think()
{
    if(!globalData->flag) printf("Signal recieved, but not from Connector.\n");
    else printf("Signal from Connector recieved.\n");

    // declare local variable based on size in shm segment for shorter code
    int boardSize = globalData->boardSize;

    char **boardArray = (char**) calloc(boardSize, sizeof(char*));
	
    // allocate memory for field
    for (int i = 0; i < boardSize; i++)
    {
            boardArray[i] = (char*) calloc(boardSize, sizeof(char));
    }

    char tmpstr[500];
    strcpy(tmpstr, globalData->board);

    //char move[BUF_SIZE];
    //int player = globalData->playerData.num;
    int i = 0;
    int j = 0;
    int k = 0;

    while (tmpstr[i] != '\0' && k < globalData->boardSize)
    {
        if (tmpstr[i] == 'w' || tmpstr[i] == 'W' || tmpstr[i] == '*' || tmpstr[i] == 'b' || tmpstr[i] == 'B')
        {
            boardArray[k][j] = tmpstr[i];
            j++;
        }
        if (j == globalData->boardSize)
        {
            k++;
            j = 0;
        }
        i++;
    }

    // printing out board recieved from connector
    printBoard(boardArray, boardSize);

    // create padded array board
    makePaddedBoard(boardArray, boardSize);

    /*

    moveNumber = 0;

    switch (globalData->playerData.num){
        case 1:
            //TODO call white functions
            for(int i = 0; i < 48; i++){
                if(paddedBoard[i] == 1){
                    if(checkBashLeftWhite(paddedBoard[i]) == 0){
                        strcat(possibleMovesLeft)

                    }
                }
                if(paddedBoard[i] == 2){

                }
            }
            break;
        case 2:
            //TODO call black functions
            break;
        default:
            printf("Die Spielernummer: %i existiert nicht!\n", globalData->playerData.num);
            break;
    }

     */



    // first run through to check if stones can be taken from the opposing player
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            if (player == 0 && boardArray[i][j] == 'w' && i != 0) 
            {   
                // Could possibly take a stone
                if (boardArray[i-1][j+1] == 'b' && i-1 >= 0 && j+1 < boardSize) 
                {
                    // check possibility
                    if (boardArray[i-1-1][j+1+1] == '*' && i-1-1 >= 0 && j+1+1 < boardSize)
                    {
                        printf("MOVE: WSR");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1+1, 8-i+1+1);
                        goto DONE;
                    }
                }
                // Could possibly take a stone
                else if (boardArray[i-1][j-1] == 'b' && i-1 >= 0 && j-1 >= 0)
                {
                    // check possibility
                    if (boardArray[i-1-1][j-1-1] == '*' && i-1-1 >= 0 && j-1-1 >= 0)
                    {
                        printf("MOVE: WSL");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1-1, 8-i+1+1);
                        goto DONE;
                    }
                }
            }
            else if (player == 1 && boardArray[i][j] == 'b' && i != boardSize-1)
            {
                // Could possibly take a stone
                if (boardArray[i+1][j-1] == 'w' && i+1 < boardSize && j-1 >= 0)
                {
                    // check possibility
                    if (boardArray[i+1+1][j-1-1] == '*' && i+1+1 < boardSize && j-1-1 >= 0)
                    {  
                        printf("MOVE: BSL");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1-1, 8-i-1-1);
                        goto DONE;
                    }
                }
                // Could possibly take a stone
                else if (boardArray[i+1][j+1] == 'w' && i-1 >= 0 && j+1 < boardSize) 
                {
                    // check possibility
                    if (boardArray[i+1+1][j+1+1] == '*' && i+1+1 < boardSize && j+1+1 < boardSize)
                    {   
                        printf("MOVE: BSR");
                        sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1+1, 8-i-1-1);
                        goto DONE;
                    }
                }
            } 
        }
    }

    // Second run through if no stones can be taken
    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardSize; j++) 
        {
            if (player == 0 && boardArray[i][j] == 'w' && i != 0) 
            {   
                if (boardArray[i-1][j+1] == '*' && i-1 >= 0 && j+1 < boardSize) 
                {
                    printf("MOVE: WR");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1, 8-i+1);
                    goto DONE;
                }
                else if (boardArray[i-1][j-1] == '*' && j-1 >= 0 && i-1 >= 0) 
                {
                    printf("MOVE: WL");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1, 8-i+1);
                    goto DONE;
                }
            }
            else if (player == 1 && boardArray[i][j] == 'b' && i != boardSize-1)
            {
                if (boardArray[i+1][j+1] == '*' && i+1 < boardSize && j+1 < boardSize) 
                {
                    printf("MOVE: BR");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j+1, 8-i-1);
                    goto DONE;
                }
                else if (boardArray[i+1][j-1] == '*' && i+1 < boardSize && j-1 >= 0) 
                {
                    printf("MOVE: BL");
                    sprintf(move, "%c%i:%c%i\n", 65+j, 8-i, 65+j-1, 8-i-1);
                    goto DONE;
                }
            } 
        }
    }
printf("Error: no move found!\n");
DONE:
    printf("\n");
    char result[BUF_SIZE] = "PLAY ";
    strcat(result, move);
    write(globalData->pipeFd[1], result, strlen(result));
    globalData->flag = 1;

}