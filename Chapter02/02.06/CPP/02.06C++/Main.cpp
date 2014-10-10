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
		string list;
		getline(inputFile, list);
		stringstream s1;
		s1 << list;

		string entry;
		getline(inputFile, entry);
		stringstream s2;
		s2 << entry;

		char loopEntry;
		s2 >> loopEntry;

		CircularList circularList;
		s1 >> circularList;
		outputFile << "The original list is: " << circularList << " of size " << circularList.getSize() << endl;
		circularList.createCircle(loopEntry);
		outputFile << "After creating loop at '" << loopEntry << "', the list is: " << circularList << endl;
		Node* loopPoint = circularList.findLoopEntry();
		if (loopPoint != NULL)
		{
			outputFile << "Function findLoopEntry() finds out the loop entry is at '" << loopPoint->getValue() << "'." << endl;
		}
		else
		{
			outputFile << "Function findLoopEntry() couldn't find a loop entry." << endl;
		}
		outputFile << "****************************************************************************************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}