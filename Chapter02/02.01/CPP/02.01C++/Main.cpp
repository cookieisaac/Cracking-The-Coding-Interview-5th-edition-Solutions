#include <fstream>
#include <iostream>
#include "Solution.h"
#include <string>
#include <list>

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
		list<int> intList;
		initList(intList, line);
		outputFile << "The original list is: " << endl;
		printList(outputFile, intList);
		outputFile << "After removing the duplicates, the list is: " << endl;
		removeDuplicate(intList);
		printList(outputFile, intList);
		outputFile << "************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}