//Sobel filter

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>

using namespace cv;
using namespace std;       // Sobel filter has to be applied on seperate image.

int main(){      
        int row1 = 0,row2 = 0, row3 = 0;
        int sum = 0;
        int sumX = 0,sumY = 0;          
        int n=3; //Kernel size like 3x3
       // int arr[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};
        int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
        int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};       
        
        Mat var1 = imread("pic.jpg", 1);  // Original Image
        Mat var(var1.rows, var1.cols, CV_8UC3, Scalar(0, 0, 0));  //Sobel image

    for(int a=0;a<3 ; a++)
    {
        for(int i=0 ; i < (var1.rows-3) ; i++){
                for(int j=0 ; j < (var1.cols-3) ; j++)
                {
                        for(int x = i; x < i+3 ; x++)
                        {
                            for(int y=j ; y < j+3 ; y++)
                            {
                                //sum = sum + (var1.at<Vec3b>(x,y)[a] * arr[x-i][y-j]);
                                sumX = sumX + (var1.at<Vec3b>(x,y)[a] * Gx[x-i][y-j]);
                                sumY = sumY + (var1.at<Vec3b>(x,y)[a] * Gy[x-i][y-j]);
                            }
                        }
                        // if(sumX > 0)
                        //     sumX = sumX;
                        // else
                        //     sumX = -sumX;
                        var.at<Vec3b>(i+1,j+1)[a] = int(sqrt((sumX*sumX) + (sumY*sumY)));
                        sumX=0;
                        sumY=0;
                        //var1.at<Vec3b>(i+1,j+1)[a] = sum/16 ;
                        //sum=0;
                }
        }
    }

        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", var1);
        namedWindow("Blurred image", WINDOW_AUTOSIZE);
        imshow("Blurred image", var);

        waitKey(0);
        return 0;
}       
