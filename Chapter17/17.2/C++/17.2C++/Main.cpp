#include <iostream>
#include <fstream>
#include "Solution.h"

using namespace std;

int main(void)
{
	ifstream inputFile;
	ofstream outputFile;

	inputFile.open("Input.txt");
	if (!inputFile)
	{
		cout << "Can't open inputFile!\n";
		return 1;
	}

	outputFile.open("Output.txt");
	if (!outputFile)
	{
		cout << "Can't open outputFile!\n";
		return 1;
	}

	while (!inputFile.eof())
	{
		int M, N;
		inputFile >> M >> N;

		//Construct board
		outputFile << "Constructing board " << M << " * "<<N<<"..."<<endl;
		if (M <= 0 || N <= 0)
		{
			outputFile << "Invalid board dimension!\n M and N must be greater than 0!" << endl;
			outputFile << "===================================" << endl;
			continue;
		}

		char **board = (char **)malloc(sizeof(char *) * M);
		for (int row = 0; row < M; row++)
		{
			board[row] = (char*)malloc(sizeof(char) * N);
		}

		//Read board from file
		for (int row = 0; row < M; row++)
		{
			for (int col = 0; col < N; col++)
			{
				inputFile >> board[row][col];
			}
			inputFile.get();
		}

		printBoard(outputFile, board, M, N);
		recordWin(outputFile, board, M, N, min(M, N));

		//Destruct board;
		outputFile << "Destructing Board..." << endl;
		outputFile << "===================================" << endl;
		for (int row = 0; row < M; row++)
		{
			free(board[row]);
		}
		free(board);
		
	}

	outputFile.close();
	inputFile.close();


	return 0;
}