#include "Solution.h"
using namespace std;

std::istream& operator>>(std::istream& is, SortedStack& mystack)
{
	int value;
	while (is >> value)
	{
		mystack._push(value);
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, SortedStack& mystack)
{
	stack<int> dump = mystack.m_stack;
	stack<int> holder;

	os << "( " ;
	while (!dump.empty())
	{
		holder.push(dump.top());
		dump.pop();
	}

	while (!holder.empty())
	{
		os << holder.top();
		holder.pop();
		if (!holder.empty())
		{
			os << " -> ";
		}
	}

	os << " )" ;

	return os;
}

void SortedStack::sort()
{
	stack<int> buffer;
	int temp;

	while (!m_stack.empty())
	{
		temp = m_stack.top();
		m_stack.pop();

		if (buffer.empty())
		{
			buffer.push(temp);
		}
		else
		{
			if (temp <= buffer.top())
			{
				buffer.push(temp);
			}
			else
			{
				while (!buffer.empty() && buffer.top() < temp)
				{
					m_stack.push(buffer.top());
					buffer.pop();
				}
				buffer.push(temp);
			}
		}
	}

	while (!buffer.empty())
	{
		m_stack.push(buffer.top());
		buffer.pop();
	}
}