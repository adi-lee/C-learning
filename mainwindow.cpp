#include "mainwindow.h"

#include "ui_mainwindow.h"

#include<string>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie(":/new/prefix1//image/100.gif");
    ui->label_20->setMovie(movie);
    movie->start();
   connect(this,&MainWindow::Username,&w1,&MainWindow1::accept);
   //connect(&w1,&MainWindow1::on_pushButton_4_clicked,this,&MainWindow::accept);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()//教师登录标志
{
     flag1=1;
}

void MainWindow::on_pushButton_2_clicked()//学生登录标志
{
    flag1=2;
}

void MainWindow::on_pushButton_3_clicked()//管理员登录标志
{
    flag1=3;
}

void MainWindow::on_pushButton_5_clicked()//关闭按钮
{
     QMainWindow::close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString username,password;

    username=ui->lineEdit->text();//获取用户工号
    password=ui->lineEdit_2->text();//获取用户登录密码
    switch(flag1){
        case 0://不选择模式直接报错，日后再进行更加人性化的设置

            ui->label->setText("the ID or key is not ture, please try again");
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();//实现输入错误会报错，并清空输入
            ui->label_21->setText("the ID or password maybe wrong,please try again");
            break;
        case 1:{//对应教师模块
            std::ifstream file1;
            file1.open("staff.txt");
            QString str1;
           std::string temp;
                if (!file1){
                    qDebug()<<"open file failed";
                }

                else {

                    while (!file1.eof()){
                        //getline(file1,temp);
                        file1>>temp;
                         str1=QString::fromStdString(temp);

                        if (str1==username){ //这里的username实际上是工号
                            myvector.push_back(str1);
                            if (str1==password){
                                qDebug()<<"sucessfully login";
                                flag3=1;

                            }
                            else if (str1!=password){
                                qDebug()<<"not sucessfully login";
                                break;
                            }
                           while(file1.get()!='\n'){
                            file1>>temp;
                            str1=QString::fromStdString(temp);
                            myvector.push_back(str1);
                           }
                        }

                    }
                }
                file1.close();//打开文件 尝试
        break;
        }
    case 2://学生登录
    {
        std::ifstream file1;
        file1.open("student.txt");
        QString str1;
       std::string temp;
            if (!file1){
                qDebug()<<"open file failed";
            }

            else {

                while (!file1.eof()){
                    //getline(file1,temp);
                    file1>>temp;
                     str1=QString::fromStdString(temp);

                    if (str1==username){ //这里的username实际上是学号
                        myvector.push_back(str1);
                        if (str1==password){
                            qDebug()<<"sucessfully login";
                            flag3=1;

                        }
                        else if (str1!=password){
                            qDebug()<<"not sucessfully login";
                            break;
                        }
                        file1>>temp;
                        str1=QString::fromStdString(temp);
                        myvector.push_back(str1);
                        file1>>temp;
                        str1=QString::fromStdString(temp);
                        myvector.push_back(str1);
                        file1>>temp;
                        str1=QString::fromStdString(temp);
                        myvector.push_back(str1);
                    }

                }
            }
            file1.close();//打开文件 尝试
       }
    case 3:
    {
        std::ifstream file1;
        file1.open("administrator.txt");
        QString str1;
       std::string temp;
            if (!file1){
                qDebug()<<"open file failed";
            }
            else {
                while (!file1.eof()){

                    file1>>temp;
                     str1=QString::fromStdString(temp);
                    if (str1==username){
                        file1>>temp;
                        str1=QString::fromStdString(temp);
                        if (str1==password){
                            qDebug()<<"sucessfully login";
                            flag3=1;
                            break;
                        }
                        else if (str1!=password){
                            qDebug()<<"not sucessfully login";
                            break;
                        }
                    }
                    else {
                       file1>>temp;//保证读取正确
                    }
                }
            }
             file1.close();
        break;
       }
    }
    if(flag3==1&&flag1==2){//学生登录并且登陆成功
//        w1.show();
//      this->send();
//        this->hide();//这三行注释将主窗口1与主窗口断开连接
        stu.m_ID=myvector[0];
        stu.m_name=myvector[1];
        stu.m_classnum=myvector[2];
        stu.m_major=myvector[3];
        ui->page->hide();
        ui->page_8->show();
        ui->page_10->hide();
        ui->page_11->hide();
        ui->label_57->setText(stu.m_ID);
        flag3=0;
    }//学生类
   else if(flag3==1&&flag1==1){//教师登录并且登陆成功
        ui->page_2->show();
        ui->page->hide();

         ui->widget_18->show();
        tea.m_ID=myvector[0];//嘿嘿，直接把m_ID改成QString
        tea.m_name=myvector[1];
         ui->label_51->setText(tea.m_ID);
         ui->label_53->setText(tea.m_ID);
        for(int i=2;i<myvector.size();i++){
        tea.m_teach.push_back(myvector[i]);
        flag3=0;
        }
    }//初始化教师类
   else if(flag3==1&&flag1==3){//管理员登录并且登陆成功
       ui->page_15->show();
       ui->page_16->hide();
       ui->page_17->hide();
       ui->page_7->hide();
       ui->page->hide();
        ui->widget_17->show();
         ui->label_55->setText(username);
         flag3=0;
    }
    else{
        ui->label->setText("the ID or key is not ture, please try again");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();//实现输入错误会报错，并清空输入
        ui->label_21->setText("the ID or password maybe wrong,please try again");
    }
}
void MainWindow::send(){
    emit Username(ui->lineEdit->text());
}
//void MainWindow::accept(){
//    this->show();
//    w1.hide();
//}

