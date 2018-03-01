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

Servo testservo;
Servo servo2;

void setup()
{
  // the 1000 & 2000 set the pulse width 
  // mix & max limits, in microseconds.
  // Be careful with shorter or longer pulses.
  testservo.attach(9, 1000, 2000);
  servo2.attach(10, 1000, 2000);

}

void loop()
{

      testservo.write(10);
      servo2.write(10);
      delay(1000);
      
      testservo.write(40);
      servo2.write(40);
      delay(1000);

        testservo.write(180);
      servo2.write(180);
      delay(1000);
      
      testservo.write(360);
      servo2.write(360);
      delay(1000);

}
