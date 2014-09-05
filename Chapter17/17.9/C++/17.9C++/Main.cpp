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

	WordCount Page4300("pg4300.txt");
	WordCount Page5000("pg5000.txt");
	WordCount Page20417("pg20417.txt");

	while (!inputFile.eof())
	{
		//Implement Testing Here
		string word;
		getline(inputFile, word);

		outputFile << "The occurence for word \"" << word << "\" in pg4300.txt is " << Page4300.getWordOccurence(lowerString(word)) << endl;
		outputFile << "The occurence for word \"" << word << "\" in pg5000.txt is " << Page5000.getWordOccurence(lowerString(word)) << endl;
		outputFile << "The occurence for word \"" << word << "\" in pg20417.txt is " << Page20417.getWordOccurence(lowerString(word)) << endl;
		outputFile << "******************************************************************************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}