#ifndef FACETHREAD_H
#define FACETHREAD_H

#include <QThread>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <QApplication>
using namespace std;
using namespace cv;
class faceThread : public QThread
{
    Q_OBJECT
  public:
     faceThread(QObject *parent);
     ~faceThread();
      void getFrame(Mat &frame);
      void run();
     // Mat pictrue;
   Mat pictrue;

public slots:
     void getPic(Mat pic);
};

#endif // FACETHREAD_H
