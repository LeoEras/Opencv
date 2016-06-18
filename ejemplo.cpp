#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{  double min, max;
   Mat image = imread(argv[1]);
   
   imshow( "Color Image", image );
   vector<Mat> planes(3); // Vector is template vector class, similar to STL's vector. It can store matrices too.
   split(image, planes); // split the image into separate color planes

/*MatIterator_<uchar> it = planes[0].begin<uchar>(), it_end = planes[0].end<uchar>();
   for(; it != it_end; ++it)
    {
        double v = *it;
	cout << v << " ";
    }
*/

/*for(int i = 0; i < image.rows; i++)
   {
     for(int j = 0; j < image.cols; j++)
      {
        Vec3b pixel = image.at<Vec3b>(i, j);
	double v =pixel[0];
        cout << v << " ";
      }
   }*/

   Rect r(10,100, 50,100);
   Mat smallImg = planes[1](r);
   imshow( "smallImg", smallImg );

   minMaxLoc(smallImg, &min, &max);
   cout  << min <<";" << max;
   Mat result_test= planes[0] > 100;
   imshow( "resultado", result_test);

   waitKey(0);
   return 0;
}
