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

	ThreeStacks ts;
	outputFile << "Initial State: " << endl;
	outputFile << ts << endl;
	outputFile << "**************************************************" << endl;
	
	for (int value = 0; value < 100; value++)
	{
		if (value % 3 == 0)
		{
			ts.push(value);
		}
		else if (value % 3 == 1)
		{
			ts.push(value, 'B');
		}
		else
		{
			ts.push(value, 'C');
		}
	}

	outputFile << "After insertion: " << endl;
	outputFile << ts << endl;
	outputFile << "**************************************************" << endl;

	for (int counter = 0; counter < 60; counter++)
	{
		if (counter % 3 == 0)
		{
			ts.pop();
		}
		else if (counter % 3 == 1)
		{
			ts.pop('B');
		}
		else
		{
			ts.pop('C');
		}
	}

	outputFile << "After popping 20 elements in each stack: " << endl;
	outputFile << ts << endl;
	outputFile << "**************************************************" << endl;

	for (int counter = 0; counter < 30; counter++)
	{
		if (counter % 3 == 0)
		{
			ts.pop();
		}
		else
		{
			ts.pop('C');
		}
	}

	outputFile << "After popping 10 elements in stack A and poppint 20 elements in stack C: " << endl;
	outputFile << ts << endl;
	outputFile << "**************************************************" << endl;

	inputFile.close();
	outputFile.close();

	return 0;
}