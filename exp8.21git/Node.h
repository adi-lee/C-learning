#include<iostream>
using namespace std;
template<typename T>
class Stack;
template<typename X>
class Node {
	template<typename T>
	friend class Stack;//声明为Node的友元，那么Stack链栈类可以访问其私有成员，那么top();函数就不会出错。
	X m_data;
	Node* m_next = nullptr;
public:
	Node(const X& val) :m_data(val) {}
	const X& data()const { return m_data; } //const 版本
	X& data() { return m_data; }            //非const版本，为什么非要搞两个版本啊
	Node* next() {return m_next;}
};