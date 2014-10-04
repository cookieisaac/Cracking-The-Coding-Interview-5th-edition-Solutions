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
		//1. Get CPP string
		string line;
		getline(inputFile, line);
		//2. Convert to NULL ended string. Note c_str returns const char*, so we have to make a copy of it.
		char *cstr = (char*)malloc(sizeof(char)*(line.length() + 1));
		strcpy_s(cstr, line.length()+1, line.c_str());
		//3. reverse the string
		reverse(cstr);
		//4. Create a reversed string
		string reversed_line = string(cstr);
		free(cstr);
		outputFile << "Reverse of string \"" << line << "\" is: \""<< reversed_line<< "\""<< endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}