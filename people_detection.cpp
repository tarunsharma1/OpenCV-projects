// peopledetection3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// opencvhaarcascadestrial1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2\imgproc\imgproc.hpp"
#include <stdio.h>
#include "opencv2\objdetect\objdetect.hpp"
#include "opencv2\features2d\features2d.hpp"
#include "opencv2\objdetect\objdetect.hpp"
using namespace cv;
using namespace std;

CascadeClassifier face;
//CascadeClassifier eyes;

Mat frame3;
//HOGDescriptor face;

void detectAndDisplay(Mat frame);
String s="C:/opencv/sources/data/haarcascades/haarcascade_upperbody.xml";
//VideoCapture cap(0);
int main( int argc, const char** argv )
{
	
     //face.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	VideoCapture cap;
	cap.open("http://192.168.137.20:8081/?dummy=param.mjpg");
   
	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
	
	if(!cap.isOpened()) 
		{// check if we succeeded

                 return -1;
	}
	 //frame3 = imread("people4.jpg", CV_LOAD_IMAGE_UNCHANGED);
	 if(!face.load(s))
		 {
			 cout<<"no"<<endl;
	 }//read the image data in the file "MyPic.JPG" and store it in 'img'
	 while(true)
	 {
		 
		 cap >> frame3;
		//bool b=cap.read(frame3);
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
	std::vector<Rect> faces;
	face.detectMultiScale(frame,faces,1.1,4, 0, Size(20, 20),Size(450,450));
	
	//ellipse( frame3,Point(faces[0].x + faces[0].width*0.5, faces[0].y + faces[0].height*0.5 ) , Size( faces[0].width*0.5, faces[0].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
	//Vec3b color=frame3.at<Vec3b>(Point(faces[0].x + faces[0].width*0.5, faces[0].y + faces[0].height*0.5 ));	
	//color.val[0]=255;
	//frame3.at<Vec3b>(Point(faces[0].x + faces[0].width*0.5, faces[0].y + faces[0].height*0.5 ))=color;
	 for( size_t i = 0; i < faces.size(); i++ )
  {
   Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
   
//	for(int j=0;j<15;j++)
	//{
		//for(int h=0;h<15;h++)
		//{

//			Vec3b color=frame3.at<Vec3b>(Point(faces[i].x + faces[i].width*0.5+h, faces[i].y + faces[i].height*0.5+j ));
	//		if(!(color.val[0]==255))
	//{
		ellipse( frame3, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
	//}
	 //}
		//}
	}
	
	

	 imshow("MyWindow",frame3);
}
    

      //create a window with the name "MyWindow"
      //display the image which is stored in the 'img' in the "MyWindow" window

      //wait infinite time for a keypress

    


