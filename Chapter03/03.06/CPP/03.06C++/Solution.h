#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>
#include <stack>

class SortedStack
{
	friend std::istream& operator>>(std::istream& is, SortedStack& mystack);
	friend std::ostream& operator<<(std::ostream& os, SortedStack& mystack);
public:
	void sort();
private:
	std::stack<int> m_stack;
	
	void _push(int value){ m_stack.push(value); }
	void _pop(){ m_stack.pop(); }
	int _peek(){ return m_stack.top(); }
	bool _isEmpty(){ return m_stack.empty(); }
};

#endif