#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include"student.h"
#include"student_inquiry.h"
//#include"Myvector.h"
namespace Ui {
class MainWindow1;
}
class MainWindow;
class MainWindow1 : public QMainWindow
{
    Q_OBJECT
friend MainWindow;
public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();
void senddata();
private slots:
    void on_pushButton_2_clicked();
    void accept(const QString&);
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

signals:
    void Userid(const QString&);
private:
    Ui::MainWindow1 *ui;
    student stu1;

    student_inquiry sti1;
   QString m_userID;
};

#endif // MAINWINDOW1_H
