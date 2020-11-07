#include<iostream> 
#include<vector>
#include<string>
#include<complex>
using namespace std;
template <typename T> class Set {
	vector<T> m_elems;//数据成员
	
public:
	Set() = default;
	
	Set(const vector<T>& elem);//构造函数
	
	bool is_elem(T);//是否为集合元素
	
	void insert(T);//插入一个元素
	void erase(T);//删除一个元素
	void  find(T);//查找一个元素
	void length();
	Set common(const Set<T>& s);//两个集合的交集
	Set sum(const Set<T>& s);//两个集合的并集
	Set Swap(Set<T>& s1,Set<T>& s2);//两个集合的交换
	Set& operator=(const Set<T>& s);//赋值函数的重载声明
	Set(const Set<T>& s);//复制构造函数
	Set clear( Set<T>& s);//删除集合内所有元素

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
}//构造函数定义



template <typename T>
Set<T>::Set(const Set<T>& s) : m_elems(s.m_elems) { };//复制构造函数


template <typename T>
bool Set<T>::is_elem(T a) {
	for (T c : m_elems) {//m_elems是一个可遍历的容器或流，是vector类型，c就用来在遍历过程中获得容器里的每一个元素。 
		if (c == a) {
			return true;
		}
	}
	return false;
}//判断是否为集合元素

template <typename T>
void Set<T>::insert(T a) {
	for (T c : m_elems) {
		if (c == a) {
			cout << "该元素已在集合内" << endl;
			return;
		}
	}
	m_elems.push_back(a);
}//插入元素函数定义

template <typename T>
void Set<T>::erase(T a) {
	vector<T>s_elems;
	for (auto c : m_elems) {
		if (c != a) {
			s_elems.push_back(c);
		}
	}
	m_elems = s_elems;
}//删除某个元素 函数定义

 
template <typename T>
void Set<T>::find(T a) {
	unsigned int i;
		for (i = 0; i< m_elems.size();++i) {
			if (m_elems[i] == a) {
				cout << "该元素在该集合第" << i+1 << "位" << endl;
				return;
			}
	}
	cout << "该元素并不在该集合中" << endl;
	return;
		
}//查找元素在第几位


template <typename T>
void Set<T>::length() {
	cout << "该集合的元素个数为:" << m_elems.size() << endl;

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
}//集合交集函数定义

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
}//集合并集函数定义

template <typename T>
Set<T> Set<T>::clear( Set<T>& s) {
	unsigned int i;
	for (i=s.m_elems.size();i>0;i--) {
			s.m_elems.pop_back();
	}
	m_elems = s.m_elems;
	return Set(m_elems);
}//删除函数定义


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
}//赋值重载函数 

/*template<typename T>
 ostream& operator<<(ostream& os, const Set<T>& s) {
	for (char c : s.m_elems) {
		os << c << " ";
	}
	return os;
}//重载<<函数
//为什么在这里重载的话会出现LNK2019的错误啊
*/
