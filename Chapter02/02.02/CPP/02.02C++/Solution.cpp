#include "Solution.h"
#include <sstream>
#include <map>

using namespace std;

void initList(std::list<int> & intList, std::string intString)
{
	stringstream ss;
	ss << intString;
	int temp;
	while (ss >> temp)
	{
		intList.push_back(temp);
	}
	return;
}

void printList(std::ostream& os, std::list<int>& intList)
{
	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{
		os << *it << " --> ";
	}
	os << "NULL" << endl;

	return;
}

std::list<int>::iterator kthToLastElement(int K, std::list<int> &intList)
{
	if (K < 1 || K > intList.size())
	{
		return intList.end();
	}
	else
	{
		list<int>::iterator it = intList.begin();
		for (int count = 0; count != intList.size() - K; count++, it++);
		return it; 
	}
}