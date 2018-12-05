#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int maxim(int a,int b,int c)
{
	if( (a>=b)&&(a>=c) )
		return a;
	else if( (b>=c)&&(b>=a) )
		return b;
	else return c;
}

int minim(int a,int b,int c)
{
	if( (a<=b)&&(a<=c) )
		return a;
	else if( (b<=c)&&(b<=a) )
		return b;
	else return c;
}

int main() {

	int i,j;
    namedWindow("lenna", WINDOW_NORMAL);
    Mat img = imread("./lenna.jpg", 1);
    Mat greyimg(img.rows,img.cols,CV_8UC1,Scalar(0));
    for(i=0;i<img.rows;i++)
    {
    	for(j=0;j<img.cols;j++)
    	{
    		greyimg.at<uchar>(i,j)=( maxim(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]) - minim(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]) )/2;
    		
    	}
    }
    imwrite("lennagreymaxmin1.jpg",greyimg);
    waitKey(0);
    return 0;
}
