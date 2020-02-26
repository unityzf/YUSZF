#include "page2.h"
#include "ui_page2.h"

page2::page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
}

page2::~page2()
{
    delete ui;
}
void page2::myDisplayChange()
{

    QPixmap *pixmap = new QPixmap(":/new/prefix1/New/3.png");
    //pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
     ui->label->setPixmap(*pixmap);
}
