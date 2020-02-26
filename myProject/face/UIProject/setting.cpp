#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    QFont ft;
    ft.setPointSize(20);
    ui->label_2->setFont(ft);

     QButtonGroup *grp1=new QButtonGroup(this);
     QButtonGroup *grp2=new QButtonGroup(this);
     QButtonGroup *grp3=new QButtonGroup(this);
     QButtonGroup *grp4=new QButtonGroup(this);
     QButtonGroup *grp5=new QButtonGroup(this);
     QButtonGroup *grp6=new QButtonGroup(this);
     grp1->addButton(ui->radioButton);
     grp1->addButton(ui->radioButton_2);
     grp2->addButton(ui->radioButton_3);
     grp2->addButton(ui->radioButton_4);
     grp3->addButton(ui->radioButton_5);
     grp4->addButton(ui->radioButton_6);
     grp5->addButton(ui->radioButton_7);
     grp5->addButton(ui->radioButton_8);
     grp5->addButton(ui->radioButton_9);
     grp6->addButton(ui->radioButton_10);
     grp6->addButton(ui->radioButton_11);
     grp6->addButton(ui->radioButton_12);





}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_clicked()
{
    emit sendsignal2();
        this->close();
}
