#include <fstream>
#include <iostream>
#include "Solution.h"
#include <sstream>
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
		string kth;
		getline(inputFile, kth);
		getline(inputFile, line);
		
		stringstream ss;
		ss << kth;
		int K;
		ss >> K;
		
		list<int> intList;
		initList(intList, line);

		outputFile << "Current list is: " << endl;
		printList(outputFile, intList);
		
		std::list<int>::iterator ktl = kthToLastElement( K, intList);

		if (ktl == intList.end())
		{
			outputFile << "WARNING: Current K: " << K << " and current list size is " << intList.size() << endl;
			outputFile << "ERROR: K is larger than size or less than 1" << endl;
		}
		else
		{
			outputFile << "Current K: " << K << " and the value of K-th to last element is: " << *ktl << endl;
		}
		outputFile << "***************************************************" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}