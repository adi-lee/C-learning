#include "student_inquiry.h"
#include "ui_student_inquiry.h"
#include<QFile>
#include<QDebug>
student_inquiry::student_inquiry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_inquiry)
{
    ui->setupUi(this);

}

student_inquiry::~student_inquiry()
{
    delete ui;
}

void student_inquiry::on_pushButton_clicked()
{m_course=ui->lineEdit->text();
        QString str1;
        QFile file1 ("score.txt");
            if (!file1.open(QIODevice::ReadOnly|QIODevice::Text)){
                qDebug()<<"open file failed";
            }
            else {
                QTextStream in(&file1);//读取
                while (!file1.atEnd()){
                    //ui->lineEdit->setText(file.readLine());
                    in>>str1;
                    if (str1==m_userID){
                        in>>str1;
                        in>>str1;
                        if (str1==m_course){
                            flag2=1;
                            in>>str1;
                           ui->label_3->setText(str1);
                            break;
                        }
                    }
                }
               if(flag2==0){
                   ui->label_3->setText("weichaxundao");
               }
            }
            file1.close();//打开文件 尝试
}

void student_inquiry::acceptdata(const QString& userid){
    m_userID=userid;
}

void student_inquiry::on_pushButton_2_clicked()
{
       this->hide();
}
