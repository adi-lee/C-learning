#include<iostream>
#include<string>
using namespace std;

template <typename T >
void Swap(T& a, T& b) //构建交换函数模板
{
	T c = a;
	a = b;
	b = c;
}

int main() 
{
	double i, j;
	cout << "please input two values:" << endl;
	cin >> i >> j;
	Swap(i, j);
	cout << i << " " << j << endl;
	
	string s1, s2;
	cout << "please input two strings:" << endl;
	cin >> s1 >> s2;
	Swap(s1, s2);
	cout << s1 << " " << s2 << endl;
	system("pause");
		return 0;

}