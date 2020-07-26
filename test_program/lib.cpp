#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include<string>
#include "lib.hpp"
using namespace cv;
using namespace std;

void BasicFunctionality::displayImage(string path){

    image= imread(path, CV_LOAD_IMAGE_COLOR);
    namedWindow( "Image ", WINDOW_AUTOSIZE );
    imshow( "Image", image ); 

    waitKey(0);
}

