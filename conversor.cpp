#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
	float r;
	cv::Mat img = cv::imread(argv[1]);
	cv::Mat gray, xXYZ, rgb;
	
	//Original
	cvtColor(img, rgb, CV_BGR2RGB);
	namedWindow("RGB", WINDOW_AUTOSIZE );
	imshow("RGB", img);

	//A gris
	cvtColor(img, gray, CV_BGR2GRAY);

	namedWindow("Gris", WINDOW_AUTOSIZE );
	imshow("Gris", gray);
	
	//A rojo
	vector<Mat> planes(3);
	split(img, planes);

	namedWindow("R en RGB", WINDOW_AUTOSIZE );
	imshow("R en RGB", planes[2]);

	//A XYZ
	vector<Mat> planes2(3);
	cvtColor(img, xXYZ, CV_BGR2XYZ);
	split(xXYZ, planes2);
	namedWindow("X en XYZ", WINDOW_AUTOSIZE );
	imshow("X en XYZ", planes2[0]);

	waitKey(0);
	return 0;
}

