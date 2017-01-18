#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

FILE *fp;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
	fprintf(fp, "A");
	fclose(fp);
     }
}

int main()
{
	while(1)
	{
		fp = fopen("/dev/ttyACM0", "w");
		Mat Original(400,400,CV_8UC3,Scalar(0,0,0));
		namedWindow("Original",WINDOW_AUTOSIZE);
        setMouseCallback("Original", CallBackFunc, NULL);

	imshow("Original", Original); 
	if(waitKey(30) == 'q')
        	break;
	}
	return 0;
}