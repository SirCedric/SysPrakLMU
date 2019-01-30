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

void resetBoard(char **boardArray, int boardSize)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // translate recieved string into boardArray
    while (globalData->board[i] != '\0' && k < globalData->boardSize)
    {
        if ((globalData->board[i] == 'w') | (globalData->board[i] == 'W') | (globalData->board[i] == '*') | (globalData->board[i] == 'b') | (globalData->board[i] == 'B'))
        {
            boardArray[k][j] = globalData->board[i];
            j++;
        }
        if (j == boardSize)
        {
            k++;
            j = 0;
        }
        i++;
    }
}


// Gets whole move as string and returns last known position as int array 
// with int[0] = x and int[1] = y.
// move is the move string
// backtrack is the amount of steps back you want to take in the given move
// with move = "A3:B4:C5" and backtrack=0 you get "C5" as int array
// with backtrack=1 you get B4 and so forth.
int * translatePosition(char move[], int backtrack)
{
	
    int length = strlen(move);
        
    backtrack = backtrack *3;
		
    int x = move[length-2-backtrack];
    int y = move[length-1-backtrack];
    
    static int retval[2];
    retval[0] = x-65;
    retval[1] = globalData->boardSize-(y-48);
    
    return retval;
}


// Gets a board and a move, executes move on board
// and returns changed board
char** makeMove(char **board, char *move)
{
        
    // get second to last position, save stone and empty field 
    int *a = translatePosition(move, 1);
    char tmp = board[a[1]][a[0]];
    board[a[1]][a[0]] = '*';

    // get last position and move saved stone to that field
    int *b = translatePosition(move, 0);
    board[b[1]][b[0]] = tmp;

    // return new board array
    return board;
}

