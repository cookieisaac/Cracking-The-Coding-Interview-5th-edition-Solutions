#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <ostream>

class Node;
class Node
{
public:
	Node(int value = 0) :m_value(value){ m_next = NULL; }

	int getValue(){ return m_value; }
	void setValue(int value){ m_value = value; }
	
	Node* getNext(){ return m_next; }
	void setNext(Node* p){ m_next = p; }
	void setNextNull(){ m_next = NULL; }

private:
	int m_value;
	Node* m_next;
};

class LinkedList
{
	friend std::ostream& operator<< (std::ostream& os, LinkedList& ll);
public:
	LinkedList(){ m_head = NULL; m_size = 0; }
	Node* getHead(){ return m_head; }
	int getSize(){ return m_size; }
	void addNodeAtHead(int nodeValue);
	void addNodeAtTail(int nodeValue);
	~LinkedList();
private:
	Node* m_head;
	int m_size;
};

void additionInForwardOrder(LinkedList& A, LinkedList& B, LinkedList& result);
void additionInReverseOrder(LinkedList& A, LinkedList& B, LinkedList& result);

#endif