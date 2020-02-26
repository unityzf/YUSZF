#include "myfacerecognizer.h"
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include<stdio.h>

myFaceRecognizer::myFaceRecognizer()
{
    recognizerCascade.load("/home/pi/opencvPro/haarcascade_frontalface_alt2.xml");//感觉用lbpcascade_frontalface效果没有它好，注意哈！要是正脸

    recognizerModel = FisherFaceRecognizer::create();
    //1.加载训练好的分类器
    recognizerModel->read("/home/pi/opencvPro/MyFaceFisherModel.xml");// opencv2用load
}
void myFaceRecognizer::takePicture()
{

    CascadeClassifier cascada;
    cascada.load("/home/pi/opencvPro/haarcascade_frontalface_alt2.xml");
    VideoCapture cap(0);
    Mat frame, myFace;
    int pic_num = 1;
    while (1) {

        cap >> frame;
        vector<Rect> faces;//
        Mat frame_gray;
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);//
        cascada.detectMultiScale(frame_gray, faces, 1.1, 4, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(1000, 1000));
        printf("%d\n", faces.size());

        for (int i = 0; i < faces.size(); i++)
        {
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
        }

        if (faces.size() == 1)
        {
            Mat faceROI = frame_gray(faces[0]);
            //cout << faces[0].x << endl;//
            resize(faceROI, myFace, Size(92, 112));//
            putText(frame, to_string(pic_num), faces[0].tl(), 3, 1.2, (0, 0, 225), 2, 0);//
            string filename = format("%d.jpg", pic_num); //
            imwrite(filename, myFace);//
            imshow(filename, myFace);//
            waitKey(500);//
            destroyWindow(filename);//
            pic_num++;
            if (pic_num == 20)
            {
                //return 0;//
                break;

            }
        }
        int c = waitKey(10);
        if ((char)c == 27) { break; }
        imshow("frame", frame);
        waitKey(100);
    }
}
//train code
Mat myFaceRecognizer::norm_0_255(InputArray _src)
{
    Mat src = _src.getMat();

    Mat dst;
    switch (src.channels()) {
    case 1:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
        break;
    case 3:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
        break;
    default:
        src.copyTo(dst);
        break;
    }
    return dst;
}

void myFaceRecognizer::read_csv(const string &filename, vector<Mat> &images, vector<int> &labels, char separator)
{

    std::ifstream file(filename.c_str(), ifstream::in);//
    if (!file)
    {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) //
    {
        stringstream liness(line);//
        getline(liness, path, separator);//
        getline(liness, classlabel);//
        if (!path.empty() && !classlabel.empty()) //
        {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

void myFaceRecognizer::train()
{
    string fn_csv = "/home/pi/opencvPro/picture/a.txt";


    vector<Mat> images;
    vector<int> labels;

    try
    {
        read_csv(fn_csv, images, labels); //
    }
    catch (cv::Exception& e)
    {
        cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;

        exit(1);
    }

    if (images.size() <= 1) {
        string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
        CV_Error(CV_StsError, error_message);
    }

    for (int i = 0; i < images.size(); i++)
    {
        if (images[i].size() != Size(92, 112))
        {
            cout << i << endl;
            cout << images[i].size() << endl;
        }
    }


    Mat testSample = images[images.size() - 1];
    int testLabel = labels[labels.size() - 1];
    images.pop_back();
    labels.pop_back();

    Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();
    model->train(images, labels);
    model->save("MyFacePCAModel.xml");

    Ptr<BasicFaceRecognizer> model1 = FisherFaceRecognizer::create();
    model1->train(images, labels);
    model1->save("MyFaceFisherModel.xml");

    Ptr<LBPHFaceRecognizer> model2 = LBPHFaceRecognizer::create();
    model2->train(images, labels);
    model2->save("MyFaceLBPHModel.xml");


    int predictedLabel = model->predict(testSample);//ŒÓÔØ·ÖÀàÆ÷
    int predictedLabel1 = model1->predict(testSample);
    int predictedLabel2 = model2->predict(testSample);


    // int predictedLabel = -1;
    // double confidence = 0.0;
    //  model->predict(testSample, predictedLabel, confidence);

    string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
    string result_message1 = format("Predicted class = %d / Actual class = %d.", predictedLabel1, testLabel);
    string result_message2 = format("Predicted class = %d / Actual class = %d.", predictedLabel2, testLabel);
    cout << result_message << endl;
    cout << result_message1 << endl;
    cout << result_message2 << endl;


}
//myFaceRecognizer
int myFaceRecognizer::Predict(Mat src_image)
{

    Mat face_test;
    int predict = 0;
    //截取的ROI人脸尺寸调整
    if (src_image.rows >= 120)
    {
        //改变图像大小，使用双线性差值
        resize(src_image, face_test, Size(92, 112));

    }
    //判断是否正确检测ROI
    if (!face_test.empty())
    {
        //测试图像应该是灰度图
        predict = recognizerModel->predict(face_test);
    }
    cout << predict << endl;
    return predict;
}
void myFaceRecognizer::Recognizer()
{

    VideoCapture cap(0);    //打开默认摄像头
    if (!cap.isOpened())
    {
        //return -1;
    }
    Mat frame;
    Mat gray;
    //这个分类器是人脸检测所用
    //CascadeClassifier cascade;
   // bool stop = false;
    //训练好的文件名称，放置在可执行文件同目录下
    //cascade.load("/home/pi/opencvPro/haarcascade_frontalface_alt2.xml");//感觉用lbpcascade_frontalface效果没有它好，注意哈！要是正脸

   // model = FisherFaceRecognizer::create();
    //1.加载训练好的分类器
    //model->read("/home/pi/opencvPro/MyFaceFisherModel.xml");// opencv2用load
                                         //3.利用摄像头采集人脸并识别
    while (1)
    {
        cap >> frame;

        vector<Rect> faces(0);//建立用于存放人脸的向量容器

        cvtColor(frame, gray, CV_RGB2GRAY);//测试图像必须为灰度图

        equalizeHist(gray, gray); //变换后的图像进行直方图均值化处理
        //检测人脸
        recognizerCascade.detectMultiScale(gray, faces,
            1.1, 4, 0
            //|CV_HAAR_FIND_BIGGEST_OBJECT
            | CV_HAAR_DO_ROUGH_SEARCH,
            //| CV_HAAR_SCALE_IMAGE,
            Size(30, 30), Size(500, 500));
        Mat* pImage_roi = new Mat[faces.size()];    //定以数组
        Mat face;
        //Point text_lb;//文本写在的位置
        //框出人脸
        string str;
        for (int i = 0; i < faces.size(); i++)
        {
            pImage_roi[i] = gray(faces[i]); //将所有的脸部保存起来
           // text_lb = Point(faces[i].x, faces[i].y);
            if (pImage_roi[i].empty())
                continue;
            switch (Predict(pImage_roi[i])) //对每张脸都识别
            {
            case 1:str = "HuangHaiNa"; break;
            case 2:str = "XuHaoRan"; break;
            case 5:str = "zhangfan"; break;
            default: str = "Error"; break;
            }
             cout <<str<<endl;
           /* Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));//所取的颜色任意值
            rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), color, 1, 8);//放入缓存
            putText(frame, str, text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));//添加文字
            */
        }

        delete[]pImage_roi;
        imshow("face", frame);
        waitKey(200);
    }

}
