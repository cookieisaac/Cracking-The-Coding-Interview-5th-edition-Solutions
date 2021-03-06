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
		int nDisks;
		inputFile >> nDisks;
		Hanoi myHanoi(nDisks);
		
		myHanoi.printSolutionSteps(outputFile);
		outputFile << "*******************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}