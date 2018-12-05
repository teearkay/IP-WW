#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;
#define pi 3.14

int main()
{
	namedWindow("vignette",WINDOW_NORMAL);
	Mat img=imread("rubik.jpg",1);
	Mat newimg(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	int i,j,r,R,rmax,x;
	cout << "Enter radius value: ";
	cin >> R;
	if(img.rows>img.cols)
		rmax=img.cols/2;
	else
		rmax=img.rows/2;
	int i0=img.rows/2;
	int j0=img.cols/2;
	for(r=0;r<R;r++)
	{
		for(x=0;x<=20000*pi;x++)
		{
			i=i0+r*cos(x);
			j=j0-r*sin(x);
			for(int k=0;k<3;k++){
			newimg.at<Vec3b>(i,j)[k]=img.at<Vec3b>(i,j)[k]*(R-r)/R;
		}
		}
	}		
	imshow("vignette",newimg);
	waitKey(0);
	return 0;
}