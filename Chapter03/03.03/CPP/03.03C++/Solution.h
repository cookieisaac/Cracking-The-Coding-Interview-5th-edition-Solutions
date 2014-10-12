#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <vector>
#include <stack>
#include <iostream>

#define MAX_STACK_SIZE 10
#define INVALID -1

class SetOfStacks
{
public:
	SetOfStacks(){ _maxStackSize = MAX_STACK_SIZE; }
	~SetOfStacks(){}
	int getNumStacks(){ return _stackSets.size(); }
	int getMaxStackSize(){ return _maxStackSize; }

	void push(int value);
	void pop();
	int peek();
	void popAt(int i);
	int peekAt(int i);

	int sizeAllValue();
	int sizeOf(int i);

	bool isEmpty();
	void printState(std::ostream& os);
private:
	std::vector<std::stack<int>> _stackSets;
	int _maxStackSize;
};

#endif