void MainWindow::on_pushButton_6_clicked()//归属教师模块，教师信息查询，页面2
{
    ui->label_2->setText(tr("工号:"));
    ui->label_3->setText(tr("姓名:"));
    ui->label_4->setText(tr("教授课程:"));
    ui->label_5->setText(myvector[0]);
    ui->label_6->setText(myvector[1]);
    for(int i=2;i<myvector.size();i++){
    ui->textEdit->append(myvector[i]);
    }

}

void MainWindow::on_pushButton_7_clicked()//归属教师模块，查询成绩入口，页面2
{
    ui->page_4->show();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_9->hide();
    ui->page_2->hide();
}

void MainWindow::on_pushButton_9_clicked()//归属教师模块，通过名字查询成绩，页面3
{
    QString temp=ui->lineEdit_3->text();
    QString temp1;
    QVector<QString> temp2= tea.search_score(temp);
    for(int i=0;i<temp2.size();i++){
        ui->textEdit_2->append(temp2[i]);
    }
}

void MainWindow::on_pushButton_10_clicked()//页面3退出按键，顺便清除页面3的内容
{
    ui->page_2->show();
    ui->page_3->hide();
    ui->textEdit_2->clear();
    ui->lineEdit_3->clear();
}

void MainWindow::on_pushButton_11_clicked()//依据名字查询成绩
{
   ui->page_5->show();
   ui->page_6->hide();
   ui->page_9->hide();
   ui->page_22->hide();
   ui->widget_18->hide();
}

void MainWindow::on_pushButton_14_clicked()
{
    QString temp=ui->lineEdit_4->text();
    QString temp1;
    QVector<QString> temp2= tea.search_score(temp);
    for(int i=0;i<temp2.size();i++){
        ui->textEdit_3->append(temp2[i]);
    }
}

void MainWindow::on_pushButton_12_clicked()//查询某门课的成绩分布按键
{
    ui->page_6->show();
    ui->page_5->hide();
    ui->page_9->hide();
    ui->page_22->hide();
     ui->widget_18->hide();
}

void MainWindow::on_pushButton_16_clicked()//page6的确定按钮，对应查询某门课的成绩分布按键
{   QString coursename=ui->lineEdit_5->text();
    QString scoremin=ui->lineEdit_6->text();
    QString scoremax=ui->lineEdit_7->text();
    double temp=scoremin.toDouble();
    double temp1=scoremax.toDouble();
    QVector<QString> temp2= tea.search_name(coursename,temp,temp1);
    for(int i=0;i<temp2.size();i++){
        ui->textEdit_4->append(temp2[i]);
    }

}

void MainWindow::on_pushButton_15_clicked()//页面4退出按键
{
    ui->page_4->hide();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_2->show();
}

void MainWindow::on_pushButton_13_clicked()//页面4成绩分析按钮
{
    ui->page_4->show();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_22->hide();
    ui->page_9->show();
     ui->widget_18->hide();

}

