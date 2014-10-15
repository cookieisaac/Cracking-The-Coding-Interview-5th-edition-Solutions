#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>
#include <vector>
#include <list>
#include <map>

typedef enum
{
	NOT_VISITED,
	IN_PROGRESS,
	VISITED
}STATUS;

template<class T>
class Graph
{
private:
	template<class Ty>
	class Vertex
	{
	private:
		Ty _data;
		STATUS _status;

	public:
		explicit Vertex(const Ty in) :_data(in), _status(NOT_VISITED){}
		~Vertex(){}
		void setStatus(const STATUS s){_status = s}
		STATUS getStatus() const{ return _status; }
		Ty getData() const{ return _data; }
	};

	typedef typename std::list<Vertex<T>*> Vertices;
	typedef typename std::list<Vertex<T>*>::iterator VerticesItr;
	typedef typename std::list<Vertex<T>*>::const_iterator VerticesItrConst;

	typedef typename std::map<Vertex<T>*, Vertices> AdjList;
	typedef typename std::map<Vertex<T>*, Vertices>::iterator AdjListItr;
	typedef typename std::map<Vertex<T>*, Vertices>::const_iterator AdjListItrConst;

	Vertices _vertices;
	AdjList _list;
	bool _isCyclic;

	Vertex<T>* allocVertex(const T in)
	{
		Vertex<T> * temp = new Vertex<T>(in);

		return temp;
	}

	Vertex<T>* find_vertex(const T in)
	{
		VerticesItrConst itr(_vertices.begin());

		for (; itr != _vertices.end(); itr++)
		{
			if ((*itr)->getData() == in)
			{
				return *itr;
			}
		}

		return NULL;
	}

public:
	explicit Graph(std::vector<T> &v)
	{
		typedef typename std::vector<T>::const_iterator inItr;
		inItr itr(v.begin());

		for (; itr != v.end(); itr++)
		{
			_vertices.push_back(new Vertex<T>(*itr));
		}

		_isCyclic = false;
	}

	~Graph()
	{
		VerticesItrConst itr(_vertices.begin());

		for (; itr != _vertices.end(); itr++)
		{
			delete (*itr);
		}
	}

	bool hasCycles(){ return _isCyclic; }

	void connectVertex(const T&s, const T&d)
	{
		Vertex<T> *src = find_vertex(s);
		Vertex<T> *dest = find_vertex(d);

		if (!src || !dest)
		{
			return;
		}

		AdjListItr itr = _list.find(src);

		if (itr == _list.end())
		{
			std::list<Vertex<T>*> edges;
			edges.push_back(dest);
			_list[src] = edges;
		}
		else
		{
			itr->second.push_back(dest);
		}
	}

	void reset()
	{
		VerticesItrConst itr(_vertices.begin());

		for (; itr != _vertices.end(); itr++)
		{
			if ((*itr)->getStatus() != NOT_VISITED)
			{
				(*itr)->setStatus(NOT_VISITED);
			}
		}
	}


	friend std::ostream& operator<<(std::ostream& os, Graph<T>& g)
	{
		Graph<T>::VerticesItr vIt(g._vertices.begin());

		for (; vIt != g._vertices.end(); vIt++)
		{
			char s = (*vIt)->getData();
			os << s << ":";
			Vertex<T>* src = g.find_vertex(s);
			Graph<T>::AdjListItr itr = g._list.find(src);

			// If node is not a source node on any edge, just ignore the node; otherwise, print all destination node from the curent source node
			if (itr != g._list.end())
			{

				for (VerticesItrConst vJt = itr->second.begin(); vJt != itr->second.end(); vJt++)
				{
					os << " -> " << (*vJt)->getData() << "; ";
				}
			}

			os << endl;
		}

		return os;
	}
};


#endif