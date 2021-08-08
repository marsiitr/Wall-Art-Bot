# Simulation of Wall Art Bot

We have done simulation by using Matlab and Simulink Software.
At first we import the cad model (which we have shared in mechanical design along with a wall on which two clamps are attached at top corners, using Solidworks to Simulink.
In Simulink block diagram we insert string, spool, end clamp blocks from Simscape Multibody and attached them to pully and wall clamp of this bot . 
After that we given commands to pully’s cylindrical joints in sine wave to perform motion in uniform manner, also we add slider gain block to pen system disk to check the manual rotation of three pen holders by 120 degree.We gave continuous commands in form of radians to the cylinders which helps to rotate the  pulleys and wind up the belt such that we get to move the bot to the desired positions
Then we run the simulation and its work fine.

 
