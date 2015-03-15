// opencvhaarcascadestrial1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2\imgproc\imgproc.hpp"
#include <stdio.h>
#include "opencv2\objdetect\objdetect.hpp"
using namespace cv;
using namespace std;

CascadeClassifier hand;
//CascadeClassifier eyes;
Mat frame3;


void detectAndDisplay(Mat frame);
String s="C:/opencv/sources/data/haarcascades/trialcascade.xml";     //cascade classifier for hand detection

int main( int argc, const char** argv )
{
	VideoCapture capture(0);
	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);

    // Mat img = imread("images.JPG", CV_LOAD_IMAGE_UNCHANGED);
	 if(!hand.load(s))
		 {
			 cout<<"no"<<endl;
	 }//read the image data in the file "MyPic.JPG" and store it in 'img'
	 while(true)
	 {
		
		 bool b=capture.read(frame3);
		 Mat frame2;
		 cvtColor(frame3,frame2,CV_RGB2GRAY);
		 equalizeHist(frame2,frame2);
		 detectAndDisplay(frame2);
		 waitKey(10);
	 }
	  destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
	 void detectAndDisplay(Mat frame)
{
	int w=50;
	int h=50;
	std::vector<Rect> hands;
	hand.detectMultiScale(frame,hands,1.1,3, 30|CV_HAAR_FIND_BIGGEST_OBJECT, Size(50, 200));
	 for( size_t i = 0; i < hands.size(); i++ )
  {
    Point center( hands[i].x + hands[i].width*0.5, hands[i].y + hands[i].height*0.5 );
    ellipse( frame3, center, Size( hands[i].width*0.5, hands[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
	 }

	 imshow("MyWindow",frame3);
}
    

      //create a window with the name "MyWindow"
      //display the image which is stored in the 'img' in the "MyWindow" window

      //wait infinite time for a keypress

    

