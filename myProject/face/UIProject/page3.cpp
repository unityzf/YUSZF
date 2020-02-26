#include "page3.h"
#include "ui_page3.h"
#include "page2.h"

page3::page3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page3)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);

    vtCity.push_back("74ls191");
        vtCity.push_back("74ls160");
        vtCity.push_back("74ls161");
        vtCity.push_back("stm32c8t6");
        vtCity.push_back("stm32f103zet6");
        vtCity.push_back("stm32f407gt6");
        vtCity.push_back("op07");
        vtCity.push_back("74ls138");
        vtCity.push_back("7448");
        vtCity.push_back("7449");
        vtCity.push_back("74ls164");
        vtCity.push_back("74ls151");

        ui->listWidget->setVisible(false);
        ItemModel = new QStandardItemModel(this);
        pg=new page1(this);

}

page3::~page3()
{
    delete ui;
}
void page3::keyPressEvent(QKeyEvent *keyevent){
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
        QString str=ui->listWidget->currentItem()->text();
         ui->listWidget_2->addItem(str);
         strList.append(str);
        ui->lineEdit->setText(ui->listWidget->currentItem()->text());
        ui->listWidget->setVisible(false);



        //add(ui->listWidget->currentItem()->text());
    }
}

void page3::on_lineEdit_textChanged(const QString &strText)
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
void page3::add(const QString cell){



          //QStringList strList;
          strList.append(cell);
//          strList.append("B");
//          strList.append("C");
//          strList.append("D");
//          strList.append("E");
//          strList.append("F");
//          strList.append("G");

          //int nCount = strList.size();

//              QString string = static_cast<QString>(strList.at(strList.indexOf(cell)));
//              QStandardItem *item = new QStandardItem(string);
//              ItemModel->appendRow(item);

//         ui->listWidget_2->setModel(ItemModel);

         for(int i = 0;i < strList.size();++i){

             if (strList[i].indexOf(cell) != -1)
             {

                 ui->listWidget_2->addItem(strList[i]);
             }
         }

        // ui->listView->setFixedSize(200,300);

         //connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(showClick(QModelIndex)));


}



void page3::on_pushButton_2_clicked()
{
    emit sendsignal1();
        this->close();
}

void page3::on_pushButton_clicked()
{
    //GO
    this->close();//主界面关闭
        page2 *videodlg = new page2(this);//新建子界面
        //connect(videodlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
        videodlg->show();//子界面出现
 videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);//videodlg->move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
pg->mySleep(3000);
        videodlg->myDisplayChange();
   pg->mySleep(3000);
   emit sendsignal1();
       videodlg->close();
}

void page3::on_listWidget_2_clicked(const QModelIndex &index)
{
    QString strTemp;
    strTemp = index.data().toString();
    ui->listWidget_2->takeItem(strList.indexOf(strTemp));
   strList.removeAt(strList.indexOf(strTemp));


}
