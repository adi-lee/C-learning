#include"Graph.h"
#include<string>
int main() {
	Graph<string> s;
	s.insertVertex("�人");
	s.insertVertex("��ɳ");
	s.insertVertex("����");
	s.insertVertex("����");
	s.insertVertex("����");
	s.insertVertex("�Ϻ�");
	s.insertVertex("����");
	s.insertVertex("����");
	s.insertVertex("����");
	s.insertVertex("����");
	s.insertVertex("����");
	s.insertVertex("����");
	/*s.printGraph();*/
	s.insertEdge("�人", "��ɳ", 297);
	s.insertEdge("�人", "����", 560);
	s.insertEdge("�人", "����", 750);
	s.insertEdge("�人", "����", 650);
	s.insertEdge("�人", "�Ϻ�", 880);
	s.insertEdge("����", "����", 760);
	s.insertEdge("����", "����", 600);
	s.insertEdge("����", "����", 1400);
	s.insertEdge( "����","����", 1500);
	s.insertEdge( "����","����", 1300);
	s.insertEdge("����", "����", 1000);
	s.insertEdge("����", "����", 1050);
	s.insertEdge("����", "����", 900);
	s.insertEdge( "����","����", 630);
	s.insertEdge("�Ϻ�", "����", 1180);
	s.insertEdge("�Ϻ�", "����", 1200);
	s.insertEdge("����", "�Ϻ�", 1200);
	s.insertEdge("��ɳ", "����", 730);
	s.printGraph();
	string a,b,c;
	cout << "�������������ʼ���У�";
	cin >> a;
	s.search(a);
	//s.deleteVertex("�人");
	cout << '\n'<<"����������͵���ĵص�";
	cin >> b >> c;
	s.minPath(b,c);
	//s.minPath("�人", "����");
}