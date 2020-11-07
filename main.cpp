#include"set.h"
int main() {
	vector<char>temp1 = { 'a','s','d','f','g' };
	vector<char>temp2 = { 'a','c','v','f','t','y','e','r' };
	vector<int >temp3 = {1,2,3,4,5,6,7,8,9};
	vector<int >temp4 = { 98,76,5,43,2,1,};
	//vector<string>temp5 = {"kkpk","fdf"};
	char a ,b ,c,d;
	Set<char> s1(temp1), s2(temp2), s4,s6;//注意更换时有很多东西要改
	/*int a, b, c, d;
	Set<int> s1(temp3), s2(temp4), s4, s6;*/


	cout << "判断元素是否在s1集合中\n" << "请输入元素：" ;
	cin >> a;
	s1.is_elem(a);
	if (s1.is_elem(a)) {
		cout << "元素" << a << "在该集合中" << endl;
	}
	else {
		cout << "元素" << a << "不在该集合中" << endl;
	}//判断元素是否在s1集合中
	
	cout << "向s1中插入元素\n" << "请输入元素：" ;
	cin >> b;
	s1.insert(b);
	cout << "s1={" << s1 << "}" << endl;

	cout << "删除s2中的元素\n" << "请输入元素：" ;
	cin >> c;
	s2.erase(c);
	cout << "s2={" << s2 << "}" << endl;

	Set <char> s3(s1);
	/*Set <int> s3(s1);*/
	s3 = s3.common(s2);
	cout << "s1和s2的交集:" << "s3={" << s3 << "}" << endl;

	s4 = s2.sum(s1);
	cout << "s1和s2的并集："<<"s4={" << s4 << "}" << endl;

	Set<char> s5(s1);//复制
	//Set<int> s5(s1);
	cout << "利用复制构造函数复制s1:"<<"s5={" << s5 << "}" << endl;
	s5 = s4;//赋值
	cout << "利用赋值运算符将s4赋值给s5:"<<"s5={" << s5 << "}" << endl;

	cout << "查找元素在s1集合中的位置，请输入要查询的元素:" ;
	cin >> d;
	s1.find(d);

	s5.clear(s5);
	cout << "将s5中的元素全部删除" <<"s5={"<< s5 <<"}" <<endl;
    cout << "s1集合中的元素个数:" ;
	s1.length();
	s1.Swap(s1,s2);
	cout << "变换内容后s1={" << s1 << "}" << "s2={" << s2 << "}" << endl;
	system("pause");
}