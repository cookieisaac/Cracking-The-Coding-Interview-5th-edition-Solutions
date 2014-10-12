#ifndef _SOLUTION_H
#define _SOLUTION_H
#include <string>
#include <list>
#include <iostream>

class Animal
{
	//Animal with smaller order will have priority in dequeue
	friend bool operator < (Animal& a1, Animal& a2);
	friend bool operator > (Animal& a1, Animal& a2);
	friend bool operator == (Animal& a1, Animal& a2);
	friend bool operator <= (Animal& a1, Animal& a2);
	friend bool operator >= (Animal& a1, Animal& a2);
	friend std::ostream& operator << (std::ostream& os, Animal& a);
public:
	Animal(std::string type = "Unknown", int order = -1){ m_type = type; m_order = order; }

	std::string getType(){ return m_type; }
	void setType(std::string type) { m_type = type; }

	void setOrder(int order){ m_order = order; }
	int getOrder(){ return m_order; }
protected:
	std::string m_type;
	int m_order;
};

class Dog :public Animal
{
public:
	Dog(){ m_type = "Dog"; }

};

class Cat :public Animal
{
public:
	Cat(){ m_type = "Cat"; }
};

class AnimalQueue
{
	friend std::ostream& operator <<(std::ostream& os, AnimalQueue& aq);
public:
	void enqueue(Animal* a);
	Animal* dequeueAny();
	Animal* dequeueCat();
	Animal* dequeueDog();

private:
	std::list<Animal*> _catQueue;
	std::list<Animal*> _dogQueue;
	static int m_timestamp;

};

#endif