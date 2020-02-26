#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "myfacerecognizer.h"
//#include <stdio.h>
//#include <cv.h>
RNG g_rng(12345);
using namespace std;
using namespace cv;
int main()
{
    myFaceRecognizer * face=new myFaceRecognizer();
   // face->takePicture();
    face->Recognizer();
    return 0;
}



