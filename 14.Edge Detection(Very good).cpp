//First order method for edge detection 

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <cmath>
using namespace cv;
using namespace std;       // Sobel filter has to be applied on seperate image.

int main(){      
        
        int threshold = 20;
        float Xval = 0,Yval = 0;    //Xval is the sum of the vertical elements next to centre after multiplying with array 
        int x=0,y=0;
        int Lx[3] = {-1,0,1};
        int Ly[3] = {1,0,-1};  
        double L=0;     
        
        Mat var1 = imread("scenery.png", 1);  // Original Image
        Mat gray(var1.rows, var1.cols, CV_8UC1, Scalar(0));
        Mat final(var1.rows, var1.cols, CV_8UC1, Scalar(0));  //final image

        cvtColor(var1, gray, CV_RGB2GRAY);

        namedWindow("Edges", WINDOW_AUTOSIZE);
        createTrackbar("Edge", "Edges",&threshold ,255);

    while(1){
        for(int i=1 ; i < (var1.rows-1) ; i++){
                for(int j=1 ; j < (var1.cols-1) ; j++)
                {
                        for( x = j-1; x < j+2 ; x++)
                        {
                                Xval = Xval + (gray.at<uchar>(i,x) * Lx[x-j+1])/2;
                        }
                        for( y= i-1; y<i+2; y++)
                        {
                            Yval = Yval + (gray.at<uchar>(y,j) * Ly[y-i+1])/2;
                        }

                        L = sqrt(double(Xval*Xval) + double(Yval*Yval));
                            if(L > threshold)   
                                final.at<uchar>(i,j) = 255 ;
                            else
                                final.at<uchar>(i,j) = 0;
                        Xval = 0;
                        Yval = 0;
                        //var1.at<Vec3b>(i+1,j+1)[a] = sum/16 ;
                        //sum=0;
                }
        }
    
        namedWindow("Original",WINDOW_AUTOSIZE);
        imshow("Original", var1);
        namedWindow("gray image", WINDOW_AUTOSIZE);
        imshow("gray image", gray);
        namedWindow("Edges", WINDOW_AUTOSIZE);
        imshow("Edges", final);

        waitKey(100);
    }
        return 0;
}       
