//Blob detectionn using Depth First Search(DFS)

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stack>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat original = imread("pic.jpg", 1);
	Mat blob(original.rows,original.cols,CV_8UC1,Scalar(0));
	//Mat visited(original.rows,original.cols,CV_8UC1,Scalar(0));
	int count = 0;

	stack<Point2d> s;

	for(int i=0;i<original.rows;i++)
	{
		for(int j=0;j<original.cols;j++)
		{
			if(original.at<Vec3b>(i,j)[2] >200 && blob.at<uchar>(i,j) == 0)
			{
				s.push(Point2d(i,j));
				blob.at<uchar>(i,j) = 255;
				count++;

				while(s.empty() == 0)
				{
					Point2d Top = s.top();
					s.pop();
					//blob.at<uchar>(Top.x,Top.y) = 255;

					for(int a=Top.x-1; a < Top.x+2; a++)
					{
						for(int b=Top.y-1; b< Top.y+2; b++)
						{
							if(original.at<Vec3b>(a,b)[2] > 200 && blob.at<uchar>(a,b) == 0)
							{
								//visited.at<uchar>(x,y) = 255;
								blob.at<uchar>(a,b) = 255;
								s.push(Point2d(a,b));
							}
						}
					}
				}
			}

		}
	}
        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", original);
        namedWindow("Blobs", WINDOW_AUTOSIZE);
        imshow("Blobs", blob);
        cout << count << endl;
        waitKey(0);
        return 0;
}