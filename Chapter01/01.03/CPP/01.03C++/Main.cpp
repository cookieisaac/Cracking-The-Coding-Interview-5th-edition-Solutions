#include <fstream>
#include <iostream>
#include "Solution.h"
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
		string string1;
		string string2;
		std::getline(inputFile, string1);
		std::getline(inputFile, string2);

		outputFile << "String 1: \"" << string1 << "\"" << endl;
		outputFile << "String 2: \"" << string2 << "\"" << endl;
		if (isPermutation(string1, string2))
		{
			outputFile << "They are permutation of one another." << endl;
		}
		else
		{
			outputFile << "They are not permutation of one another." << endl;
		}
		outputFile << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}