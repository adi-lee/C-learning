#pragma once
//#include"person.h"//既然包含student.h就没必要包含person
#include"student.h"
#include"math.h"
//#include<QVector>
#include<fstream>
#include<QFile>
#include<QFileDevice>
#include<QTextStream>
class teacher :public person {
private:
    void file();//我并不希望任何人都有查看信息的权力
public:
   QVector<QString> m_teach;//所教的课程
   int flag1=0;//由名字查询学号标志位
   int flag2=0;//成绩修改标志位
public:
    teacher() = default;
    teacher(QString &name, int &sex, int& age, QString& id, QVector<QString>& teach){
        m_name = name;
        m_sex = sex;
        m_age = age;
        m_ID = id;
        m_teach = teach;
    }
    QVector<QString> search_score(const QString& name);//查找某学生的课程成绩
    QVector<QString> search_name(QString& str,double& scoremin, double& scoremax);//查找某分数段的学生名单
     QVector<QString> search_statics(QString& coursename);//某个课程的成绩分析
     QVector<QString> sort(QString &coursename);//成绩排序
    bool xiugai(QString &,QString &,QString &);//成绩修改
    QString namechaxuehao(QString &);//由学生姓名查找学号

};
