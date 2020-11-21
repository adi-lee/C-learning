#include"Listnode.h"

template<typename T>
class Slist {
	Listnode <T>* m_head = nullptr;
	int size = 0;
public:
	Slist() {
		m_head = new Listnode<T>();
		m_head->m_next = m_head;
	}
	~Slist() { clear(); }
	void clear();
	Listnode<T>* gethead() { return m_head; }
	void push_back(const T& val);
	void insert(int pos, const T& val);
	void erase(const T& val);
	void print();
	void sloution(Slist<T>& Js, int& n, int& m);
	Listnode<T>* find(const T& val);
	friend ostream& operator <<(ostream& os, const Slist<T>& list) {
		Listnode<T>* p = list.m_head;
		while (p != nullptr) {
			os << p->data() << " ";
			p = p->next();
		}
		return os;
	}

};
template<typename T>
void Slist<T>::push_back(const T& val) {
	Listnode<T>* current = this->m_head;
	if (current->m_next == this->m_head&& size==0) {
		m_head->m_data = val;
		size++;
	}
	else{
		while (current->m_next != this->m_head) {
			current = current->m_next;
		}
	Listnode<T>* newnode = new Listnode<T>(val, current->m_next);
	current->m_next = newnode;
	size++;
	}
	
}


template<typename T>
void Slist<T>::insert(int pos, const T& val) {//在第几位后面插入数据
	Listnode<T>* current = this->m_head;
	if (pos==1&&this->size==0) {
		m_head->m_data = val;
		size++;
	}
	else if (this->size<pos) {
		cout << "插入超范围" << endl;
		return ;
	}
	else { 
			for (int i = 0; i < pos - 1; i++) {
			current = current->m_next;
		}
		Listnode<T>* newNode = new Listnode<T>(val, current->m_next);
			current->m_next = newNode;
			size++; 
	}
	/*listNode<T>* current = this->ahead->next;
	for (int i = 0; i < index - 1; i++)
		current = current->next;
	listNode<T>* newNode = new listNode<T>(element, current->next);
	current->next = newNode;
	listSize++;*/


	/*Listnode<T>* node = new Listnode<T>(val);
	node->m_next = pos->m_next;
	pos->m_next = node;
	if(pos==m_tail){
		m_tail = node;
	}
	return node;*/
	return ;
}

template<typename T>
void Slist<T>::erase(const T& val) {
	Listnode<T>* current = this->m_head;
	Listnode<T>* currentfront = current;
	/*if (current->m_next == this->m_head) {
		cout << "该链表为空链表，无法完成删除操作" << endl;
	}*/
	if (m_head->m_data == val) {
		m_head = current->m_next;
		delete current;
		cout << "已删除" << endl;
	}
	else {
		while (current->m_next != this->m_head) {//如果当前的下一个结点又指向头的话其实说明已经找完了
			if (current->m_data == val) {
				currentfront->m_next = current->m_next;//找到了，删除当前的结点
				delete current;
				cout << "已删除" << endl;
				size--;
				return;
			}
			else {
				currentfront = current;
				current = current->m_next;//没找到继续遍历
			}

			if (current->m_next == this->m_head) {
				cout << "未在该链表中找到你想删除的" << endl;
			}
		}
	}
	/*Listnode<T>* p = m_head, * q = p;
	while (p != nullptr && p->m_data != val) {
		q = p;
		p = p->m_next;
	}
	if (p)
		q->m_next = p->m_next;
	if (p == m_tail)
		m_tail = q;
	if (p == m_head)
		m_head = nullptr;
	delete p;*/
}

template<typename T>
void Slist<T>::clear() {
	Listnode<T>* current;
	while (m_head->m_next !=m_head)
	{
		current= m_head->m_next;
		if (m_head != nullptr) {
			delete m_head;
		}
		m_head = current;
		if (m_head->m_next = m_head) {
			break;
		}
	}
	/*Listnode<T>* p = nullptr;
	while (m_head!=nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
	}*/
}
template < typename T >
Listnode<T>* Slist<T>::find(const T& val) {
	Listnode<T>* current = this->m_head;
	/*if (current->m_next == this->m_head) {
		cout << "该链表为空链表，无法完成查找操作" << endl;
	}*/
	while (current->m_next != this->m_head) {//如果当前的下一个结点又指向头的话其实说明已经找完了
		if (current->m_data == val) {
			return current;
		}
		else {
			current = current->m_next;//没找到继续遍历
		}
		if (current->m_next == this->m_head) {
			cout << "未在该链表中找到你想查找的" << endl;
		}
	}
	return nullptr;
	/*Listnode <T>* p = m_head;
	while (p != nullptr && p->m_data != val)
		p = p->m_next;
	return p;*/
}

template<class T>
void Slist<T>::print()
{
	Listnode<T>* current = this->m_head;
	cout << current->m_data << "  ";
	current = current->m_next;
	while (current != this->m_head)
	{
		cout << current->m_data << "  ";
		current = current->m_next;
	}
	cout << endl;
}//要额外写一个打印函数是因为如果不写的话就会一直循环输出，毕竟循环链表。

template<typename T>
void Slist<T>::sloution(Slist<T>& Js, int& n, int& m) {

	Listnode<T>* p = Js.gethead(), * q = NULL;
	//p = p->m_next;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			q = p;
			p = p->m_next;
		}
		cout << "出列的人是" << p->data() << endl;
		q->m_next = p->m_next;
		delete p;
		p = q->m_next;
	}
	m_head = p;//神来之笔，重新召唤m_head使得析构和打印等不用重写
}