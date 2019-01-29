#include "config.h"

int checkMoveRightWhite(int position) {
    if (paddedBoard[position + 5] == 0) {
        printf("Found possible move right.\n");
        possibleMoves[moveNumber] = position;
        moveNumber++;
        return 0;
    }
    return 1;
}
int checkMoveLeftWhite(int position){
        if(paddedBoard[position+4] == 0){
            printf("Found possible move left.\n");
            strcat(possibleMoves[moveNumber], paddedToString[position]);
            strcat(possibleMoves[moveNumber], ":");
            strcat(possibleMoves[moveNumber], , paddedToString[position+4]);
            moveNumber++;
            return 0;
        }
        return 1;
}

int checkBashRightWhite(int position){
    if(paddedBoard[position+5] == 3 || paddedBoard[position+5] == 4){
        if(checkMoveRight((position+5)) == 0){
            //TODO save move
            strcat()
        }
        else if(checkMoveLeft((position+4)) == 0){
            //TODO save move
        }
        else if(checkBashRight((position+5)) == 0){
            //TODO save move, recall functions
        }
        else if(checkBashLeft((postion+4)) == 0){
            //TODO save move, recall functions
        }
    }
    return 1;
}

int checkBashLeftWhite(int position){
    if(paddedBoard[position+4] == 3 || paddedBoard[position+4] == 4){
        if(checkMoveRight((position+5)) == 0){
            //TODO save move
        }
        else if(checkMoveLeft((position+4)) == 0){
            //TODO save move
        }
        else if(checkBashRight((position+5)) == 0){
            //TODO save move, recall functions
        }
        else if(checkBashLeft((postion+4)) == 0){
            //TODO save move, recall functions
        }
    }
    return 1;
}


int checkMoveRightBlack(int position) {
    if (paddedBoard[position - 5] == 0) {
        printf("Found possible move right.\n");
        possibleMovesRight[movesRightFound] = position;
        movesRightFound++;
        return 0;
    }
    return 1;
}
int checkMoveLeftBlack(int position){
        if(paddedBoard[position-4] == 0){
            printf("Found possible move left.\n");
            possibleMovesLeft[movesLeftFound] = position;
            movesLeftFound++;
            return 0;
        }
        return 1;
}

int checkBashRightBlack(int position){
    if(paddedBoard[position-5] == 1 || paddedBoard[position-5] == 2){
        if(checkMoveRight((position-5)) == 0){
            //TODO save move
        }
        else if(checkMoveLeft((position-4)) == 0){
            //TODO save move
        }
        else if(checkBashRight((position-5)) == 0){
            //TODO save move, recall functions
        }
        else if(checkBashLeft((postion-4)) == 0){
            //TODO save move, recall functions
        }
    }
    return 1;
}

int checkBashLeftBlack(int position){
    if(paddedBoard[position-4] == 1 || paddedBoard[position-4] == 2){
        if(checkMoveRight((position-5)) == 0){
            //TODO save move
        }
        else if(checkMoveLeft((position-4)) == 0){
            //TODO save move
        }
        else if(checkBashRight((position-5)) == 0){
            //TODO save move, recall functions
        }
        else if(checkBashLeft((postion-4)) == 0){
            //TODO save move, recall functions
        }
    }
    return 1;
}