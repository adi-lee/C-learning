#pragma once//�˽���vector��STL��׼���е�ʵ����ͨ�������ڴ��ռ䲻�����ͻ����������ڴ�
//#pragma execution_character_set("utf-8");
//#include<QTextCodec>
//QTextCodec *codec = QTextCodec::codecForName("UTF-8");

//    //QTextCodec::setsetCodecForTr(codec);

  // QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
//   // QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

#include<iostream>
//#include<vector>
#include<string>
using namespace std;
template <typename T>
class MyVector {
    T* m_arr;
    int m_size;
    int m_capacity;
public:
    MyVector() = default;//Ĭ�Ϲ��캯��
    MyVector(const std::initializer_list<T>& l);
    MyVector(const MyVector& rhs) :m_arr(rhs.m_arr), m_size(rhs.m_size), m_capacity(rhs.m_capacity) {};      //���ƹ��캯��
    MyVector(MyVector&& rhs):m_arr(rhs.m_arr),m_size(rhs.m_size),m_capacity(rhs.m_capacity){
        rhs.m_arr = nullptr;
        rhs.m_size = 0;
        rhs.m_capacity = 0;
    };            //�ƶ����캯��
    ~MyVector() { delete[] m_arr; };            //��������
    T& operator[](size_t i);                   //����ȡ�±�������
    int size() { return m_size; };                      //����Ԫ�ظ���
    MyVector& operator=(const MyVector& rhs); //��ֵ������
    MyVector& operator=(MyVector&& rhs) {
        if (this != &rhs) {
            delete[] m_arr;
            m_size = rhs.m_size;
            m_arr = rhs.m_arr;
            rhs.m_arr = nullptr;
            rhs.m_size = 0;
            rhs.m_capacity = 0;
        }
        return *this;
    }; //�ƶ���ֵ������

    T front() { return m_arr[0];}       //��ȡ��Ԫ�غ���
    T back() {return m_arr[m_size - 1];	}//��ȡβԪ�غ���
    T at(int i) const { return m_arr[i - 1];}
    void push_back(const T& a);//β�庯��
    void pop_back();
    void insert(int a,const T b);
    void erase(int a);
    void clear() {
        delete[]m_arr;
        m_arr = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
    friend ostream& operator<<(ostream& os, const MyVector<T>& s) {
        for (int i = 0; i < s.m_size; i++) {
            os << s.m_arr[i] << " ";
            }
        return os;
    }//����<<
};
template <typename T>
MyVector<T>::MyVector(const std::initializer_list<T>& l) {

    m_size=l.size();
    m_capacity = m_size*2;
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = *(l.begin() + i);
   }
}


template<typename T>
 T& MyVector<T>::operator[](size_t i)
{
     if (i > m_size) {
         cout << "������������" << endl;
     }
      else return m_arr[i - 1];
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& rhs) {
    if (this != nullptr) {
        delete[]m_arr;
    }
        m_size = rhs.m_size;
        m_capacity = rhs.m_capacity;
        m_arr = new T[m_capacity];
        for (int i = 0; i < m_size; i++) {
            m_arr[i] = rhs.m_arr[i];
        }

       return*this;
}

template<typename T>
 void MyVector<T>::push_back(const T& a){
     if (m_size < m_capacity) {
         m_arr[m_size] = a;
         m_size = m_size + 1;
     }
     else {
         T* b = m_arr;
         //delete[]m_arr;
         m_capacity = m_size * 2;
         m_arr = new T[m_capacity];
         for (int i = 0; i < m_size; i++) {
             m_arr[i] = b[i];
         }
         m_arr[m_size] = a;
         m_size++;
         delete[]b;
     }
}

 template<typename T>
 void MyVector<T>::pop_back() {
     m_size = m_size - 1;
 }

 template<typename T>
  inline void MyVector<T>::insert(int a,const T b){
      if (a < m_size) {
          if (m_size < m_capacity) {
              m_size = m_size + 1;
              for (int i = 0; i < m_size; i++) {
                  if (a > 0) {
                      if (i == a) {
                          for (i = m_size; i > a - 1; i--) {
                              m_arr[i] = m_arr[i - 1];
                          }
                          m_arr[a - 1] = b;
                          m_size++;
                          break;
                      }
                  }
                  else cout << "��������" << endl;//���븺����
              }
          }
          else {
              int d = a;
              const T e = b;
              T* c = m_arr;
              //delete[]m_arr;
              m_capacity = m_size * 2;
              m_arr = new T[m_capacity];
              for (int i = 0; i < m_size; i++) {
                  m_arr[i] = c[i];
              }
              delete[]c;
              insert(a,b);
          }
      }
      else cout << "������λ�ò�������" << endl;

 }

  template<typename T>
  void MyVector<T>::erase(int a)
  {
      if (a <=m_size ) {
                for (int i = 0; i < m_size; i++) {
                    if (a > 0) {
                        if (i == a) {
                            for (; i < m_size; i++) {
                                m_arr[i - 1] = m_arr[i];
                            }
                            pop_back();
                            m_size--;
                            break;
                        }
                    }
                    else cout << "��������" << endl;
                }
            }
            else cout << "������������" << endl;
  }
