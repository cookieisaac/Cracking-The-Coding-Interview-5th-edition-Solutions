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

	int counts;
	inputFile >> counts;
	for (int i = 0; i < counts; i++)
	{
		outputFile << rand7() << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}