#include<opencv2/opencv.hpp>
#include<opencv2/calib3d/calib3d.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

class MyCalibration{
	public:
		void configure_board(int,int);
		void initialization();
		void input_directory(std::string);
		void print_calibrated_result();
		void calibration_process();

};
