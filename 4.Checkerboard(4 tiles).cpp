//Checkerboard - 4 tiles

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){
        Mat var1( 600,600,CV_8UC1,Scalar(0));  //rows,columns

        for(int i=0; i<var1.rows; i++){
        	for(int j=0; j<var1.cols; j++){

                      if(i<300)
                      {  
        		if(j < 300)
        			{
        			var1.at<uchar>(i,j) = 255; 
        			} //Template function - blue
        		else
        		{
        			var1.at<uchar>(i,j) = 0;
        		}
                      }

                      else
                      {
                        if(j < 300)
                                {
                                var1.at<uchar>(i,j) = 0; 
                                } //Template function - blue
                        else
                        {
                                var1.at<uchar>(i,j) = 255;
                        }
                      }
        	} 
        }

        imshow("window1", var1);
        waitKey(0);
        return 0;
}

