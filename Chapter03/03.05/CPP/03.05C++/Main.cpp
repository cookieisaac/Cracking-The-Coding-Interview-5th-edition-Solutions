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

	MyQueue mq;

	for (int value = 1; value < 11; value++)
	{
		mq.enqueue(value);
	}
	outputFile << "Initial queue: " << mq << endl;
	outputFile << "Size: " << mq.getSize() << " and peek returns " << mq.peek() << endl;
	outputFile << "------------------------------------------------------" << endl;
	
	for (int counter = 20; counter < 50; counter++)
	{
		if (counter % 3 == 0)
		{
			mq.enqueue(counter);
			outputFile << "After enqueue: " << mq << endl;
			outputFile << "Size: " << mq.getSize() << " and peek returns " << mq.peek() << endl;
			outputFile << "------------------------------------------------------" << endl;
		}
		else
		{
			mq.dequeue();
			outputFile << "After enqueue: " << mq << endl;
			outputFile << "Size: " << mq.getSize() << " and peek returns " << mq.peek() << endl;
			outputFile << "------------------------------------------------------" << endl;
		}

	}

	inputFile.close();
	outputFile.close();

	return 0;
}