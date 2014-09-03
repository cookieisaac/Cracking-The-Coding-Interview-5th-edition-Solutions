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
		int a, b;
		
		inputFile >> a >> b;

		outputFile << "Maximum of " << a << " and " << b << " is " << getMax(a, b) << endl;
		outputFile << "Maximum of " << a << " and " << b << " is " << getMaxNaive(a, b) <<" using naive method (might overflow/underflow)."<< endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}