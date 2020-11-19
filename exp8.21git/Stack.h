#include<iostream>
#include"Node.h"
using namespace std;
template<typename T>
class Stack {
	Node <T>* m_top = nullptr;
public:
	Stack() = default;
	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;
	~Stack();
	void clear();
	void push(const T& val);
	void pop();
	bool empty()const { return m_top == nullptr; }
	const T& top() { return m_top->m_data; }//类的友元
};
template<typename T>
void Stack<T>::push(const T& val) {
	Node<T> *node = new Node<T>(val);
	node->m_next = m_top;//书上这里写错了，但是PPT没错
	m_top = node;
}

template<typename T>
void Stack<T>::pop() {
	Node<T>* p = m_top;
	m_top = m_top->m_next;
	delete p;//是不是空悬指针？
	//p = nullptr;
}
template<typename T>
void Stack<T>::clear() {
	Node <T>* p = nullptr;
	while (m_top != nullptr) {
		p = m_top;
		m_top = m_top->m_next;
		delete p;
		//p = nullptr;我看老师这个没有加这个东西啊，难道不是指向空更好吗

	}
}
template<typename T>
Stack<T>::~Stack() {
	clear();
}
