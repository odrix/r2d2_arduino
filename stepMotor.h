// This Arduino example demonstrates bidirectional operation of a 
// 28BYJ-48, using a ULN2003 interface board to drive the stepper.
// The 28BYJ-48 motor is a 4-phase, 8-beat motor, geared down by
// a factor of 68. One bipolar winding is on motor pins 1 & 3 and
// the other on motor pins 2 & 4. The step angle is 5.625/64 and the 
// operating Frequency is 100pps. Current draw is 92mA. 
////////////////////////////////////////////////

#ifndef StepMotor_h
#define StepMotor_h

#include "Arduino.h"

class StepMotor
{
  public:
    StepMotor(int pin1, int pin2, int pin3, int pin4);
    void init();
    void anticlockwise(int degree);
    void clockwise(int degree);
  private:    
    int motorPin1;    // Blue   - 28BYJ48 pin 1
    int motorPin2;    // Pink   - 28BYJ48 pin 2
    int motorPin3;    // Yellow - 28BYJ48 pin 3
    int motorPin4;    // Orange - 28BYJ48 pin 4
                      // Red    - 28BYJ48 pin 5 (VCC)
    int motorSpeed;   //variable to set stepper speed
    int lookup[8];
    void setOutput(int out);
};

#endif
