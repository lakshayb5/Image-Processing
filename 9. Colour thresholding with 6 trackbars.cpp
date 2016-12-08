#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){
        int gray=0,red = 0, green=0, blue=0, binary = 0;
        int redvalue = 0,bluevalue = 0, greenvalue = 0;
        int delRed = 30, delBlue = 30, delGreen = 30; //Delta red. Tolerance value

        Mat var1 = imread("pic.jpg", 1);  //BGR
        Mat filter(var1.rows, var1.cols, CV_8UC3, Scalar(0,0,0));

        namedWindow("Trackbar",WINDOW_AUTOSIZE);
        createTrackbar("Red","Trackbar", &redvalue, 255 );
        createTrackbar("Green","Trackbar", &greenvalue, 255 );
        createTrackbar("Blue","Trackbar", &bluevalue, 255);
        createTrackbar("Red Tolerance","Trackbar", &delRed, 255 );
        createTrackbar("Green Tolerance","Trackbar", &delGreen, 255 );
        createTrackbar("Blue Tolerance","Trackbar", &delBlue, 255);
        
        while(1){
        for(int i=0 ; i < var1.rows ; i++){
                for(int j=0 ; j < var1.cols ; j++)
                {

                        blue = var1.at<Vec3b>(i,j)[0];
                        green = var1.at<Vec3b>(i,j)[1];
                        red = var1.at<Vec3b>(i,j)[2];

                        if( blue > (bluevalue - delBlue) && blue < (bluevalue + delBlue)) //Blue colour thresholding
                        {
                                filter.at<Vec3b>(i,j)[0] = blue;
                        }
                        else
                        {
                                filter.at<Vec3b>(i,j)[0] = 0;
                        }

                        if( green > (greenvalue - delGreen) && green < (greenvalue + delGreen)) //Green colour thresholding
                        {
                                filter.at<Vec3b>(i,j)[1] = green;
                        }
                        else
                        {
                                filter.at<Vec3b>(i,j)[1] = 0;
                        }

                        if( red > (redvalue - delRed) && red < (redvalue + delRed)) //Red colour thresholding
                        {
                                filter.at<Vec3b>(i,j)[2] = red;
                        }
                        else
                        {
                                filter.at<Vec3b>(i,j)[2] = 0;
                        }

                }
        }

        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", var1);
        namedWindow("window", WINDOW_AUTOSIZE);
        imshow("window", filter);

        waitKey(50);
        }
        return 0;
}       

