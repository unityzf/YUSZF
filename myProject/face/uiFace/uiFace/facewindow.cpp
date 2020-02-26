#include "facewindow.h"
#include "ui_facewindow.h"
#include <QtConcurrent>
#include <qmetatype.h>
#include <QMetaType>
#include <QDebug>

Q_DECLARE_METATYPE(Mat)
 Mat frame;
   VideoCapture capture;
faceWindow::faceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::faceWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<Mat>("Mat");
//thread=new faceThread(this);
    //thread=new faceThread(this,frame);
   // connect(thread,&faceWindow::sendPic,this,&faceThread::getPic);
  //connect(this,&faceWindow::sendPic,thread,&faceThread::getPic);

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

        while(1)
        {
    //cout<<"55";
             Mat frame;
            capture >>frame;
            if(!frame.empty())
            {
//                namedWindow("thread");

//               imshow("thread",frame);

//                startWindowThread();//开始不断的更新图片


               // qDebug() <<"1";
                //  waitKey(100);
            }else{

            }
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
           // emit sendPic(frame);


     }

}



