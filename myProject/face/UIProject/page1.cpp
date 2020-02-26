#include "page1.h"
#include "ui_page1.h"
#include "page2.h"

page1::page1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page1)
{

    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    QPalette label_pe;
     QPalette label_pe1;
     label_pe1.setColor(QPalette::WindowText, Qt::blue);
        label_pe.setColor(QPalette::WindowText, Qt::red);
        ui->label_2->setPalette(label_pe1);
        ui->label_3->setPalette(label_pe);
}

page1::~page1()
{
    delete ui;
}

void page1::on_pushButton_2_clicked()
{
    back();
}

void page1::on_pushButton_clicked()
{
    GO();
}


void page1::back(){
    emit sendsignal();
        this->close();
}
void page1::GO(){
    this->close();//主界面关闭
        page2 *videodlg = new page2(this);//新建子界面
        //connect(videodlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        videodlg->show();//子界面出现
         videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);//videodlg->move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
mySleep(3000);
        videodlg->myDisplayChange();
   mySleep(3000);
   emit sendsignal();
       videodlg->close();


}

void page1::mySleep(unsigned int msec){


        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}
