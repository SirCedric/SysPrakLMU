#include "config.h"

void makePaddedBoard(char **board, int boardSize){
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            if( (i%2!=0 && j%2==0) || (i%2==0 && j%2!=0) ){}

            printf("%c\n", board[i][j]);

            //////  Check Fields of the first row ///////
            if(i == 7){

                if(j == 0){

                    if(board[i][j] == '*'){
                        paddedBoard[5] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[5] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[5] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[5] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[5] = 4;
                    }
                }

                if(j == 2){

                    if(board[i][j] == '*'){
                        paddedBoard[6] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[6] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[6] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[6] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[6] = 4;
                    }
                }

                if(j == 4){

                    if(board[i][j] == '*'){
                        paddedBoard[7] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[7] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[7] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[7] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[7] = 4;
                    }
                }

                if(j == 6){

                    if(board[i][j] == '*'){
                        paddedBoard[8] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[8] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[8] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[8] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[8] = 4;
                    }
                }
            }



            //////  Check Fields of the second row ///////
            if(i == 6){

                if(j == 1){

                    if(board[i][j] == '*'){
                        paddedBoard[10] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[10] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[10] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[10] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[10] = 4;
                    }
                }

                if(j == 3){

                    if(board[i][j] == '*'){
                        paddedBoard[11] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[11] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[11] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[11] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[11] = 4;
                    }
                }

                if(j == 5){

                    if(board[i][j] == '*'){
                        paddedBoard[12] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[12] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[12] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[12] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[12] = 4;
                    }
                }

                if(j == 7){

                    if(board[i][j] == '*'){
                        paddedBoard[13] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[13] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[13] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[13] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[13] = 4;
                    }
                }
            }

            //////  Check Fields of the third row ///////
            if(i == 5){

                if(j == 0){

                    if(board[i][j] == '*'){
                        paddedBoard[14] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[14] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[14] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[14] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[14] = 4;
                    }
                }

                if(j == 2){

                    if(board[i][j] == '*'){
                        paddedBoard[15] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[15] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[15] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[15] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[15] = 4;
                    }
                }

                if(j == 4){

                    if(board[i][j] == '*'){
                        paddedBoard[16] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[16] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[16] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[16] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[16] = 4;
                    }
                }

                if(j == 6){

                    if(board[i][j] == '*'){
                        paddedBoard[17] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[17] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[17] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[17] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[17] = 4;
                    }
                }
            }



            //////  Check Fields of the fourth row ///////
            if(i == 4){

                if(j == 1){

                    if(board[i][j] == '*'){
                        paddedBoard[19] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[19] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[19] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[19] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[19] = 4;
                    }
                }

                if(j == 3){

                    if(board[i][j] == '*'){
                        paddedBoard[20] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[20] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[20] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[20] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[20] = 4;
                    }
                }

                if(j == 5){

                    if(board[i][j] == '*'){
                        paddedBoard[21] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[21] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[21] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[21] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[21] = 4;
                    }
                }

                if(j == 7){

                    if(board[i][j] == '*'){
                        paddedBoard[22] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[22] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[22] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[22] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[22] = 4;
                    }
                }
            }



            //////  Check Fields of the fifth row ///////
            if(i == 3){

                if(j == 0){

                    if(board[i][j] == '*'){
                        paddedBoard[23] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[23] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[23] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[23] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[23] = 4;
                    }
                }

                if(j == 2){

                    if(board[i][j] == '*'){
                        paddedBoard[24] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[24] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[24] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[24] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[24] = 4;
                    }
                }

                if(j == 4){

                    if(board[i][j] == '*'){
                        paddedBoard[25] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[25] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[25] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[25] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[25] = 4;
                    }
                }

                if(j == 6){

                    if(board[i][j] == '*'){
                        paddedBoard[26] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[26] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[26] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[26] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[26] = 4;
                    }
                }
            }



            //////  Check Fields of the sixth row ///////
            if(i == 2){

                if(j == 1){

                    if(board[i][j] == '*'){
                        paddedBoard[28] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[28] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[28] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[28] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[28] = 4;
                    }
                }

                if(j == 3){

                    if(board[i][j] == '*'){
                        paddedBoard[29] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[29] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[29] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[29] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[29] = 4;
                    }
                }

                if(j == 5){

                    if(board[i][j] == '*'){
                        paddedBoard[30] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[30] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[30] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[30] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[30] = 4;
                    }
                }

                if(j == 7){

                    if(board[i][j] == '*'){
                        paddedBoard[31] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[31] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[31] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[31] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[31] = 4;
                    }
                }
            }



            //////  Check Fields of the seventh row ///////
            if(i == 1){

                if(j == 0){

                    if(board[i][j] == '*'){
                        paddedBoard[32] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[32] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[32] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[32] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[32] = 4;
                    }
                }

                if(j == 2){

                    if(board[i][j] == '*'){
                        paddedBoard[33] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[33] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[33] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[33] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[33] = 4;
                    }
                }

                if(j == 4){

                    if(board[i][j] == '*'){
                        paddedBoard[34] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[34] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[34] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[34] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[34] = 4;
                    }
                }

                if(j == 6){

                    if(board[i][j]== '*'){
                        paddedBoard[35] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[35] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[35] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[35] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[35] = 4;
                    }
                }
            }



            //////  Check Fields of the eighths row ///////
            if(i == 0){

                if(j == 1){

                    if(board[i][j] == '*'){
                        paddedBoard[37] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[37] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[37] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[37] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[37] = 4;
                    }
                }

                if(j == 3){

                    if(board[i][j] == '*'){
                        paddedBoard[38] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[38] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[38] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[38] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[38] = 4;
                    }
                }

                if(j == 5){

                    if(board[i][j] == '*'){
                        paddedBoard[39] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[39] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[39] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[39] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[39] = 4;
                    }
                }

                if(j == 7){

                    if(board[i][j] == '*'){
                        paddedBoard[40] = 0;
                    }

                    if(board[i][j] == 'w'){
                        paddedBoard[40] = 1;
                    }

                    if(board[i][j] == 'W'){
                        paddedBoard[40] = 2;
                    }

                    if(board[i][j] == 'b'){
                        paddedBoard[40] = 3;
                    }

                    if(board[i][j] == 'B'){
                        paddedBoard[40] = 4;
                    }
                }
            }

        }
    }
}
