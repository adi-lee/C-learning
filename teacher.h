#pragma once
//#include"person.h"//��Ȼ����student.h��û��Ҫ����person
#include"student.h"
#include"math.h"
//#include<QVector>
#include<fstream>
#include<QFile>
#include<QFileDevice>
#include<QTextStream>
class teacher :public person {
private:
    void file();//�Ҳ���ϣ���κ��˶��в鿴��Ϣ��Ȩ��
public:
   QVector<QString> m_teach;//���̵Ŀγ�
   int flag1=0;//�����ֲ�ѯѧ�ű�־λ
   int flag2=0;//�ɼ��޸ı�־λ
public:
    teacher() = default;
    teacher(QString &name, int &sex, int& age, QString& id, QVector<QString>& teach){
        m_name = name;
        m_sex = sex;
        m_age = age;
        m_ID = id;
        m_teach = teach;
    }
    QVector<QString> search_score(const QString& name);//����ĳѧ���Ŀγ̳ɼ�
    QVector<QString> search_name(QString& str,double& scoremin, double& scoremax);//����ĳ�����ε�ѧ������
     QVector<QString> search_statics(QString& coursename);//ĳ���γ̵ĳɼ�����
     QVector<QString> sort(QString &coursename);//�ɼ�����
    bool xiugai(QString &,QString &,QString &);//�ɼ��޸�
    QString namechaxuehao(QString &);//��ѧ����������ѧ��

};
