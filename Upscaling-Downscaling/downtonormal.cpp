#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	int i,j;
	namedWindow("original",WINDOW_AUTOSIZE);
	namedWindow("upscaling",WINDOW_AUTOSIZE);
	Mat img=imread("./lennadownscaled.jpg",1);
	Mat newimg(img.rows*3,img.cols*3,CV_8UC3,Scalar(0,0,0));
	for(i=0;i<img.rows*3;i++)
	{
		for(j=0;j<img.cols*3;j++)
		{
			newimg.at<Vec3b>(i,j)=img.at<Vec3b>(i/3,j/3);
		}
	}
	imshow("original", img);
	imshow("upscaling", newimg);
	imwrite("downtonormal.jpg",newimg);
	//imwrite("upscaled.jpg",newimg);
	waitKey(0);
	return 0;
}
