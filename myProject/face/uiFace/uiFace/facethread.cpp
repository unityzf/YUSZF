#include "facethread.h"
#include <QDebug>

 extern VideoCapture capture;
faceThread::faceThread(QObject *parent):QThread(parent)
{


}

faceThread::~faceThread()
{

}
void faceThread::run()
{

    //QApplication::processEvents();
    while(1)
    {
//cout<<"55";
         Mat frame;
        capture >>frame;
        if(!frame.empty())
        {
            namedWindow("thread");

           imshow("thread",frame);

            startWindowThread();//开始不断的更新图片


           // qDebug() <<"1";
            //  waitKey(100);
        }else{

        }
 //qDebug() <<"1";
    }

}
void faceThread::getFrame(Mat& frame)
{
         pictrue=frame;

}
void faceThread::getPic(Mat pic)
{

    if(pic.empty())
    {
        cout <<"aaaa";
    }
      imshow("thread",pic);
    cout <<"a";
     pictrue=pic;


}
