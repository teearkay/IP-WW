#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace cv;
using namespace std;
#define pi 3.14159
#define wid 5

int main()
{
	namedWindow("hough",WINDOW_NORMAL);
	namedWindow("houghinit",WINDOW_NORMAL);
	int i,j,x;
	Mat img=imread("./pentagon.png",0);
	Mat bwimg(img.rows,img.cols,CV_8UC1,Scalar(0));
	int rmax=sqrt(pow(img.rows,2)+pow(img.cols,2));
	//cout << rmax;
	Mat hough(rmax,800,CV_8UC1,Scalar(0));
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)>180)
				bwimg.at<uchar>(i,j)=255;
			else
				bwimg.at<uchar>(i,j)=0;
		}
	}
	imshow("bnw",bwimg);
	int r;
	for(i=0;i<bwimg.rows;i++)
	{
		for(j=0;j<bwimg.cols;j++)
		{
			if(bwimg.at<uchar>(i,j)==255)
			{	
				for(x=0;x<=360;x++)//use x/10 everywhere!!
				{
					/*
						we have to draw graph b/w r and x at every point where 
						pixels are white.
					*/
					r=(int)(j*cos(x*(pi/180))+i*sin(x*(pi/180)));
					if (r<0)
						continue;
					hough.at<uchar>(r,x)+=2;
					if(hough.at<uchar>(r,x)>=255)
					{
						hough.at<uchar>(r,x)=255;
						//cout<< "y" <<" " <<"r: " << r << " x: " << x <<endl;
					}
					//cout<<rmax <<" " <<r <<endl;
					
				}	
			}
		}
	}
	imshow("houghinit",hough);
	int l,m;
	int cnt=0;
	int z[7];
	int y[7];
	for(i=0;i<hough.rows;i++)
	{
		for(j=0;j<hough.cols;j++)
		{
			if(hough.at<uchar>(i,j)>140)
			{
				z[cnt]=i;
				y[cnt]=j;
				//cout<< i <<" "<<j<<endl;
				//cout<< z[cnt] <<" "<< y[cnt] <<endl;
				cnt++;
				for(l=i-wid;l<i+wid+1;l++)
				{
					for(m=j-wid;m<j+wid+1;m++)
					{
						hough.at<uchar>(l,m)=0;
					}
				}
			}
		}
	}
	for(i=0;i<hough.rows;i++)
	{
		for(j=0;j<hough.cols;j++)
		{
			if(hough.at<uchar>(i,j)<140)
				hough.at<uchar>(i,j)=0;
		}
	}
	for(i=0;i<cnt;i++)
	{
		cout << z[i] << " " <<y[i] <<endl; 
	}

	for(i=0;i<hough.rows;i++)
	{
		for(j=0;j<hough.cols;j++)
		{
			for(int k=0;k<cnt;k++)
			{
				if((int)(j*cos(y[k]*(pi/180))+i*sin(y[k]*(pi/180)))==z[k])
					hough.at<uchar>(i,j)=255;

			}
		}
	}
	imshow("hough",hough);
	waitKey(0);
	return 0;
}