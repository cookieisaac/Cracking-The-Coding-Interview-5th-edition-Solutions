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

	SetOfStacks mySet;


	for (int value = 0; value < 100; value++)
	{
		mySet.push(value);
	}

	outputFile << "Initial set of stacks: " << endl;
	mySet.printState(outputFile) ;
	outputFile << "********************************************************************************" << endl;
	
	for (int stack = 0; stack < mySet.getNumStacks(); stack++)
	{
		for (int popTimes = stack; popTimes > 0; popTimes--)
		{
			mySet.popAt(stack);
		}
	}

	outputFile << "After popping n elements at stack n: " << endl;
	mySet.printState(outputFile);
	outputFile << "********************************************************************************" << endl;

	for (int counter = 0; counter < 7; counter++)
	{
		mySet.pop();
	}

	outputFile << "After popping 7 elements at set of stacks: " << endl;
	mySet.printState(outputFile);
	outputFile << "********************************************************************************" << endl;

	for (int counter = 0; counter < 7; counter++)
	{
		mySet.popAt(2);
	}

	outputFile << "After popping 7 elements at stack[2]: " << endl;
	mySet.printState(outputFile);
	outputFile << "********************************************************************************" << endl;

	mySet.popAt(2);
	outputFile << "After popping one more time at stack[2]: " << endl;
	mySet.printState(outputFile);
	outputFile << "********************************************************************************" << endl;

	while (!mySet.isEmpty())
	{
		mySet.pop();
	}
	outputFile << "After popping all elements: " << endl;
	mySet.printState(outputFile);
	outputFile << "********************************************************************************" << endl;

	inputFile.close();
	outputFile.close();

	return 0;
}