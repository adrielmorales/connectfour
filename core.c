#include <stdio.h>
#include "src\functions.h"

int main() {
    printf("Welcome to Connect 4\n");
    char gameBoard[6][7]; //The Connect4 Board.
    char playerOne = 'X'; //First Player.
    char** ptr = gameBoard;
    char playerTwo = 'O'; //Second Player.
    int column, columnChooser = 0;
    int hashMarker = 0; //Combines Column Limit Checking, and of course, Values to dictate where the choosing player goes.
    int winPoints = 0; //Win Flag.
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            gameBoard[i][j] = '#'; //ASCII 0x23
        }
    }
    while (winPoints == 0) {
        printf("Player One. Go and choose your column. You are 'X'\n");
        scanf("%d", &columnChooser);
        column = columnChooser - 1;
        hashMarker = hashCheck(column, ptr);
        printf("%d\n", hashMarker);
        if (hashMarker != 8) {
            gameBoard[hashMarker][column] = 'X';
            printBoard(ptr);
        }
        //Player Two.
        printf("Player Two. Go and choose your column. You are 'O'\n");
        scanf("%d", &columnChooser);
        column = columnChooser - 1;
        hashMarker = hashCheck(column, ptr);
        printf("%d\n", hashMarker);
        if (hashMarker != 8) {
            gameBoard[hashMarker][column] = 'O';
            printBoard(ptr);
        }
        winPoints = winCheckVERTICLE(ptr);
        winPoints = winCheckHORIZONTAL(ptr);
        winPoints = winCheckDIAGONAL(ptr);
    }


    return 0;
}
