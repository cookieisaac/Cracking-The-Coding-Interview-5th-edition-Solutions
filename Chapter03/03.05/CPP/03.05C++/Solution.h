#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <ostream>
#include <stack>
#define INVALID -1
class MyQueue
{
	friend std::ostream& operator<<(std::ostream& os, MyQueue& q);
public:
	int getSize(){ return (_oldStacks.size() + _newStacks.size()); }
	bool isEmpty(){ return _oldStacks.empty() && _newStacks.empty(); }
	void enqueue(int value);
	void dequeue();
	int peek();
private:
	std::stack<int> _oldStacks;
	std::stack<int> _newStacks;
	void _shiftStacks();
};

#endif