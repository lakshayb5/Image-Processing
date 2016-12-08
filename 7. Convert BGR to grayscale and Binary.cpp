//Converting BGR to grayscale and binary

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){
        int gray=0,red = 0, green=0, blue=0, binary = 0;

        Mat var1 = imread("pic.jpg", 1);  //BGR values
        Mat gray_img(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat binary_img(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        //Mat gray = imread("pic.jpg",0);
        for(int i=0 ; i < var1.rows ; i++){
                for(int j=0 ; j < var1.cols ; j++)
                {

                        blue = var1.at<Vec3b>(i,j)[0];
                        green = var1.at<Vec3b>(i,j)[1];
                        red = var1.at<Vec3b>(i,j)[2];
                        
                        gray = (red+green+blue)/3 ; // Grayscale image
                        gray_img.at<uchar>(i,j) = gray ;

                        if(gray > 80)  // Binary : 80 is the threshold value for binary
                                binary_img.at<uchar>(i,j) = 0;
                        else
                                binary_img.at<uchar>(i,j) = 255;

                }
        }
        namedWindow("window1",WINDOW_AUTOSIZE); //Original
        imshow("window1", var1);
        namedWindow("window2", WINDOW_AUTOSIZE); //Grayscale
        imshow("window2", gray_img);
        namedWindow("window3", WINDOW_AUTOSIZE); //Binary
        imshow("window3", binary_img);
        waitKey(0);
        return 0;
}

