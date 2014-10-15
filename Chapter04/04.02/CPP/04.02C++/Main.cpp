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


	vector<char> v;
	for (char value = 'a'; value <= 'f'; value++)
	{
		v.push_back(value);
	}

	Graph<char> g(v);

	g.connectVertex('a', 'b');
	g.connectVertex('a', 'e');
	g.connectVertex('b', 'd');
	g.connectVertex('b', 'c');
	g.connectVertex('e', 'd');
	g.connectVertex('e', 'f');

	outputFile << g;

	inputFile.close();
	outputFile.close();

	return 0;
}