void MainWindow::on_pushButton_34_clicked()//页面4成绩修改按钮
{
    ui->page_4->show();
    ui->page_5->hide();
    ui->page_6->hide();
    ui->page_22->show();
    ui->page_9->hide();
     ui->widget_18->hide();

}

void MainWindow::on_pushButton_35_clicked()//页面22 成绩修改确定按钮
{QString name,course,grade;
    name=ui->lineEdit_9->text();
    course=ui->lineEdit_10->text();
     grade=ui->lineEdit_11->text();
   if(tea.xiugai(name,course,grade)){
       ui->label_42->setText("修改成功");
   }
   else{ui->label_42->setText("修改失败");}
}
void MainWindow::on_pushButton_17_clicked()//页面7的确定按钮
{
    QString coursename=ui->lineEdit_8->text();
    QVector<QString> temp2= tea.search_statics(coursename);
    QVector<QString> temp3= tea.sort(coursename);
    ui->label_27->setText(temp2[0]);//平均分
    ui->label_28->setText(temp2[1]);//及格率
    ui->label_29->setText(temp2[2]);//标准差
    for(int i=0;i<temp3.size();i++){
        ui->textEdit_5->append(temp3[i]);
    }

}

void MainWindow::on_pushButton_8_clicked()//页面2成绩录入按钮
{
    ui->widget_18->hide();
    openFile();

}
void MainWindow::openFile()//打开文件并录入
{
        ui->label_4->setText(tr("成绩录入:"));
        QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));
        if(!path.isEmpty()) {
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Read File"),
                tr("Cannot open file:\n%1").arg(path));
                return;
            }
            QTextStream in(&file);
            in.setCodec("UTF-8");
            ui->textEdit->setText(in.readAll());
            QFile file1("score.txt");
            if (file1.open(QIODevice::ReadWrite |QIODevice::Append )) {
                QTextStream out(&file1);
                out.setCodec("UTF-8");
                out<<ui->textEdit->toPlainText();
            }
            file1.close();
            file.close();
        }
    else {
            QMessageBox::warning(this, tr("Path"),
             tr("You did not select any file."));
         }
}

void MainWindow::on_pushButton_21_clicked()//修改学生信息page15
{
    ui->page_16->show();
    ui->page_17->hide();
    ui->page_7->hide();
     ui->widget_17->hide();
}

void MainWindow::on_pushButton_24_clicked()//添加按钮，学生信息page16
{
    std::ifstream file;
    file.open("student.txt");
    QString str1;
    string str;
    if (file) {

        QFile file1("in.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text|QIODevice::Append )) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(getline(file,str)){
            str1=QString::fromStdString(str);
            out<<str1;
            out<<"\r";
        }
        file.close();
        out<<ui->lineEdit_14->text()<<"\t";//学号
        out<<ui->lineEdit_15->text()<<"\t";//姓名
        out<<ui->lineEdit_16->text()<<"\t";//班级
        out<<ui->lineEdit_17->text()<<"\t";//专业
        out<<"\r";
        file1.close();
        }
        else {
            file.close();
        }

    }
    else{
       return;
    }
}

void MainWindow::on_pushButton_25_clicked()//删除按钮，学生信息page16
{
    std::ifstream file;
    file.open("student.txt");
    QString str1;
    string str;
    QString stud;
    stud+=ui->lineEdit_14->text();
    stud+="\t";//学号
    stud+=ui->lineEdit_15->text();
    stud+="\t";//姓名
    stud+=ui->lineEdit_16->text();
    stud+="\t";//班级
    stud+=ui->lineEdit_17->text();
    stud+="\t";//专业
    stud+="\t";
    stud+="\t";
    qDebug()<<stud;
    if (file) {

        QFile file1("in2.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(getline(file,str)){
            str1=QString::fromStdString(str);
            if (str1!=stud){
                out<<str1;
                qDebug()<<str1;
                out<<"\r";
            }
            else{
                continue;
            }

        }
        file.close();
        file1.close();
        }
        else {
            file.close();
        }

    }
    else{
       return;
    }
}

void MainWindow::on_pushButton_22_clicked()//修改教师信息page15
{
    ui->page_16->hide();
    ui->page_17->show();
    ui->page_7->hide();
     ui->widget_17->hide();
}

