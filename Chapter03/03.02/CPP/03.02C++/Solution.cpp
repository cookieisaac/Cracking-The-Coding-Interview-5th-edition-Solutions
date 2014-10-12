#include "Solution.h"
using namespace std;

void StackWithMin::printStack(std::ostream& os)
{
	stack<int> dump = _valueStack;
	stack<int> print;

	while (!dump.empty())
	{
		print.push(dump.top());
		dump.pop();
	}

	os << "(";
	while (!print.empty())
	{
		os << print.top() << " -> ";
		print.pop();
	}
	os << " NULL )" << endl;

	os << "Its size is " << this->size() << " its min value is " << this->min() << endl;
}

void StackWithMin::push(int value)
{
	if (!_valueStack.empty())
	{
		_valueStack.push(value);
		if (_valueStack.top() <= _minStack.top())
		{
			_minStack.push(value);
		}
	}
	else
	{
		_valueStack.push(value);
		_minStack.push(value);
	}
}

void StackWithMin::pop()
{
	if (_valueStack.empty())
	{
		return;
	}
	else
	{
		if (_valueStack.top() == _minStack.top())
		{
			_minStack.pop();
		}
		 _valueStack.pop();
	}
}

int StackWithMin::min()
{
	return _valueStack.empty() ? MIN : _minStack.top();
}