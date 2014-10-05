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

/*
// Space: O(N), Time: O(N)
void removeDuplicate(std::list<int>& intList)
{
	map<int, bool> memberList;

	for (list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{
		if (memberList.count(*it) == 0)
		{
			//The element is not a duplicate
			memberList.insert(pair<int, bool>(*it, true));
		}
		else
		{
			list<int>::iterator itToDelete = it;
			it--;
			intList.erase(itToDelete);
		}
	}

	return;
}
*/

// Space: O(1), Time: O(N^2)
void removeDuplicate(std::list<int>& intList)
{
	for (list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{
		list<int>::iterator runner = it;
		runner++;
		for (; runner != intList.end(); runner++)
		{
			if (*runner == *it)
			{
				list<int>::iterator itemToDelete = runner;
				runner--;
				intList.erase(itemToDelete);
			}
		}
		
	}

	return;
}

