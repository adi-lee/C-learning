#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Slist;
template<typename T>
class Listnode {
	friend class Slist<T>;
	T m_data;
	Listnode* m_next = nullptr;
public:
	Listnode<T>(const Listnode<T>& rhs) = delete;
	Listnode<T>& operator = (const Listnode& rhs) = delete;
	Listnode() = default;
	Listnode(const T&val):m_data(val){}
	Listnode(const T& val, Listnode<T>* Next) { this->m_data = val; this->m_next =Next; }
	const T& data()const { return m_data; }
	T& data() { return m_data; }
	Listnode* next() { return m_next; }

};