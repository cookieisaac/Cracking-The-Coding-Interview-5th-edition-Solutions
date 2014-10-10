#include "Solution.h"

using namespace std;

std::ostream& operator << (std::ostream& os, DoublelyLinkedList& dll)
{
	Node* runner = dll.m_head;

	if (runner == NULL)
	{
		os << "( NULL )";
		return os;
	}
	else
	{
		os << "( NULL <=> ";
	}

	while (runner != NULL)
	{
		os << runner->getValue() << " <=> " ;
		runner = runner->getNext();
	}
	os << " NULL )";

	return os;
}

std::istream& operator >> (std::istream& is, DoublelyLinkedList& dll)
{
	char value;

	while (is >> value)
	{
		dll.addNodeAtTail(value);
	}
	return is;
}

DoublelyLinkedList::~DoublelyLinkedList()
{
	Node* runner=m_head;

	while (m_head != NULL)
	{
		m_head = runner->getNext();
		free(runner);
		runner = m_head;
	}
}

void DoublelyLinkedList::addNodeAtTail(char value)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->setValue(value);
	pNode->setNextNULL();
	pNode->setPrevNULL();
	
	m_size++;

	if (m_head == NULL)
	{
		m_head = pNode;
		m_tail = pNode;
	}
	else
	{
		m_tail->setNext(pNode);
		pNode->setPrev(m_tail);
		m_tail = pNode;
	}
}

bool DoublelyLinkedList::isPalindrome()
{
	int guard = m_size / 2;
	Node* headRunner = m_head;
	Node* tailRunner = m_tail;
	bool result = true;

	if (m_head == NULL || m_head->getNext() == NULL)
	{
		return true;
	}

	for (int i = 0; i < guard; i++)
	{
		if (headRunner->getValue() != tailRunner->getValue())
		{
			result = false;
			break;
		}
		headRunner = headRunner->getNext();
		tailRunner = tailRunner->getPrev();
	}

	return result;
}