void MainWindow::on_pushButton_26_clicked()//增加,教师信息page17
{
    std::ifstream file;
    file.open("staff.txt");
    QString str1;
    string str;
    if (file) {

        QFile file1("staffupdate.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(getline(file,str)){
            str1=QString::fromStdString(str);
            out<<str1;
            out<<"\r";
        }
        file.close();
        out<<ui->lineEdit_18->text()<<"\t";//工号
        out<<ui->lineEdit_19->text()<<"\t";//姓名
        out<<ui->textEdit_7->toPlainText()<<"\t";//教授课程
        out<<"\r";
        file1.close();
        }
        else {
            file.close();
        }

    }
    else{
       return;
    }
}

void MainWindow::on_pushButton_27_clicked()//删除,教师信息page17
{
    std::ifstream file;
    file.open("staff.txt");
    QString str1;
    string str;
    QString stud;
    stud+=ui->lineEdit_18->text();
    stud+=" ";//工号

    stud+=ui->lineEdit_19->text();
    stud+=" ";//姓名

    stud+=ui->textEdit_7->toPlainText();
   //教授课程
    qDebug()<<stud;
    if (file) {

        QFile file1("staffupdate1.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(getline(file,str)){
            str1=QString::fromStdString(str);
            if (str1!=stud){
                out<<str1;
                qDebug()<<str1;
                out<<"\r";
            }
            else{
                continue;
            }

        }
        file.close();
        file1.close();
        }
        else {
            file.close();
        }

    }
    else{
       return;
    }
}

void MainWindow::on_pushButton_23_clicked()//修改课程信息page15
{
    ui->page_16->hide();
    ui->page_17->hide();
    ui->page_7->show();
    ui->widget_17->hide();
}

void MainWindow::on_pushButton_18_clicked()//增加，课程信息page7
{
    std::ifstream file;
    file.open("module.txt");
    QString str1;
    string str;
    if (file) {

        QFile file1("moduleupdate.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(getline(file,str)){
            str1=QString::fromStdString(str);
            out<<str1;
            out<<"\r";
        }
        file.close();
        out<<ui->lineEdit_20->text()<<" ";//课程编号
        out<<ui->lineEdit_21->text()<<" ";//课程名称
        out<<ui->lineEdit_22->text()<<" ";//学分
        out<<"\r";
        file1.close();
        }
        else {
            file.close();
        }

    }
    else{
       return;
    }
}

void MainWindow::on_pushButton_19_clicked()//删除，课程信息page7
{
    std::ifstream file;
    file.open("module.txt");
    QString str1;
    string str;
    QString stud;
    stud+=ui->lineEdit_20->text();
    stud+=" ";//课程编号

    stud+=ui->lineEdit_21->text();
    stud+=" ";//课程名称

    stud+=ui->lineEdit_22->text();
   //学分
    qDebug()<<stud;
    if (file) {

        QFile file1("moduleupdate1.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(getline(file,str)){
            str1=QString::fromStdString(str);
            if (str1!=stud){
                out<<str1;
                qDebug()<<str1;
                out<<"\r";
            }
            else{
                continue;
            }

        }
        file.close();
        file1.close();
        }
        else {
            file.close();
        }

    }
    else{
       return;
    }
}

void MainWindow::on_pushButton_28_clicked()//归属学生模块 查看已修课程 page8
{   ui->page_10->show();
    ui->page_12->hide();
    ui->page_11->hide();
    if (flag2 !=1){//没按过可以进
    flag2=1;

            QString str1;
            string str;
            std::ifstream file;
            file.open("score.txt");
            if(file){
                while (!file.eof()){
                    file>>str;
                    str1=QString::fromStdString(str);
                    if (str1==stu.m_ID){
                        file>>str;
                        file>>str;
                        str1=QString::fromStdString(str);
                        qDebug()<<str1;
                        ui->textEdit_6->append(str1);
                        stu.m_course.push_back(str1);//学过的课程即添加
                    }

                }
                file.close();//打开文件 尝试
            }
          else{
              qDebug()<<"open file failed";
          }
            QString str2;//算累积学分
            string str3;
            std::ifstream file1;
            file1.open("module.txt");
            if(file1){
                while (!file1.eof()){
                    file1>>str3;//课程编号
                    file1>>str3;//课程名称
                    str2=QString::fromStdString(str3);

                    double a;
                    for (int i=0;i<stu.m_course.size();i++){
                        if (str2==stu.m_course[i]){
                            file1>>str3;//学分
                            str2=QString::fromStdString(str3);
                            a=str2.toDouble();
                            stu.m_credit+=a;
                            continue;
                        }
                        else if(i==stu.m_course.size()){
                            file1>>str3;
                        }
                    }
                }
                file1.close();//打开文件 尝试
                str2=QString::number(stu.m_credit);
                ui->label_18->setText(str2);//显示累积学分
            }
          else{
              qDebug()<<"open file failed";
          }
    }
}



