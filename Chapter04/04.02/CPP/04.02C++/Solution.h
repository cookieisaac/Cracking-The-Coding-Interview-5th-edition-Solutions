#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>

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
		void setStatus(const STATUS s){ _status = s; }
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

	void setOutput(std::ostream& out){ _out = out; }

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

	Vertices findPath(const T& source, const T& destination)
	{
		Vertex<T>* src = find_vertex(source);
		Vertex<T>* dest = find_vertex(destination);

		Vertices path;
		std::map<Vertex<T>*, Vertex<T>*> parent;

		bool found = false;
		if (src == NULL || dest == NULL)
		{
			return path;
		}
		else if (src == dest)
		{
			path.push_back(src);
			return path;
		}
		else
		{
			reset();
			
			std::queue<Vertex<T>*> q;
			q.push(src);
			parent.insert(std::pair<Vertex<T>*, Vertex<T>*>(src, NULL));

			while (!q.empty())
			{
				Vertex<T>* cur = q.front();
				q.pop();
				
				AdjListItr itr = _list.find(cur);

				if (itr != _list.end())
				{
					Vertices neighbors = itr->second;
					for (VerticesItr vItr = neighbors.begin(); vItr != neighbors.end(); vItr++)
					{
						parent.insert(std::pair<Vertex<T>*, Vertex<T>*>((*vItr), cur));
						STATUS status = (*vItr)->getStatus();

						if (status == NOT_VISITED)
						{
							if ((*vItr) == dest)
							{
								found = true;
								//Construct path for return
								
								Vertex<T>* temp = (*vItr);
								path.push_front(temp);
								while (temp != src)
								{
									path.push_front(parent[temp]);
									temp = parent[temp];
								}

								return path;
							}
							else
							{
								(*vItr)->setStatus(IN_PROGRESS);
								q.push(*vItr);
							}
						}
					}
				}

				cur->setStatus(VISITED);
				path.remove(cur);
			}
		}
		return path;
	}

	void BreadthFirstTraversal(std::ostream& os)
	{
		reset(); // reset node status as NOT_VISITED
		os << "Breadth First Tranversal" << std::endl;

		std::queue<Vertex<T>*> q;

		for (VerticesItr itr=_vertices.begin(); itr != _vertices.end() && (*itr)->getStatus() != VISITED; itr++)
		{
			q.push(*itr);

			while (!q.empty())
			{
				Vertex<T>* cur = q.front();
				q.pop();
				if (cur->getStatus() != VISITED)
				{
					cur->setStatus(VISITED);
					os << cur->getData() << " ";
				}

				AdjListItr jtr = _list.find(cur);
				if (jtr != _list.end())
				{
					Vertices v = jtr->second;

					VerticesItrConst vItr(v.begin());

					for (; vItr != v.end(); vItr++)
					{
						if ((*vItr)->getStatus() != VISITED)
						{
							q.push(*vItr);
						}
					}
				}
			}
		}
		os << std::endl;
	}

	void DepthFirstTraversal(std::ostream& os)
	{
		reset(); // reset node status as NOT_VISITED
		os << "Depth First Traversal" << endl;

		std::stack<Vertex<T>*> s;

		for (VerticesItr itr = _vertices.begin(); itr != _vertices.end(); itr++)
		{
			s.push(*itr);

			while (!s.empty())
			{
				Vertex<T> *cur = s.top();
				s.pop();

				if (cur->getStatus() != VISITED)
				{
					os << cur->getData() << " ";
					cur->setStatus(IN_PROGRESS);
				}

				AdjListItr jtr = _list.find(cur);

				if (jtr != _list.end())
				{
					Vertices v = jtr->second;
					if (!v.empty())
					{
						for (VerticesItrConst vItr = v.begin(); vItr != v.end(); vItr++)
						{
							STATUS status = (*vItr)->getStatus();
							if (status == IN_PROGRESS)
							{
								_isCyclic = true;
							}
							else if (status == NOT_VISITED)
							{
								(*vItr)->setStatus(IN_PROGRESS);
								s.push(*vItr);
							}
						}
					}
				}
				cur->setStatus(VISITED);
			}
		}
		os << endl;
		
		if (hasCycles())
		{
			os << "Graph has cycles!" << endl;
		}
		else
		{
			os << "Graph  has no cycles! " << endl;
		}
	}

	void printPath(Vertices path, std::ostream& os)
	{
		if (!path.empty())
		{
			os << "Path is found! " << std::endl;
			VerticesItr pathItr= path.begin();
			while (pathItr != path.end()&&(*pathItr)!=NULL)
			{
				os << (*pathItr)->getData();
				pathItr++;
				if (pathItr != path.end())
				{
					os << " -> ";
				}
			}
			os << endl;
		}
		else
		{
			os << "Path can not be found! " << std::endl;
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