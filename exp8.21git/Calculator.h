#include<iostream>
#include"Stack.h"
#include<string>
using namespace std;
class Calculator {
private:
	Stack<double>m_num;
	Stack<char>m_opr;
	Stack<string>m_fcn;
	int precedence(const char& s)const;//定义优先级函数
	double readNum(string::const_iterator& it);
	string readFcn(string::const_iterator& it);
	void calculate();
	void calculateFcn();
	bool isNum(string::const_iterator& c)const {
		return *c >= '0' && *c <= '9' || *c == '.';
	}
	bool isFcn(string::const_iterator& c)const {
		return *c >= 'a' && *c <= 'z';
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
	case'+':case'-':return 2;//两个case还可以这么用吗
	case'*':case'/':case'%':return 3;
	case'^':return 4;
	case'(':case')':return 6;
	case'5':return 5;
	}
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
	m_fcn.pop();
	m_opr.pop();
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
void Calculator::calculate() {
	double b = m_num.top();
	m_num.pop();
	double a = m_num.top();
	m_num.pop();
	if (m_opr.top() == '+'){
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
		m_num.push(pow(a, b));
		m_opr.pop();//求幂
	}
	else if (m_opr.top() == '%') {
		m_num.push(fmod(a, b));
		m_opr.pop();
	}
}
double Calculator::doIt(const string& exp) {
	m_num.empty();//老师书上是自定义的stack
	for (auto it = exp.begin(); it != exp.end();)
	{
		if (isNum(it)) {
			m_num.push(readNum(it));
		}
		else if (isFcn(it)) {
			string t = readFcn(it);
			if (t == "pi") {
				m_num.push(std::atan(1.0) * 4);
			}
			else {
				/*m_fcn.push(readFcn(it));*///这样写的话又进行一次readFcn
				m_fcn.push(t);

				m_opr.push('5');
			}
		}
		else {
			while (precedence(*it) <= precedence(m_opr.top())) {
				if (m_opr.top() == '5') {
					calculateFcn();
				}
				else if (m_opr.top() != ')' && m_opr.top() != '5' && m_opr.top() != '(') {
					calculate();
				}
				if (m_opr.top() == '#')
					break;
				else if (m_opr.top() == '(') {
					break;
				}

				if (m_opr.top() == ')') {
					m_opr.pop();
					while (m_opr.top() != '(') {
						if (m_opr.top() != '5')
						{
							calculate();
						}
						if (m_opr.top() == '5') {
							calculateFcn();
						}
					}
					if (m_opr.top() == '(') {
						m_opr.pop();
					}
				}
			}
			if (*it != '=')
				m_opr.push(*it);
			++it;
		}
	}
	return m_num.top();
}
