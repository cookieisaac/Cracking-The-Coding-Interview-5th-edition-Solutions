#include "Solution.h"
#define EMPTY '-'

int min(int X, int Y)
{
	return X <= Y ? X : Y;
}

void printBoard(std::ofstream &outputFile,  char** board, int M, int N)
{
	//Print board to file
	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < N; col++)
		{
			outputFile << board[row][col];
		}
		outputFile << std::endl;
	}
	//outputFile << std::endl;
}

char checkWin(char** board, int M, int N, int K)
{
	int row, col, k;

	//Check Row
	for (row = 0; row < M; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (col >= N - K + 1)  // Last column point (row, col + k - 1) must be in bound: 0 <= col + k - 1 < N
				break;
			for (k = 1; k < K; k++)
			{
				if (board[row][col] != board[row][col + k])
					break;
			}
			if (k == K && board[row][col] != EMPTY)
				return board[row][col];
		}
	}


	//Check Col
	for (col = 0; col < N; col++)
	{
		for (row = 0; row < M; row++)
		{
			if (row >= M - K + 1)  // Last row point (row + k - 1, col) must be in bound: 0 <= row + k -1 < M
				break;
			for (k = 1; k < K; k++)
			{
				if (board[row][col] != board[row + k][col])
					break;
			}
			if (k == K && board[row][col] != EMPTY)
				return board[row][col];
		}
	}

	//Check Diagonal
	for (col = 0; col < N; col++)
	{
		for (row = 0; row < M; row++)
		{
			if ((row >= M - K + 1) || (col >= N - K + 1)) // Last diaganal point (row + k - 1, col + k - 1) must be in range:  0 <= row + k -1 < M && 0 <= col + k - 1 < N 
				break;
			for (k = 1; k < K; k++)
			{
				if (board[row][col] != board[row + k][col+k])
					break;
			}
			if (k == K && board[row][col] != EMPTY)
				return board[row][col];
		}
	}

	//Check Reverse-Diagonal
	for (col = 0; col < N; col++)
	{
		for (row = 0; row < M; row++)
		{
			if ((row >= M - K + 1) || (col >= N + K - 1) || (col < k - 1) ) // Last reverse diaganal point (row + k - 1, col- k + 1) must be in bound: 0 <= row + k -1 < M && 0 <= col - k + 1 < N 
				break;
			for (k = 1; k < K; k++)
			{
				if (board[row][col] != board[row + k][col - k])
					break;
			}
			if (k == K && board[row][col]!=EMPTY)
				return board[row][col];
		}
	}

	return '-';
}

void recordWin(std::ofstream& outputFile, char** board, int M, int N, int K)
{
	char winner;

	winner = checkWin(board, M, N, K);
	switch (winner)
	{
	case 'X':
		outputFile << "First Player ['X'] has won! " << std::endl; break;
	case 'O':
		outputFile << "Second Player ['O'] has won! " << std::endl; break;
	case EMPTY:
		outputFile << "No one has won yet! " << std::endl; break;
	default:
		outputFile << "Unknown player...";
	}

	return;
}