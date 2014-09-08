#include "stepMotor.h"
#include "Arduino.h"

StepMotor::StepMotor(int pin1, int pin2, int pin3, int pin4)
{
  motorPin1 = pin1;    // Blue   - 28BYJ48 pin 1
  motorPin2 = pin2;    // Pink   - 28BYJ48 pin 2
  motorPin3 = pin3;    // Yellow - 28BYJ48 pin 3
  motorPin4 = pin4;    // Orange - 28BYJ48 pin 4
  motorSpeed = 1000;
  lookup[0] = B01000;
  lookup[1] = B01100;
  lookup[2] = B00100;
  lookup[3] = B00110;
  lookup[4] = B00010;
  lookup[5] = B00011;
  lookup[6] = B00001;
  lookup[7] = B01001;
}

//////////////////////////////////////////////////////////////////////////////
void StepMotor::init() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

//////////////////////////////////////////////////////////////////////////////
//set pins to ULN2003 high in sequence from 1 to 4
//delay "motorSpeed" between each pin setting (to determine speed)
void StepMotor::anticlockwise(int degree)
{
  int maxRotate = degree;
  for(int j = 0; j < maxRotate; j++) {
    for(int i = 0; i < 8; i++)
    {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
  }
}

void StepMotor::clockwise(int degree)
{
  int maxRotate = degree;
  for(int j = 0; j < maxRotate; j++) {
    for(int i = 7; i >= 0; i--)
    {
      setOutput(i);
      delayMicroseconds(motorSpeed);
    }
  }
}

void StepMotor::setOutput(int out)
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}

void StepMotor::setDebug(boolean debug)
{
  _debug = debug;
}
