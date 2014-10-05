#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <list>
#include <string>
#include <ostream>

void initList(std::list<int> & intList, std::string intString);
void printList(std::ostream& os, std::list<int>&);
void removeDuplicate(std::list<int>& intList);

#endif