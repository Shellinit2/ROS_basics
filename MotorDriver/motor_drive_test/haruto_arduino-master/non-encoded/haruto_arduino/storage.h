#ifndef Storage_h
#define Storage_h

const int Sleep1 = 2; //For the motor M1
const int Dir1 = 4; //pin to change direction for motor M1
const int pwm1 = 3; //Pwm pin for motor M1
const int pwm2 = 5;// Pwm pin for motor M2
const int Dir2 = 6; // pin to change direction for motor M2
const int Sleep2 = 7; //For the motor M2

const int Sleep3 = 8; //For the motor M3
const int Dir3 = 9; //pin to change direction for motor M3
const int pwm3 = 10; //Pwm pin for motor M3
const int pwm4 = 11;// Pwm pin for motor M4
const int Dir4 = 12; // pin to change direction for motor M4
const int Sleep4 = 13; //For the motor M4


#include "Arduino.h"
#include <ros.h>

extern ros::NodeHandle nh;
extern int front_left_pwm, front_right_pwm, back_left_pwm, back_right_pwm, left_state1, right_state1,left_state2, right_state2;

#endif
