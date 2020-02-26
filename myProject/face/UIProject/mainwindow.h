#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QListWidget>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QPalette>
#include <QString>
#include "page4.h"
#include <QDesktopWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString str;

private slots:
    void on_lineEdit_textChanged(const QString &strText);
    void timerUpdate();
void reshow();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

protected:
    void keyPressEvent ( QKeyEvent * keyevent);

private:
    Ui::MainWindow *ui;
    QVector<QString> vtCity;

};

#endif // MAINWINDOW_H
