# OpenCV-projects
A collection of OpenCV projects done by me

AR_Keyboard.cpp :- An augmented reality keyboard using a projector, and a webcam which sends the live video stream to opencv for processsing.
The user sees a set of 6 large keys being projected on the wall. The user has to wear a red cap on his finger, or can use a read cloth around his
hand to activate the keys and see the output also on the projector. 
The camera is placed in such a position that the keys line up with certain predetermined areas. Those areas are checked every frame
for the colour red. If the colour red is found say in the second key area, then that particular character is pressed using a keypress in c++.
So basically each area is searched in each frame for the colour red and the appropriate keypress function is called.
I first expected this to have a delay since it is computational expensive, but there was no delay at all when I ran the program on 
my local machine. This gives the feel of an actual augmented reality keyboard to the user.


hand_detection_haar.cpp :- A simple hand detection algorithm which detects a hand using a pretrained haar classifier called trial.xml
The same program can be used for face,eye or any detection just by changing the haar classifier.


people_detection.cpp :- An algorithm which uses opencvs hog classifier for people detection. This was used on a quadcopter we made which
had a camera and a raspberry pi mounted on it. The pi would stream the video to a local server. Then the video is read from the server
and the hog classifier is applied to each frame. This would detect humans while the quad is flying and draw a circle around them.
