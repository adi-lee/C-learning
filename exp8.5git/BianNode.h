#include <iostream>
using namespace std;
template<typename T>
class BianNode {
	template<typename T>
	friend class HeadNode;//��Ԫ��ϵ���ɴ���
	template<typename T>
	friend class Graph;
	int m_weight=0;//Ȩ��
	BianNode<T>* mb_next;
	int m_head=0;
};
