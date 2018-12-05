#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#define n 3

using namespace std;
using namespace cv;

Mat img=imread("./binarydfs.jpg",0);

int main()
{
	int remr, remc, i,j,k,nrow,ncol;
	namedWindow("downscale",WINDOW_AUTOSIZE);
	namedWindow("original",WINDOW_AUTOSIZE);
	Mat img=imread("./binarydfs.jpg",0);
	remr=img.rows%n;
	// remr is remainder of rows.
	remc=img.cols%n;
	
	// remainder of columns.
	
	Mat newimg(img.rows+remr, img.cols+remc, CV_8UC3, Scalar(0,0,0));
	
	//this code below, is for padding!
	
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			newimg.at<uchar>(i,j)=img.at<uchar>(i,j);
		}
	}
	for(;i<img.rows+remr;i++)
	{
		for(;j<img.cols+remc;j++)
		{
			newimg.at<uchar>(i,j)=0;	
		}
	}
	
	//now we have finished padding.
	nrow=img.rows+remr;
	ncol=img.cols+remc;

	Mat downimg(nrow/n,ncol/n,CV_8UC3,Scalar(0,0,0));
	
	for(i=0;i<nrow;i++)
	{
		for(j=0;j<ncol;j++)
		{
			downimg.at<uchar>(i/n,j/n) += newimg.at<uchar>(i,j)/ (n*n);
		}
	}
	imshow("donwscale",downimg);
	imshow("originalpadded",newimg);
	imwrite("scaled.jpg", downimg);
	waitKey(0);
	return 0;
}





