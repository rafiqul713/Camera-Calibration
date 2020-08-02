/*
    https://www.learnopencv.com/camera-calibration-using-opencv/
*/

#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <iostream>
#include "calibration.hpp"

using namespace std;
using namespace cv;

int *Board; //chess board dimension
vector<Point3f> object_point;
vector<vector<Point3f> > objects_points;
vector<vector<Point2f> > image_points;
vector<String> images;
string path;
vector<Point2f> corner_points;

Mat camera_matrix,distance_coeffiecient,rotation_vector,translation_vector;
Mat image, gray_scale_image;


void MyCalibration::initialization(){
  for(int i=0; i<Board[1];i++){
      for(int j=0; j<Board[0]; j++){
          object_point.push_back(Point3f(j,i,0));
        }
    }
}

void MyCalibration::configure_board(int row, int col){
  Board= new int[2]{row,col};
}

void MyCalibration::print_calibrated_result(){
  cout << "Camera Matrix : " << camera_matrix << endl;
  cout << "Distance Coefficient : " << distance_coeffiecient << endl;
  cout << "Rotation vector : " << rotation_vector << endl;
  cout << "Translation vector : " << translation_vector << endl;

}

void MyCalibration::input_directory(string p){
  path=p;
}
void MyCalibration::calibration_process(){
  glob(path, images);
  for(unsigned int i=0; i<images.size(); i++){
    image = imread(images[i]);
    cvtColor(image,gray_scale_image,COLOR_BGR2GRAY);
    if(findChessboardCorners(gray_scale_image,Size(Board[0],Board[1]), corner_points,CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE)){
      TermCriteria criteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.001);
      cornerSubPix(gray_scale_image,corner_points,Size(20,20), Size(-1,-1),criteria);
      drawChessboardCorners(image, Size(Board[0],Board[1]), corner_points,1);
      objects_points.push_back(object_point);
      image_points.push_back(corner_points);
    }

    imshow("Image",image);
    waitKey(1000);
  }

  destroyAllWindows();
  calibrateCamera(objects_points, image_points,Size(gray_scale_image.rows,gray_scale_image.cols),camera_matrix,distance_coeffiecient,rotation_vector,translation_vector);

}