//TODO: logic for queen:
int queenCheckForMoveBash(char pos[], char **boardArray, int boardSize, char **queenBashList)
{
    char tmpPos[BUF_SIZE];
    strcpy(tmpPos, pos);
    
    int player = globalData->playerData.num;
    char *move = calloc(2, sizeof(char*));

    bool foundMove = false;
    
    int *a = translatePosition(tmpPos, 0);
    
    int i = a[1];
    int j = a[0];

    char playerQueen = 'W';
    char opStone = 'b';
    char opQueen = 'B';
    
    if (player == 2)
    {
        playerQueen = 'B';
        opStone = 'w';
        opQueen = 'W';
    }
    

    // first run through
    while(i >=0 && i < boardSize && j >= 0 && j < boardSize)
    {
        if (i+1 < boardSize && j+1 < boardSize)
        {
            if (boardArray[i+1][j+1] == '*')
            {
                i++;
                j++;
            }
            else if ( i+1 < boardSize && j+1 < boardSize && i+1+1 < boardSize && j+1+1 < boardSize)
            {
                if ((boardArray[i+1][j+1] == opStone || boardArray[i+1][j+1] == opQueen) && boardArray[i+1+1][j+1+1] == '*')
                {
                    printf("MOVE: QMDCR\n");
                    foundMove = true;
                    move[0] = 65+j+1+1;
                    move[1] = 8-i-1-1+48;
                    strcat(tmpPos, ":");
                    strcat(tmpPos, move);
                    // execute move on board for recursive function call
                    boardArray[a[1]][a[0]] = '*';
                    boardArray[i+1][j+1] = '*';
                    boardArray[i+1+1][j+1+1] = playerQueen;
                    // recursively call function in case of multiple jumps
                    queenCheckForMoveBash(tmpPos, boardArray, boardSize, queenBashList); 
                    return 0;
                }
               break;
            }
            else break;
        } 
        else break;
    }
    // reset position
    i = a[1];
    j = a[0];
    
        
    // second run through
    while(i >=0 && i < boardSize && j >= 0 && j < boardSize)
    {
        if (i+1 < boardSize && j-1 >= 0)
        {
            if (boardArray[i+1][j-1] == '*')
            {
                i++;
                j--;
            }
            else if (i+1 < boardSize && j-1 > 0 && i+1+1 < boardSize && j-1-1 >= 0)
            {
                if ((boardArray[i+1][j-1] == opStone || boardArray[i+1][j-1] == opQueen) && boardArray[i+1+1][j-1-1] == '*')
                {
                    printf("MOVE: QMDCL\n");
                    foundMove = true;
                    move[0] = 65+j-1-1;
                    move[1] = 8-i-1-1+48;
                    strcat(tmpPos, ":");
                    strcat(tmpPos, move);
                    // execute move on board for recursive function call
                    boardArray[a[1]][a[0]] = '*';
                    boardArray[i+1][j-1] = '*';
                    boardArray[i+1+1][j-1-1] = playerQueen;
                    // recursively call function in case of multiple jumps
                    queenCheckForMoveBash(tmpPos, boardArray, boardSize, queenBashList); 
                    return 0;
                }
                break;
            }
            else break;
        } 
        else break;
    }
    // reset position
    i = a[1];
    j = a[0];


    // third run through
    while(i >=0 && i < boardSize && j >= 0 && j < boardSize)
    {
        if (i-1 >= 0 && j+1 < boardSize)
        {   
            if (boardArray[i-1][j+1] == '*')
            {
                i--;
                j++;
            }
            else if ( i-1 > 0 && j+1 < boardSize && i+1+1 >= 0 && j+1+1 < boardSize)
            {
                if ((boardArray[i-1][j+1] == opStone || boardArray[i-1][j+1] == opQueen) && boardArray[i-1-1][j+1+1] == '*')
                {
                    printf("MOVE: QMUCR\n");
                    foundMove = true;
                    move[0] = 65+j+1+1;
                    move[1] = 8-i+1+1+48;
                    strcat(tmpPos, ":");
                    strcat(tmpPos, move);
                    // execute move on board for recursive function call
                    boardArray[a[1]][a[0]] = '*';
                    boardArray[i-1][j+1] = '*';
                    boardArray[i-1-1][j+1+1] = playerQueen;
                    // recursively call function in case of multiple jumps
                    queenCheckForMoveBash(tmpPos, boardArray, boardSize, queenBashList); 
                    return 0;
                }
                break;
                
            }
            else break;
        }
        else break;
    }
    // reset position
    i = a[1];
    j = a[0];

    // fourth run through
    while(i >=0 && i < boardSize && j >= 0 && j < boardSize)
    {
        if (i-1 > 0 && j-1 > 0)
        {
            if (boardArray[i-1][j-1] == '*')
            {
                i--;
                j--;
            }
            else if (i-1-1 >= 0 && j-1-1 >= 0)
            {
                if ((boardArray[i-1][j-1] == opStone || boardArray[i-1][j-1] == opQueen) && boardArray[i-1-1][j-1-1] == '*')
                {
                    printf("MOVE: QDCL\n");
                    foundMove = true;
                    move[0] = 65+j-1-1;
                    move[1] = 8-i+1+1+48;
                    strcat(tmpPos, ":");
                    strcat(tmpPos, move);
                    // execute move on board for recursive function call
                    boardArray[a[1]][a[0]] = '*';
                    boardArray[i-1][j-1] = '*';
                    boardArray[i-1-1][j-1-1] = playerQueen;
                    // recursively call function in case of multiple jumps
                    queenCheckForMoveBash(tmpPos, boardArray, boardSize, queenBashList); 
                    return 0;
                }
                break;
                
            }
            else break;
        }
        else break;
    }
    // reset position
    i = a[1];
    j = a[0];
    
    free(move);

    if (foundMove == false && strlen(tmpPos) > 2)  
    {
        printf("writing bash move(%s) to queenBashList.\n", tmpPos);
        strcpy(queenBashList[queenBashIndex], tmpPos);
        printf("%i\n", queenBashIndex);
        queenBashIndex++;
        resetBoard(boardArray, boardSize);
        return 0;
    }
    else 
    {
        return -1;
    }
}


int queenCheckForMove(char pos[], char **boardArray, int boardSize, char **queenMoveList)
{
    char *move = calloc(2, sizeof(char*));
    
    int *a = translatePosition(pos, 0);
    
    int i = a[1];
    int j = a[0];
    
    printf("i:%i, j:%i, field:%c\n", i, j, boardArray[i][j]);

    // Second run through if no stones can be taken
        if(i-1 >= 0 && j+1 < boardSize)
        {
            if (boardArray[i-1][j+1] == '*') 
            {
                printf("%s: MOVE: QUR\n", pos);
                move[0] = 65+j+1;
                move[1] = 8-i+1+48;
                sprintf(queenMoveList[queenMoveIndex], "%s:%s", pos, move);
                queenMoveIndex++;
            }
        }
        if(j-1 >= 0 && i-1 >= 0)
        {
            if (boardArray[i-1][j-1] == '*') 
            {
                printf("%s: MOVE: QUL\n", pos);
                move[0] = 65+j-1;
                move[1] = 8-i+1+48;
                sprintf(queenMoveList[queenMoveIndex], "%s:%s", pos, move);
                queenMoveIndex++;
            }
        }
        if(i+1 < boardSize && j+1 < boardSize)
        {
            if (boardArray[i+1][j+1] == '*') 
            {
                printf("%s: MOVE: QDR\n", pos);
                move[0] = 65+j+1;
                move[1] = 8-i-1+48;
                sprintf(queenMoveList[queenMoveIndex], "%s:%s", pos, move);
                queenMoveIndex++;
            }
        }
        if(i+1 < boardSize && j-1 >= 0)
        {
            if (boardArray[i+1][j-1] == '*') 
            {
                printf("%s: MOVE: QUL\n", pos);
                move[0] = 65+j-1;
                move[1] = 8-i-1+48;
                sprintf(queenMoveList[queenMoveIndex], "%s:%s", pos, move);
                queenMoveIndex++;
            }
        }
        
        free(move);

    return 0;
}


