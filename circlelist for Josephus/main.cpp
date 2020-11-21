#include"Slist.h"


int main() {
	Slist <int>s;
	int i, n, m;
	cout << "输入游戏人数和报数值" << endl;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		s.push_back(i);
	}
	s.print();
	s.sloution(s, n, m);
	s.print();
	//Slist <int>s;
	//s.insert(1, 2);
	//int val;
	//while (cin >> val) {
	//	s.push_back(val);
	//	s.print();
	//}
	//	s.insert(2, 25);
	////s.insert(1, 20);
	//s.print();
	//s.erase(25);
	//s.print();
}