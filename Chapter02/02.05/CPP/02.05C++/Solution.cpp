#include "Solution.h"

using namespace std;

std::ostream& operator<< (ostream& os, LinkedList& ll)
{
	Node* runner = ll.getHead();

	if (runner == NULL)
	{
		os << "( )";
		return os;
	}

	os << "( " ;
	while (runner->getNext() != NULL)
	{
		os << runner->getValue() << " -> ";
		runner = runner->getNext();
	}

	os << runner->getValue() << " )";

	return os;
}
void LinkedList::addNodeAtHead(int nodeValue)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->setValue(nodeValue);
	pNode->setNextNull();

	m_size++; //Assuming thread safe
	if (m_head == NULL)
	{
		m_head = pNode;
	}
	else
	{
		pNode->setNext(m_head);
		m_head = pNode;
	}
}

void LinkedList::addNodeAtTail(int nodeValue)
{
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode->setValue(nodeValue);
	pNode->setNextNull();

	m_size++; //Assuming thread safe
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

LinkedList::~LinkedList()
{
	Node* runner = NULL;

	while (m_head != NULL)
	{
		runner = m_head;
		m_head = m_head->getNext();
		free(runner);
	}
	m_size = 0;
}

void additionInForwardOrder(LinkedList& A, LinkedList& B, LinkedList& result)
{
	Node* runnerA=A.getHead();
	Node* runnerB=B.getHead();

	Node* pDoneA=NULL;
	Node* pDoneB=NULL;

	int sum = 0;
	int carry = 0;
	int digit = 0;

	while (pDoneA != A.getHead() && pDoneB != B.getHead())
	{
		// Run runner A and B to get the right-most non-calculated bit
		runnerA = A.getHead();
		while (runnerA->getNext() != pDoneA)
		{
			runnerA = runnerA->getNext();
		}

		runnerB = B.getHead();
		while (runnerB->getNext() != pDoneB)
		{
			runnerB = runnerB->getNext();
		}

		// Do the computation
		sum = runnerA->getValue() + runnerB->getValue() + carry;
		digit = sum % 10;
		carry = sum / 10;

		result.addNodeAtHead(digit);

		// Update the Done pointer
		pDoneA = runnerA;
		pDoneB = runnerB;
	}

	while (pDoneA != A.getHead())
	{
		runnerA = A.getHead();
		while (runnerA->getNext() != pDoneA)
		{
			runnerA = runnerA->getNext();
		}

		// Do the computation
		sum = runnerA->getValue() + carry;
		digit = sum % 10;
		carry = sum / 10;

		result.addNodeAtHead(digit);

		// Update the Done pointer
		pDoneA = runnerA;
	}

	while (pDoneB != B.getHead())
	{
		runnerB = B.getHead();
		while (runnerB->getNext() != pDoneB)
		{
			runnerB = runnerB->getNext();
		}

		// Do the computation
		sum = runnerB->getValue() + carry;
		digit = sum % 10;
		carry = sum / 10;

		result.addNodeAtHead(digit);

		// Update the Done pointer
		pDoneB = runnerB;
	}

	if (carry != 0)
	{
		result.addNodeAtHead(carry);
	}


}

void additionInReverseOrder(LinkedList& A, LinkedList& B, LinkedList& result)
{
	Node* runnerA = A.getHead();
	Node* runnerB = B.getHead();

	int carry = 0;
	while (runnerA != NULL && runnerB != NULL)
	{
		int sum = runnerA->getValue() + runnerB->getValue() + carry;
		int digit = sum % 10;
		carry = sum / 10;

		result.addNodeAtTail(digit);

		runnerA = runnerA->getNext();
		runnerB = runnerB->getNext();
	}
	
	while (runnerA != NULL)
	{
		int sum = runnerA->getValue() + carry;
		int digit = sum % 10;
		carry = sum / 10;

		result.addNodeAtTail(digit);

		runnerA = runnerA->getNext();
	}

	while (runnerB != NULL)
	{
		int sum = runnerB ->getValue() + carry;
		int digit = sum % 10;
		carry = sum / 10;

		result.addNodeAtTail(digit);

		runnerB = runnerB->getNext();
	}

	if (carry != 0)
	{
		result.addNodeAtTail(carry);
	}
}