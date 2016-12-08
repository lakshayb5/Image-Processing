//Converting BGR image to grayscale

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

/* Direct function for converting BGR/RGB image to grayscale
 cvtColor(inputMatVariable, outputMatVariable, #);
 # : CV_RGB2GRAY, CV_BGR2HSV, CV_HSV2BGR */

int main(){
        int gray=0,red = 0, green=0, blue=0;

        Mat var1 = imread("pic.jpg", 1);
        Mat gray_img(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        //Mat gray = imread("pic.jpg",0);
        for(int i=0 ; i < var1.rows ; i++){
                for(int j=0 ; j < var1.cols ; j++)
                {

                        blue = var1.at<Vec3b>(i,j)[0];
                        green = var1.at<Vec3b>(i,j)[1];
                        red = var1.at<Vec3b>(i,j)[2];
                        gray = (red+green+blue)/3 ; //Taking average
                        gray_img.at<uchar>(i,j) = gray ;
                }
        }
       
        imshow("window1", var1);
        imshow("window2", gray_img);
        waitKey(0);
        return 0;
}

