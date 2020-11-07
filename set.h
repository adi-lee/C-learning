#include<iostream> 
#include<vector>
#include<string>
#include<complex>
using namespace std;
template <typename T> class Set {
	vector<T> m_elems;//���ݳ�Ա
	
public:
	Set() = default;
	
	Set(const vector<T>& elem);//���캯��
	
	bool is_elem(T);//�Ƿ�Ϊ����Ԫ��
	
	void insert(T);//����һ��Ԫ��
	void erase(T);//ɾ��һ��Ԫ��
	void  find(T);//����һ��Ԫ��
	void length();
	Set common(const Set<T>& s);//�������ϵĽ���
	Set sum(const Set<T>& s);//�������ϵĲ���
	Set Swap(Set<T>& s1,Set<T>& s2);//�������ϵĽ���
	Set& operator=(const Set<T>& s);//��ֵ��������������
	Set(const Set<T>& s);//���ƹ��캯��
	Set clear( Set<T>& s);//ɾ������������Ԫ��

	friend ostream& operator<<(ostream& os, const Set<T>& s) {
		for (T c : s.m_elems) {
			os << c << " ";
		}
		return os;
	}
	//char Set();
	//Set();

};






template <typename T>
Set<T>::Set(const vector<T>& elem) {
	for (char c : elem) {
		m_elems.push_back(c);
	}
}//���캯������



template <typename T>
Set<T>::Set(const Set<T>& s) : m_elems(s.m_elems) { };//���ƹ��캯��


template <typename T>
bool Set<T>::is_elem(T a) {
	for (T c : m_elems) {//m_elems��һ���ɱ�����������������vector���ͣ�c�������ڱ��������л���������ÿһ��Ԫ�ء� 
		if (c == a) {
			return true;
		}
	}
	return false;
}//�ж��Ƿ�Ϊ����Ԫ��

template <typename T>
void Set<T>::insert(T a) {
	for (T c : m_elems) {
		if (c == a) {
			cout << "��Ԫ�����ڼ�����" << endl;
			return;
		}
	}
	m_elems.push_back(a);
}//����Ԫ�غ�������

template <typename T>
void Set<T>::erase(T a) {
	vector<T>s_elems;
	for (auto c : m_elems) {
		if (c != a) {
			s_elems.push_back(c);
		}
	}
	m_elems = s_elems;
}//ɾ��ĳ��Ԫ�� ��������

 
template <typename T>
void Set<T>::find(T a) {
	unsigned int i;
		for (i = 0; i< m_elems.size();++i) {
			if (m_elems[i] == a) {
				cout << "��Ԫ���ڸü��ϵ�" << i+1 << "λ" << endl;
				return;
			}
	}
	cout << "��Ԫ�ز����ڸü�����" << endl;
	return;
		
}//����Ԫ���ڵڼ�λ


template <typename T>
void Set<T>::length() {
	cout << "�ü��ϵ�Ԫ�ظ���Ϊ:" << m_elems.size() << endl;

}
template <typename T>
Set<T> Set<T>::common(const Set<T>& s) {
	Set rset;
	for (T es : m_elems) {
		for (T ses : s.m_elems) {
			if (es == ses) {
				rset.insert(es);
			}
		}
	}
	m_elems = rset.m_elems;
	return Set(m_elems);
}//���Ͻ�����������

template <typename T>
Set<T> Set<T>::sum(const Set<T>& s) {
	Set result;

	for (T c : m_elems) {
		if (result.is_elem(c) != true) {
			result.insert(c);
		}
	}
	for (T c : s.m_elems) {
		if (result.is_elem(c) != true) {
			result.insert(c);
		}
	}
	m_elems = result.m_elems;
	return Set(m_elems);
}//���ϲ�����������

template <typename T>
Set<T> Set<T>::clear( Set<T>& s) {
	unsigned int i;
	for (i=s.m_elems.size();i>0;i--) {
			s.m_elems.pop_back();
	}
	m_elems = s.m_elems;
	return Set(m_elems);
}//ɾ����������


template <typename T>
Set<T> Set<T>::Swap(Set<T>& a, Set<T>& b) {
	Set result(a);
	
	a=b;
	b=result;
	return a,b;
	
}
template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& s) {
	m_elems = s.m_elems;
	return *this;
}//��ֵ���غ��� 

/*template<typename T>
 ostream& operator<<(ostream& os, const Set<T>& s) {
	for (char c : s.m_elems) {
		os << c << " ";
	}
	return os;
}//����<<����
//Ϊʲô���������صĻ������LNK2019�Ĵ���
*/
