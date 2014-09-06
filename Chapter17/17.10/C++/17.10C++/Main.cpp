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

	/*
	while (!inputFile.eof())
	{
		//Implement Testing Here
	}
	*/

	Attribute a1("at1", "av1");
	Attribute a2("at2", "av2");

	XMLElement test;

	test.setTag("TestTag");
	test.addAttribute(a1);
	test.addAttribute(a2);

	XMLElement test2;
	test2.setTag("TestTag2");
	test2.addAttribute(a1);
	test2.addAttribute(a2);

	XMLElement test3;
	test3.setTag("TestTag3");
	test3.setValue("TestValue3");
	test3.addAttribute(a1);
	test3.addAttribute(a2);

	test2.addChild(&test3);
	test2.addChild(&test3);
	test2.addChild(&test3);
	test.addChild(&test3);
//	test3.addChild(&test2);
//	test.addChild(&test3);
	test.addChild(&test2);

	outputFile << test;

	inputFile.close();
	outputFile.close();

	return 0;
}