#include"set.h"
int main() {
	vector<char>temp1 = { 'a','s','d','f','g' };
	vector<char>temp2 = { 'a','c','v','f','t','y','e','r' };
	vector<int >temp3 = {1,2,3,4,5,6,7,8,9};
	vector<int >temp4 = { 98,76,5,43,2,1,};
	//vector<string>temp5 = {"kkpk","fdf"};
	char a ,b ,c,d;
	Set<char> s1(temp1), s2(temp2), s4,s6;//ע�����ʱ�кܶණ��Ҫ��
	/*int a, b, c, d;
	Set<int> s1(temp3), s2(temp4), s4, s6;*/


	cout << "�ж�Ԫ���Ƿ���s1������\n" << "������Ԫ�أ�" ;
	cin >> a;
	s1.is_elem(a);
	if (s1.is_elem(a)) {
		cout << "Ԫ��" << a << "�ڸü�����" << endl;
	}
	else {
		cout << "Ԫ��" << a << "���ڸü�����" << endl;
	}//�ж�Ԫ���Ƿ���s1������
	
	cout << "��s1�в���Ԫ��\n" << "������Ԫ�أ�" ;
	cin >> b;
	s1.insert(b);
	cout << "s1={" << s1 << "}" << endl;

	cout << "ɾ��s2�е�Ԫ��\n" << "������Ԫ�أ�" ;
	cin >> c;
	s2.erase(c);
	cout << "s2={" << s2 << "}" << endl;

	Set <char> s3(s1);
	/*Set <int> s3(s1);*/
	s3 = s3.common(s2);
	cout << "s1��s2�Ľ���:" << "s3={" << s3 << "}" << endl;

	s4 = s2.sum(s1);
	cout << "s1��s2�Ĳ�����"<<"s4={" << s4 << "}" << endl;

	Set<char> s5(s1);//����
	//Set<int> s5(s1);
	cout << "���ø��ƹ��캯������s1:"<<"s5={" << s5 << "}" << endl;
	s5 = s4;//��ֵ
	cout << "���ø�ֵ�������s4��ֵ��s5:"<<"s5={" << s5 << "}" << endl;

	cout << "����Ԫ����s1�����е�λ�ã�������Ҫ��ѯ��Ԫ��:" ;
	cin >> d;
	s1.find(d);

	s5.clear(s5);
	cout << "��s5�е�Ԫ��ȫ��ɾ��" <<"s5={"<< s5 <<"}" <<endl;
    cout << "s1�����е�Ԫ�ظ���:" ;
	s1.length();
	s1.Swap(s1,s2);
	cout << "�任���ݺ�s1={" << s1 << "}" << "s2={" << s2 << "}" << endl;
	system("pause");
}