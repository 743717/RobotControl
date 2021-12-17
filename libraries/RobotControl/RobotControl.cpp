/*
 ╬═════════════════════════════════════════════════════════╬
 ║  Programmer: Colin Schwartz                             ║
 ╬═════════════════════════════════════════════════════════╬
 ║  Date: 4 Oct 2021                                       ║
 ╬═════════════════════════════════════════════════════════╬
 ║  Program: Robot Control                                 ║
 ╬═════════════════════════════════════════════════════════╬
 ║  Description:                                           ║
 ║  Has everything you need to control your robot          ║
 ╬═════════════════════════════════════════════════════════╬
*/

//----------------------------------------------------------------------------------------------------------
// Global Section: where all gobal data (meaning that everything can use the data that is here) lives.
//----------------------------------------------------------------------------------------------------------
#include "Arduino.h"
#include "RobotControl.h"
//----------------------------------------------------------------------------------------------------------

/*
Variables to keep in mind:
t is for the time you want the function to go for
c is for how big or small the curve is
*/

//----------------------------------------------------------------------------------------------------------
// TurnTime: allows you to set the time it takes to turn 90 degrees, 
// and then this function times it by 4 and divides by 360 so that the code 
// gets the time it takes to turn 1 degree so that you can use angles instead of time to turn your robot. 
//----------------------------------------------------------------------------------------------------------
void control::TurnTime(int time90) {
turningTiming = time90*4/360;// times the 90 degree time by 4, then divde it by 360
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// Attach: used for first time use
//----------------------------------------------------------------------------------------------------------
void control::Attach() { 
servoRight.attach(13); //attaches pin 13 to servoRight
servoLeft.attach(12); //attaches pin 12 to servoLeft
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// AttachSet: similar to Attach, but allows you to set the pins you self
//----------------------------------------------------------------------------------------------------------
void control::AttachSet(int servoLeftpin, int servoRightpin) { 
servoRight.attach(servoRightpin); //sets servoRight to certain pin
servoLeft.attach(servoLeftpin); //sets servoLeft to certain pin
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// TurnRight: turns the robot right at a certain amount
//----------------------------------------------------------------------------------------------------------
void control::TurnRight(int angle) { 
servoLeft.writeMicroseconds(1600);
servoRight.writeMicroseconds(1600);
delay(turningTiming*angle);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// TurnLeft: turns the robot left for a set amount of time
//----------------------------------------------------------------------------------------------------------
void control::TurnLeft(int angle) {
servoRight.writeMicroseconds(1400);
servoLeft.writeMicroseconds(1400);
delay(turningTiming*angle);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// CurveRight: curves the robot right
//----------------------------------------------------------------------------------------------------------
void control::CurveRight(int c, int t) { 
  servoRight.writeMicroseconds(1500-c); //c should be between 1400 and 1500
  servoLeft.writeMicroseconds(1600); //makes the left wheel go forward
  delay(t);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// CurveLeft: curves the robot left
//----------------------------------------------------------------------------------------------------------
void control::CurveLeft(int c, int t) {
  servoRight.writeMicroseconds(1400); //makes the right wheel go forward
  servoLeft.writeMicroseconds(1500+c); //c should be between 1500 and 1600
  delay(t);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// Forward: makes the robot  go forward
//----------------------------------------------------------------------------------------------------------
void control::Forward(int t) { 
  servoRight.writeMicroseconds(1400);
  servoLeft.writeMicroseconds(1600);
  delay(t);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// Backwards: makes the robot go backwards
//----------------------------------------------------------------------------------------------------------
void control::Backward(int t) { 
  servoRight.writeMicroseconds(1600);
  servoLeft.writeMicroseconds(1400);
  delay(t);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// Stop: makes the  stop
//----------------------------------------------------------------------------------------------------------
void control::Stop(int t) { 
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1500);
  delay(t);
}
//----------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------
// TurnRtime: This turns the robot right for a set amount of time
//----------------------------------------------------------------------------------------------------------
void control::TurnRtime(int time) { 
  servoLeft.writeMicroseconds(1600);
  servoRight.writeMicroseconds(1600);
  delay(time);
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1500);
}
//----------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------
// TurnLtime: This turns the robot right for a set amount of time
//----------------------------------------------------------------------------------------------------------
void control::TurnLtime(int time) { 
  servoLeft.writeMicroseconds(1400);
  servoRight.writeMicroseconds(1400);
  delay(time);
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1500);
}
//----------------------------------------------------------------------------------------------------------L
//----------------------------------------------------------------------------------------------------------
// Detach: detaches the pins from the servos
//----------------------------------------------------------------------------------------------------------
void control::Detach() { 
  servoRight.detach(); 
  servoLeft.detach();
} 
//----------------------------------------------------------------------------------------------------------
