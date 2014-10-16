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
		exit(1);
	}

	if (!outputFile)
	{
		cout << "Can't open Output.txt!" << endl;
		exit(1);
	}

	string line;
	while (inputFile >> line)
	{
		stringstream ss;
		ss << line;

		Tree tree;
		ss >> tree;

		int toSearch;
		inputFile >> toSearch;

		outputFile << "Orignial Tree: " << tree << endl;
		if (tree.isBalanced())
		{
			outputFile << "This tree is balanced." << std::endl;
		}
		else
		{
			outputFile << "This tree is NOT balanced!" << std::endl;
		}
		if (tree.isBST())
		{
			outputFile << "This tree is a binary search tree." << std::endl;
		}
		else
		{
			outputFile << "This tree is NOT a binary search tree!" << std::endl;
		}

		if (tree.inorderSuccessor(tree.findNode(toSearch)) == NULL)
		{
			outputFile << "Cannot find in-order successor of " << toSearch << endl;
		}
		else
		{
			outputFile << "In-order successor of " << toSearch << " is " << tree.inorderSuccessor(tree.findNode(toSearch))->getValue() << endl;
		}
	
		outputFile << "-----------------------------------------------------------" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}