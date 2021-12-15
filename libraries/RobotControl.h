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
#ifndef RobotControl
#define RobotControl
//----------------------------------------------------------------------------------------------------------
// Global Section: where all gobal data (meaning that everything can use the data that is here) lives.
//----------------------------------------------------------------------------------------------------------
#include "Arduino.h"
#include "Servo.h" // includes the servo
//----------------------------------------------------------------------------------------------------------
class control { //creates a class called control, because if it was called robot, it would be confusing.
private:
Servo servoRight; //This the servo on the right side
Servo servoLeft; //This the servo on the left side
const int numPins = 14;
public:
int turningTiming = 7;
void TurnTime(int time90);
void Attach();
void AttachSet(int servoLeftpin, int servoRightpin);
void TurnRight(int angle);
void TurnLeft(int angle);
void CurveRight(int c, int t);
void CurveLeft(int c, int t);
void Forward(int t);
void Backward(int t);
void Stop(int t);
void Calibrate();
void Detach();
};
#endif
