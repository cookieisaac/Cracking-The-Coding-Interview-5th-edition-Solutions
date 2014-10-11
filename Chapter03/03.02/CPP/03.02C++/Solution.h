#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>
#include <stack>

#define MIN 100000
class StackWithMin
{
//	friend std::ostream operator<<(std::ostream& os, StackWithMin& swm);

public:
	StackWithMin(){}
	~StackWithMin(){}
	void push(int value);
	void pop();
	bool empty(){ return _valueStack.empty(); }
	int peek(){ return _valueStack.empty() ? MIN : _valueStack.top(); }
	int min();
	int size(){ return _valueStack.size(); }
	void printStack(std::ostream& os);
private:
	std::stack<int> _valueStack;
	std::stack<int> _minStack;
};


#endif