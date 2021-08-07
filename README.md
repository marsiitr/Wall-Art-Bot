# Wall-Art-Bot
Open Projects 2021

## Abstract
The main aim of this project is to draw a desired sketch on a wall.

<p align="center">
  <img src="Image%20and%20Videos/Mechanical%20Design%20Images/Multiple%20view.png" alt="Multiple View of Design" height="600" width="850">
  <br><i>Multiple View of Design</i>
  </p>
  
<p align="justify">
<h2>Motivation</h2>
<p>We always want to draw pictures from what we see scrolling on the web. But it's always difficult to convince the professional painter to draw the exact same picture on our walls. This project helps users to draw the exact same sketch that they have uploaded.</p>
</p>

## Components
* 2 x Nema 11/17 Stepper Motor                                     
* 1x MG90S Servo Motor                                    
* 1x Arduino Mega                                        
* 1x L293D Motor Drive Shield
* 1x 28B28BYJ-48 DC 5V Stepper Motor 
  + ULN2003 Driver Test Module Board
* 2 X Command Large Plastic Hooks for walls 
* Rope - DYNAMICA XBO    
		     
## Workflow
  
   <p align="center">
  <img src="Image and Videos/Images//workflow.jpg" alt="Workflow" height="600" width="800">
  <br><i>Workflow</i>
  </p>
  
## Mechanism
  The logic of our bot is shown in below figure:
 
  <p align="center">
  <img src="Image%20and%20Videos/Electronics%20Mechanism/Electronics%20mechanism.jpeg" alt="Mechanism" height="700" width="650">
  <br><i>Mechanism</i>
  </p>
  
## Mechanical Aspect of the Design
   #### 1.Pulley Movement
   Used Stepper motors to rotate pulleys and helps the pen to reach desired coordinate.
   <p align="center">
  <img src="Image%20and%20Videos/Mechanical%20Design%20Images/Pulley%20movement.png" alt="Pulley Movement" height="350" width="800">
  <br><i>Pulley Movement</i>
  </p>
  
   #### 2.Pen Module
   The pen module which is a disc contains 3 pen holders and the disc rotates using a stepper motor and then there are ball bearings that ease the rotation of the disc.
   
   <p align="center">
  <img src="Image%20and%20Videos/Mechanical%20Design%20Images/Pen%20module.png" alt="Pen Module" height="350" width="410">
  <br><i>Pen Module</i>
  </p>
 
   #### 3.Pen Lifting
   Reck and Pinion mechanism helps us to lift the whole bot by providing perpendicular force on the wall while the pen module is in the process of rotation.
 
  <p align="center">
  <img src="Image%20and%20Videos/Mechanical%20Design%20Images/Pen%20lifting.png" alt="Pen Lifting" height="250" width="500">
  <br><i>Pen Lifting</i>
  </p>
  
## Electronics Aspect of the Design
 In this project, OpenCV is used for image processing and the coordinates are stored in the form of a 30-30 array. Which are sent to arduino through serial transfer library. Then every coordinate is transformed into the length of two strings, which is again converted into number of steps of individual stepper motors.
 <p align="center">
  <img src="Image%20and%20Videos/Electronics%20Mechanism/circuit_diagram.png" alt="circuit diagram" height="500" width="810">
  <br><i>Circuit diagram</i>
  </p>
 
## Cost Structre
| Components | Quantity | Cost (in INR) |
|:----------------------------------:|:-------:|:------------:|
| Nema 11/17 Stepper Motor | 2 | 1000 |
| Arduino Mega | 1 | 1000 |
| MG90S Servo Motor  | 1 | 250 |
| L293D Motor Drive Shield | 1 | 150 |
| 28BYJ-48 DC 5V Stepper Motor(with ULN2003 Driver) | 1 | 150 |
| Command Large Plastic Hooks for walls | 2 | 280 |
| Rope - DYNAMICA XBO | 2m | 350 |
|Total Cost|    | 3180  |

## Applications

* The wall art bot is planned to draw or sketch a picture which the user has in his laptop or phone.
* This bot has three pen holders so, it can draw a picture with three different colors.

## Limitations

* If the two points from where the two strings are attached are not in the same level then the drawn picture will also be tilted.

* The dimension of the picture should not go beyond the workspace area of the bot( although the workspace area can be increased by increasing the distance between two points where strings are attached).

## Future Improvements
Raspberry pi can be used instead of Arduino to overcome the problem with limited storage. And also an app can be developed such that user can upload the picture directly from the phone.
#### Team members

1. [Aradhya Saxena](https://github.com/aries2001)
2. [Bhunesh Gepal](https://github.com/Bhunesh22)
3. [Kodumuru Firdose Kouser](https://github.com/fidosekouser1902)
4. [Shikar Gupta](https://github.com/shikhar2624)
5. [Trishit Mondal](https://github.com/trishit-byte)


#### Mentors
1. [Naman Agarwalla](https://github.com/naman99-agar)
2. [Parul Chaudhary](https://github.com/Parul253)

## References
* http://42bots.com/tutorials/28byj-48-stepper-motor-with-uln2003-driver-and-arduino-uno/
* https://github.com/PowerBroker2/pySerialTransfer
* https://www.youtube.com/watch?v=T0jwdrgVBBc&t=72s&ab_channel=MERTArduino%26Tech
* https://www.youtube.com/watch?v=FbR9Xr0TVdY&ab_channel=ProgrammingKnowledge
* https://www.hackster.io/fredrikstridsman/stringent-the-15-wall-plotter-d965ca#overview
