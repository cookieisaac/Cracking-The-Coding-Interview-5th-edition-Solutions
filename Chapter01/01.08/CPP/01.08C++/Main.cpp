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
		string strA, strB;
		inputFile >> strA >> strB;
		if (isRotation(strA, strB))
		{
			outputFile << "String \"" << strA << "\" is a rotation of string \"" << strB << "\"" << endl;
		}
		else
		{
			outputFile << "String \"" << strA << "\" is not a rotation of string \"" << strB << "\"" << endl;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}