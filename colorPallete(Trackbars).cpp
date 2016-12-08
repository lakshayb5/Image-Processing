#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){
        int a = 0,b=0,c=0;
        Mat var1(600, 600, CV_8UC3, Scalar(0,0,0));
       
        namedWindow("colour", WINDOW_AUTOSIZE);
        createTrackbar("blue", "colour",&a,255);
        createTrackbar("green", "colour",&b,255);
        createTrackbar("red", "colour",&c,255);

        while(1)
        {
        for(int i=0 ; i < var1.rows ; i++){
                for(int j=0 ; j < var1.cols ; j++)
                {

                        var1.at<Vec3b>(i,j)[0] = a;
                        var1.at<Vec3b>(i,j)[1] = b;
                        var1.at<Vec3b>(i,j)[2] = c;                  

                 }
                }

                namedWindow("colour",WINDOW_AUTOSIZE); //Original
                imshow("colour", var1);
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
