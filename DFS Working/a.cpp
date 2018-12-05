#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace cv;
using namespace std;

Mat img=imread("./binarydfs.jpg",0);
Mat anim(img.rows,img.cols,CV_8UC1,Scalar(0));

int isvalid(int i, int j)
{
	if( (i<0)||(j<0)||(i>=img.rows)||(j>=img.cols))
		return 0;
	else return 1;
}

void dfs(int i, int j, Mat img)
{
	namedWindow("anim",WINDOW_NORMAL);
	img.at<uchar>(i,j)=255;
	anim.at<uchar>(i,j)=255;
	imshow("anim",anim);
	waitKey(1);
	if(isvalid(i-1,j)&&(img.at<uchar>(i-1,j)==0))
		dfs(i-1,j,img);
	if(isvalid(i+1,j)&&(img.at<uchar>(i+1,j)==0))
		dfs(i+1,j,img);
	if(isvalid(i,j-1)&&(img.at<uchar>(i,j-1)==0))
		dfs(i,j-1,img);
	if(isvalid(i,j+1)&&(img.at<uchar>(i,j+1)==0))
		dfs(i,j+1,img);
	else return;
}

int main()
{
	namedWindow("bnw",WINDOW_NORMAL);
	Mat img=imread("./binarydfs.jpg",0);
	Mat bwimg(img.rows,img.cols,CV_8UC1,Scalar(0));
	int i,j,obj=0;
	for(i=0;i<img.rows;i++)
	{
		for(j=0;j<img.cols;j++)
		{
			if(img.at<uchar>(i,j)>100)
				bwimg.at<uchar>(i,j)=255;
		}
	}
	imshow("bnw",bwimg);
	/*
	for(i=0;i<bwimg.rows;i++)
	{
		for(j=0;j<bwimg.cols;j++)
		{
			if(bwimg.at<uchar>(i,j)==255)
				bwimg.at<uchar>(i,j)=0;
			else 
				bwimg.at<uchar>(i,j)=255;
		}		
	}
	namedWindow("img",WINDOW_NORMAL);
	imshow("img",bwimg);
	*/
	//int count=0;
	for(i=0;i<bwimg.rows;i++)
	{
		for(j=0;j<bwimg.cols;j++)
		{
			if(bwimg.at<uchar>(i,j)==0)
			{
				obj++;
				dfs(i,j,bwimg);
				/*
				for(int l=count;l<count+1;l++)
				{
					for(int m=0;m<img.cols;m++)
					{
						anim.at<uchar>(l,m)=255;

					}

				}
				count+=2;
				*/
			}
		}
	}
	cout<<obj<<endl;
	return 0;
}
