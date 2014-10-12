#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <stack>
#include <iostream>

void printStack(std::ostream& os, std::stack<int> s);
class Hanoi
{
public:
	Hanoi(int disks):_disks(disks){  for (int i = _disks; i > 0; i--)_A.push(i); }
	~Hanoi(){}
	void printCurrentState(std::ostream& os);
	void printSolutionSteps(std::ostream& os);

private:
	std::stack<int> _A;
	std::stack<int> _B;
	std::stack<int> _C;
	int _disks;

	void _moveDisks(int N, std::stack<int>&, std::stack<int>&, std::stack<int>&, std::ostream&, int& steps);
	void _moveTop(std::stack<int>&, std::stack<int>&, std::ostream&, int& steps);
};

#endif