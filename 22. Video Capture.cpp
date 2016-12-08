//Video Capture

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(){

    int lowthresh = 0;
        
        VideoCapture a(0);
        Mat img;
        Mat edges;
        namedWindow("Edges", WINDOW_AUTOSIZE);
        namedWindow("Video", WINDOW_AUTOSIZE);
        createTrackbar("Bar","Video",&lowthresh,100);
        while(a.isOpened())
        {
            a>>img;
            imshow("Video",img);
            if(waitKey(30)=='q') //quit on keypress q
            {
            return 0;
            }
        }


        //waitKey(100);  //refresh every 100ms       
}

