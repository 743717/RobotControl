# RobotControl
Library of controls for arduino robots


Programmer: Colin Schwartz

Date: 4 Oct 2021

Library: Robot Control

Description:                                           
Has everything you need to control your robot quickly  



How to use:
═══════════════════════════════════════
	* You do not need to add the servo library or create servo objects because the library does this for you. 
	If you do, this library and your code will break.
	* This library needs you to use TurnTime() and input the time it takes to turn 90 degrees, 
	so that you can use angles instead of time for turning
	* You need to make an object with the class "control" to use


List of Functions:
═══════════════════════════════════════

	Setup/Calibration:
---------------------------------------

		Attach():
		Attaches the pins automatically to servo objects.

		AttachSet(servoLeftpin, servoRightpin):
		Similar to Attach, but allows you to set the servos to a different pin of your choice.      
		
		TurnTime(time):                                                                         												   ║
		This uses the time it takes for your robot to turn 90 degrees, 
		and uses it to do some math so you can use angles instead of time to turn your robot.

		Calibrate():
		Same as Stop, but it also attaches the pins so you don't need to add 
		Attach to your code to calibrate the wheels.

---------------------------------------

	Movement:

		Drive:
			Forward(time):
			Moves the robot forward for a set amount of time.

			Backward(time):
			Moves the robot backward for a set amount of time.

		Turning:

			TurnLeft(angle):
			Turns the robot left for a set amount of time.

			TurnRight(angle):
			Turns the robot right to a set angle.

		Curving:

			CurveLeft(curve, time):
			Curves the robot left a defined curve for a set amount of time.

			CurveRight(curve, time):
			Curves the robot right a defined curve for a set amount of time.

---------------------------------------

	Other:
		Detach():
		Detaches the servos from the pins and should only be used when your code is finished.
