#include <iostream>
#include <fstream>
#include "Solution.h"

using namespace std;

int main(void)
{
	ifstream inputFile ("Input.txt");
	ofstream outputFile ("Output.txt");
	int a, b;
	
	if (!inputFile.is_open())
	{
		cout << "Can't open inputFile!\n";
		return 1;
	}

	if (!outputFile.is_open())
	{
		cout << "Can't open outputFile!\n";
		return 1;
	}

	while (!inputFile.eof())
	{
		inputFile >> a >> b;
		

		outputFile << "First integer: "<< a << " Second Integer: " << b <<endl;
		swap(a, b);
		outputFile << "After swap in-place: " << endl;
		outputFile << "First integer: " << a << " Second Integer: " << b << endl;
		outputFile << endl;
	}


	outputFile.close();
	inputFile.close();

	return 0;
}