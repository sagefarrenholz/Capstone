/* Get tilt angles on X and Y, and rotation angle on Z
 * Angles are given in degrees
 * 
 * License: MIT
 */

#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

void GetAngleSetup() {
  Serial.begin(9600);
  Wire.begin();
  
  byte status = mpu.begin(2,3); //gyro 500 deg/s, Acc 16g
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
}

int GetAngle() {
  mpu.update();
  bool flag = false;
  if (abs(mpu.getAngleX()) >= 90 || abs(mpu.getAngleX()) >= 90) {
        flag = true;
  } else if (abs(mpu.getAccX()) > 15 || abs(mpu.getAccY()) > 15 || abs(mpu.getAccZ()) > 15){
        flag = true;
  }
	timer = millis();  

  return flag;
}

void printData() {
  Serial.print("\nOrientation (°): ");
  Serial.print("X: ");
  Serial.print(mpu.getAngleX());
  Serial.print("\tY: ");
  Serial.println(mpu.getAngleY());;
  Serial.print("Force (g): ");
  Serial.print("X: ");Serial.print(mpu.getAccX());
  Serial.print("\tY: ");Serial.print(mpu.getAccY());
  Serial.print("\tZ: ");Serial.println(mpu.getAccZ());
  Serial.print("Temp : ");
  Serial.print((mpu.getTemp() * 9/5) + 32);
  Serial.print("°");
}
