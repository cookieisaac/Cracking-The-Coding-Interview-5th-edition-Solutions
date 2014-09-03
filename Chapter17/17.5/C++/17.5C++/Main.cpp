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
		string line;
		getline(inputFile, line);

		if (line == "")
		{
			cout << "Can't readline!" << endl;
			exit(1);
		}

		const string::size_type space_position = line.find(' ');

		string target = line.substr(0, space_position);
		string guess = line.substr(space_position + 1);

		int hitCount, pseudoHitCount;

		checkGuess(target, guess, hitCount, pseudoHitCount);
		
		outputFile << "Actual solution is " << target << " and your guess is " << guess << endl;
		outputFile << "You have made " << hitCount << " hit(s) and " << pseudoHitCount << " pseudo hit(s)" << endl;
		outputFile << "*************************************************" << endl;
		
	}

	inputFile.close();
	outputFile.close();

	return 0;
}