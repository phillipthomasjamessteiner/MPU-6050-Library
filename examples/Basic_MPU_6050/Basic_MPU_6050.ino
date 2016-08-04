/*
 * Test MPU6050 - Phillip Steiner 7/28/16
 * 
 * This library uses the wire library included with the Arduino IDE
 * 
 * 
 * Connect:
 *  =====================
 *  Pin A4 -> SDA
 *  Pin A5 -> SCL
 *  5v -> VCC
 *  GND -> GND & AD0
 *  
 * The MPU6050 comes in a variaty of packages. This library was written for the GY521
 * module which is a 6 axis accelerometer and gyroscope
 * 
 */



#include <Wire.h>
#include <MPU_6050_Wire.h>

#define MPU_ADDRESS B1101000 // With AD0 connected to GND

MPU_6050_Wire MPU;


void setup() {
  
  Wire.begin(); // Begin I2C comms (Not in library to allow for multiple I2C devices)
  Serial.begin(115200); // Begin Serial at 9600 Baud

  MPU.begin(MPU_ADDRESS); // Wake up the MPU6050
  
  MPU.setAccelConfig(0); // Set Accelerometer accuracy (16,384 LSB changes/g)
  MPU.setGyroConfig(0); // Set Gyroscope accuracy (131 LSB changes/(degrees/second))
  
}

void loop() {

  // Print out readings from MPU6050 to serial
  // Note that the returned value from accelInGs(), tempInCelcius(), and gyroInDegPerSec() is a double
  
  Serial.print(MPU.accelInGs(MPU.readAccelX())); Serial.print(" | ");
  Serial.print(MPU.accelInGs(MPU.readAccelY())); Serial.print(" | ");
  Serial.print(MPU.accelInGs(MPU.readAccelZ())); Serial.print(" |---| ");

  Serial.print(MPU.gyroInDegPerSec(MPU.readGyroX())); Serial.print(" | ");
  Serial.print(MPU.gyroInDegPerSec(MPU.readGyroY())); Serial.print(" | ");
  Serial.print(MPU.gyroInDegPerSec(MPU.readGyroZ())); Serial.print(" |---| ");

  Serial.println(MPU.tempInCelcius(MPU.readTemp()));
}
