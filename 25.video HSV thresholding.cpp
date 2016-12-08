//Erosion and dilation

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){

    int H_lowthresh = 0,H_highthresh = 0,S_lowthresh = 0,S_highthresh = 0,V_lowthresh = 0,V_highthresh = 0;
        
        Mat img;
        Mat thresh;
        Mat HSV;
        namedWindow("Threshold", WINDOW_AUTOSIZE);
        namedWindow("Video", WINDOW_AUTOSIZE);
        createTrackbar("Low H","Threshold",&H_lowthresh,180);
        createTrackbar("High H","Threshold",&H_highthresh,180);
        createTrackbar("Low S","Threshold",&S_lowthresh,255);
        createTrackbar("High S","Threshold",&S_highthresh,255);
        createTrackbar("Low V","Threshold",&V_lowthresh,255);
        createTrackbar("High V","Threshold",&V_highthresh,255);

        VideoCapture a(0);
        while(a.isOpened())
        {
            a>>img;
            cvtColor(img, HSV, CV_BGR2HSV);
            inRange(HSV,Scalar(H_lowthresh,S_lowthresh,V_lowthresh), Scalar(H_highthresh,S_highthresh,V_highthresh),thresh);

            imshow("Thresholded",thresh);
            imshow("Video",img);
            //imshow("HSV",HSV);
            if(waitKey(30)=='q')
            {
            //imwrite("video.png",img);
            break;
            }
        }
        return 0;
        //waitKey(100);  //refresh every 100ms       
}

/* 
thresh_callback)
void thresh_callback(int, void*)
{
    
}

thresh_callback(0,0)
*/