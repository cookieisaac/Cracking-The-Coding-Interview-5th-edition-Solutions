#include "Solution.h"
using namespace std;

void LinkedList::addNodeAtHead(Node* pNode)
{
	if (m_head == NULL)
	{
		m_head = pNode;
		m_size++;
	}
	else
	{
		pNode->setNext(m_head);
		m_head = pNode;
		m_size++;
	}
}

void LinkedList::deleteByNode(Node* pNode)
{
	// Limitation of this method is that we can't delete the last node
	if (pNode->getNext() == NULL)
	{
		return; 
	}
	pNode->setValue(pNode->getNext()->getValue());
	pNode->setNext(pNode->getNext()->getNext());
	m_size--;
}

std::ostream& operator << (std::ostream & os, LinkedList& ll)
{
	Node* pNode = ll.getHead();

	while (pNode != NULL)
	{
		os << pNode->getValue() << " -> ";
		pNode = pNode->getNext();
	}
	os << "NULL" << endl;

	return os;
}