int checkForBash(char pos[], char **boardArray, int boardSize, char **bashList)
{
    char tmpPos[BUF_SIZE];
    strcpy(tmpPos, pos);
    
    bool foundMove = false;
    
    int player = globalData->playerData.num;
    char *move = calloc(2, sizeof(char*));

    int *a = translatePosition(tmpPos, 0);
    
    int i = a[1];
    int j = a[0];

    //printf("Before: %s, i: %i, j: %i\n", tmpPos, i, j);
    
//    printf("i:%i, j:%i, field:%c\n", i, j, boardArray[i][j]);
    if (player == 1 && (boardArray[i][j] == 'w' || boardArray[i][j] == 'W') && i != 0) 
    {   
        // Could possibly take a stone
        // check if move is in bounds
        if (i-1 >= 0 && j+1 < boardSize && i-1-1 >= 0 && j+1+1 < boardSize)
        {
            // check possibility
            if ((boardArray[i-1][j+1] == 'b' || boardArray[i-1][j+1] == 'B') && boardArray[i-1-1][j+1+1] == '*') 
            {
                printf("MOVE: WCR\n");
                foundMove = true;
                move[0] = 65+j+1+1;
                move[1] = 8-i+1+1+48;
                strcat(tmpPos, ":");
                strcat(tmpPos, move);
                printf("After: %s\n", tmpPos);
                // execute move on board for recursive function call
                boardArray[i][j] = '*';
                boardArray[i-1][j+1] = '*';
                boardArray[i-1-1][j+1+1] = 'w';
                // recursively call function in case of multiple jumps
                checkForBash(tmpPos, boardArray, boardSize, bashList);
            }
        }
        // check if move is in bounds
        if(i-1 >= 0 && j-1 >= 0 && i-1-1 >= 0 && j-1-1 >= 0)
        {
            // Could possibly take a stone
            if ((boardArray[i-1][j-1] == 'b' || boardArray[i-1][j-1] == 'B') && boardArray[i-1-1][j-1-1] == '*')
            {
                printf("MOVE: WCL\n");
                foundMove = true;
                move[0] = 65+j-1-1;
                move[1] = 8-i+1+1+48;
                strcat(tmpPos, ":");
                strcat(tmpPos, move);
                // execute move on board for recursive function call
                boardArray[i][j] = '*';
                boardArray[i-1][j-1] = '*';
                boardArray[i-1-1][j-1-1] = 'w';
                // recursively call function in case of multiple jumps
                checkForBash(tmpPos, boardArray, boardSize, bashList);
            }
        }
    }
    else if (player == 2 && (boardArray[i][j] == 'b' || boardArray[i][j] == 'B') && i != boardSize-1)
    {
        // Could possibly take a stone
        // first check if move is in bounds
        if(i+1 < boardSize && j-1 >= 0 && i+1+1 < boardSize && j-1-1 >= 0)
        {
            // check possibility
            if ((boardArray[i+1][j-1] == 'w' || boardArray[i+1][j-1] == 'W' )&& boardArray[i+1+1][j-1-1] == '*')
            {  
                printf("MOVE: BCL\n");
                foundMove = true;
                move[0] = 65+j-1-1;
                move[1] = 8-i-1-1+48;
                strcat(tmpPos, ":");
                strcat(tmpPos, move);
                // execute move on board for recursive function call
                boardArray[i][j] = '*';
                boardArray[i+1][j-1] = '*';
                boardArray[i+1+1][j-1-1] = 'b';
                // recursively call function in case of multiple jumps
                checkForBash(tmpPos, boardArray, boardSize, bashList);
            }
        }
        // Could possibly take a stone
        // first check if move is in bounds
        if( i-1 >= 0 && j+1 < boardSize && i+1+1 < boardSize && j+1+1 < boardSize)
        {
            if ((boardArray[i+1][j+1] == 'w' || boardArray[i+1][j+1] == 'W') && boardArray[i+1+1][j+1+1] == '*') 
            {
                printf("MOVE: BCR\n");
                foundMove = true;
                move[0] = 65+j+1+1;
                move[1] = 8-i-1-1+48;
                strcat(tmpPos, ":");
                strcat(tmpPos, move);
                // execute move on board for recursive function call
                boardArray[i][j] = '*';
                boardArray[i+1][j+1] = '*';
                boardArray[i+1+1][j+1+1] = 'b';
                // recursively call function in case of multiple jumps
                checkForBash(tmpPos, boardArray, boardSize, bashList);
                
            }
        }
    } 
    
    //TODO: Speicherverwaltung prüfen:
    //free(move);
    
    if (foundMove == false && strlen(tmpPos) > 2)  
    {
        printf("writing bash move(%s) to bashList.\n", tmpPos);
        strcpy(bashList[bashIndex], tmpPos);
        bashIndex++;
        printf("%s\n", bashList[bashIndex]);
        resetBoard(boardArray, boardSize);
        return 0;
    }
    else 
    {
        return -1;
    }
}

