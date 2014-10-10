#include "Solution.h"
using namespace std;

std::ostream& operator<<(std::ostream& os, LinkedList& ll)
{
	Node* runner = ll.getHead();
	while (runner != NULL)
	{
		os << runner->getValue() << " --> " ;
		runner = runner->getNext();
	}
	os << "NULL" << endl;
	return os;
}

void LinkedList::addNodeAtTail(int value)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->setValue(value);
	pNode->setNextNull();
//	pNode->setNext(NULL);

	//First Node
	if (m_head == NULL)
	{
		m_head = pNode;
		m_size++;
		return;
	}

	//Other Node
	Node* runner = m_head;
	while (runner->getNext() != NULL)
	{
		runner = runner->getNext();
	}
	runner->setNext(pNode);
	m_size++;
}

LinkedList::~LinkedList() 
{ 
	Node* tempHolder;
	while (m_head != NULL)
	{
		tempHolder = m_head;
		m_head = m_head->getNext();
		free(tempHolder);
	}
	m_size = 0;
}
void LinkedList::partitionByValue(int partitionValue)
{
	Node* smallerStart = NULL; //Smaller or equal
	Node* smallerEnd = NULL; // Smaller or equal

	Node* largerStart = NULL;
	Node* largerEnd = NULL;

	Node* runner = m_head;
	while (runner != NULL)
	{
		Node* pCurrent = runner;
		int value = pCurrent->getValue();
		runner = runner->getNext(); //Get to next node before current node is modified
		pCurrent->setNextNull(); //Let the current node be a stand alone node

		if (value <= partitionValue)
		{
			if (smallerStart == NULL && smallerEnd == NULL)
			{
				//First node
				smallerStart = pCurrent;
				smallerEnd = pCurrent;
			}
			else
			{
				//Other node: insert at tail
				smallerEnd->setNext(pCurrent);
				smallerEnd = pCurrent;
				
			}
		}
		else
		{
			if (largerStart == NULL && largerEnd == NULL) 
			{
				//first node
				largerStart = pCurrent;
				largerEnd = pCurrent;
			}
			else
			{
				//Insert node at head
				largerEnd->setNext(pCurrent);
				largerEnd = pCurrent;
			}
		}
	}

	// Merge the two list
	if (smallerStart && smallerEnd == NULL)
	{
		// If the first list is empty, merge the two lists
		smallerStart = largerStart;
	}
	else 
	{
		smallerEnd->setNext(largerStart);
	}
	
	m_head = smallerStart;

	return;
}