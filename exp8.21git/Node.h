#include<iostream>
using namespace std;
template<typename T>
class Stack;
template<typename X>
class Node {
	template<typename T>
	friend class Stack;//����ΪNode����Ԫ����ôStack��ջ����Է�����˽�г�Ա����ôtop();�����Ͳ������
	X m_data;
	Node* m_next = nullptr;
public:
	Node(const X& val) :m_data(val) {}
	const X& data()const { return m_data; } //const �汾
	X& data() { return m_data; }            //��const�汾��Ϊʲô��Ҫ�������汾��
	Node* next() {return m_next;}
};