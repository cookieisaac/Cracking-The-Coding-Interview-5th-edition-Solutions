#ifndef _SOLUTION_H
#define _SOLUTION_H
#include <fstream>

int** initMatrix(int M, int N);
void loadMatrix(std::ifstream& ifs, int** matrix, int M, int N);
void printMatrix(std::ofstream& ofs, int** matrix, int M, int N);
void freeMatrix(int** matrix, int M, int N);

void rotateMatrix(int** matrix, int M, int N);

#endif