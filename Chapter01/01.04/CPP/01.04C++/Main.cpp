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
		string str;
		std::getline(inputFile, str);
		outputFile << "Original string is: \"" << str << "\"." << endl;
		replaceAllSpace(str);
		outputFile << "The new string is: \"" << str << "\"." << endl;
		outputFile << "**************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}