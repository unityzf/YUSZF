#ifndef PAGE4_H
#define PAGE4_H
#include <QApplication>
#include <QMainWindow>
#include <QLayout>
#include <QListWidget>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QPalette>
#include <QString>
#include <QPixmap>
#include <QDesktopWidget>
namespace Ui {
class page4;
}

class page4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page4(QWidget *parent = 0);
    ~page4();
    void setlabel(QString str);
    void setMyPIC(QString pic,QString picpdf);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::page4 *ui;
signals:
    void sendsignal3();//这个函数用户向主界面通知关闭的消息
};

#endif // PAGE4_H
