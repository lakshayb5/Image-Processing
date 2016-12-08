//Using DFS to make a paint bucket tool

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stack>
#include <iostream>

using namespace cv;
using namespace std;

int flag = 0;
int i,j;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          i=y;
          j=x;
          flag = 1;
     }
}

int main()
{
	Mat original = imread("shape.jpg", 1);
	Mat blob(original.rows,original.cols,CV_8UC1,Scalar(0));
	Mat final(original.rows,original.cols,CV_8UC3,Scalar(0,0,0));
	//Mat visited(original.rows,original.cols,CV_8UC1,Scalar(0));
	int count = 0;

	namedWindow("Original",WINDOW_AUTOSIZE);
        setMouseCallback("Original", CallBackFunc, NULL);

	stack<Point2d> s;

	while(1)
	{

	if(flag == 1)
	{
		flag = 0;
			if(original.at<Vec3b>(i,j)[2] >248 && original.at<Vec3b>(i,j)[1] >248 && original.at<Vec3b>(i,j)[0] >248 && blob.at<uchar>(i,j) == 0)
			{
				s.push(Point2d(i,j));
				blob.at<uchar>(i,j) = 255;
				final.at<Vec3b>(i,j)[0] = 255;
				//final.at<Vec3b>(i,j)[1] = 0;
				//final.at<Vec3b>(i,j)[2] = 0;
				original.at<Vec3b>(i,j)[0] = 255;
				original.at<Vec3b>(i,j)[1] = 0;
				original.at<Vec3b>(i,j)[2] = 0;

				while(s.empty() == 0)
				{
					Point2d Top = s.top();
					s.pop();
					//blob.at<uchar>(Top.x,Top.y) = 255;

					for(int a=Top.x-1; a < Top.x+2; a++)
					{
						for(int b=Top.y-1; b< Top.y+2; b++)
						{
							if(original.at<Vec3b>(a,b)[2] >248 && original.at<Vec3b>(a,b)[1] >248 && original.at<Vec3b>(a,b)[0] >248 && blob.at<uchar>(a,b) == 0)
							{
								//visited.at<uchar>(x,y) = 255;
								blob.at<uchar>(a,b) = 255;
								final.at<Vec3b>(a,b)[0] = 255;
								//final.at<Vec3b>(a,b)[1] = 0;
								//final.at<Vec3b>(a,b)[2] = 0;
								original.at<Vec3b>(a,b)[0] = 255;
								original.at<Vec3b>(a,b)[1] = 0;
								original.at<Vec3b>(a,b)[2] = 0;
								s.push(Point2d(a,b));
								cout << "working" << endl;
							}
						}
					}
				}
			}

        }
        //namedWindow("Blobs", WINDOW_AUTOSIZE);
        //imshow("Blobs", blob);
        imshow("Original", original); // Here for printing colour on this
        namedWindow("Final",WINDOW_AUTOSIZE);
        imshow("Final", final);
        //cout << count << endl;
        if(waitKey(10) == 'q')
        	break;
	}
        return 0;
}