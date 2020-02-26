#ifndef PAGE1_H
#define PAGE1_H

#include <QMainWindow>
#include <QFont>
#include <QLayout>
#include <QListWidget>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QPalette>
#include <QApplication>
#include <QDesktopWidget>
namespace Ui {
class page1;
}

class page1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page1(QWidget *parent = 0);
    ~page1();
void mySleep(unsigned int msec);
    void GO();
    void back();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息
private:
    Ui::page1 *ui;
};

#endif // PAGE1_H
