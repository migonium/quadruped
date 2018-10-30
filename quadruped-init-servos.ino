// Locate the initial position of legs 
// RegisHsu 2015-09-09

// Wire - Version: Latest 
#include <Wire.h>

// Adafruit PWM Servo Driver Library - Version: Latest 
#include <Adafruit_PWMServoDriver.h>


//define servos' ports
const int servo[4][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11} };
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
  
void setup()
{
  //initialize all servos
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);
}

void loop(void)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      pwm.setPWM(servo[i][j], 0, map(90, 0, 180, SERVOMIN, SERVOMAX));
      delay(20);
    }
  }
}

