#include "Solution.h"

using namespace std;

void printStack(std::ostream& os, std::stack<int> s)
{
	stack<int> dump = s;
	stack<int> holder;

	while (!dump.empty())
	{
		holder.push(dump.top());
		dump.pop();
	}

	os << "( ";
	while (!holder.empty())
	{
		os << holder.top();
		holder.pop();
		if (!holder.empty())
		{
			os << " -> ";
		}
	}
	os << " )";
}

void Hanoi::printCurrentState(std::ostream& os)
{
	os << "Stack [A]: ";
	printStack(os, _A);
	os << endl;

	os << "Stack [B]: ";
	printStack(os, _B);
	os << endl;

	os << "Stack [C]: ";
	printStack(os, _C);
	os << endl;
	os << "-----------------------------------------" << endl;
}
void Hanoi::printSolutionSteps(std::ostream& os)
{
	os << "Hanoi Tower with " << _disks << " disks" << endl;
	os << "-----------------------------------------" << endl;
	os << "Initial state: " << endl;
	printCurrentState(os);
	
	if (_disks == 0)
	{
		os << "No action required!" << endl;
		return;
	}
	else
	{
		int steps = 1;
		_moveDisks(_disks, _A, _C, _B, os, steps);
		os << "Done!" << endl;
	}
}

void Hanoi::_moveDisks(int N, std::stack<int>& _Source, std::stack<int>& _Target, std::stack<int>& _Helper, std::ostream& os, int& steps)
{
	if (N == 0)
	{
		return;
	}
	else if (N == 1)
	{
		_moveTop(_Source, _Target, os, steps);
	}
	else if (N == 2)
	{
		_moveTop(_Source, _Helper, os, steps);
		_moveTop(_Source, _Target, os, steps);
		_moveTop(_Helper, _Target, os, steps);
	}
	else
	{

		_moveDisks(N - 1, _Source, _Helper, _Target, os, steps);
		_moveTop(_Source, _Target, os, steps);
		_moveDisks(N - 1, _Helper, _Target, _Source, os, steps);
	}

}
void Hanoi::_moveTop(std::stack<int>& _Source, std::stack<int>& _Target, std::ostream& os, int& steps)
{
	_Target.push(_Source.top());
	_Source.pop();
	os << "Step " << steps << " " << endl;
	printCurrentState(os);
	steps = steps + 1;
	return;
}

