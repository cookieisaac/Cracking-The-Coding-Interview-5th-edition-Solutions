#include "Solution.h"

using namespace std;

int ThreeStacks::pop(char stack)
{
	int returnValue;

	if (stack != 'A'&& stack != 'B' && stack!='C') 
	{
		return INVALID;
	}

	if (_size[stack] == 0)
	{
		returnValue = INVALID;
	}
	else
	{
		returnValue = _array[_top[stack]];
		_size[stack]--;
		_array[_top[stack]] = INVALID;
		_top[stack]--;
	}

	return returnValue;
}

int ThreeStacks::push(int value, char stack)
{
	if (_size[stack]+1 >= _capacity[stack])
	{
		return INVALID;
	}
	else
	{
		_top[stack]++;
		_array[_top[stack]] = value;
		_size[stack]++;
	}
}
int ThreeStacks::peek(char stack)
{
	if (_size[stack] > 0 && _size[stack] <= _capacity[stack])
		return _array[_top[stack]];
	else
		return INVALID;
}

std::ostream& operator<<(std::ostream& os, ThreeStacks& ts)
{
	for (char stack = 'A'; stack <= 'C'; stack++)
	{
		os << "Stack ['" << stack << "']: ";
		for (int i = ts._bottom[stack]; i < ts._bottom[stack]+ts._size[stack]; i++)
		{
			os << ts._array[i] << " -> ";
		}
		os << "NULL" << endl;;
		os << "Its size is " << ts.getSize(stack) << " and its top value is " << ts.peek(stack) << ".";

		if (stack != 'C')
		{
			os << endl;
		}
	}
	return os;
}