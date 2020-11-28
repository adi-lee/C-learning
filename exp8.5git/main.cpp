#include"Graph.h"
#include<string>
int main() {
	Graph<string> s;
	s.insertVertex("武汉");
	s.insertVertex("长沙");
	s.insertVertex("杭州");
	s.insertVertex("重庆");
	s.insertVertex("西安");
	s.insertVertex("上海");
	s.insertVertex("广州");
	s.insertVertex("昆明");
	s.insertVertex("拉萨");
	s.insertVertex("北京");
	s.insertVertex("沈阳");
	s.insertVertex("兰州");
	/*s.printGraph();*/
	s.insertEdge("武汉", "长沙", 297);
	s.insertEdge("武汉", "杭州", 560);
	s.insertEdge("武汉", "重庆", 750);
	s.insertEdge("武汉", "西安", 650);
	s.insertEdge("武汉", "上海", 880);
	s.insertEdge("重庆", "兰州", 760);
	s.insertEdge("兰州", "西安", 600);
	s.insertEdge("兰州", "拉萨", 1400);
	s.insertEdge( "拉萨","重庆", 1500);
	s.insertEdge( "昆明","拉萨", 1300);
	s.insertEdge("广州", "昆明", 1000);
	s.insertEdge("杭州", "广州", 1050);
	s.insertEdge("北京", "西安", 900);
	s.insertEdge( "沈阳","北京", 630);
	s.insertEdge("上海", "沈阳", 1180);
	s.insertEdge("上海", "北京", 1200);
	s.insertEdge("西安", "上海", 1200);
	s.insertEdge("长沙", "杭州", 730);
	s.printGraph();
	string a,b,c;
	cout << "请输入遍历的起始城市：";
	cin >> a;
	s.search(a);
	//s.deleteVertex("武汉");
	cout << '\n'<<"请输入出发和到达的地点";
	cin >> b >> c;
	s.minPath(b,c);
	//s.minPath("武汉", "杭州");
}