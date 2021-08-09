# Simulation of Wall Art Bot

We have done simulation by using Matlab and Simulink Software.
At first we import the cad model (which we have shared in mechanical design along with a wall on which two clamps are attached at top corners, using Solidworks to Simulink.
In Simulink block diagram we insert string, spool, end clamp blocks from Simscape Multibody and attached them to pully and wall clamp of this bot . 
After that we given commands to pully’s cylindrical joints in sine wave to perform motion in uniform manner, also we add slider gain block to pen system disk to check the manual rotation of three pen holders by 120 degree.We gave continuous commands in form of radians to the cylinders which helps to rotate the  pulleys and wind up the belt such that we get to move the bot to the desired positions
Then we run the simulation and its work fine.

 # Instructions
 
 1. In solidworks,using "Simscape Multibody" plugin import the cad model to Simulink,which will convert your model into xml files.
 2. Then import this CAD model into Simulink using the command 
simport(" name of the xml file").For this you have to install simscape multibody in matlab
3. Later we find that our model got converted into block system in simulink.
4. To simulate our bot using strings, first of all we have to get the strings into our environment  by adding the belt cable properties block into our block system
5. Also we have to add spool blocks, pulley belt blocks which  helps the pulley to wind up the belt, belt end cable blocks which will be connected to the clamps on the wall as shown in the figure provided

 <p align="center">
  <img src="Simulation/Simulation.JPG" alt="Simulation" height="400" width="570">
  <br><i>Simulation</i>
  </p>
