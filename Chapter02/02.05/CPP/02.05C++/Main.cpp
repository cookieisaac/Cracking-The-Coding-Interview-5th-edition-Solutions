#include <fstream>
#include <iostream>
#include "Solution.h"
#include <sstream>
#include <string>

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
		string first;
		string second;

		getline(inputFile, first);
		getline(inputFile, second);

		stringstream s1;
		stringstream s2;

		s1 << first;
		s2 << second;

		LinkedList forwardA;
		LinkedList forwardB;

		LinkedList reverseA;
		LinkedList reverseB;

		int value;
		while (s1 >> value)
		{
			forwardA.addNodeAtTail(value);
			reverseA.addNodeAtHead(value);
		}
		while (s2 >> value)
		{
			forwardB.addNodeAtTail(value);
			reverseB.addNodeAtHead(value);
		}

		LinkedList forwardResult;
		LinkedList reverseResult;

		additionInForwardOrder(forwardA, forwardB, forwardResult);
		additionInReverseOrder(reverseA, reverseB, reverseResult);

		outputFile << "Addition for List in Reverse Order: " << endl;
		outputFile << "First addend is " << reverseA << endl;
		outputFile << "Second addend is " << reverseB << endl;
		outputFile << "The reverse result is " << reverseResult << endl;
		outputFile << "----------------------------------------" << endl;
		outputFile << "Addition for List in Forward Order: " << endl;
		outputFile << "First addend is " << forwardA << endl;
		outputFile << "Second addend is " << forwardB << endl;
		outputFile << "The forward result is " << forwardResult << endl;
		outputFile << "================================================" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}