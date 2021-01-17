#include"teacher.h"

void teacher::file() {
    ifstream inFile;

}//算了，我先不搞这玩意，我先完成功能再说
QVector<QString> teacher::search_score( const QString& name) {
    ifstream inFile;
    inFile.open("score.txt");
    string str;
    QString str1;
    string temp;
    //student student1(name);
    QVector<QString> temp1;
    if (inFile) { //条件成立，则说明文件打开成功
        //cout << "sorce.txt open scessful" << endl;
        /*getline(inFile, str);
        cout << str << endl;
        getline(inFile, str);
        cout << str << endl;
        getline(inFile, str);
        cout << str << endl;*/
        int flag = 0;
        while (!inFile.eof()) {
            inFile >> str;
            //getline(inFile, str);//按行显示
            temp=name.toStdString();
            if (str == temp) {//如果找到名字，直接输出本行数据
                //cout << str << endl;
                getline(inFile, str);
                str1=QString::fromStdString(str);
                temp1.push_back(str1);
                cout << str << endl;
                flag = 1;
            }
            //cout << str << endl;
        }

        /*if (str == student1.m_ID) {
            cout << student1.m_course << endl;
            inFile.close();
        }*/
        inFile.close();
        if (flag == 0) {
            temp1.push_back("The student's grade is not found. Please check it before inquiring");
            //cout << "未查询到此人的成绩信息，请核实后再进行查询" << endl;
        }
    }
    else {
        cout << "score.txt doesn't exist" << endl;
    }
    return temp1;
}
QVector<QString> teacher::search_name(QString& course_name,double& scoremin, double& scoremax) {
    ifstream inFile;
    inFile.open("score.txt");
    double temp;
    string str;
   // string str1;
    QString temp1;
    QString temp2;
     QString temp4;
      QVector<QString> temp3;
    if (inFile) { //条件成立，则说明文件打开成功
        int flag = 0;
        while (!inFile.eof()) {
            inFile >> str;
            temp1=QString::fromStdString(str);
            //temp1=course_name.toStdString();
            if (temp1==course_name) {
                inFile >> temp;
                if (temp >= scoremin && temp <= scoremax) {
                    temp2=QString::number(temp);
                    //cout << "\r" ;
                    //getline(inFile, str);
                    //cout <<str1<<setw(20) <<str<<setw(6)<<temp<<endl;
                    temp3.push_back(temp4);//尾插姓名
                    temp3.push_back(temp2);//尾插分数
                    flag = 1;
                }

            }
            temp4=temp1;
        }//这段比较繁琐，但是没有查到如何将文件指针移动到本行首端，之后再改吧
        inFile.close();
        if (flag == 0) {
            cout << "未查询到该课程对应的成绩信息，请核实后再进行查询" << endl;
        }
    }
    else {
        cout << "score.txt doesn't exist" << endl;
    }
    return temp3;
}

QVector<QString> teacher::sort(QString &coursename) {
    QVector<QString> temp1;
    QString str,str1;
    double scoremin=0;
    double scoremax=100;
    temp1=search_name(coursename,scoremin,scoremax);//利用已经写好的分数段查询该课的所有学生成绩
    for(int i=1;i<temp1.size()-2;i+=2){
        for(int j=1;j<temp1.size()-2;j+=2){
            if(temp1[j]>temp1[j+2]){
                str=temp1[j];
                temp1[j]=temp1[j+2];
                temp1[j+2]=str;
                str=temp1[j-1];
                temp1[j-1]=temp1[j+1];
                temp1[j+1]=str;
            }
        }
    }
    return temp1;
}


QVector<QString> teacher::search_statics(QString& coursename){
    QVector<double> temp;
    QVector<QString> temp1;
    QVector<QString> temp2;
    double scoremin=0;
    double scoremax=100;
     double totalscore=0;
     double average=0;
     double passrate=0;
     QString a;
    temp1=search_name(coursename,scoremin,scoremax);//利用已经写好的分数段查询该课的所有学生成绩
    for(int i=1;i<temp1.size();i+=2){//将该门课的所有成绩提取出来
        double score=temp1[i].toDouble();
        temp.push_back(score);
    }

    for(int j=0;j<temp.size();j++){
       totalscore=totalscore+temp[j];
    }
    average=totalscore/(temp.size()-1);
    a=QString::number(average);
    temp2.push_back(a);//平均分的计算

    scoremin =60;
    temp1=search_name(coursename,scoremin,scoremax);
    double b=(temp1.size());
    passrate=b/(2*(temp.size()));
    a=QString::number(passrate);
    temp2.push_back(a);//及格率的计算

    for(int j=0;j<temp.size();j++){
       totalscore=abs(average-temp[j])*abs(average-temp[j]);
    }
     totalscore=sqrt(totalscore);//用totalscore当标准差算了
     a=QString::number(totalscore);
     temp2.push_back(a);//标准差的计算
    return temp2;
}
bool teacher::xiugai(QString &name, QString &course,QString &grade){

    QString str1;
    string str;
    QString stud;
    QString stud1;
    stud+=namechaxuehao(name);
    stud+=" ";//学号
    stud+=name;
    stud+=" ";//姓名

    stud+=course;
    stud+=" ";//课程

    stud+=grade;
    std::ifstream file;
    file.open("score.txt");

   //修改后的成绩
    if (file) {

        QFile file1("scoreupdate.txt");
        if (file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream out(&file1);
        out.setCodec("UTF-8");
        while(!file.eof()){
          file>>str;
          str1=QString::fromStdString(str);
          stud1+=str1;
          stud1+=" ";//学号
          file>>str;
          str1=QString::fromStdString(str);
          stud1+=str1;//姓名
          stud1+=" ";
            if (str1==name){
                file>>str;
                str1=QString::fromStdString(str);
                stud1+=str1;//课程
                stud1+=" ";
                if (str1==course){
                    out<<stud;
                    flag2=1;
                     out<<"\n";
                     stud1.clear();
                     file>>str;
                }
               else if(str1!=course){
                    file>>str;
                    str1=QString::fromStdString(str);
                    stud1+=str1;//原来的成绩
                    stud1+=" ";
                    out<<stud1;
                    out<<"\n";
                    stud1.clear();
                   continue;
                }
            }
            else if(str1!=name){
                file>>str;
                str1=QString::fromStdString(str);
                stud1+=str1;//课程
                stud1+=" ";
                file>>str;
                str1=QString::fromStdString(str);
                stud1+=str1;//原来的成绩
                stud1+=" ";
                out<<stud1;
                out<<"\n";
                stud1.clear();
               continue;
            }


        }
        file.close();
        file1.close();

            if(flag2==1){
                flag2=0;
                    return 1;
            }
        }
        else {
            file.close();
            return 0;
        }

    }
    else{
       return  0;
    }
}


QString teacher::namechaxuehao(QString &name){
    std::ifstream file1;
    file1.open("student.txt");
    QString str1;
    QString str;
    QString str2="weichaxundao";
   std::string temp;
        if (!file1){
            //qDebug()<<"open file failed";
            return str2;
        }

        else {

            while (!file1.eof()){
                //getline(file1,temp);
                file1>>temp;
                 str=QString::fromStdString(temp);
                 file1>>temp;
                  str1=QString::fromStdString(temp);
                if (str1==name){ //这里的username实际上是学号
                    flag1=1;

                    }
                    else if (str1!=name){
                        file1>>temp;
                         file1>>temp;
                         continue;
                  }
                }

            }

        file1.close();//打开文件 尝试
        if(flag1==1){
            return str;
            flag1=0;
        }
        else if (flag1==0){
            return str2;
        }
        //return str2;
}
