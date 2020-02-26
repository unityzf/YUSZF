#ifndef SETTING_H
#define SETTING_H
#include <QApplication>
#include <QMainWindow>
#include <QLayout>
#include <QListWidget>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QPalette>
#include <QWidget>
#include <QButtonGroup>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QDesktopWidget>
namespace Ui {
class setting;
}

class setting : public QMainWindow
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    ~setting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setting *ui;
signals:
    void sendsignal2();//这个函数用户向主界面通知关闭的消息
};

#endif // SETTING_H
