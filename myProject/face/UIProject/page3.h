#ifndef PAGE3_H
#define PAGE3_H
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
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QStringList>
#include "page1.h"
#include <QDesktopWidget>
namespace Ui {
class page3;
}

class page3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page3(QWidget *parent = 0);
    ~page3();
    QStringListModel *Model;
        QStandardItemModel *ItemModel;
        void add(const QString cell);
protected:
    void keyPressEvent ( QKeyEvent * keyevent);

private slots:
    void on_lineEdit_textChanged(const QString &strText);
    //void showClick(QModelIndex index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_listWidget_2_clicked(const QModelIndex &index);

signals:
    void sendsignal1();//这个函数用户向主界面通知关闭的消息
private:
    Ui::page3 *ui;
    QVector<QString> vtCity;
    QStringList strList;
    page1 *pg;
};

#endif // PAGE3_H
