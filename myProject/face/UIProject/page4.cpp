#include "page4.h"
#include "ui_page4.h"
#include "page2.h"
#include "page1.h"
page4::page4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page4)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);

}

page4::~page4()
{
    delete ui;
}

void page4::on_pushButton_clicked()
{
    this->close();//主界面关闭
     page1 *pg=new page1(this);
        page2 *videodlg = new page2(this);//新建子界面
        //connect(videodlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        videodlg->show();//子界面出现
        videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);// videodlg->move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
pg->mySleep(3000);
        videodlg->myDisplayChange();
   pg->mySleep(3000);
   emit sendsignal3();
       videodlg->close();
}

void page4::on_pushButton_2_clicked()
{
    emit sendsignal3();
        this->close();
}
void page4::setlabel(QString str)
{
//    vtCity.push_back("74ls191");
//        vtCity.push_back("74ls160");
//        vtCity.push_back("74ls161");
//        vtCity.push_back("stm32c8t6");
//        vtCity.push_back("stm32f103zet6");
//        vtCity.push_back("stm32f407gt6");
//        vtCity.push_back("LM317");
//        vtCity.push_back("LM324");
//        vtCity.push_back("LM358");
//        vtCity.push_back("74ls138");
//        vtCity.push_back("NE555");
//        vtCity.push_back("74ls04");
//        vtCity.push_back("OP07");
//        vtCity.push_back("74ls153");


    ui->label_2->setText(str);

    if(str=="74ls191")
    {
       setMyPIC(":/new/prefix1/New/pic/74ls191.png",":/new/prefix1/New/pic/picPDF/74LS191.png");
    }
    if(str=="74ls160")
    {
        setMyPIC(":/new/prefix1/New/pic/74ls160.png",":/new/prefix1/New/pic/picPDF/74ls160.png");
    }
    if(str=="74ls161")
    {
        setMyPIC(":/new/prefix1/New/pic/74ls161.png",":/new/prefix1/New/pic/picPDF/74LS161.png");
    }
    if(str=="stm32c8t6")
    {setMyPIC(":/new/prefix1/New/pic/stm8.png",":/new/prefix1/New/pic/picPDF/Stm8s105c4t6.png");

    }
    if(str=="stm32f103zet6")
    {setMyPIC(":/new/prefix1/New/pic/stm32.png",":/new/prefix1/New/pic/picPDF/Stm32f103zet6.png");

    }
    if(str=="LM317")
    {setMyPIC(":/new/prefix1/New/pic/LM317.png",":/new/prefix1/New/pic/picPDF/LM317.png");

    }
    if(str=="LM324")
    {
        setMyPIC(":/new/prefix1/New/pic/LM324.png",":/new/prefix1/New/pic/picPDF/LM324.png");
    }
    if(str=="LM358")
    {
        setMyPIC(":/new/prefix1/New/pic/LM358.png",":/new/prefix1/New/pic/picPDF/LM358.png");
    }
    if(str=="74ls138")
    {
        setMyPIC(":/new/prefix1/New/pic/74ls138.jpg",":/new/prefix1/New/pic/picPDF/74LS138.png");
    }
    if(str=="NE555")
    {
        setMyPIC(":/new/prefix1/New/pic/NE555.png",":/new/prefix1/New/pic/picPDF/NE555.png");
    }
    if(str=="74ls04")
    {
        setMyPIC(":/new/prefix1/New/pic/74ls04.png",":/new/prefix1/New/pic/picPDF/74LS04.png");
    }
    if(str=="OP07")
    {
        setMyPIC(":/new/prefix1/New/pic/OP07.png",":/new/prefix1/New/pic/picPDF/OP07.png");
    }
    if(str=="74ls153")
    {
        setMyPIC(":/new/prefix1/New/pic/74ls153.png",":/new/prefix1/New/pic/picPDF/74LS153.png");
    }

//    switch(mystr)
//    {
//         case "74ls191":setMyPIC(":/new/prefix1/New/pic/74ls191.png",":/new/prefix1/New/pic/picPDF/74LS191.png");break;
//         case "74ls160":setMyPIC(":/new/prefix1/New/pic/74ls160.png",":/new/prefix1/New/pic/picPDF/74ls160.png");break;
//         case "74ls161":setMyPIC(":/new/prefix1/New/pic/74ls161.png",":/new/prefix1/New/pic/picPDF/74LS161.png");break;
//         case "stm32c8t6":setMyPIC(":/new/prefix1/New/pic/stm8.png",":/new/prefix1/New/pic/picPDF/Stm8s105c4t6.png");break;
//         case "stm32f103zet6":setMyPIC(":/new/prefix1/New/pic/stm32.png",":/new/prefix1/New/pic/picPDF/Stm32f103zet6.png");break;
//         case "LM317":setMyPIC(":/new/prefix1/New/pic/LM317.png",":/new/prefix1/New/pic/picPDF/LM317.png");break;
//         case "LM324":setMyPIC(":/new/prefix1/New/pic/LM324.png",":/new/prefix1/New/pic/picPDF/LM324.png");break;
//         case "LM358":setMyPIC(":/new/prefix1/New/pic/LM358.png",":/new/prefix1/New/pic/picPDF/LM358.png");break;
//         case "74ls138":setMyPIC(":/new/prefix1/New/pic/74ls138.jpg",":/new/prefix1/New/pic/picPDF/74LS138.png");break;
//         case "NE555":setMyPIC(":/new/prefix1/New/pic/NE555.png",":/new/prefix1/New/pic/picPDF/NE555.png");break;
//         case "74ls04":setMyPIC(":/new/prefix1/New/pic/74ls04.png",":/new/prefix1/New/pic/picPDF/74LS04.png");break;
//         case "OP07":setMyPIC(":/new/prefix1/New/pic/OP07.png",":/new/prefix1/New/pic/picPDF/OP07.png");break;
//         case "74ls153":setMyPIC(":/new/prefix1/New/pic/74ls153.png",":/new/prefix1/New/pic/picPDF/74LS153.png");break;



//    }
}
void page4::setMyPIC(QString pic,QString picpdf){
    QPixmap *pic1 = new QPixmap(pic);
    QPixmap *picpdf1 = new QPixmap(picpdf);
    //pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label_4->setScaledContents(true);
     ui->label_4->setPixmap(*pic1);

     ui->label_3->setScaledContents(true);
      ui->label_3->setPixmap(*picpdf1);

}

