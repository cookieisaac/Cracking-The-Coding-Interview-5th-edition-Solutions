#include "Solution.h"
#include <fstream>
using namespace std;

/*
Initialize matrix[M][M] if M >= N;
Initialize matirx[N][N] if M < N
And intialize every elemets as 0;
Over allocating to ensure rotation will never be out of bound;
*/
int** initMatrix(int M, int N)
{
	int size = (M >= N) ? M : N;
	int **matrix = (int**)malloc(sizeof(int *)* size);
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * size);
	}

	for (int i = 0, j; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

void loadMatrix(std::ifstream& ifs, int** matrix, int M, int N)
{
	for (int i = 0, j; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			ifs >> matrix[i][j];
		}
	}
}
void printMatrix(std::ofstream& ofs, int** matrix, int M, int N)
{
	for (int i = 0, j; i < M; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			ofs << matrix[i][j] << '\t';
		}
		ofs << matrix[i][j] << endl;
	}
}

void freeMatrix(int** matrix, int M, int N)
{
	int size = (M > N) ? M : N;
	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
	free (matrix);
}


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void rotateMatrix(int** matrix, int rowSize, int colSize)
{
	int N = (rowSize >= colSize) ? rowSize : colSize;  //Assuming N is larger of the rowSize and colSize
	/* // These code are for matrix transpose A^T
	for (int i = 0, j; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	*/

	int outMostLayer = 0;
	int innerMostLayer = N / 2;

	for (int layer = outMostLayer; layer <= innerMostLayer; layer++)
	{
		//Process each element on Top Boarder
		/*
			Top Border [Layer, LeftBound ~ RightBound]

					left  offset	right
					* * * * * * * * *
					* * * * * * * * *
					* * * * * * * * *
					* * * * * * * * * offset
			offset	* * * * * * * * *
					* * * * * * * * *
					* * * * * * * * *
					* * * * * * * * *
							  offset
		*/
		int LeftBound = layer;
		int RightBound = N - 1 - layer;
		for (int i = LeftBound; i < RightBound; i++)
		{
			int offset = i - LeftBound;

			// Store Top Value
			int temp = matrix[layer][i];
			// Left to Top
			matrix[layer][i] = matrix[RightBound - offset][layer];
			// Bottom to Left
			matrix[RightBound - offset][layer] = matrix[RightBound][RightBound - offset];
			// Right to Bottom
			matrix[RightBound][RightBound - offset] = matrix[i][RightBound];
			// Top to Right
			matrix[i][RightBound] = temp;
		}	
	}
}