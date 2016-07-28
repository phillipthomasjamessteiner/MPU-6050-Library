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
  Serial.begin(9600); // Begin Serial at 9600 Baud

  MPU.begin(MPU_ADDRESS); // Wake up the MPU6050
  
  MPU.setAccelConfig(1); // Set Accelerometer accuracy (65.5 LSB changes/g)
  MPU.setGyroConfig(1); // Set Gyroscope accuracy (8,192 LSB changes/(degrees/second))
  
}

void loop() {

  // Print out readings from MPU6050 to serial
  
  Serial.print(MPU.readAccelX()); Serial.print(" | ");
  Serial.print(MPU.readAccelY()); Serial.print(" | ");
  Serial.print(MPU.readAccelZ()); Serial.print(" | ");
  Serial.println("");
  Serial.print(MPU.readGyroX()); Serial.print(" | ");
  Serial.print(MPU.readGyroY()); Serial.print(" | ");
  Serial.print(MPU.readGyroZ()); Serial.print(" | ");
  Serial.println("");
  Serial.print(MPU.readTemp()); Serial.println("");
  Serial.println("");
  
}
