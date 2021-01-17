#pragma once
#include"person.h"
class student :public person {
public:
    std::string m_classnum;//班号
    QVector<std::string> m_course;//需要学一下map关联容器的用法
    double m_credit;//已经学过的累积学分
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

