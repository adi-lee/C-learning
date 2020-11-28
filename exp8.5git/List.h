#include"BianNode.h"
template<typename T>
class HeadNode {
	template<typename T>
	friend class Graph;
	T m_data;
	BianNode<T>* m_next;
};