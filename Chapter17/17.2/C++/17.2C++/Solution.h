#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <fstream>

int min(int x, int y);
void printBoard(std::ofstream& outputFile, char** board, int M, int N);
char checkWin(char** board, int M, int N, int K);
void recordWin(std::ofstream& outputFile, char** board, int M, int N, int K);

#endif