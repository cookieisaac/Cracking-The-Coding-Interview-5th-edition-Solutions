#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>

class Node;
class Node
{
public:
	Node(char value) :m_value(value){ m_next = NULL; }
	~Node() { m_next = NULL; }

	void setNextNULL(){ m_next = NULL; }
	void setNext(Node* p){ m_next = p; }
	Node* getNext(){ return m_next; }

	void setValue(char value){ m_value = value; }
	char getValue(){ return m_value; }
private:
	char m_value;
	Node* m_next;
};

class CircularList
{
	friend std::istream& operator>>(std::istream& is, CircularList& cl);
	friend std::ostream& operator<<(std::ostream& os, CircularList& cl);
public:
	CircularList(){ m_head = NULL; m_size = 0; }
	~CircularList();

	Node* getHead(){ return m_head; }
	int getSize(){ return m_size; }

	void addNodeAtTail(char c);
	void createCircle(char c);

	Node* findLoopEntry();
private:
	Node* m_head;
	int m_size;
};

#endif