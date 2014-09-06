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
		int * array = (int*)malloc(N* sizeof(int));

		for (int i = 0; i < N; i++)
		{
			inputFile >> array[i];
		}

		outputFile << "Array of size " << N << " : ( ";
		for (int i = 0; i < N; i++)
		{
			if (i == N - 1)
				outputFile << array[i] << " ) " << endl;
			else
				outputFile << array[i] << ", ";
		}

		int start = 0;
		int end = 0;
		outputFile << "Max Sum is " << findMaxSum(array, N, start, end);
		outputFile << " from range " << start << " to " << end << ": ( ";
		for (int i = start; i <= end; i++)
		{
			if (i == end)
				outputFile << array[i] << " ) " << endl;
			else
				outputFile << array[i] << ", ";
		}
		outputFile << "************************************************************************************************" << endl;

	}

	inputFile.close();
	outputFile.close();

	return 0;
}