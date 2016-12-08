//Display a blue screen

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){
        Mat var1( 100,100,CV_8UC3,Scalar(0,0,0));
        for(int i=0; i<var1.cols; i++){
        	for(int j=0; j<var1.rows; j++){
        		var1.at<Vec3b>(i,j)[0] = 255;  //Template function - blue
        	} 
        }

        imshow("window1", var1);
        waitKey(0);
        return 0;
}