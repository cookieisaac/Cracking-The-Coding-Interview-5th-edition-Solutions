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

/*	while (!inputFile.eof())
	{
		//Implement Testing Here
	}
*/
	LinkedList ll;
	Node node1(1);
	Node node2(2);
	Node node3(3);
	Node node4(4);
	Node node5(5);

	ll.addNodeAtHead(&node5);
	ll.addNodeAtHead(&node4);
	ll.addNodeAtHead(&node3);
	ll.addNodeAtHead(&node2);
	ll.addNodeAtHead(&node1);

	outputFile << "Original list is a list of size "<<ll.getSize()<<": " << endl;
	outputFile << ll;
	ll.deleteByNode(&node3);
	outputFile << "After deleting the third node, list size is " << ll.getSize() << endl;
	outputFile << ll;
	ll.deleteByNode(&node1);
	outputFile << "After delete the first node, list size is " << ll.getSize() << endl;
	outputFile << ll;
	outputFile << "We can't delete the last node by this method. After \"deleting\" node5, the size is " << ll.getSize() << endl;
	ll.deleteByNode(&node5);
	outputFile << ll;

	inputFile.close();
	outputFile.close();

	return 0;
}