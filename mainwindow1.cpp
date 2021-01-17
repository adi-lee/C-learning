#include "mainwindow1.h"
#include "ui_mainwindow1.h"

#include<QFile>
#include<QDebug>
#include<QTextStream>
#include<fstream>
#include<QTextCodec>
MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    connect(this,&MainWindow1::Userid,&sti1,&student_inquiry::acceptdata);

}

MainWindow1::~MainWindow1()
{
    delete ui;
 }

void MainWindow1::on_pushButton_2_clicked()
{  sti1.show();
   //this->hide();
   this->senddata();
}

void MainWindow1::accept(const QString& userid){

    ui->label->setText(userid);
  m_userID=userid;
}
void MainWindow1::senddata(){
   // emit Userid(m_userID);
    emit Userid(ui->label->text());
}

void MainWindow1::on_pushButton_clicked()
{   QString str1;
    QByteArray arr;
  //  MyVector<QString> vector;
   // QTextCodec *codec = QTextCodec::codecForName("GBK");
    ui->label_3->setText(tr("学号:"));
    ui->label_4->setText(tr("姓名:"));
    ui->label_5->setText(tr("班级:"));
    ui->label_6->setText(tr("专业:"));
    std::ifstream file1;
       file1.open("student.txt");
      std::string temp;
           if (!file1){
               qDebug()<<"open file failed";
           }
           else {
               while (!file1.eof()){
                   file1>>temp;
                    str1=QString::fromStdString(temp);
                   if (str1==m_userID){
                           ui->label_7->setText(str1);//显示学号
                           file1>>temp;
                            str1=QString::fromStdString(temp);
                            ui->label_8->setText(str1);//显示姓名
                            file1>>temp;
                             str1=QString::fromStdString(temp);
                            ui->label_9->setText(str1);//显示班级
                            file1>>temp;
                             str1=QString::fromStdString(temp);
                             ui->label_10->setText(str1);//显示专业
                               break;
                         file1.close();//打开文件 尝试
                   }
               }
           }
}





void MainWindow1::on_pushButton_4_clicked()
{
QMainWindow::close();
}
