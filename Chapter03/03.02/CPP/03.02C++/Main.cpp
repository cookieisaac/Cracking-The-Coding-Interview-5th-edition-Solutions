#include <fstream>
#include <iostream>
#include "Solution.h"
#include <string>
#include <sstream>

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
		string line;
		getline(inputFile, line);

		stringstream ss;
		ss << line;

		StackWithMin myStack;
		int value;
		while (ss >> value)
		{
			myStack.push(value);
		}

		outputFile << "Initial Stack: " ;
		myStack.printStack(outputFile);
		for (int i = 1; !myStack.empty(); i++)
		{
			myStack.pop();
			outputFile << "---------------------------------------------------" << endl;
			outputFile << "After popping " << i << " time(s): ";
			myStack.printStack(outputFile);
		}
		outputFile << "**************************************************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}