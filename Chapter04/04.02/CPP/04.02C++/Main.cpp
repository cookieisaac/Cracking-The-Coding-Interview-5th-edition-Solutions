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
		exit(1);
	}

	if (!outputFile)
	{
		cout << "Can't open Output.txt!" << endl;
		exit(1);
	}


	int nNodes, nEdges;
	while (inputFile >> nNodes >> nEdges)
	{
		vector<char> v;
		for (char value = 'a'; value < 'a'+nNodes; value++)
		{
			v.push_back(value);
		}

		Graph<char> g(v);
		//g.setOutput(outputFile);

		for (int i = 0; i < nEdges; i++)
		{
			char source, destination;

			inputFile >> source >> destination;
			g.connectVertex(source, destination);
		}

		outputFile << g;
		outputFile << "-------------------------------------------------" << endl;
		g.BreadthFirstTraversal(outputFile);
		outputFile << "-------------------------------------------------" << endl;
		g.DepthFirstTraversal(outputFile);
		outputFile << "-------------------------------------------------" << endl;
		outputFile << "Find path between a and f" << endl;
		g.printPath(g.findPath('a', 'f'), outputFile);
		outputFile << "-------------------------------------------------" << endl;
		outputFile << "Find path between a and d" << endl;
		g.printPath(g.findPath('a', 'd'), outputFile);
		outputFile << "-------------------------------------------------" << endl;
		outputFile << "Find path between g and g" << endl;
		g.printPath(g.findPath('f', 'f'), outputFile);
		outputFile << "-------------------------------------------------" << endl;
		outputFile << "Find path between d and f" << endl;
		g.printPath(g.findPath('g', 'f'), outputFile);
		outputFile << "-------------------------------------------------" << endl;
		outputFile << "Find path between g and i" << endl;
		g.printPath(g.findPath('g', 'i'), outputFile);
		outputFile << "-------------------------------------------------" << endl;
	}
	inputFile.close();
	outputFile.close();

	return 0;
}