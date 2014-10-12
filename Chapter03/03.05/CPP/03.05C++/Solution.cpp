#include "Solution.h"

#include <queue>
using namespace std;

std::ostream& operator<<(std::ostream& os, MyQueue& orig)
{
	MyQueue q = orig;

	os << "( " ;
	if (!q.isEmpty())
	{
		if (q._newStacks.empty())
		{
			q._shiftStacks();
		}
		while (!q._newStacks.empty())
		{
			os << q._newStacks.top();
			q._newStacks.pop();
			if (!q._newStacks.empty())
			{
				os << " <- ";
			}
		}
	}
	os << " )" << endl;

	return os;
}

void MyQueue::enqueue(int value)
{
	if (isEmpty())
	{
		_oldStacks.push(value);
	}
	else
	{
		if (_oldStacks.empty())
		{
			_shiftStacks();
		}
		_oldStacks.push(value);
	}
}


void MyQueue::dequeue()
{
	if (isEmpty())
	{
		return;
	}

	if (_newStacks.empty())
	{
		_shiftStacks();
	}

	_newStacks.pop();

}


int MyQueue::peek()
{
	if (isEmpty())
	{
		return INVALID;
	}

	if (_newStacks.empty())
		_shiftStacks();
	return _newStacks.top();
}

void MyQueue::_shiftStacks()
{
	if (isEmpty())
		return;
	if (_oldStacks.empty())
	{
		while (!_newStacks.empty())
		{
			_oldStacks.push(_newStacks.top());
			_newStacks.pop();
		}
	}
	else
	{
		while (!_oldStacks.empty())
		{
			_newStacks.push(_oldStacks.top());
			_oldStacks.pop();
		}
	}
}