void MainWindow::on_pushButton_20_clicked()//归属学生模块 选课 page8
{   ui->page_10->hide();
    ui->page_12->hide();
    ui->page_11->show();
    if(flag5!=2){
    flag5=2;
    int j=1;
    QString js;
    QString str2;
    string str3;
    QString str4;
    std::ifstream file1;
    file1.open("module.txt");
    if(file1){
        while (!file1.eof()){
            int flag4=0;
            file1>>str3;//课程编号
            file1>>str3;//课程名称
            str2=QString::fromStdString(str3);
            for (int i=0;i<stu.m_course.size();i++){
                if (str2==stu.m_course[i]){
                    file1>>str3;//学分
                    flag4=1;//学过标志位置1
                    break;
                }
//                else if(i==stu.m_course.size()){
//                    file1>>str3;
//                }
            }
            if (flag4==0){//没学过加入没学
                file1>>str3;//学分
                stu.m_weicourse.push_back(str2);
                js=QString::number(j);
                str4=QString::fromStdString(str3);
                ui->textEdit_8->append(js);
                ui->textEdit_8->append(str2+" "+str4);
                j++;
            }
        }
        file1.close();//打开文件 尝试

    }
      else{
          qDebug()<<"open file failed";
      }
  }
}

void MainWindow::on_pushButton_30_clicked()//归属教师模块 返回 page2注销
{

    ui->page_2->hide();
    ui->page->show();
    zhuxiao();

}

void MainWindow::on_pushButton_31_clicked()//归属教师模块 返回 page4
{

    ui->page_4->hide();
    ui->page_2->show();
}

void MainWindow::on_pushButton_32_clicked()//归属管理员模块 返回 page15注销
{
    ui->page_15->hide();
    ui->page->show();
    zhuxiao();
}

void MainWindow::on_pushButton_33_clicked()//归属学生模块 返回 page8注销
{
    ui->page_8->hide();
    ui->page->show();
    zhuxiao();

}
void MainWindow::zhuxiao(){
    stu.m_course.clear();
    stu.m_credit=0;
    tea.m_teach.clear();
    myvector.clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->textEdit->clear();
    ui->textEdit_6->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
    ui->textEdit_7->clear();
    ui->textEdit_8->clear();
    ui->textEdit_9->clear();
    ui->textEdit_13->clear();
    ui->textEdit_18->clear();
    flag2=0;flag5=0;

}


void MainWindow::on_checkBox_stateChanged(int arg1)
{int i=1;
    xuanke(arg1,i);
}

