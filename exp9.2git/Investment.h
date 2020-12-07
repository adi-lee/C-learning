#pragma once
#pragma once
#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;
class Person;
class Investment {
	friend class Person;
protected:
	double m_capital;

public:
	Investment() = default;
	Investment(const double& s) :m_capital(s) {}
	virtual double settlement()const { return 0; }
};
class Fund :public Investment {
protected:

public:
	Fund() = default;
	Fund(const double& p) :Investment(p) {}
	double settlement()const {
		srand((unsigned)time(NULL));
		return  m_capital * (rand() % 20 + 90) / 100;
	}
	double& captial() { return m_capital; }
};

class Saving :public Investment {
protected:

public:
	Saving() = default;
	Saving(const double& p) :Investment(p) {}
	double settlement()const {
		return  m_capital * (1 + 1.78 / 100);
	}
	double& captial() { return m_capital; }
};
class Person {
protected:
	double m_principal;

public:
	vector<const Investment*> m_invest;
	Person(const double& s) :m_principal(s) {
		m_invest.reserve(100);
	}

	void addInvest(const Investment&);
	double settle();
	double& princinpal() { return m_principal; }
};

void Person::addInvest(const Investment& f) {
	m_principal -= f.m_capital;

	m_invest.push_back(&f);
}
double Person::settle()
{
	for (int i = m_invest.size() - 1; i >= 0; i--) {
		//Investment* p = m_invest.at(i);
		m_principal = m_principal + m_invest.at(i)->settlement();//¶¯Ì¬°ó¶¨
		m_invest.pop_back();
	}
	return m_principal;
}

