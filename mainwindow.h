#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mainwindow1.h"
#include "ui_mainwindow1.h"
#include<QFileDialog>
#include<QMessageBox>
#include"teacher.h"
#include<QMovie>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow1;
class student_inquiry;
class MainWindow : public QMainWindow
{
    Q_OBJECT
friend MainWindow1;//声明为友元
friend student_inquiry;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void send();
    void openFile();
    void zhuxiao();
    void xuanke(int&,int&);
    void tuike(int&,int&);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();
    //void accept();
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_checkBox_16_stateChanged(int arg1);

    void on_checkBox_17_stateChanged(int arg1);

    void on_checkBox_18_stateChanged(int arg1);

    void on_checkBox_19_stateChanged(int arg1);

    void on_checkBox_20_stateChanged(int arg1);

    void on_checkBox_21_stateChanged(int arg1);

    void on_checkBox_22_stateChanged(int arg1);

    void on_checkBox_23_stateChanged(int arg1);

    void on_checkBox_24_stateChanged(int arg1);

    void on_pushButton_29_clicked();

    void on_checkBox_52_stateChanged(int arg1);

    void on_checkBox_55_stateChanged(int arg1);

    void on_checkBox_61_stateChanged(int arg1);

    void on_checkBox_60_stateChanged(int arg1);

    void on_checkBox_50_stateChanged(int arg1);

    void on_checkBox_54_stateChanged(int arg1);

    void on_checkBox_64_stateChanged(int arg1);

    void on_checkBox_57_stateChanged(int arg1);

    void on_checkBox_59_stateChanged(int arg1);

    void on_checkBox_66_stateChanged(int arg1);

    void on_checkBox_71_stateChanged(int arg1);

    void on_checkBox_53_stateChanged(int arg1);

    void on_checkBox_72_stateChanged(int arg1);

    void on_checkBox_65_stateChanged(int arg1);

    void on_checkBox_58_stateChanged(int arg1);

    void on_checkBox_49_stateChanged(int arg1);

    void on_checkBox_70_stateChanged(int arg1);

    void on_checkBox_68_stateChanged(int arg1);

    void on_checkBox_63_stateChanged(int arg1);

    void on_checkBox_51_stateChanged(int arg1);

    void on_checkBox_56_stateChanged(int arg1);

    void on_checkBox_67_stateChanged(int arg1);

    void on_checkBox_69_stateChanged(int arg1);

    void on_checkBox_62_stateChanged(int arg1);

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_label_55_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
     MainWindow1 w1;
    int flag1=0;//登录模块选择标志位
    int flag2=0;//是否按过标志位
    int flag5=0;//是否按过标志位
    int flag3=0;//登录成功标志块
    QVector<QString> myvector;
    teacher tea;
    student stu;
signals:
    void Username(const QString&);

};
#endif // MAINWINDOW_H
