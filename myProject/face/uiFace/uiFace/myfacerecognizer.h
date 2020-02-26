#ifndef MYFACERECOGNIZER_H
#define MYFACERECOGNIZER_H
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include<stdio.h>
#include<opencv2/face/facerec.hpp>

#include<opencv2/face.hpp>
#include<opencv2/core.hpp>

#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

#include <math.h>
#include <fstream>
#include <sstream>


using namespace cv;
using namespace cv::face;
using namespace std;
using namespace cv;
class myFaceRecognizer
{
   private:
    Ptr<FaceRecognizer> recognizerModel;
    CascadeClassifier recognizerCascade;
   public:
    myFaceRecognizer();
    takePicture( Mat frame);
    void train(string fn_csv);
    Mat norm_0_255(InputArray _src);
     void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';');
     void Recognizer(Mat frame);
     int Predict(Mat src_image);
};

#endif // MYFACERECOGNIZER_H
