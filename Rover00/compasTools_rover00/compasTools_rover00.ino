/*

 Title:  shadow_chassis_withIR_withHMC5883Compass

 Description:
 Using the Shaddow Chassis, with Arduino Moto driver shied, IR sensor and HMC5883L Compass.  Detect obstacles and back away.

 Version 2.0  Nov 2017
 */

#include <Wire.h>
#include <SparkFunLSM9DS1.h>

//Library
LSM9DS1 compass;  // Storing the features in the HMC5883 library as a variable called compass

// I2C setup

// SDO_XM and SDO_G are both pulled high, so our addresses are:
#define LSM9DS1_M  0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW

float currentHeading = 0.0;  // Variable to hold Heading in degrees
float rHeadingOffset = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();                // join i2c bus

  compassSetup();                // setup the HMC5883L
  delay(10000);
}

void loop()
{
  Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8
  Serial.println(getHeading());
  delay(3000);

  currentHeading = getRoverHeading();  // Call the Function getHeading and save the results in currentHeading
  //Serial.println("");             //start on a new line and Print out the Compass heading
  Serial.print("Compass: ");
  Serial.print(currentHeading);
  Serial.print("\n");

}



int getHeading(){
  Wire.requestFrom(8, 2);    // request 6 bytes from slave device #8
  byte MSB = Wire.read();
  byte LSB = Wire.read();
  return (MSB<<8)|LSB;
}





