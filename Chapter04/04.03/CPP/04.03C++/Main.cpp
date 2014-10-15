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

	int myArray[] = { 1, 2, 3, 4 };

	Tree t;
	t.populateTreeFromSortedArray(myArray, 4);
	outputFile << t;

	inputFile.close();
	outputFile.close();

	return 0;
}