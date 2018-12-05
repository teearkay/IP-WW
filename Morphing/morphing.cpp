#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img1 = imread("./img1.jpg",1);
Mat img2 = imread("./img2.jpeg",1);

void callback (int x, void* c)
{
	namedWindow("mrphing",WINDOW_NORMAL);
	int i,j,k;
	Mat img1 = imread("./img1.jpg",1);
	Mat img2 = imread("./img2.jpeg",1);
	Mat mphimg(img1.rows,img1.cols,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img1.rows;i++)
	{
		for(j=0;j<img1.cols;j++)
		{
			for(k=0;k<3;k++)
			{
				mphimg.at<Vec3b>(i,j)[k]= img1.at<Vec3b>(i,j)[k]*x/100 + img2.at<Vec3b>(i,j)[k]*(100-x)/100;
			}			
		}
	}
	imshow("mrphing",mphimg);
}

int main()
{
	int x=0;
	namedWindow("mrphing",WINDOW_NORMAL);
	createTrackbar("mrph","mrphing", &x, 100, callback);
	waitKey(0);
	return 0;
}
