// Erosion and dialation

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){
        int gray=0,red = 0, green=0, blue=0, binary = 0;
        int a = 0; //Threshold value for binary
        int sum = 0;

        Mat var1 = imread("pic.jpg", 1);  //BGR values
        Mat gray_img(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat binary_img(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat eroded(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat dilated(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        
        //create Trackbar
        namedWindow("Binary Window", WINDOW_AUTOSIZE);
        createTrackbar("Track", "Binary Window",&a,255);

        while(1)
        {
        for(int i=0 ; i < var1.rows ; i++){
                for(int j=0 ; j < var1.cols ; j++)
                {

                        blue = var1.at<Vec3b>(i,j)[0];
                        green = var1.at<Vec3b>(i,j)[1];
                        red = var1.at<Vec3b>(i,j)[2];
                        
                        gray = (red+green+blue)/3 ; // Grayscale image
                        gray_img.at<uchar>(i,j) = gray ;

                        if(gray > a)  // Binary : 80 is the threshold value for binary
                                binary_img.at<uchar>(i,j) = 0;
                        else
                                binary_img.at<uchar>(i,j) = 255;

                 }
            }

            //EROSION 
        for(int i=1;i<var1.rows-2;i++)
        {
            for(int j=1;j<var1.cols-2;j++)
            {
                for(int x = i-1; x< i+2;x++)
                {
                    for(int y=j-1;y<j+2;y++)
                    {
                        sum = sum + binary_img.at<uchar>(x,y);
                    }
                }

                if(sum == 2295) //IF all are 255, centre is 255
                    eroded.at<uchar>(i,j) = 255;
                else
                    eroded.at<uchar>(i,j) = 0;
                 sum = 0;
            }
        }

            //DILATED
        for(int i=1;i<var1.rows-2;i++)
        {
            for(int j=1;j<var1.cols-2;j++)
            {
                for(int x = i-1; x< i+2;x++)
                {
                    for(int y=j-1;y<j+2;y++)
                    {
                        sum = sum + eroded.at<uchar>(x,y);
                    }
                }

                if(sum >250) //If one is 255, centre is 255
                    dilated.at<uchar>(i,j) = 255;
                else
                    dilated.at<uchar>(i,j) = 0;
                 sum = 0;
            }
        }

                imshow("Binary Window", binary_img); //Trackbar
                imshow("Eroded image", eroded);
                imshow("Dilated image", dilated);
                namedWindow("Original",WINDOW_AUTOSIZE); //Original
                imshow("Original", var1);
                waitKey(100);  //refresh every 100ms
        }

       /* namedWindow("window1",WINDOW_AUTOSIZE); //Original
        imshow("window1", var1);
        namedWindow("window2", WINDOW_AUTOSIZE); //Grayscale
        imshow("window2", gray_img);
        namedWindow("window3", WINDOW_AUTOSIZE); //Binary
        imshow("window3", binary_img);*/
        
        return 0;
}