int checkForMove(char *pos, char **boardArray, int boardSize, char **moveList)
{

    int player = globalData->playerData.num;
    char *move = calloc(2, sizeof(char*));
    
    int *a = translatePosition(pos, 0);
    
    int i = a[1];
    int j = a[0];
    
    printf("i:%i, j:%i, field:%c\n", i, j, boardArray[i][j]);
    // Second run through if no stones can be taken
    if (player == 1 && boardArray[i][j] == 'w' && i != 0) 
    {   
        if(i-1 >= 0 && j+1 < boardSize)
        {
            if (boardArray[i-1][j+1] == '*') 
            {
                printf("%s: MOVE: WR\n", pos);
                move[0] = 65+j+1;
                move[1] = 8-i+1+48;
                sprintf(moveList[moveIndex], "%s:%s", pos, move);
                moveIndex++;
            }
        }
        if(j-1 >= 0 && i-1 >= 0)
        {
            if (boardArray[i-1][j-1] == '*') 
            {
                printf("%s: MOVE: WL\n", pos);
                move[0] = 65+j-1;
                move[1] = 8-i+1+48;
                sprintf(moveList[moveIndex], "%s:%s", pos, move);
                moveIndex++;
            }
        }
    }
    else if (player == 2 && boardArray[i][j] == 'b' && i != boardSize-1)
    {
        if(i+1 < boardSize && j+1 < boardSize)
        {
            if (boardArray[i+1][j+1] == '*') 
            {
                printf("%s: MOVE: BR\n", pos);
                move[0] = 65+j+1;
                move[1] = 8-i-1+48;
                sprintf(moveList[moveIndex], "%s:%s", pos, move);
                moveIndex++;
            }
        }
        if(i+1 < boardSize && j-1 >= 0)
        {
            if (boardArray[i+1][j-1] == '*') 
            {
                printf("%s: MOVE: BL\n", pos);
                move[0] = 65+j-1;
                move[1] = 8-i-1+48;
                sprintf(moveList[moveIndex], "%s:%s", pos, move);
                moveIndex++;
            }
        }
    } 
    free(move);
    
    return -1;
}

