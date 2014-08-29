#include <iostream>
#include <fstream>
#include "Solution.h"

using namespace std;

int main(void)
{
	ifstream inputFile ("Input.txt");
	ofstream outputFile ("Output.txt");

	if (!inputFile)
	{
		cout << "Can't open input file!";
		return 1;
	}

	if (!outputFile)
	{
		cout << "Can't open output file!";
		return 1;
	}

	while (!inputFile.eof())
	{
		int n;
		inputFile >> n;

		int result = computeZero(n);
		if (result != -1)
		{
			outputFile << "There are " << result << " trailing zeros  in factorial of " << n << endl;
			outputFile << "=================================" << endl;

		}
		else
		{
			outputFile << "Can't compute trailing zeros for " << n << endl;
			outputFile << "=================================" << endl;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}