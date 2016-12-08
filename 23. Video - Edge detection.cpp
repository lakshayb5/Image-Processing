//Erosion and dilation

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
            cvtColor(img, edges, CV_BGR2GRAY);
            GaussianBlur(edges,edges,Size(7,7),1.5,1.5);
            Canny(edges,edges,lowthresh,3*lowthresh,3);
            imshow("Edges",edges);
            imshow("Video",img);
            if(waitKey(30)=='q')
            {
            imwrite("video.png",img);
            return 0;
            }
        }


        //waitKey(100);  //refresh every 100ms       
}

