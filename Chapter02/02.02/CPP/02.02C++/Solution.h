#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <list>
#include <string>
#include <ostream>

void initList(std::list<int> & intList, std::string intString);
void printList(std::ostream& os, std::list<int>&);

/*
Assuming 
	last == 1th to last
	last - 1 == 2nd to last
	....
	first == sizeth to last
Return list.end() if K is less than 1 or greater than size
*/
std::list<int>::iterator kthToLastElement(int K, std::list<int> &);

#endif