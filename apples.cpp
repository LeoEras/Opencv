#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
	cv::Mat img = cv::imread(argv[1]);
	cv::Mat red1, red2, realred, HSV;
	
	//Original
	namedWindow("Original", WINDOW_AUTOSIZE );
	imshow("Original", img);

	//En HSV
	cvtColor(img, HSV, CV_BGR2HSV);

	vector<Mat> planes(3);
	split(HSV, planes);

	//Deteccion de color rojo
	red1 = planes[0] > 170;
	red2 = planes[0] < 10;
	cv::bitwise_or(red1, red2, realred);
	imshow("resultado", realred);

	waitKey(0);
	return 0;
}

