#include "Solution.h"
using namespace std;

std::ostream& operator <<(std::ostream& os, Animal& a)
{
	os << a.getType() << "[" << a.getOrder() << "]";

	return os;
}

bool operator < (Animal& a1, Animal& a2)
{
	return a1.getOrder() < a2.getOrder();
}

bool operator > (Animal& a1, Animal& a2)
{
	return a1.getOrder() > a2.getOrder();
}

bool operator == (Animal& a1, Animal& a2)
{
	return a1.getOrder() == a2.getOrder();
}

bool operator <= (Animal& a1, Animal& a2)
{
	return a1.getOrder() <= a2.getOrder();
}

bool operator >= (Animal& a1, Animal& a2)
{
	return a1.getOrder() >= a2.getOrder();
}


int AnimalQueue::m_timestamp = 0;
void AnimalQueue::enqueue(Animal* a)
{
	m_timestamp++;
	a->setOrder(m_timestamp);
	if (a->getType() == "Cat")
	{
		_catQueue.push_back(a);
	}
	else if (a->getType() == "Dog")
	{
		_dogQueue.push_back(a);
	}

}

Animal* AnimalQueue::dequeueAny()
{
	if (_catQueue.empty())
		return dequeueDog();
	else if (_dogQueue.empty())
		return dequeueCat();
	else if (_dogQueue.front()->getOrder() < _catQueue.front()->getOrder())
	{
		return dequeueDog();
	}
	else
	{
		return dequeueCat();
	}

}
Animal* AnimalQueue::dequeueCat()
{
	if (_catQueue.empty())
	{
		return NULL;
	}
	else
	{
		Animal* temp = _catQueue.front();
		_catQueue.pop_front();
		return temp;
	}
}

Animal* AnimalQueue::dequeueDog()
{
	if (_dogQueue.empty())
	{
		return NULL;
	}
	else
	{
		Animal* temp = _dogQueue.front();
		_dogQueue.pop_front();
		return temp;
	}
}

std::ostream& operator <<(std::ostream& os, AnimalQueue& aq)
{
	os << "Cat queue: ( ";
	for (std::list<Animal*>::iterator ii=aq._catQueue.begin(); ii != aq._catQueue.end(); ii++)
	{
		os << (*ii)->getType() << "[" << (*ii)->getOrder() << "]";
		std::list<Animal*>::iterator jj = ii;
		if (++jj != aq._catQueue.end())
		{
			os << " <- ";
		}

	}
	os << " )" << endl;

	os << "Dog queue: ( ";
	for (std::list<Animal*>::iterator ii = aq._dogQueue.begin(); ii != aq._dogQueue.end(); ii++)
	{
		os << (*ii)->getType() << "[" << (*ii)->getOrder() << "]";
		std::list<Animal*>::iterator jj = ii;
		if (++jj != aq._dogQueue.end())
		{
			os << " <- ";
		}
	}
	os << " )" << endl;

	return os;
}
