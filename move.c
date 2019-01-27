#include "config.h"

int checkMoveRightWhite(char *position) {
    if (paddedBoard[position + 5] == 0) {
        printf("Found possible move right.\n");
        possibleMovesRight[movesRightFound] = position;
        movesRightFound++;
        return 0;
    }
    return 1;
}
int checkMoveLeftWhite{
        if(paddedBoard[position+4] == 0){
            printf("Found possible move left.\n");
            possibleMovesLeft[movesLeftFound] = position;
            movesLeftFound++;
            return 0;
        }
        return 1;
}

int checkBashRightWhite(char *position){
    if(paddedBoard[position+5] == 3 || paddedBoard[position+5] == 4){
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

int checkBashLeftWhite(char *position){
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


int checkMoveRightBlack(char *position) {
    if (paddedBoard[position - 5] == 0) {
        printf("Found possible move right.\n");
        possibleMovesRight[movesRightFound] = position;
        movesRightFound++;
        return 0;
    }
    return 1;
}
int checkMoveLeftBlack{
        if(paddedBoard[position-4] == 0){
            printf("Found possible move left.\n");
            possibleMovesLeft[movesLeftFound] = position;
            movesLeftFound++;
            return 0;
        }
        return 1;
}

int checkBashRightBlack(char *position){
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

int checkBashLeftBlack(char *position){
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