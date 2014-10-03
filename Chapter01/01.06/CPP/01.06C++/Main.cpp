#include <fstream>
#include <iostream>
#include "Solution.h"

using namespace std;

int main(void)
{
	ifstream inputFile("Input.txt");
	ofstream outputFile("Output.txt");

	if (!inputFile)
	{
		cout << "Can't open Input.txt!" << endl;
		exit (1);
	}

	if (!outputFile)
	{
		cout << "Can't open Output.txt!" << endl;
		exit (1);
	}

	while (!inputFile.eof())
	{
		int M = 0, N = 0;
		inputFile >> M >> N;
		int **matrix = initMatrix(M, N);
		loadMatrix(inputFile, matrix, M, N);
		outputFile << "Before rotation: the matrix is: " << endl;
		printMatrix(outputFile, matrix, M, N);
		rotateMatrix(matrix, M, N);
		outputFile << "After rotation: the matrix is: " << endl;
		printMatrix(outputFile, matrix, N, M);
		outputFile << "****************************************" << endl;
		freeMatrix(matrix, M, N);
	}

	inputFile.close();
	outputFile.close();

	return 0;
}