#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;       //HISTOGRAM

int main(){

        int redvalue = 0,bluevalue = 0, greenvalue = 0;
        int RedCount[256];

        for(int i=0; i <256 ; i++)
        {
                RedCount[i] = 0;
        }

        Mat var1 = imread("pic.jpg", 1);  //BGR
        Mat histogram(300, 256, CV_8UC3, Scalar(0,0,0));

        //namedWindow("Trackbar",WINDOW_AUTOSIZE);
        //createTrackbar("Red","Trackbar", &redvalue, 255 );
        
        
        //while(1){
        for(int i=0 ; i < var1.rows ; i++){
                for(int j=0 ; j < var1.cols ; j++)
                {
                        redvalue = var1.at<Vec3b>(i,j)[2];
                        if(redvalue > 0)
                                RedCount[redvalue-1]++ ;
                }
        }

        for(int j=0 ; j < 256 ; j++){
                for(int i = 0; i < RedCount[j]/30; i++){
                        histogram.at<Vec3b>(i,j)[2] = 255;               
                        histogram.at<Vec3b>(i,j)[0] = 0;
                        histogram.at<Vec3b>(i,j)[1] = 0;
                }
        }
        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", var1);
        namedWindow("window", WINDOW_AUTOSIZE);
        imshow("window", histogram);

        waitKey(0);
       // }
        return 0;
}       