// function with thinks of the next best move
void think()
{
    if(!globalData->flag) printf("Signal recieved, but not from Connector.\n");
    else printf("Signal from Connector recieved.\n");

    // declare local variable based on size in shm segment for shorter code
    int boardSize = globalData->boardSize;
    int player = globalData->playerData.num;

    printf("!player: %i\n", player);

    char **boardArray = (char**) calloc(boardSize, sizeof(char*));
    
    // allocate memory for field
    for (int i = 0; i < boardSize; i++)
    {
        boardArray[i] = (char*) calloc(boardSize, sizeof(char));
    }

    //char move[BUF_SIZE];
    int i = 0;
    int j = 0;
    int k = 0;
    char result[BUF_SIZE] = "PLAY ";
    srand(time(NULL));

    char **stoneList = (char**) calloc(boardSize*3/2, sizeof(char*));
    
    // allocate memory for list
    for (i = 0; i < (boardSize*3/2); i++) 
    {
        stoneList[i] = (char*) calloc(boardSize*3, sizeof(char));
    }
    
    int stoneListIndex = 0;
    for (i = 0; i < boardSize; i++)
    {
        stoneList[i][0] = '\0';
    }
    i = 0;

    char queenList[3*(boardSize/2)][BUF_SIZE];
    int queenListIndex = 0;

    // translate recieved string into boardArray
    while (globalData->board[i] != '\0' && k < globalData->boardSize)
    {
        if ((globalData->board[i] == 'w') | (globalData->board[i] == 'W') | (globalData->board[i] == '*') | (globalData->board[i] == 'b') | (globalData->board[i] == 'B'))
        {
            boardArray[k][j] = globalData->board[i];

            if ((player == 1 && globalData->board[i] == 'w') || (player == 2 && globalData->board[i] == 'b'))
            {
                sprintf(stoneList[stoneListIndex], "%c%i", 65+j, boardSize-k);
                stoneListIndex++;
            }
            if ((player == 1 && globalData->board[i] == 'W') || (player == 2 && globalData->board[i] == 'B'))
            {
                sprintf(queenList[queenListIndex], "%c%i", 65+j, boardSize-k);
                queenListIndex++;
            }
            
            j++;
        }
        if (j == boardSize)
        {
            k++;
            j = 0;
        }
        i++;
    }

    // printing out board recieved from connector
    printBoard(boardArray, boardSize);
    
    for(i=0; i<stoneListIndex;i++)
    {
        printf("%s\n", stoneList[i]);
    }  
    
    // create List for possible quen captures
    char **queenBashList = (char **) calloc(boardSize*3*3, sizeof(char*));
    // allocate memory for list
    for(i = 0; i < (boardSize*3*3); i++)
    {
        queenBashList[i] = (char*) calloc(boardSize*3, sizeof(char));
    }
    
    queenBashIndex = 0;
    
    printf("checking for possible queen move captures:\n");
    for (i = 0; i < queenListIndex; i++)
    {
        queenCheckForMoveBash(queenList[i], boardArray, boardSize, queenBashList);
    }
    
    // if queen moves are available, choose one and send it.
    if (queenBashIndex > 0)
    {
        strcat(result, queenBashList[rand() % queenBashIndex]);
    }
    // if there is no queen move available
    else
    {
        // create List with possible stone captures
        char **bashList = (char**) calloc(boardSize*3*3, sizeof(char*));
        // allocate memory for list
        for (i = 0; i < (boardSize*3*3); i++) 
        {
            bashList[i] = (char*) calloc(boardSize*3, sizeof(char));
        }
        
        bashIndex = 0;
        
        printf("checking for possible bashes:\n");
        for (i = 0; i < stoneListIndex; i++) 
        {
            
            checkForBash(stoneList[i], boardArray, boardSize, bashList);
        }
        
        // check if move was found that could take stone
        if (bashIndex > 0)
        {
            strcat(result, bashList[rand() % bashIndex]);

        }
        //if not generate a list of movable stones and move a random one
        else 
        {
            // create List with possible moves
            char **moveList = (char**) calloc(boardSize*3*2, sizeof(char*));
            // allocate memory for list
            for (i = 0; i < (boardSize*3*2); i++) 
            {
                moveList[i] = (char*) calloc(boardSize*3, sizeof(char));
                strcpy(moveList[i], "");
            }
            
            // set index to beginning of moveList
            moveIndex = 0;
            
            // go through list of available stones and add possible moves to moveList
            printf("checking for possible moves:\n");
            for (i = 0; i < stoneListIndex; i++) 
            {
                checkForMove(stoneList[i], boardArray, boardSize, moveList);
            }
            if (moveIndex > 0)
            {
                // choose random move and send to connector
                strcat(result, moveList[rand() % moveIndex]);
            }
            else
            {
                // create List with possible queen moves
                char **queenMoveList = (char**) calloc(boardSize*3*2, sizeof(char*));
                // allocate memory for list
                for (i = 0; i < (boardSize*3*2); i++) 
                {
                    queenMoveList[i] = (char*) calloc(boardSize*3, sizeof(char));
                }

                queenMoveIndex = 0;

                // go through list of available stones and add possible moves to moveList
                printf("checking for possible queen moves:\n");
                for (i = 0; i < queenListIndex; i++) 
                {
                    queenCheckForMove(queenList[i], boardArray, boardSize, queenMoveList);
                }

                if (queenMoveIndex > 0)
                {
                    // choose random move and send to connector
                    strcat(result, queenMoveList[rand() % queenMoveIndex]);
                }
                free(queenMoveList);
            }
            free(moveList);
        }
    }

    free(queenBashList);

    // finish PLAY message and send to connector through pipe
    strcat(result, "\n");
    printf("Sending move: %s", result);
    write(globalData->pipeFd[1], result, strlen(result));
    globalData->flag = 1;


    // create padded array board
    //makePaddedBoard(boardArray, boardSize);

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



}
