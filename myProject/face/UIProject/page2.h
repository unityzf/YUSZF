#ifndef PAGE2_H
#define PAGE2_H

#include <QMainWindow>
#include <QFont>
#include <QLayout>
#include <QListWidget>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QPalette>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>
namespace Ui {
class page2;
}

class page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = 0);
    ~page2();
    void myDisplayChange();

private:
    Ui::page2 *ui;
};

#endif // PAGE2_H
