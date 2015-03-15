// handdetection2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"



#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#define WINVER 0x0500
#include <windows.h>
//#include "opencv/cv.h" 
using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
	 INPUT ip;
	 ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0;
	VideoCapture cap(2);
	//cap.open("http://10.1.12.141:8080");
	cap.set(CV_CAP_PROP_FPS, 2);
	Mat img;
	Mat img2(100,100,CV_8UC3,Scalar(0,255,255));
	int c=1;
	
	while(1)
	{
		c=1;
		bool b =cap.read(img);
		Mat img3;
		cvtColor(img,img3,CV_BGR2HSV);
		
		for(int j=95;j<=100;j++)
		{int i=100;
		while(i<175)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}
		//middle part
		for(int j=95;j<=100;j++)
		{int i=300;
		while(i<375)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}

		for(int j=95;j<=100;j++)
		{int i=500;
		while(i<575)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}


		for(int j=295;j<=300;j++)
		{int i=500;
		while(i<575)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}
		for(int j=295;j<=300;j++)
		{int i=300;
		while(i<375)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}
		for(int j=295;j<=300;j++)
		{int i=100;
		while(i<175)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}


		//end part
		for(int j=200;j<=205;j++)
		{int i=100;
		while(i<175)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}

		for(int j=200;j<=205;j++)
		{int i=300;
		while(i<375)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}

		for(int j=200;j<=205;j++)
		{int i=500;
		while(i<575)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}
		for(int j=400;j<=405;j++)
		{int i=500;
		while(i<575)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}
		for(int j=400;j<=405;j++)
		{int i=300;
		while(i<375)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}
		for(int j=400;j<=405;j++)
		{int i=100;
		while(i<175)
		{
			Vec3b pixel=img.at<Vec3b>(j,i);
				   pixel.val[1]=255;
					    img.at<Vec3b>(j,i)=pixel;
						i++;
		}
		
		
		}


	/*for(int i=95;i<=205;i=i+1)
		{
			for(int j=95;j<=205;j=j+1)
			{
				
				while(j<100||j>200)
				{
					Vec3b pixel=img.at<Vec3b>(i,j);
				   pixel.val[1]=255;
					    img.at<Vec3b>(i,j)=pixel;
						j=j+1;
				}
				
			
			}
			
		}
		*/
		//detecting if hand is there inside box


		//PRINTING A FIRST BOX
		for(int i=100;i<200;i=i+5)
		{
			for(int j=100;j<200;j=j+5)
			{
				Vec3b pixel=img3.at<Vec3b>(i,j);
				//check for skin colour...later use hsv
				if(pixel.val[0]==0&&pixel.val[1]>95&&pixel.val[2]>74)
				{
				//c=0;
				  ip.ki.wVk = 0x41; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
				
				//break;
				}
					
				break;
			}
			
		}



		//SECOND BOX
		for(int i=100;i<200;i=i+5)
		{
			for(int j=300;j<400;j=j+5)
			{
				Vec3b pixel=img3.at<Vec3b>(i,j);
				//check for skin colour...later use hsv
				if(pixel.val[0]==0&&pixel.val[1]>95&&pixel.val[2]>74)
				{
				//c=0;
				  ip.ki.wVk = 0x42; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
				
				//break;
				}
					
				break;
			}
			
		}


		//THIRD BOX
		//SECOND BOX
		for(int i=100;i<200;i=i+5)
		{
			for(int j=500;j<600;j=j+5)
			{
				Vec3b pixel=img3.at<Vec3b>(i,j);
				//check for skin colour...later use hsv
				if(pixel.val[0]==0&&pixel.val[1]>95&&pixel.val[2]>74)
				{
				//c=0;
				  ip.ki.wVk = 0x43; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
				
				//break;
				}
					
				break;
			}
			
		}
		//FOURTH BOX
		for(int i=300;i<400;i=i+5)
		{
			for(int j=100;j<200;j=j+5)
			{
				Vec3b pixel=img3.at<Vec3b>(i,j);
				//check for skin colour...later use hsv
				if(pixel.val[0]==0&&pixel.val[1]>95&&pixel.val[2]>74)
				{
				//c=0;
				  ip.ki.wVk = 0x44; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
				
				//break;
				}
					
				break;
			}
			
		}
		//FIFTH BOX
		for(int i=300;i<400;i=i+5)
		{
			for(int j=300;j<400;j=j+5)
			{
				Vec3b pixel=img3.at<Vec3b>(i,j);
				//check for skin colour...later use hsv
				if(pixel.val[0]==0&&pixel.val[1]>95&&pixel.val[2]>74)
				{
				//c=0;
				  ip.ki.wVk = 0x45; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
				
				//break;
				}
					
				break;
			}
			
		}
		//SIXTH BOX


		
		for(int i=300;i<400;i=i+5)
		{
			for(int j=500;j<600;j=j+5)
			{
				Vec3b pixel=img3.at<Vec3b>(i,j);
				//check for skin colour...later use hsv
				if(pixel.val[0]==0&&pixel.val[1]>95&&pixel.val[2]>74)
				{
				//c=0;
				  ip.ki.wVk = 0x46; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
				
				//break;
				}
					
				break;
			}
			
		}

		//doing something while hand is inside box
		
		/*for(int i=100;i<200;i++)
		{
			for(int j=100;j<200;j++)
			{
				Vec3b pixel=img.at<Vec3b>(i,j);
				Vec3b pixel2=img2.at<Vec3b>(i-100,j-100);
				if(c==1)
				{
				    //pixel.val[1]=pixel2.val[1];
				    //img.at<Vec3b>(i,j)=pixel;
				}
				else
				{

					//pixel.val[2]=pixel2.val[2];
					 ip.ki.wVk = 0x41; // virtual-key code for the "a" key
                     ip.ki.dwFlags = 0; // 0 for key press
                     SendInput(1, &ip, sizeof(INPUT));

                       // Release the "A" key
                      ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                       SendInput(1, &ip, sizeof(INPUT));
					   //Sleep(1000);
					 //  img.at<Vec3b>(i,j)=pixel;
					   break;
					
				}
				
			}
			break;
		}
			*/
		//img=img+img2;

     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
     imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

     waitKey(5); 
	 //wait infinite time for a keypress

     
	}
	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
