//Canny filter : Without double thresholding

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>

using namespace cv;
using namespace std;       // Sobel filter has to be applied on seperate image.

int main(){      
        
        int sum = 0;
        int sumX = 0,sumY = 0;          
        int n=3; //Kernel size like 3x3
        int arr[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};
        int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
        int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
        int a,b = 0;

        int value = 0;

        double theta = 0;       
        Mat var1 = imread("scenery.png", 1);  // Original Image
        Mat sobel(var1.rows, var1.cols, CV_8UC1, Scalar(0));  //Sobel image
        Mat gray(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat gauss(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat final(var1.rows, var1.cols, CV_8UC1, Scalar(0));

        cvtColor(var1,gray,CV_RGB2GRAY);

    for(int a=0;a<3 ; a++)
    {
        for(int i=1 ; i < (var1.rows-2) ; i++){
                for(int j=1 ; j < (var1.cols-2) ; j++)
                {

                    //GAUSSIAN FILTER
                        for(int x = i-1; x < i+2 ; x++)
                        {
                            for(int y=j-1 ; y < j+2 ; y++)
                            {
                                sum = sum + (gray.at<uchar>(x,y) * arr[x-i+1][y-j+1]);
                            }
                        }
                        gauss.at<uchar>(i,j) = sum/16;
                        sum=0;

                        //SOBEL FILTER
                        for(int x = i-1; x < i+2 ; x++)
                        {
                            for(int y=j-1 ; y < j+2 ; y++)
                            {
                                //sum = sum + (var1.at<Vec3b>(x,y)[a] * arr[x-i][y-j]);
                                sumX = sumX + (gauss.at<uchar>(x,y) * Gx[x-i+1][y-j+1]);  //sumX represents total Gx
                                sumY = sumY + (gauss.at<uchar>(x,y) * Gy[x-i+1][y-j+1]);  //sumY represents total Gy
                            }
                        }
                        sobel.at<uchar>(i,j) = int(sqrt((sumX*sumX) + (sumY*sumY)));

                        if(sumX == 0)
                            {theta = 90;}
                        else{
                        theta = ((atan(sumY/sumX)+1.57)/3.14)*180;}

                        value = sobel.at<uchar>(i,j);


                        if( theta > 0 && theta < 45/2.0)
                        {
                            theta = 0;
                            if( value > sobel.at<uchar>(i,j-1) && value > sobel.at<uchar>(i,j+1))
                            {final.at<uchar>(i,j) = 255;}
                            else
                            {final.at<uchar>(i,j) = 0;}
                        }

                        if( theta >= 45/2.0 && theta < 135/2.0)
                        {
                            theta = 45;
                            if( value > sobel.at<uchar>(i+1,j-1) && value > sobel.at<uchar>(i-1,j+1))
                            {final.at<uchar>(i,j) = 255;}
                            else
                            {final.at<uchar>(i,j) = 0;}
                        }

                        if( theta >= 135/2.0 && theta < 225/2)
                        {
                            theta = 90;
                            if( value > sobel.at<uchar>(i+1,j) && value > sobel.at<uchar>(i-1,j))
                            {final.at<uchar>(i,j) = 255;}
                            else
                            {final.at<uchar>(i,j) = 0;}
                        }

                        if( theta > 225/2 )
                        {
                            theta = 135;
                            if( value > sobel.at<uchar>(i-1,j-1) && value > sobel.at<uchar>(i+1,j+1))
                            {final.at<uchar>(i,j) = 255;}
                            else
                            {final.at<uchar>(i,j) = 0;}
                        }

                        sumX=0;
                        sumY=0;
                        //var1.at<Vec3b>(i+1,j+1)[a] = sum/16 ;
                        //sum=0;
                }
        }
    }

        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", var1);
        namedWindow("Final image", WINDOW_AUTOSIZE);
        imshow("Final image", final);

        waitKey(0);
        return 0;
}       
