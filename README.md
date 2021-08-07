# Wall-Art-Bot
Open Projects 2021

## Abstract
The main aim of this project is to draw a desired sketch on a wall.
![](Image%20and%20Videos/Mechanical%20Design%20Images/Multiple%20view.png)

## Motivation
We always want to draw pictures from what we see scrolling on the web. But it's always difficult to convince the professional painter to draw the exact same picture on our walls. This project helps users to draw the exact same sketch that they have uploaded.

## Components and cost
* 2 x Nema 11/17 Stepper Motor       - Rs.1000                                     
* 1x MG90S Servo Motor               - Rs.250                                     
* 1x Arduino Mega                    - Rs.1000                                     
* 1x L293D Motor Drive Shield        - Rs.150                                    
* 1x 28B28BYJ-48 DC 5V Stepper Motor - Rs.150
  + ULN2003 Driver Test Module Board
* 2 X Command Large Plastic Hooks for walls -Rs. 140
* Rope - DYNAMICA XBO       	     - Rs.350
* Total- Rs.3040				     
## Workflow
   ![](Report%20and%20Poster/workflow.jpg)
## Mechanism
  The logic of our bot is shown in below figure:
  ![](Image%20and%20Videos/Electronics%20Mechanism/Electronics%20mechanism.jpeg)
## Mechanical Aspect of the Design
   #### 1.Pulley Movement
   Used Stepper motors to rotate pulleys and helps the pen to reach desired coordinate.
   ![](Image%20and%20Videos/Mechanical%20Design%20Images/Pulley%20movement.png)
   #### 2.Pen Module
   The pen module which is a disc contains 3 pen holders and the disc rotates using a stepper motor and then there are ball bearings that ease the rotation of the disc.
   
   ![](Image%20and%20Videos/Mechanical%20Design%20Images/Pen%20module.png)
   #### 3.Pen Lifting
   Reck and Pinion mechanism helps us to lift the whole bot by providing perpendicular force on the wall while the pen module is in the process of rotation.
 
  ![](Image%20and%20Videos/Mechanical%20Design%20Images/Pen%20lifting.png)
## Electronics Aspect of the Design
 In this project, OpenCV is used for image processing and the coordinates are stored in the form of a 30-30 array. Which are sent to arduino through serial transfer library. Then every coordinate is transformed into the length of two strings, which is again converted into number of steps of individual stepper motors.
 
 

## Applications
The wall art bot is planned to draw or sketch a picture which the user has in his laptop or phone.
## Limitations

If the two points from where the two strings are attached are not in the same level then the drawn picture will also be tilted.

The dimension of the picture should not go beyond the workspace area of the bot( although the workspace area can be increased by increasing the distance between two points where strings are attached).

## Future Improvements
Raspberry pi can be used instead of Arduino to overcome the problem with limited storage. And also an app can be developed such that user can upload the picture directly from the phone.
#### Team members

1. [Aradhya Saxena](https://github.com/aries2001)
2. [Bhunesh Gepal](https://github.com/Bhunesh22)
3. [Kodumuru Firdose Kouser](https://github.com/fidosekouser1902)
4. [Shikar Gupta](https://github.com/shikhar2624)
5. [Trishit Mondal](https://github.com/trishit-byte)


#### Mentors
1. [Naman Agarwalla]
2. [Parul Chaudhary]

## References
* http://42bots.com/tutorials/28byj-48-stepper-motor-with-uln2003-driver-and-arduino-uno/
* https://github.com/PowerBroker2/pySerialTransfer
* https://www.youtube.com/watch?v=T0jwdrgVBBc&t=72s&ab_channel=MERTArduino%26Tech
* https://www.youtube.com/watch?v=FbR9Xr0TVdY&ab_channel=ProgrammingKnowledge
* https://www.hackster.io/fredrikstridsman/stringent-the-15-wall-plotter-d965ca#overview
