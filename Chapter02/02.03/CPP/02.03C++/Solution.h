#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <ostream>

class Node;

class LinkedList
{
public:
	LinkedList(){ m_head = NULL; m_size = 0; }
	Node* getHead(){ return m_head; }
	int getSize() { return m_size; }
	void addNodeAtHead(Node* pNode);
	void deleteByNode(Node* pNode);
	friend std::ostream& operator << (std::ostream & os, LinkedList&);
private:
	Node* m_head;
	int m_size;
};

class Node
{
public:
	Node(int value=0) :m_value(value){ m_next = NULL; }
	void setValue(int value){ m_value = value; }
	void setNext(Node* pNode) { m_next = pNode; }
	int getValue(){ return m_value; }
	Node* getNext(){ return m_next; }
	~Node(){ m_next = NULL; }
private:
	int m_value;
	Node* m_next;
};


#endif