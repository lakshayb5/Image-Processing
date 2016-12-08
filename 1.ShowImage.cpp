*Read and display an image*

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat var1 = imread("pic.jpg",1); //coloured image, 0 - grayscale
	namedWindow("window1",WINDOW_AUTOSIZE);
	imshow("window1",var1);
	waitKey(0);
	return 0;
}
