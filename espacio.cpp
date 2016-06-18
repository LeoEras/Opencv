#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
	float r;
	double min, max;
	cv::Mat img = cv::imread(argv[1]);
	cv::Mat HSV, green1, green2, realgreen;
	
	//Original
	namedWindow("Original", WINDOW_AUTOSIZE );
	imshow("Original", img);

	//En HSV
	cvtColor(img, HSV, CV_BGR2HSV);
	vector<Mat> planes(3);
	split(HSV, planes);
	imshow("S", planes[2]);
	minMaxLoc(planes[0], &min, &max);
	cout  << min <<";" << max;

	//Deteccion de color verde
	green1 = planes[0] > 30;
	green2 = planes[0] < 90;
	cv::bitwise_and(green1, green2, realgreen);
	imshow("resultado", realgreen);

	waitKey(0);
	return 0;
}

