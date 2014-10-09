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
		string partitionValueLine;
		getline(inputFile, partitionValueLine);

		stringstream ss;
		ss << partitionValueLine;
		int partitionValue;
		ss >> partitionValue;

		string listLine;
		getline(inputFile, listLine);
		stringstream ss2;
		ss2 << listLine;

		LinkedList ll;
		int nodeValue;

		while (ss2 >> nodeValue)
		{
			ll.addNodeAtTail(nodeValue);
		}

		outputFile << "Linked List of size " << ll.getSize() << " is created!" << endl;
		outputFile << ll;
		outputFile << "Partition the list above by value " << partitionValue <<": "<< endl;
		ll.partitionByValue(partitionValue);
		outputFile << ll;
		outputFile << "**********************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}