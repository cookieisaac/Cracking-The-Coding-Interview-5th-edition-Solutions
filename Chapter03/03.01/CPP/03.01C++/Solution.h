#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <map>
#include <ostream>

#define SIZE 100
#define INVALID -1

class ThreeStacks
{
	friend std::ostream& operator<<(std::ostream& os, ThreeStacks& ts);
public:
	ThreeStacks()
	{ 
		for (int i = 0; i < SIZE; i++)
		{
			_array[i] = INVALID;
		}
		_size['A'] = 0; _size['B'] = 0; _size['C'] = 0;
		_capacity['A'] = SIZE / 3; _capacity['B'] = SIZE / 3; _capacity['C'] = SIZE / 3; 
		_bottom['A'] = 0; _bottom['B'] = _capacity['A']; _bottom['C'] = _capacity['A'] + _capacity['B'];
		_top['A'] = _bottom['A'] - 1; _top['B'] = _bottom['B'] - 1; _top['C'] = _bottom['C'] - 1;
	}

	~ThreeStacks(){}

	int pop(char stack = 'A');
	int push(int value, char stack = 'A');
	int peek(char stack = 'A');

	int getSize(char stack){ return _size[stack]; }
	int getCapacity(char stack){ return _capacity[stack]; }

private:
	int _array[SIZE];
	
	std::map<char, int> _capacity;
	std::map<char, int> _size;
	std::map<char, int> _bottom;
	std::map<char, int> _top;
};

#endif