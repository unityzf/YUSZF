#include "facewindow.h"
#include "ui_facewindow.h"
#include <QtConcurrent>
#include <qmetatype.h>
#include <QMetaType>
#include <QDebug>
#include <QThread>
#include <QString>
#include "myfacerecognizer.h"
#include "mainwindow.h"
//Q_DECLARE_METATYPE(Mat)
Mat frame;
VideoCapture capture;
myFaceRecognizer * recognizer;
QString message;
int flag;
faceWindow::faceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::faceWindow)
{
    ui->setupUi(this);
    //qRegisterMetaType<Mat>("Mat");
    message="";
//thread=new faceThread(this);
    //thread=new faceThread(this,frame);
   // connect(thread,&faceWindow::sendPic,this,&faceThread::getPic);
  //connect(this,&faceWindow::sendPic,thread,&faceThread::getPic);
    recognizer=new myFaceRecognizer();

    capture.open(0);
    capture >>frame;
    rate=capture.get(CV_CAP_PROP_FPS);

   // thread->getFrame(frame);
   // thread->start();

    if(!frame.empty())
    {
      image=MatToImage(frame);
      ui->picShow->setPixmap(QPixmap::fromImage(image));
      timer =new QTimer(this);
       timer->setInterval(1000/rate);
       connect(timer,&QTimer::timeout,this,&faceWindow::nextFrame);
       timer->start();
    }
//    while(1)
//     emit sendPic(frame);

    QtConcurrent::run([=](){
        Mat frame;
        while(1)
        {
    //cout<<"55";
//
           capture >>frame;
//            if(!frame.empty())
//            {
//                namedWindow("thread");
               recognizer->Recognizer(frame);
//               imshow("thread",frame);

//                startWindowThread();//开始不断的更新图片


               // qDebug() <<"1";
                //  waitKey(100);

//            }else{

//            }
               QThread::msleep(100);
               if(flag==1)
                   break;

     //qDebug() <<"1";
        }
    });
}

faceWindow::~faceWindow()
{
    delete ui;
}


QImage faceWindow::MatToImage(Mat frame)
{
     QImage QImg;
     if(frame.channels()==3)//彩色通道
       {
             cvtColor(frame,frame,CV_BGR2RGB);
             QImg=QImage((const unsigned char *)(frame.data),
             frame.cols,frame.rows,
             frame.cols*frame.channels(),
             QImage::Format_RGB888);

         }
       else if(frame.channels()==1)
             {

             QImg=QImage((const unsigned char *)(frame.data),
             frame.cols,frame.rows,
             frame.cols*frame.channels(),
             QImage::Format_Indexed8);

             }else{
                     QImg=QImage((const unsigned char *)(frame.data),
             frame.cols,frame.rows,
             frame.cols*frame.channels(),
            QImage::Format_RGB888);
                }

return QImg;
}


void  faceWindow::nextFrame()
{
    capture >> frame;
     emit this->sendPic(frame);
     if(!frame.empty())
        {
           image=MatToImage(frame);
           ui->picShow->setPixmap(QPixmap::fromImage(image));
           ui->showMessage->setText(message);
           // emit sendPic(frame);
         // recognizer->Recognizer(frame);

     }

}




void faceWindow::on_GO_clicked()
{
    if(QString::compare(message,"人脸识别通过，请按钮进入系统")==0)
    {
        capture.release();
        this->hide();//主界面关闭
            MainWindow *videodlg = new MainWindow(this);//新建子界面
          // connect(videodlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数

            videodlg->show();//子界面出现
            videodlg->move ((QApplication::desktop()->width() - videodlg->width())/2,(QApplication::desktop()->height() - videodlg->height())/2);
             flag=1;
    }

}
