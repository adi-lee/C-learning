#ifndef STUDENT_H
#define STUDENT_H
#include"person.h"
class student :public person {
public:
    QString m_classnum;//班号
    QVector<QString> m_course;
    QVector<QString> m_weicourse;
    QVector<QString> m_choosecourse;
    double m_credit;//已经学过的累积学分
    QString m_major;
public:
    student() = default;
    student(QString &name,int &sex,int&age,QString &id,QString &classnum,QVector<QString> &course , double &credit){
        m_name = name;
        m_sex = sex;
        m_age = age;
        m_ID = id;
        m_classnum = classnum;
        m_course = course;
        m_credit = credit;
    }
    student(QString &name,QString &id,QString &classnum,QString &major){
        m_name = name;
        m_ID = id;
        m_classnum = classnum;
        m_major=major;
    }
//    student(QString& name) {
//        m_name = name;
//    }
};

#endif // STUDENT_H
