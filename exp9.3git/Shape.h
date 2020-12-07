#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//class Color {

class basket;
class Shape {
	friend class basket;
protected:
	string m_name;
public:
	Shape(const string  &s="") :m_name(s) {}
	virtual double area()const { return 0; }//此函数为虚函数
	virtual double length()const { return 0; }
	virtual double volumn()const { return 0; }
	virtual double value()const { return 0; }
	virtual ~Shape(){}
	/*Shape(const Shape& s) :m_RGB(s.m_RGB) {
		cout << "copy construct Shape" << endl;
	}
	~Shape() { cout << "detruct Shape" << endl; }
	Shape& operator=(Shape& s) {
		if (this != &s) {
			m_RGB = s.m_RGB;
		}
		cout << "Shape endow" << endl;
		return *this;
	}*/
};

bool operator < (const Shape& s1, const Shape& s2) {
	if (s1.length() != 0 && s2.length() != 0) {
		return s1.length() < s2.length();
	}
	else if (s1.area() != 0 && s2.area() != 0) {
		return s1.area() < s2.area();
	}
	else  {
		return s1.volumn() < s2.volumn();
	}
}
class Point :public Shape {
protected:
	double m_x, m_y;
public:
	Point() { };
	Point(double x, double y,const string &s="") :m_x(x), m_y(y), Shape(s) {}
	Point(const Point& p) :m_x(p.m_x), m_y(p.m_y),Shape(p.m_name) {
		
	}
	~Point() { }
	Point& operator=(const Point& p) {
		if (this != &p) {
			m_x = p.m_x;
			m_y = p.m_y;
			m_name= p.m_name;
		}
		return *this;
	}
	double area() const{ return 0; }
	double& x() { return m_x; }
	const double& y() { return m_y; }
	double length(const Point& p) {
		return sqrt(abs(this->m_x - p.m_x) * abs(this->m_x - p.m_x) + abs(this->m_y - p.m_y) * abs(this->m_y - p.m_y));
	}
};

class Circle :public Point {
protected:
	double m_radius;
	Point m_centre;
public:
	Circle() { }
	Circle(const Point& p, double r) :m_centre(p), m_radius(r) {}
	Circle(const Circle& c) :m_centre(c), m_radius(c.m_radius) {}
	~Circle() {}
	Circle& operator=(const Circle& c) {
		if (this != &c) {
			m_x = c.m_x;
			m_y = c.m_y;
			m_radius = c.m_radius;
		}
		cout << "circle endow" << endl;
		return *this;
	}
	double area() const{return   std::atan(1.0) * 4 * (m_radius*m_radius); }
};


class Segement :public Point {
protected:
	Point m_p1;
	Point m_p2;
public:
	Segement() = default;
	Segement(const Point& a, const Point& b) :m_p1(a), m_p2(b){}
	double area() const { return 0; }
	double length()const {
		Point temp=m_p1;
		return temp.length(m_p2);
	}
};
class  triangle:public Segement {
protected:
	Segement m_t1;
	Segement m_t2;
public:
	triangle(const Segement &a,const Segement &b):m_t1(a),m_t2(b){}
	double area()const { return 0.5 * m_t1.length() * m_t2.length(); }
};

class  rectangle :public Segement {
protected:
	Segement m_r1;
	Segement m_r2;
public:
	rectangle() = default;
	rectangle(const Segement&a, const Segement&b):m_r1(a), m_r2(b) {}
	double area()const { return  m_r1.length() * m_r2.length(); }
};

class cuboid :public rectangle{//长方体
protected:
	rectangle m_cu;
	double m_cuheight;
	double m_cuvalue;
public:
	cuboid(const rectangle &a,const double &b,const double &c):m_cu(a),m_cuheight(b),m_cuvalue(c){}
	double volumn() const { return m_cu.area()* m_cuheight; }//我去，不加const就不能实现动态绑定,可能函数不是完全相同
	double value()const { return m_cuvalue; }
};
class Column :public Circle{//圆柱
protected:
	Circle m_c1;
	double m_coheight;
	double m_covalue;
public:
	Column() = default;
	Column(const Circle& c1,const double &c2,const double &c3):m_c1(c1),m_coheight(c2),m_covalue(c3){}//参数之前不加const会报类型无法转换
	double volumn() const { return m_c1.area() * m_coheight; }
	double value()const { return m_covalue; }
};

class Cone :public Circle {//圆锥
protected:
	Circle m_cone;
	double m_coneheight;
	double m_conevalue;
public:
	Cone(const Circle& c1, const double& c2,const double& c3) :m_cone(c1), m_coneheight(c2), m_conevalue(c3) {}
	double volumn() const{ return (1.0/3.0)*m_cone.area() * m_coneheight; }
	double value()const { return m_conevalue; }
};

class basket {
protected:
	vector<const Shape*> m_vector;
	double m_finalvalue;
public:
	basket() = default;
	basket(const double &s):m_finalvalue(s){}
	void push_back(const Shape &s);
	void sort();
	void valuerate();
	void place();
	void printchoose(vector<int>&);
	void print(vector<const Shape*>&);

};
void basket::push_back(const Shape &s){
	if (s.volumn() != 0) {
		m_vector.push_back(&s);
	}
	else cout << "该Shape不能放进容器" << endl;
}

 void basket::sort(){
	const Shape* temp = new Shape;
	 for (int i = 0; i < m_vector.size(); i++) {
		 for (int j = 0; j < m_vector.size() - 1; j++) {
			 if (m_vector.at(j)->volumn() < m_vector.at(j + 1)->volumn()) {
				 temp = m_vector.at(j);
				 m_vector.at(j) = m_vector.at(j + 1);
				 m_vector.at(j + 1) = temp;
			 }
		 }
	 }
}

 void basket::valuerate(){
	 const Shape* temp = new Shape;
	 for (int i = 0; i < m_vector.size(); i++) {
		 for (int j = 0; j < m_vector.size() - 1; j++) {
			 if ((m_vector.at(j)->value()/ m_vector.at(j)->volumn()) > (m_vector.at(j+1)->value()/ m_vector.at(j + 1)->volumn())) {
				 temp = m_vector.at(j);
				 m_vector.at(j) = m_vector.at(j + 1);
				 m_vector.at(j + 1) = temp;
			 }
		 }
	 }
 }

 void basket::place(){
	 this->valuerate();
	 print(m_vector);
	 vector<const Shape*> m_vector1;
	 vector<int> ischoose;
	 while (m_finalvalue >=0&&m_vector.size()>0) {
		 if (m_finalvalue >= m_vector.at(m_vector.size() - 1)->volumn()) {
			 m_vector1.push_back(m_vector.at(m_vector.size() - 1));
			 m_finalvalue -= m_vector.at(m_vector.size() - 1)->volumn();
			 m_vector.pop_back();
			 ischoose.push_back(1);
		 }
		 else {
			 m_vector.pop_back();//说明这个虽然价值率高但是没有这么多容量了，换个小的
			 ischoose.push_back(0);
		 }
	 }
	 m_vector = m_vector1;
	 printchoose(ischoose);
	 
 }

void basket::printchoose(vector<int>&s1){
	cout << "最优方案：";
	for (int i = s1.size()-1; i >= 0; i--) {
		cout<<s1.at(i);
	}
	cout << endl;
 }
void basket::print(vector<const Shape*>&s1) {
	cout << "basket容量：" << m_finalvalue<<endl;
	
	for (int i = 0; i <s1.size(); i++) {
		cout << "物品容量：";
		cout<< s1.at(i)->volumn() << endl;
		cout << "物品价值：" << s1.at(i)->value() << endl;
	}
}


