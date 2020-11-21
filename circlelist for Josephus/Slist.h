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
void Slist<T>::insert(int pos, const T& val) {//�ڵڼ�λ�����������
	Listnode<T>* current = this->m_head;
	if (pos==1&&this->size==0) {
		m_head->m_data = val;
		size++;
	}
	else if (this->size<pos) {
		cout << "���볬��Χ" << endl;
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
		cout << "������Ϊ�������޷����ɾ������" << endl;
	}*/
	if (m_head->m_data == val) {
		m_head = current->m_next;
		delete current;
		cout << "��ɾ��" << endl;
	}
	else {
		while (current->m_next != this->m_head) {//�����ǰ����һ�������ָ��ͷ�Ļ���ʵ˵���Ѿ�������
			if (current->m_data == val) {
				currentfront->m_next = current->m_next;//�ҵ��ˣ�ɾ����ǰ�Ľ��
				delete current;
				cout << "��ɾ��" << endl;
				size--;
				return;
			}
			else {
				currentfront = current;
				current = current->m_next;//û�ҵ���������
			}

			if (current->m_next == this->m_head) {
				cout << "δ�ڸ��������ҵ�����ɾ����" << endl;
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
		cout << "������Ϊ�������޷���ɲ��Ҳ���" << endl;
	}*/
	while (current->m_next != this->m_head) {//�����ǰ����һ�������ָ��ͷ�Ļ���ʵ˵���Ѿ�������
		if (current->m_data == val) {
			return current;
		}
		else {
			current = current->m_next;//û�ҵ���������
		}
		if (current->m_next == this->m_head) {
			cout << "δ�ڸ��������ҵ�������ҵ�" << endl;
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
}//Ҫ����дһ����ӡ��������Ϊ�����д�Ļ��ͻ�һֱѭ��������Ͼ�ѭ������

template<typename T>
void Slist<T>::sloution(Slist<T>& Js, int& n, int& m) {

	Listnode<T>* p = Js.gethead(), * q = NULL;
	//p = p->m_next;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			q = p;
			p = p->m_next;
		}
		cout << "���е�����" << p->data() << endl;
		q->m_next = p->m_next;
		delete p;
		p = q->m_next;
	}
	m_head = p;//����֮�ʣ������ٻ�m_headʹ�������ʹ�ӡ�Ȳ�����д
}