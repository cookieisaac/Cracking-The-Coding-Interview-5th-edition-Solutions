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
		std::string str;
		std::getline(inputFile, str);

		outputFile << "Original string: \"" << str << "\"" << endl;
		std::string compressed = compressString(str);
		outputFile << "Compressed string: \"" << compressed << "\"" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}