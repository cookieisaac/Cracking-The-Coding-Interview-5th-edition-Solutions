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


	Cat cat1;
	Cat cat2;
	Cat cat3;
	Cat cat4;
	Dog dog1;
	Dog dog2;
	Dog dog3;
	Dog dog4;

	AnimalQueue aq;
	outputFile << "Initial state: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;

	aq.enqueue(&cat1);
	aq.enqueue(&cat2);
	aq.enqueue(&dog1);
	outputFile << "After enqueue two cats and one dog: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;


	aq.enqueue(&dog2);
	aq.enqueue(&dog3);
	aq.enqueue(&dog4);
	outputFile << "After enqueue three dogs: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;

	aq.dequeueCat();
	outputFile << "After dequeue one cat: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;

	aq.dequeueAny();
	outputFile << "After dequeue one animal: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;

	aq.enqueue(&cat3);
	aq.enqueue(&cat4);
	outputFile << "After enqueue two cats: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;

	aq.dequeueDog();
	aq.dequeueDog();
	outputFile << "After dequeue two dogs: " << endl;
	outputFile << aq;
	outputFile << "-----------------------------------------------------------------" << endl;

	for (int i = 1; i < 6; i++)
	{
		aq.dequeueAny();
		outputFile << "After dequeue one animal: " << endl;
		outputFile << aq;
		outputFile << "-----------------------------------------------------------------" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}