#include"List.h"
#include<vector>
#include<string>
#include <algorithm>
template<typename T>
class Graph {
	int m_vexnum=0, m_edgenum=0;//m_vexnum��ʾ��������m_arcnum��ʾ����
	vector< HeadNode<T> > m_vextex;//��vector����ÿһ����������ڽӱ�
    vector<string>* searchcity = new vector<string>;
public:
    Graph() = default;
    void insertVertex(const T& vertex); //����һ������
    void deleteVertex(const T& vertex); //ɾ��һ������
    void deleteEdge(const T& vertex1, const T& vertex2);//ɾ��һ����
    void insertEdge(const T& vertex1, const T& vertex2, int weight);                    //����һ����
    void printGraph();
    void search(const T& beginVertex);  //����
    void minPath(const T& sVertex, const T& eVertex); //��С·��
};

template <typename T>
void Graph<T>::insertVertex(const T& vertex) {
    HeadNode<T> h_vertex;
    h_vertex.m_data = vertex;
    h_vertex.m_next = nullptr;
    m_vextex.push_back(h_vertex);
    ++m_vexnum;
}//����һ������

template <typename T>
void Graph<T>::deleteVertex(const T& vertex) {
    for (int i = 0; i < m_vexnum;i++) {
        if (m_vextex[i].m_data == vertex) {
            m_vextex.erase(i);//��䲻�ԣ�������˵
            break;
       }
    }
}

template <typename T>
void Graph<T>::printGraph()
{
    for (int i = 0; i < m_vexnum; ++i) {
        BianNode<T>* tmp = m_vextex[i].m_next;
        cout << "·��:" <<i <<m_vextex[i].m_data << "->";
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
                    m_edgenum++;//�������˿��������̬�ڴ���ͷ����⣬�������ʹ������ָ��
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
                    m_edgenum--;//�������˿��������̬�ڴ���ͷ����⣬�������ʹ������ָ��
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
    if (m_vexnum > searchcity->size()) {//�п��ܴ�����ͼ��"�人"���޷���������
        for (int i = 0; i < m_vexnum; ++i) {
            vector<string>::iterator result = find(searchcity->begin(), searchcity->end(), m_vextex[i].m_data);
            if (result == searchcity->end()) {//���÷���find��vector����find;
                searchcity->push_back(m_vextex[i].m_data);//δ�ҵ��ͼҵ����棬��ֹ�ظ����
                cout << m_vextex[i].m_data<<" ";

            }
            /* for (int i = 0; i < m_vexnum; ++i) {
                 for(int j=0;j<searchcity->size();++j)
                 while (m_vextex[i].m_data != searchcity->at(j)) {
                     cout << m_vextex[i].m_data;
                     break;
                 }
             }*///������ظ����
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
                    cout <<"��С·����" <<p->m_weight << "km"<<endl;
                    break;
                }
            }//ֱ������ϵ

        }
    }

}