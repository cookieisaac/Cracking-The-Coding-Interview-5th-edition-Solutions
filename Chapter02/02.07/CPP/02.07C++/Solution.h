#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>

class Node;
class Node
{
public:
	Node(char value='0'):m_value(value){ m_next = NULL; m_prev = NULL; }
	~Node(){ m_next = NULL; m_prev = NULL; }

	void setValue(char value){ m_value = value; }
	char getValue(){ return m_value; }

	void setNext(Node* p){ m_next = p; }
	void setNextNULL(){ m_next = NULL; }
	Node* getNext(){ return m_next; }

	void setPrev(Node* p){ m_prev = p; }
	void setPrevNULL(){ m_prev = NULL; }
	Node* getPrev(){ return m_prev; }
private:
	Node* m_next;
	Node* m_prev;
	char m_value;
};

class DoublelyLinkedList
{
	friend std::ostream& operator << (std::ostream& os, DoublelyLinkedList& dll);
	friend std::istream& operator >> (std::istream& is, DoublelyLinkedList& dll);
public:
	DoublelyLinkedList()
	{
		m_head = NULL;
		m_tail = NULL;
		m_size = 0;
	}

	~DoublelyLinkedList();
	int getSize(){ return m_size; }
	Node* getHead(){ return m_head; }
	Node* getTail(){ return m_tail; }
	void addNodeAtTail(char value);
	bool isPalindrome();

private:
	Node* m_head;
	Node* m_tail;
	int m_size;
};


#endif