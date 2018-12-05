#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	int tc,tr,i,j,temporary[3];
	// t is total columns
    namedWindow("lenna", WINDOW_NORMAL);
    Mat img = imread("./lenna.jpg", 1);
    tc=img.cols;
	tr=img.rows;
    Mat newimg(tr,tc*2,CV_8UC3,Scalar(0,0,0));
    Mat origimg=imread("./lenna.jpg",1);
	for(i=0;i<tr;i++)
	{
		for(j=0;j<(tc/2);j++)
		{
			temporary[0]=img.at<Vec3b>(i,tc-j)[0];
			temporary[1]=img.at<Vec3b>(i,tc-j)[1];
			temporary[2]=img.at<Vec3b>(i,tc-j)[2];
			img.at<Vec3b>(i,tc-j)=img.at<Vec3b>(i,j);
			img.at<Vec3b>(i,j)[0]=temporary[0];
			img.at<Vec3b>(i,j)[1]=temporary[1];
			img.at<Vec3b>(i,j)[2]=temporary[2];
		}
	}
	for(i=0;i<tr;i++)
	{
		for(j=0;j<tc;j++)
		{
			newimg.at<Vec3b>(i,j)=origimg.at<Vec3b>(i,j);
		}
		for(j=tc;j<2*tc;j++)
		{
			newimg.at<Vec3b>(i,j)=img.at<Vec3b>(i,j-tc);
		}
	}
    imshow("lenna", img);
    imwrite("./newlenna.jpg",newimg);
    waitKey(0);
    return 0;
}
