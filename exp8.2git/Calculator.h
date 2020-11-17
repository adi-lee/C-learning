#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;
class Calculator {
private:
	stack<double>m_num;
	stack<char>m_opr;
	stack<string>m_fcn;
	int precedence(const char& s)const;//定义优先级函数
	double readNum(string::const_iterator& it);//如果遇到数字，判断数字多长，是1位两位还是……
	string readFcn(string::const_iterator& it);
	void calculate();
	void calculateFcn();
	bool isNum(string::const_iterator& c)const {
		return *c >= '0' && *c <= '9' || *c == '.';
	}
	bool isFcn(string::const_iterator& c)const {
		return *c >= 'a' && *c<= 'z';
	}
public:
	Calculator() { m_opr.push('#'); }
	double doIt(const string& exp);
	/*~Calculator() { m_num.empty(); m_opr.empty(); }*/
};
int Calculator::precedence(const char& s)const {
	switch (s) {
	case'=':return 0;
	case'#':return 1;
	case'+':case'-':return 2;
	case'*':case'/':case'%':return 3;
	case'^':return 4;
	case'(':case')':return 5;
	/*case's':*/

	}
}
double Calculator::readNum(string::const_iterator& it) {
	string t;
	while (isNum(it))
		t += *it++;
	return stod(t);//string to double
}
string Calculator::readFcn(string::const_iterator& it) {
	string t;
	while (isFcn(it))
		t += *it++;
	return t;
}

void Calculator::calculateFcn() {
	double a = m_num.top();
	m_num.pop();
	if (m_fcn.top() == "sin")
		m_num.push(sin(a));
	else if (m_fcn.top() == "cos")
		m_num.push(cos(a));
	else if (m_fcn.top() == "tan")
		m_num.push(tan(a));
	else if (m_fcn.top() == "sqrt")
		m_num.push(sqrt(a));
}
void Calculator::calculate() {
	double b = m_num.top();
	m_num.pop();
	double a = m_num.top();
	m_num.pop();
	if (m_opr.top() == '+') {
		m_num.push(a + b);
		m_opr.pop();
	}
	else if (m_opr.top() == '-') {
		m_num.push(a - b);
		m_opr.pop();
	}
	else if (m_opr.top() == '*') {
		m_num.push(a * b);
		m_opr.pop();
	}
	else if (m_opr.top() == '/') {
		m_num.push(a / b);
		m_opr.pop();
	}
	else if (m_opr.top() == '^') {
		m_num.push(pow(a,b));
		m_opr.pop();//求幂
	}
	/*else if (m_opr.top() == '%') {
		m_num.push(a % b);
		m_opr.pop();
	}*///两个double类型的数据求余？
	
	
}
double Calculator::doIt(const string& exp) {
	int flag = 0;
	m_num.empty();//老师书上是自定义的stack
	for (auto it = exp.begin(); it != exp.end();)
	{
		if (isNum(it)) {
			m_num.push(readNum(it));
			if (flag == 1) {
				calculateFcn();
				flag = 0;
			}
		}
		else if (isFcn(it)) {
			string t = readFcn(it);
			if (t == "pi") {
				m_num.push(std::atan(1.0) * 4);
				flag = 0;
				calculateFcn();
			}
			else {
				/*m_fcn.push(readFcn(it));*///这样写的又进行一次readFcn
				m_fcn.push(t);
				flag = 1;
			}
		}
		
		else {
			
			while (precedence(*it) <= precedence(m_opr.top())&&m_opr.top() != '(') {
				if (m_opr.top() == '#')
					break;
				 if (m_opr.top() != ')') {
					 calculate();
				 }
				if (m_opr.top() == ')') {
					m_opr.pop();
					if (m_opr.top() == '(') {
						m_opr.pop();
					}
					else calculate();
					if (m_opr.top() == '(') {
						m_opr.pop();
					}
				}
			/*if (*it == '=' && m_opr.top() == '(') { m_opr.pop(); calculate(); }	*/
			/*if ((*it == '*'|| *it == '-'|| *it == '+'|| *it == '/') && m_opr.top() == '(') {
				m_opr.push(*it);
				++it;
			}*/
			}
			if (*it == '=' && m_opr.top() == '(') { m_opr.pop(); calculate(); }
			if (*it != '=') 
				m_opr.push(*it);
				++it;
			
		}
	}
	return m_num.top();
}

//当运算符栈顶为‘（’，而输入运算符为‘）’时，直接出栈不运算
//这个计算器还是做不到任意带括号的加减乘除