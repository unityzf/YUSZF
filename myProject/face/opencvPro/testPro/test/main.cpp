#include "mainwindow.h"
//#include <opencv2/core/core.hpp>

//#include <opencv2/imgcodecs.hpp>

//#include <opencv2/highgui/highgui.hpp>

//using namespace cv;
//int main(int argc, char *argv[])
//{
////    Mat image;//Mat是OpenCV最基本的数据结构，这是定义一个图像矩阵类型

////        image = imread("/home/pi/1.jpg", IMREAD_COLOR);//读入图片数据

////        if (image.empty())//读取失败时
////               return -1;
////        namedWindow("Display window", WINDOW_AUTOSIZE); // 创建一个窗口

////        imshow("Display window", image);                // 在窗口中显示图片

////        waitKey(0); // 等待一次按键，程序结束


////    return 0;

//    Mat image;//Mat是OpenCV最基本的数据结构，这是定义一个图像矩阵类型

//            image = imread("/home/pi/1.jpg", IMREAD_COLOR);//读入图片数据

//            if (image.empty())//读取失败时
//                   return -1;
//            namedWindow("Display window", WINDOW_AUTOSIZE); // 创建一个窗口

//            imshow("Display window", image);                // 在窗口中显示图片

//            waitKey(0); // 等待一次按键，程序结束


//        return 0;
//}

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include <vector>
#include <cstdio>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);
        Mat frame;
        while(1)
        {

            cap >> frame;
            imshow("【人脸识别detectMultiScale】", frame);
            waitKey(100);
        }


//    // 【1】加载分类器
//    CascadeClassifier cascade;
//    bool flag=cascade.load("/home/pi/opencvPro/haarcascade_frontalface_alt2.xml");
//    cout << flag << endl;
//    Mat srcImage, grayImage, dstImage;
//    // 【2】读取图片
//    srcImage = imread("/home/pi/opencvPro/image.jpg");
//    dstImage = srcImage.clone();
//    imshow("【原图】", srcImage);

//    grayImage.create(srcImage.size(), srcImage.type());
//    cvtColor(srcImage, grayImage, CV_BGR2GRAY); // 生成灰度图，提高检测效率

//                                                // 定义7种颜色，用于标记人脸
//    Scalar colors[] =
//    {
//        // 红橙黄绿青蓝紫
//        CV_RGB(255, 0, 0),
//        CV_RGB(255, 97, 0),
//        CV_RGB(255, 255, 0),
//        CV_RGB(0, 255, 0),
//        CV_RGB(0, 255, 255),
//        CV_RGB(0, 0, 255),
//        CV_RGB(160, 32, 240)
//    };

//    // 【3】检测
//    vector<Rect> rect;
//    cascade.detectMultiScale(grayImage, rect, 1.1, 3, 0);  // 分类器对象调用

//    printf("检测到人脸个数：%d\n", rect.size());

//    // 【4】标记--在脸部画圆
//    for (int i = 0; i < rect.size(); i++)
//    {
//        Point  center;
//        int radius;
//        center.x = cvRound((rect[i].x + rect[i].width * 0.5));
//        center.y = cvRound((rect[i].y + rect[i].height * 0.5));

//        radius = cvRound((rect[i].width + rect[i].height) * 0.25);
//        circle(dstImage, center, radius, colors[i % 7], 2);
//    }

//    // 【5】显示
//    imshow("【人脸识别detectMultiScale】", dstImage);

//    waitKey(0);
   return 0;
}


