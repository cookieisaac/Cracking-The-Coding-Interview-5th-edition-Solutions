#include "Solution.h"
using namespace std;

void SetOfStacks::push(int i)
{
	if (_stackSets.empty())
	{
		stack<int> firstStack;
		firstStack.push(i);
		_stackSets.push_back(firstStack);
	}
	else
	{
		stack<int>& lastStack = _stackSets.back();
		if (lastStack.size() >= MAX_STACK_SIZE)
		{
			stack<int> newStack;
			newStack.push(i);
			_stackSets.push_back(newStack);
		}
		else
		{
			lastStack.push(i);
		}
	}
}

void SetOfStacks::pop()
{
	if (_stackSets.empty())
	{
		return;
	}
	else
	{
		stack<int>& lastStack = _stackSets.back();
		lastStack.pop();

		if (lastStack.empty())
		{
			_stackSets.pop_back();
		}
	}
}

int SetOfStacks::peek()
{
	if (_stackSets.empty())
	{
		return INVALID;
	}
	else
	{
		return _stackSets.back().top();
	}
}

void SetOfStacks::popAt(int i)
{
	if (i >= 0 && i < _stackSets.size())
	{
		_stackSets[i].pop();
		if (_stackSets[i].empty())
		{
			_stackSets.erase(_stackSets.begin() + i);
		}
	}
}

int SetOfStacks::peekAt(int i)
{
	if (i < _stackSets.size())
	{
		return _stackSets[i].top();
	}
	else
	{
		return INVALID;
	}
}

int SetOfStacks::sizeAllValue()
{
	int size = 0;
	for (int i = 0; i < _stackSets.size(); i++)
	{
		size += _stackSets[i].size();
	}

	return size;
}
int SetOfStacks::sizeOf(int i)
{
	if (i < _stackSets.size())
	{
		return _stackSets[i].size();
	}
	else
	{
		return INVALID;
	}
}

bool SetOfStacks::isEmpty()
{
	return _stackSets.empty();
}

void SetOfStacks::printState(ostream& os)
{
	if (isEmpty())
	{
		os << "Set of 0 stacks! " << endl;
	}
	else
	{
		os << "Set of " << getNumStacks() << " stacks: " << endl;
		for (int i = 0; i < _stackSets.size(); i++)
		{
			os << "Stack ['" << i << "']: ( ";
			stack<int> dump = _stackSets[i];
			stack<int> holder;
			while (!dump.empty())
			{
				holder.push(dump.top());
				dump.pop();
			}
			while (!holder.empty())
			{
				os << holder.top() << " -> ";
				holder.pop();
			}
			os << "NULL )" << endl;
		}
	}
}