void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    int i=2;
        xuanke(arg1,i);

}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    int i=3;
        xuanke(arg1,i);
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    int i=4;
        xuanke(arg1,i);
}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
     int i=5;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_6_stateChanged(int arg1)
{
    int i=6;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_7_stateChanged(int arg1)
{
    int i=7;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_8_stateChanged(int arg1)
{
    int i=8;
        xuanke(arg1,i);
}

void MainWindow::on_checkBox_9_stateChanged(int arg1)
{
   int i=9;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_10_stateChanged(int arg1)
{
    int i=10;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_11_stateChanged(int arg1)
{
    int i=11;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_12_stateChanged(int arg1)
{
     int i=12;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_13_stateChanged(int arg1)
{
   int i=13;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_14_stateChanged(int arg1)
{
     int i=14;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_15_stateChanged(int arg1)
{
    int i=15;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_16_stateChanged(int arg1)
{
    int i=16;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_17_stateChanged(int arg1)
{
    int i=17;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_18_stateChanged(int arg1)
{
    int i=18;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_19_stateChanged(int arg1)
{
    int i=19;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_20_stateChanged(int arg1)
{
   int i=20;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_21_stateChanged(int arg1)
{
    int i=21;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_22_stateChanged(int arg1)
{
     int i=22;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_23_stateChanged(int arg1)
{
   int i=23;
        xuanke(arg1,i);
}
void MainWindow::on_checkBox_24_stateChanged(int arg1)
{
     int i=24;
        xuanke(arg1,i);
}

void MainWindow::xuanke(int&checkbox,int&xuhao){
    if (stu.m_weicourse.size()>xuhao&&checkbox){
        stu.m_choosecourse.push_back(stu.m_weicourse[xuhao-1]);
        ui->textEdit_9->append(stu.m_weicourse[xuhao-1]);
    }
    else return;
}



void MainWindow::on_pushButton_29_clicked()//退选按钮
{
        ui->page_10->hide();
        ui->page_11->hide();
        ui->page_12->show();
        for(int i=0;i<stu.m_choosecourse.size();i++){
            QString a=QString::number(i+1);
            ui->textEdit_13->append(a);
            ui->textEdit_13->append(stu.m_choosecourse[i]);

        }
}

void MainWindow::on_checkBox_52_stateChanged(int arg1)
{
    int i=1;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_55_stateChanged(int arg1)
{
    int i=2;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_61_stateChanged(int arg1)
{
    int i=3;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_60_stateChanged(int arg1)
{
    int i=4;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_50_stateChanged(int arg1)
{
    int i=5;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_54_stateChanged(int arg1)
{
    int i=6;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_64_stateChanged(int arg1)
{
    int i=7;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_57_stateChanged(int arg1)
{
    int i=8;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_59_stateChanged(int arg1)
{
    int i=9;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_66_stateChanged(int arg1)
{
    int i=10;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_71_stateChanged(int arg1)
{
    int i=11;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_53_stateChanged(int arg1)
{
    int i=12;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_72_stateChanged(int arg1)
{
    int i=13;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_65_stateChanged(int arg1)
{
    int i=14;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_58_stateChanged(int arg1)
{
    int i=15;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_49_stateChanged(int arg1)
{
    int i=16;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_70_stateChanged(int arg1)
{
    int i=17;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_68_stateChanged(int arg1)
{
    int i=18;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_63_stateChanged(int arg1)
{
    int i=19;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_51_stateChanged(int arg1)
{
    int i=20;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_56_stateChanged(int arg1)
{
    int i=21;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_67_stateChanged(int arg1)
{
    int i=22;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_69_stateChanged(int arg1)
{
    int i=23;
         tuike(arg1,i);
}

void MainWindow::on_checkBox_62_stateChanged(int arg1)
{
    int i=24;
         tuike(arg1,i);
}
void MainWindow::tuike(int&checkbox,int&xuhao){
    if (stu.m_choosecourse.size()>=xuhao&&checkbox){
      ui->textEdit_18->append(stu.m_choosecourse[xuhao-1]);
//      auto iter=stu.m_choosecourse.begin();
//      *iter=(xuhao-1);
        //stu.m_choosecourse.erase(iter);
      stu.m_choosecourse[xuhao-1]="";
    }
    else return;
}





void MainWindow::on_pushButton_36_clicked()//下载选课名单
{   QMessageBox::information(NULL, "download", "你确定要下载选课名单嘛？",
                             QMessageBox::Yes | QMessageBox::No);
    if(QMessageBox::Yes){

        QFile file1("choosecourse.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text|QIODevice::Append )) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        out<<stu.m_ID<<" "<<stu.m_name<<" "<<stu.m_major<<" "<<stu.m_classnum<<"\n";
        for(int i=0;i<stu.m_choosecourse.size();i++){
            out<<stu.m_choosecourse[i]<<"\n";
        }
        file1.close();
      }
        QMessageBox::warning(NULL, "warning", "download successfully", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else if (QMessageBox::No){
        QMessageBox::warning(NULL, "warning", "download falied", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    else {
        QMessageBox::warning(NULL, "warning", "download falied", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}


void MainWindow::on_label_55_linkActivated(const QString &link)
{

}
