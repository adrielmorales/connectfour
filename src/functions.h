#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void printBoard(char(*ptr)[7]);
int hashCheck(int column, char(*ptr)[7]);
int winCheckHORIZONTAL(char(*ptr)[7]);
int winCheckVERTICLE(char(*ptr)[7]);
int winCheckDIAGONAL(char(*ptr)[7]);
void resetColor();
#endif
