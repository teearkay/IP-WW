#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img=imread("./a.png",1);

int rl=0, rh=255, gl=0, gh=255, bl=0, bh=255;

void callback(int low,void* c)
{
	int i,j;
	Mat img=imread("./a.png",1);
	for(i=0;i<img.rows;i++)
 	{
 		for(j=0;j<img.cols;j++)
 		{
 			if( (img.at<Vec3b>(i,j)[2] > rl)&&(img.at<Vec3b>(i,j)[2] < rh)&&(img.at<Vec3b>(i,j)[1] > gl)&&(img.at<Vec3b>(i,j)[1] < gh)&&(img.at<Vec3b>(i,j)[0] > bl)&&(img.at<Vec3b>(i,j)[0] < bh) );
	 		else
	 		{
	 			img.at<Vec3b>(i,j)[2] = 0;
	 			img.at<Vec3b>(i,j)[1] = 0;
	 			img.at<Vec3b>(i,j)[0] = 0;
	 		}
 		}
 		//use if elses for each loop structure
 	}
 	imshow("segment",img);
}

int main()
{
	namedWindow("segment", WINDOW_NORMAL);
	createTrackbar("Red High","segment",&rh,255,callback);
	createTrackbar("Green High","segment",&gh,255,callback);
	createTrackbar("Blue High","segment",&bh,255,callback);
	createTrackbar("Red Low","segment",&rl,255,callback);
	createTrackbar("Green Low","segment",&gl,255,callback);
	createTrackbar("Blue Low","segment",&bl,255,callback);
	waitKey(0);
	return 0;
}
