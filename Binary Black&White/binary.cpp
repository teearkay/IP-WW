#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img=imread("./lenna.jpg",0);

void callback(int low, void* param)
{
	int i,j;
	Mat img=imread("./lenna.jpg",0);
 	for(i=0;i<img.rows;i++)
 	{
 		for(j=0;j<img.cols;j++)
 		{
 			if( img.at<uchar>(i,j) > low)
 				img.at<uchar>(i,j)=255;
 			else
 				img.at<uchar>(i,j)=0;
 		}
 	}
 	imshow("lenna",img);
}

int main()
{
	int var=127;
	namedWindow("lenna",WINDOW_NORMAL);
	createTrackbar("B&W", "lenna", &var, 255,callback);
	waitKey(0);
	return 0;
}
