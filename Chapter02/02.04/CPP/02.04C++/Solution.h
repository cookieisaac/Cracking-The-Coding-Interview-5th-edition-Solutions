#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <ostream>

class Node;
class Node
{
public:
	Node(int value = 0) :m_value(value){ m_next = NULL; }
	~Node(){ m_next = NULL; }
	void setValue(int value){ m_value = value; }
	int getValue(){ return m_value; }
	void setNext(Node* pNode){ m_next = pNode; }
	void setNextNull(){ m_next = NULL; }
	Node* getNext(){ return m_next; }
private:
	int m_value;
	Node* m_next;
};


class LinkedList
{
public:
	friend std::ostream& operator<<(std::ostream&, LinkedList&);
	LinkedList(){ m_head = NULL; m_size = 0; }
	~LinkedList();
	int getSize() { return m_size; }
	Node* getHead() { return m_head; }
	void addNodeAtTail(int value);
	void partitionByValue(int value);
private:
	Node* m_head;
	int m_size;
};

#endif