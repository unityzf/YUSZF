#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include "page1.h"
#include "page3.h"
#include "setting.h"
#include <QApplication>
#include <wiringSerial.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
extern int fd;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //time
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    //background
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    //like
    vtCity.push_back("74ls191");
        vtCity.push_back("74ls160");
        vtCity.push_back("74ls161");
        vtCity.push_back("stm32c8t6");
        vtCity.push_back("stm32f103zet6");
        vtCity.push_back("stm32f407gt6");
        vtCity.push_back("LM317");
        vtCity.push_back("LM324");
        vtCity.push_back("LM358");
        vtCity.push_back("74ls138");
        vtCity.push_back("NE555");
        vtCity.push_back("74ls04");
        vtCity.push_back("OP07");
        vtCity.push_back("74ls153");


        ui->listWidget->setVisible(false);
//label
        QPalette label_pe;
            QFont ft;
            ft.setPointSize(20);
            label_pe.setColor(QPalette::WindowText, Qt::red);
            ui->label->setPalette(label_pe);
            ui->label_3->setFont(ft);
            ui->label_3->setPalette(label_pe);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent ( QKeyEvent * keyevent )
{


    if(QApplication::focusWidget() != ui->lineEdit || ui->listWidget->count() == 0)return;
    int uKey = keyevent->key();
    Qt::Key key = static_cast<Qt::Key>(uKey);
    int iIndex = ui->listWidget->currentRow ();
    if(key == Qt::Key_Up)
    {
        iIndex--;
        if(iIndex < 0) iIndex = 0;
        QListWidgetItem *pItem = ui->listWidget->item(iIndex);
        pItem->setForeground(Qt::red);
        ui->listWidget->setCurrentItem(pItem);

    }
    else if (key == Qt::Key_Down)
    {
        iIndex++;
        if(iIndex >= ui->listWidget->count()) iIndex = ui->listWidget->count() - 1;
        QListWidgetItem *pItem = ui->listWidget->item(iIndex);
        ui->listWidget->setCurrentItem(pItem);
    }
    else if (key == Qt::Key_Enter || key == Qt::Key_Return)
    {
        str=ui->listWidget->currentItem()->text();
        ui->lineEdit->setText(ui->listWidget->currentItem()->text());
        ui->listWidget->setVisible(false);
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &strText)
{
    ui->listWidget->clear();
        for(int i = 0;i < vtCity.size();++i){

            if (vtCity[i].indexOf(strText) != -1)
            {

                ui->listWidget->addItem(vtCity[i]);
            }
        }
        if (ui->listWidget->count() > 0)
        {
            ui->listWidget->setVisible(true);
        }

}
void MainWindow::timerUpdate()
{
QDateTime time = QDateTime::currentDateTime();
QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
ui->label_2->setText(str);
}
//存入
void MainWindow::on_pushButton_clicked()
{
    this->hide();//主界面关闭
        page1 *videodlg = new page1(this);//新建子界面
        connect(videodlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数

        videodlg->show();//子界面出现
        videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);

}
void MainWindow::reshow(){
    this->show();
     this->move ((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
}
//取出
void MainWindow::on_pushButton_2_clicked()
{
        this->hide();//主界面关闭
        page3 *videodlg = new page3(this);//新建子界面
        connect(videodlg,SIGNAL(sendsignal1()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        videodlg->show();//子界面出现
        videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);
}
//设置
void MainWindow::on_pushButton_3_clicked()
{
    this->hide();//主界面关闭
     serialPuts(fd, "Usart send Test,Just by launcher!");
        setting *videodlg = new setting(this);//新建子界面
        connect(videodlg,SIGNAL(sendsignal2()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        videodlg->show();//子界面出现
        videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);// videodlg->move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
}
//go
void MainWindow::on_pushButton_4_clicked()
{
    this->hide();//主界面关闭
        page4 *videodlg = new page4(this);//新建子界面
        videodlg->setlabel(str);
        connect(videodlg,SIGNAL(sendsignal3()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        videodlg->show();//子界面出现
         videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);//videodlg->move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
}
