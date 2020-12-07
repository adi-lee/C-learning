#include"Shape.h"
//int main() {
//	/*{	Color co1(122, 122.2, 33);
//	Shape sh1(co1);
//	Point p1(2, 3, sh1), p2(3, 4, sh1), p3(p1), p4;
//
//	Circle c1(p1, 3), c2(c1), c3;
//	Segement s1(p1, p2, co1), s2;
//	s2 = s1;
//	p4 = p2;
//	c3 = c1;
//	}
//	return 0;*/
//		Point p1(0, 0), p2(0, 3), p3(0, 0), p4(4, 0);
//		Circle c1(p1, 3);
//		Segement s1(p1, p2);
//		Segement s2(p3, p4);
//		triangle t1(s1, s2);
//		rectangle r1(s1, s2);
//		cuboid cu1(r1, 2, 31);
//		cuboid cu2(r1, 0.1, 100);
//		cout << cu1.volumn() << endl;
//		Column co1(c1, 3, 25);
//		Column co2(c1, 20, 100);
//		cout << co1.volumn() << endl;
//		Cone cone1(c1, 4, 37);
//		cout<<cone1.volumn()<<endl;
//		basket b1(100);
//		b1.push_back(cu1);
//		b1.push_back(co1);
//		b1.push_back(cone1);//有点问题
//		b1.push_back(co1);
//		b1.push_back(cu2);
//		b1.sort();
//		b1.valuerate();
//		b1.place();
//	
//		
//		/*if (t1 < r1) {
//			cout << "zhen" << endl;
//		}
//		if (cu1 < co1) {
//			cout << "zhen1" << endl;
//		}
//		else cout << "jia" << endl;
//		cout << t1.area() << endl;*/
//	}
int main() {
	Point p1(0, 0), p2(0, 1), p3(0, 0), p4(1, 0);
	Circle c1(p1, 3);
	Segement s1(p1, p2);
	Segement s2(p3, p4);
	triangle t1(s1, s2);
	rectangle r1(s1, s2);
	cuboid cu1(r1, 23, 92);
	cuboid cu2(r1, 31, 57);
	cuboid cu3(r1, 29, 49);
	cuboid cu4(r1, 44, 68);
	cuboid cu5(r1, 53, 60);
	cuboid cu6(r1, 38, 43);
	cuboid cu7(r1, 63, 67);
	cuboid cu8(r1, 85, 84);
	cuboid cu9(r1, 89, 87);
	cuboid cu10(r1, 82, 72);
	
	basket b1(165);
	b1.push_back(cu1);
	b1.push_back(cu2);
	b1.push_back(cu3);
	b1.push_back(cu4);
	b1.push_back(cu5);
	b1.push_back(cu6);
	b1.push_back(cu7);
	b1.push_back(cu8);
	b1.push_back(cu9);
	b1.push_back(cu10);
	//b1.sort();
	//b1.valuerate();
	b1.place();

}