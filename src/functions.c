#include <stdio.h>
#include "functions.h"

int winPoints = 0;
void printBoard(char(*ptr)[7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%c", *((ptr[i]) + j));
        }
        printf("\n");
    }
    return;
}
int hashCheck(int column, char(*ptr)[7]) {
    int hashMarker = 5;
    int cheatChecking = 0;
    for (int i = 5; i > 0; i--) {
        if (*((ptr[i]) + column) == 'X' || *((ptr[i]) + column) == 'O') {
            hashMarker = hashMarker - 1;
        }
    }
    if (*((ptr[0]) + column) == 'X' || *((ptr[0]) + column) == 'O') {
        printf("Sorry! You cannot choose there! Repeat.\n");
        cheatChecking = 8;
        return cheatChecking;
    }
    return hashMarker;
}
int winCheckVERTICLE(char(*ptr)[7]) {
    int markerX[7];
    int markerO[7];
    for (int i = 0; i < 7; i++) {
        markerX[i] = 0;
        markerO[i] = 0;
    }
    for (int j = 0; j < 7; j++) {
        for (int i = 5; i > 0; i--) {

            if (*((ptr[i]) + j) == 'X') {
                markerX[j]++;
                markerO[j] = 0;
            }
            if (*((ptr[i]) + j) == 'O') {
                markerO[j]++;
                markerX[j] = 0;
            }
        }
    }
    for (int r = 0; r < 7; r++) {
        if (markerX[r] == 4) {
            printf("Congratulations X! You Won!\n");
            winPoints = 1;
            break;
        }
        if (markerO[r] == 4) {
            printf("Congratulations O! You Won!\n");
            winPoints = 1;
            break;
        }
    }
    return winPoints;
}
int winCheckHORIZONTAL(char(*ptr)[7]) {
    int markerX[6];
    int markerO[6];
    for (int i = 0; i < 6; i++) {
        markerX[i] = 0;
        markerO[i] = 0;
    }
    for (int i = 0; i < 6; i++) {
        if (winPoints == 1) {
            break;
        }
        for (int j = 0; j < 7; j++) {
            if (*((ptr[i]) + j) == 'X') {
                markerX[i]++;
                markerO[i] = 0;
            }
            while(markerX[i]<4 || markerO[i]<4){
                if(*((ptr[i]) + j) == '#'){
                    markerX[i] = 0;
                    markerO[i] = 0;
                    break;
                }
                break;
            }
            if (*((ptr[i]) + j) == 'O') {
                markerO[i]++;
                markerX[i] = 0;
            }
            if (markerX[i] == 4) {
                printf("Congratulations X! You Won!\n");
                winPoints = 1;
                break;
            }
            if (markerO[i] == 4) {
                printf("Congratulations O! You Won!\n");
                winPoints = 1;
                break;
            }
        }
    }
    return winPoints;
}
int winCheckDIAGONAL(char(*ptr)[7]) {
    int markerX[2] = {0, 0};
    int markerO[2] = {0, 0};
    for (int i = 0; i < 6; i++) {
        if (winPoints == 1) {
            break;
        }
        for (int j = 0; j < 7; j++) {
            if (*((ptr[i]) + j) == 'X') {
                markerX[0]++;
                for (int r = 1; r < 4; r++) {
                    if (*((ptr[i + r]) + j - r) == 'X') {
                        if (i + r > 5 || j - r < -1) {
                            markerX[0] = 0;
                        }
                        markerX[0]++;
                    }
                    else {
                        break;
                    }
                    if (*((ptr[i + r]) + j - r) == 'O' || *((ptr[i + r]) + j - r) == '#') {
                        markerX[0] = 0;
                    }
                    if(markerX[0] == 4){
                      printf("Congratulations X! You Won!\n");
                    }
                }
            }
            markerX[0] = 0;
            if (*((ptr[i]) + j) == 'O') {
                markerO[0]++;
                for (int r = 1; r < 4; r++) {
                    if (*((ptr[i + r]) + j - r) == 'O') {
                        if (i + r > 5 || j - r < -1) {
                            markerO[0] = 0;
                        }
                        markerO[0]++;
                    }
                    else {
                        break;
                    }
                    if (*((ptr[i + r]) + j - r) == 'X' || *((ptr[i + r]) + j - r) == '#') {
                        markerO[0] = 0;
                    }
                    if(markerO[0] == 4){
                      printf("Congratulations O! You Won!\n");
                    }
                }
            }
        }
        markerO[0] = 0;
        for (int i = 5; i >= 0; i--) {
            if (winPoints == 1) {
                break;
            }
            for (int j = 6; j >= 0; j--) {
                if (*((ptr[i]) + j) == 'X') {
                    markerX[1]++;
                    for (int r = 1; r < 4; r++) {
                        if (*((ptr[i - r]) + j - r) == 'X') {
                            if (i - r < -1 || j - r < -1) {
                                markerX[1] = 0;
                                
                            }
                            markerX[1]++;
                        }
                        else {
                            break;
                        }
                        if (*((ptr[i - r]) + j - r) == 'O' || *((ptr[i - r]) + j - r) == '#') {
                            markerX[1] = 0;   
                        }
                        if(markerX[1] == 4){
                          printf("Congratulations X! You Won!\n");
                        }
                    }
                    markerX[1] = 0;
                }
                if (*((ptr[i]) + j) == 'O') {
                    markerO[1]++;
                    for (int r = 1; r < 4; r++) {
                        if (*((ptr[i - r]) + j - r) == 'O') {
                            if (i - r < -1 || j - r < -1) {
                                markerO[1] = 0;   
                            }
                            markerO[1]++; 
                        }
                        else {
                            break;
                        }
                        if (*((ptr[i - r]) + j - r) == 'X' || *((ptr[i - r]) + j - r) == '#') {
                            markerO[1] = 0; 
                        }
                        if(markerO[1] == 4){
                          printf("Congratulations O! You Won!\n");
                        }
                    }
                }
                markerO[1] = 0;
            }
        }
      }
    return winPoints;
}
