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

	int N;
	while (inputFile >> N)
	{
		outputFile << "Test case of size [" << N << "]: { ";
		int* myArray = (int*)malloc(sizeof(int)*N);

		for (int i = 0; i < N; i++)
		{
			inputFile >> myArray[i];
			outputFile << myArray[i]<< " ";
		}
		outputFile << "}" << endl;

		Tree t;
		t.populateTreeFromSortedArray(myArray, N);
		outputFile << t << endl;
		outputFile << "--------------------------------------------------------" << endl;

		free(myArray);
	}
	inputFile.close();
	outputFile.close();

	return 0;
}