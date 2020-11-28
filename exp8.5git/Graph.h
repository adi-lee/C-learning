#include"List.h"
#include<vector>
#include<string>
#include <algorithm>
template<typename T>
class Graph {
	int m_vexnum=0, m_edgenum=0;//m_vexnum表示顶点数，m_arcnum表示边数
	vector< HeadNode<T> > m_vextex;//用vector储存每一个链表组成邻接表
    vector<string>* searchcity = new vector<string>;
public:
    Graph() = default;
    void insertVertex(const T& vertex); //插入一个顶点
    void deleteVertex(const T& vertex); //删除一个顶点
    void deleteEdge(const T& vertex1, const T& vertex2);//删除一条边
    void insertEdge(const T& vertex1, const T& vertex2, int weight);                    //插入一条边
    void printGraph();
    void search(const T& beginVertex);  //遍历
    void minPath(const T& sVertex, const T& eVertex); //最小路径
};

template <typename T>
void Graph<T>::insertVertex(const T& vertex) {
    HeadNode<T> h_vertex;
    h_vertex.m_data = vertex;
    h_vertex.m_next = nullptr;
    m_vextex.push_back(h_vertex);
    ++m_vexnum;
}//插入一个顶点

template <typename T>
void Graph<T>::deleteVertex(const T& vertex) {
    for (int i = 0; i < m_vexnum;i++) {
        if (m_vextex[i].m_data == vertex) {
            m_vextex.erase(i);//这句不对，放着再说
            break;
       }
    }
}

template <typename T>
void Graph<T>::printGraph()
{
    for (int i = 0; i < m_vexnum; ++i) {
        BianNode<T>* tmp = m_vextex[i].m_next;
        cout << "路线:" <<i <<m_vextex[i].m_data << "->";
        while (tmp) {
            cout << "(" << tmp->m_weight << "km)";
            cout << tmp->m_head << m_vextex[tmp->m_head].m_data <<"->";
            tmp = tmp->mb_next;
        }
        cout << "NULL" << endl;
    }
}

template <typename T>
void Graph<T>::insertEdge(const T& vertex1, const T& vertex2, int weight) {
    for (int i = 0; i < m_vexnum; ++i) {
        if (m_vextex[i].m_data == vertex1) {
            for (int j = 0; j < m_vexnum; ++j) {
                if (m_vextex[j].m_data == vertex2) {
                    BianNode<T> *edge=new BianNode<T>;
                    edge->m_head = j;
                    edge->m_weight = weight;
                    edge->mb_next = nullptr;
                    if (m_vextex[i].m_next != nullptr) {
                        edge->mb_next = m_vextex[i].m_next;
                            m_vextex[i].m_next =edge;
                        /*while (edge->mb_next != nullptr) {
                            edge = edge->mb_next;
                        }
                        edge->mb_next = edge;*/
                    }
                    else m_vextex[i].m_next = edge;
                    m_edgenum++;//最后别忘了考虑这个动态内存的释放问题，或许可以使用智能指针
                }
                
            }
          
        }
    }
}

template <typename T>
void Graph<T>::deleteEdge(const T& vertex1, const T& vertex2) {
    for (int i = 0; i < m_vexnum; ++i) {
        if (m_vextex[i].m_data == vertex1) {
            for (int j = 0; j < m_vexnum; ++j) {
                if (m_vextex[j].m_data == vertex2) {
                    if (m_vextex[i].m_next != nullptr) {
                       
                    }
                    m_edgenum--;//最后别忘了考虑这个动态内存的释放问题，或许可以使用智能指针
                }

            }

        }
    }
}

template <typename T>
void Graph<T>::search(const T& beginVertex) {
    for (int i = 0; i <m_vexnum; ++i) {
        while (m_vextex[i].m_data == beginVertex) {
            cout << m_vextex[i].m_data << " ";
            searchcity->push_back(m_vextex[i].m_data);
            BianNode<T>* p = m_vextex[i].m_next;
            while (p != nullptr) {
                int j = p->m_head; int flag = 0;
                for (int k = 0; k < searchcity->size();k++) {
                    if (  m_vextex[j].m_data==searchcity->at(k)) {
                        flag = 1;
                        p = p->mb_next;
                        if (p==nullptr){ return; }
                        else {
                            j = p->m_head;
                            search(m_vextex[j].m_data);
                        }
                        break;   
                    }
                }
                if (flag == 0) {
                    search(m_vextex[j].m_data);
                    p = p->mb_next;
                    ++i;
                }

            }
        }
    }
    if (m_vexnum > searchcity->size()) {//有可能存在如图中"武汉"，无法被遍历到
        for (int i = 0; i < m_vexnum; ++i) {
            vector<string>::iterator result = find(searchcity->begin(), searchcity->end(), m_vextex[i].m_data);
            if (result == searchcity->end()) {//利用泛型find，vector中无find;
                searchcity->push_back(m_vextex[i].m_data);//未找到就家到里面，防止重复输出
                cout << m_vextex[i].m_data<<" ";

            }
            /* for (int i = 0; i < m_vexnum; ++i) {
                 for(int j=0;j<searchcity->size();++j)
                 while (m_vextex[i].m_data != searchcity->at(j)) {
                     cout << m_vextex[i].m_data;
                     break;
                 }
             }*///这个会重复输出
        }
    }
}

template <typename T>
void Graph<T>::minPath(const T& sVertex, const T& eVertex) {

    for (int i = 0; i < m_vexnum; ++i) {
        if (m_vextex[i].m_data == sVertex) {
            BianNode<T>* p = m_vextex[i].m_next;
            while (m_vextex[p->m_head].m_data != eVertex) {
                p = p->mb_next;
                if (m_vextex[p->m_head].m_data == eVertex) {
                    cout <<"最小路径：" <<p->m_weight << "km"<<endl;
                    break;
                }
            }//直接有联系

        }
    }

}