//General mean filter

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>

using namespace cv;
using namespace std;       

//General Mean filter. 
//'n' sets kernel size
//Variated with taskbar

//Floating point exception when n=0

int main(){      
        int row1 = 0,row2 = 0, row3 = 0;
        int sum = 0;
        int n=3; //Kernel size like 3x3
        
        //Mat var = imread("pic.jpg", 1);  //BGR
        Mat var1 = imread("pic.jpg", 1);
        Mat blur(var1.rows, var1.cols, CV_8UC3, Scalar(0,0,0));   
        namedWindow("Trackbar",WINDOW_AUTOSIZE);
       createTrackbar("Blur","Trackbar", &n, 4);    
        
        while(1){

    for(int a=0 ; a<3 ; a++)
    {
        for(int i=0 ; i < (var1.rows-n) ; i++){
                for(int j=0 ; j < (var1.cols-n) ; j++)
                {
                        for(int x = i; x < i+n ; x++)
                        {
                            for(int y=j ; y < j+n ; y++)
                            {
                                sum = sum + var1.at<Vec3b>(x,y)[a];
                            }
                        }
                        blur.at<Vec3b>((i+(n-1)/2),(j+(n-1)/2))[a] = int(sum/(n*n));
                        sum=0;
                }
        }
    }

        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", var1);
        namedWindow("Blurred image", WINDOW_AUTOSIZE);
        imshow("Blurred image", blur);

        waitKey(100);
        }
        return 0;
}       

