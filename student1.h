#pragma once
#include"person.h"
class student :public person {
public:
    std::string m_classnum;//���
    QVector<std::string> m_course;//��Ҫѧһ��map�����������÷�
    double m_credit;//�Ѿ�ѧ�����ۻ�ѧ��
public:
    student() = default;
    student(QString &name,int &sex,int&age,QString &id,std::string &classnum,QVector<std::string> &course , double &credit){
        m_name = name;
        m_sex = sex;
        m_age = age;
        m_ID = id;
        m_classnum = classnum;
        m_course = course;
        m_credit = credit;
    }
//    student(QString& name) {
//        m_name = name;
//    }
};

