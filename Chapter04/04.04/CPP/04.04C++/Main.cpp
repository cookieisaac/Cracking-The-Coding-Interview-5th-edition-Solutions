#include <fstream>
#include <iostream>
#include "Solution.h"
#include <string>
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
		getline(inputFile, line);

		stringstream ss;
		ss << line;

		Tree tree;
		ss >> tree;
		outputFile << "Orignial Tree: " << tree << endl; 

		std::vector<std::list<TreeNode*>> layerLists;
		tree.createListByDepth(layerLists);
		tree.printLayerList(outputFile, layerLists);

		outputFile << "-----------------------------------------------------------" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}