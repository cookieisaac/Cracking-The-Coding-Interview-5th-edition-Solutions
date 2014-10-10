#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
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
		string line;
		getline(inputFile, line);

		stringstream ss;
		ss << line;

		DoublelyLinkedList dll;
		ss >> dll;

		outputFile << "Test list is " << dll << " of size " << dll.getSize() << endl;
		if (dll.isPalindrome())
		{
			outputFile << "It is a palindrome." << endl;
		}
		else
		{
			outputFile << "It is NOT a palindrome." << endl;
		}
		outputFile << "***************************************************************************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}