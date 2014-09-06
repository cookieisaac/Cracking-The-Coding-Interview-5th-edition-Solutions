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
		int N;
		inputFile >> N;
		int * array = (int* )malloc(N* sizeof(int));

		for (int i = 0; i < N; i++)
		{
			inputFile >> array[i];
		}

		int start = 0;
		int end = N - 1;

		findUnordered(array, N, start, end);

		outputFile << "Array of size " << N << " : ( ";
		for (int i = 0; i < N; i++)
		{
			if (i == N - 1)
				outputFile << array[i] << " ) " << endl;
			else
				outputFile << array[i] << ", ";
		}
		outputFile << "The unordered range is ( " << start << " , " << end << " ) " << endl;
		outputFile << "************************************************************************************************" << endl;

	}

	inputFile.close();
	outputFile.close();

	return 0;
}