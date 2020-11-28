#include"Node.h"
#include<iomanip>
#include<vector>
#include <algorithm>
using namespace std;
template <typename T>
class HTree {//HTree即huffmantree
public:
    HTree()=default;//默认构造函数
   /* ~HTree() {
        for (iterator i = begin(); i != end(); ++i)

            delete* i;
    }*/
    HN<T>* createHfmTree(vector<HN<T>*>&);//创建哈夫曼树
    void print(HN<T>*, vector<int>);
    void sort(vector<HN<T>*>&);
};
template<typename T>
HN<T>* HTree<T>::createHfmTree(vector<HN<T>*> &hnode) {
   while (hnode.size() > 1) {
       sort(hnode);
        HN<T>* lightest = hnode.at(0);
        HN<T>* lighter = hnode.at(1);//取出频率最小的两个
       HN<T> *newnode = new HN<T>;
        newnode->m_data = NULL;
        newnode->m_weight = lightest->m_weight + lighter->m_weight;
        newnode->m_left = lightest;
        newnode->m_right = lighter;//建立新的结点，并确定左右孩子
        typename vector<HN<T>*>::iterator iter;
        iter = hnode.erase(hnode.begin(), hnode.begin() + 2);
        hnode.push_back(newnode);
    }  
    return hnode[0];
}

template<typename T>
void HTree<T>::print(HN<T>* hnode, vector<int>key) {
    
        ofstream in;
        in.open("huffmancode.txt", ios::app);
    if (hnode->m_left == NULL && hnode->m_right == NULL) {
        cout << hnode->m_data << ":"<<endl;
        cout << setw(19)<<"该字符的频率为：";
        cout << hnode->m_weight << endl;
        cout << setw(15)<<"该字符编码：";
        for (vector<int>::iterator iter = key.begin(); iter != key.end(); iter++) {
            cout << *iter;
        }
        cout << endl;//输出到控制台
        in << hnode->m_data << ":" << endl;
        in << setw(19) << "该字符的频率为：";
        in << hnode->m_weight << endl;
        in << setw(15) << "该字符编码：";
        for (vector<int>::iterator iter = key.begin(); iter != key.end(); iter++) {
            in << *iter;
        }
        in << endl;
        in.close();//输出到文本文件，并关闭
        return;
    }
    else {
        key.push_back(0);
        print(hnode->m_left, key);
        key.pop_back();
        key.push_back(1);
        print(hnode->m_right, key);
        key.pop_back();
    }
}

template<typename T>
void  HTree<T>::sort(vector<HN<T>*> &hnode) {//对结点排序，形参为：指向存放结点的数组 和 待排序结点

    HN<T>  *temp1=new HN<T>;//Node类型结点（排序用，工具结点）
    temp1->data()= NULL;
    temp1->weight() = 0;
    temp1->left() = nullptr;
    temp1->right() = nullptr;

    for (int i = 0; i < hnode.size(); i++) {//双循环让其按权重从小到大排序
        for (int j = 0; j < hnode.size() - 1 - i; j++) {
            if (hnode[j]->weight() > hnode[j+1]->weight()) {
                temp1 = hnode[j];
                hnode[j] = hnode[j + 1];
                hnode[j + 1] = temp1;

            }
        }
    }
    /*delete temp1;
    temp1 = nullptr;*/
}

