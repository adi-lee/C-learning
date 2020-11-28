#include <iostream>
using namespace std;
template<typename T>
class BianNode {
	template<typename T>
	friend class HeadNode;//友元关系不可传递
	template<typename T>
	friend class Graph;
	int m_weight=0;//权重
	BianNode<T>* mb_next;
	int m_head=0;
};
