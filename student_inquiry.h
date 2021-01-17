#ifndef STUDENT_INQUIRY_H
#define STUDENT_INQUIRY_H

#include <QDialog>

namespace Ui {
class student_inquiry;
}
class MainWindow;
class student_inquiry : public QDialog
{
    Q_OBJECT
friend MainWindow;
public:
    explicit student_inquiry(QWidget *parent = nullptr);
    ~student_inquiry();
 void acceptdata(const QString&);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::student_inquiry *ui;
    int flag2=0;//成绩查询是否成功标志位
    QString m_userID;
    QString m_course;
};

#endif // STUDENT_INQUIRY_H
