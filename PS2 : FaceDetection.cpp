//#include "opencv2/objdetect.hpp"
//#include "opencv2/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include<deque>
#include <opencv2/core/core.hpp>
 #include <opencv2/objdetect/objdetect.hpp>
#include <string>
#include <sstream>

using namespace std;
using namespace cv;

CascadeClassifier face_cascade;
int count_person = 0;
int flag = 0;
int frame_visible = 0;

void detectAndDisplay( Mat img);

int main()
{
face_cascade.load("haarcascade_frontalface_default.xml");
	VideoCapture a("face.mp4");
	Mat img;
	Mat gray;
	namedWindow("Video", 1);
	while(a.isOpened())
        {
            a>>img;
            resize(img,img, Size(400,400),0,0,INTER_CUBIC);
            detectAndDisplay(img);
            imshow("Video",img);
           // cout << "Persons" <<count_person << endl; // Print number of persons
            if(waitKey(10)=='q') //quit on keypress q
            {
            	cout<< "Total number of people = "<< count_person << endl;
            return 0;
            }
        }
}

void detectAndDisplay( Mat frame)
{
// faces = face_cascade.detectMultiScale(gray, 1.3, 5);
//      for (x,y,w,h) in faces:
//          rectangle(img,(x,y),(x+w,y+h),(255,0,0),2);
//          roi_gray = gray[y:y+h, x:x+w];
//          roi_color = img[y:y+h, x:x+w];
	int prev = 1000;
	 std::vector<Rect> faces;
  Mat frame_gray;

  float x,y;

  cvtColor( frame,frame_gray, CV_BGR2GRAY );
  //-- Detect faces
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0, Size(30, 30) ); //|CV_HAAR_SCALE_IMAGE

  if( (!faces.size()) && flag == 1)
  {
  	flag = 0;
  	count_person++ ;
  	cout << "Persons = " << count_person<< endl;
  }

  for( size_t i = 0; i < faces.size(); i++ ) //Ellipse draw
  {
  	//x = faces[i].x + faces[i].width*0.5;
  	//y = faces[i].y + faces[i].height*0.5;

    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    ellipse( frame, center, Size( faces[i].width*0.8, faces[i].height*0.8), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

	frame_visible++;
  		if(frame_visible > 5)
  		{
  			flag = 1;
  			frame_visible = 0;
  		}

    //cout << faces[i].width << endl;
  }

  //-- Show what you got
  imshow( "Video", frame );
}