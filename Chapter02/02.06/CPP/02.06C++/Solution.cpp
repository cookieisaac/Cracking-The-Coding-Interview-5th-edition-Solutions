#include "Solution.h"

std::istream& operator>>(std::istream& is, CircularList& cl)
{
	char value;

	while (is >> value)
	{
		cl.addNodeAtTail(value);
	}

	return is;
}
std::ostream& operator<<(std::ostream& os, CircularList& cl)
{
	Node* runner = cl.getHead();

	if (runner == NULL)
	{
		os << "( NULL )";
		return os;
	}

	int counter = 0;
	int loopGuard = 3 * cl.getSize();
	os << "( ";
	while (runner->getNext() != NULL && counter < loopGuard)
	{
		counter++;
		os << runner->getValue() << " --> ";
		runner = runner->getNext();
	}

	if (runner->getNext() == NULL)
	{
		os << runner->getValue() << " -> NULL )";
	}
	else
	{
		os << runner->getValue() << " -> Infinity.... )";
	}

	return os;
}

CircularList::~CircularList()
{
	int counter = m_size;
	Node* runner = m_head;
	while (counter > 0)
	{
		m_head = runner->getNext();
		free(runner);
		runner = m_head;
		counter--;
	}
}

void CircularList::addNodeAtTail(char c)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->setNextNULL();
	pNode->setValue(c);

	m_size++;

	if (m_head == NULL)
	{
		m_head = pNode;
	}
	else
	{
		Node* runner = m_head;
		while (runner->getNext() != NULL)
		{
			runner = runner->getNext();
		}
		runner->setNext(pNode);
	}
}

void CircularList::createCircle(char c)
{
	Node* runner = m_head;
	Node* finder = NULL;

	if (runner == NULL)
	{
		return;
	}

	while (runner->getNext() != NULL)
	{
		if (runner->getValue() == c)
		{
			finder = runner;
		}

		runner = runner->getNext();
	}

	if (runner->getValue() == c)
	{
		finder = runner;
	}

	runner->setNext(finder);

	return;
}


Node* CircularList::findLoopEntry()
{
	Node* result = NULL;
	Node* collision = NULL;
	Node* fastRunner = m_head;
	Node* slowRunner = m_head;

	while (fastRunner != NULL&& fastRunner->getNext() != NULL)
	{
		fastRunner = fastRunner->getNext()->getNext();
		slowRunner = slowRunner->getNext();

		if (fastRunner == slowRunner)
		{
			collision = slowRunner;
			break;
		}
	}

	if (collision != NULL)
	{
		Node* slowRunner2 = m_head;
		slowRunner = collision;

		while (slowRunner != slowRunner2)
		{
			slowRunner = slowRunner->getNext();
			slowRunner2 = slowRunner2->getNext();
		}

		result = slowRunner;
	}

	return result;
}