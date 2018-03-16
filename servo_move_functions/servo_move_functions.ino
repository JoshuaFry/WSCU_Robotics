/******************************************************************************
servo-skatch.ino
Example sketch for connecting a hobby servo to a sparkfun redboard
  (https://www.sparkfun.com/products/9065)
  (https://www.sparkfun.com/products/12757)
Byron Jacquot@ SparkFun Electronics
May 17, 2016

**SparkFun code, firmware, and software is released under the MIT License(http://opensource.org/licenses/MIT).**

Development environment specifics:
Arduino 1.6.5
******************************************************************************/

#include <Servo.h>
#include <SlowMotionServo.h>

Servo left_front;
Servo right_front;
Servo left_rear;
Servo right_rear;
int i = 0;

void setup()
{
  // the 1000 & 2000 set the pulse width 
  // mix & max limits, in microseconds.
  // Be careful with shorter or longer pulses.
  Serial.begin(9600);
  left_front.attach(9, 1000, 2000);
  right_front.attach(10, 1000, 2000);
  left_rear.attach(6, 1000, 2000);
  right_rear.attach(5, 1000, 2000);
}

void TurnLeft(){
  checkAttached();
  right_front.writeMicroseconds(2400);
  right_rear.writeMicroseconds(2400);
  delay(2000);
  left_front.detach();
  left_rear.detach();
}

void TurnRight(){
  checkAttached();
  left_front.writeMicroseconds(2400);
  left_rear.writeMicroseconds(2400);
  delay(2000);
  right_front.detach();
  right_rear.detach();
}

void checkAttached(){
    if (!left_front.attached()){
      left_front.attach(0, 1000, 2000);
    }
    if (!right_front.attached()){
      right_front.attach(10, 1000, 2000);
    }
    if (!left_rear.attached()){
      left_rear.attach(6, 1000, 2000);
    }
    if (!right_rear.attached()){
      right_rear.attach(5, 1000, 2000);
    }
}

void Reverse(){
  checkAttached();
  right_front.writeMicroseconds(550);
  left_front.writeMicroseconds(550);
  right_rear.writeMicroseconds(550);
  left_rear.writeMicroseconds(550);
}

void Move(){
  checkAttached();
  right_front.writeMicroseconds(2400);
  left_front.writeMicroseconds(2400);
  right_rear.writeMicroseconds(2400);
  left_rear.writeMicroseconds(2400);
}

void loop()
{
  
    TurnRight();
    delay(5000);
    Reverse();
    delay(5000);
    TurnLeft();
    delay(5000);
    Move();
    delay(5000);
}
