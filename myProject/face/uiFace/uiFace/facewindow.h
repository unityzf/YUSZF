#ifndef FACEWINDOW_H
#define FACEWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "facethread.h"
#include <vector>
#include <cstdio>
#include <QImage>
#include <QTime>
#include <QTimer>
#include <QMetaType>

using namespace std;
using namespace cv;

namespace Ui {
class faceWindow;
}

class faceWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit faceWindow(QWidget *parent = 0);
    ~faceWindow();
    QImage MatToImage(Mat frame);
    void  nextFrame();

   // VideoCapture capture;
    QImage image;
    QTimer *timer;
    double rate;
    faceThread *thread;

private:
    Ui::faceWindow *ui;

signals:
    void sendPic(Mat pic);
};

#endif // FACEWINDOW_H
