// Library for MPU-6050 6 axis Accel/Gryo/Temp

#include "Arduino.h"
#include "MPU_6050_Wire.h"
#include "Wire.h"


MPU_6050_Wire::MPU_6050_Wire() {

};

void MPU_6050_Wire::begin(uint8_t address) {

    this->address = address;

    // Wire.begin();
    Wire.beginTransmission(this->address);
    Wire.write(byte(107));  // PWR_MGMT_1 register
    Wire.write(0);     // set to zero (wakes up the MPU-6050)
    Wire.endTransmission(true);

};

void MPU_6050_Wire::setAccelConfig(uint8_t AFS) {
    Wire.beginTransmission(this->address);
    Wire.write(byte(ACCEL_CONFIG_REG));
    this->AFS = AFS;
    switch (AFS) {
        case 0:
            Wire.write(B00000000); // Set Full Scale Range to +- 2g & Set Sensitivity to 16,384 LSB changes per 1 g of change
            break;
        case 1:
            Wire.write(B00001000); // Set Full Scale Range to +- 4g & Set Sensitivity to 8,192 LSB changes per 1 g of change
            break;
        case 2:
            Wire.write(B00010000); // Set Full Scale Range to +- 8g & Set Sensitivity to 4,096 LSB changes per 1 g of change
            break;
        case 3:
            Wire.write(B00011000); // Set Full Scale Range to +- 16g & Set Sensitivity to 2,048 LSB changes per 1 g of change
            break;
    }
    Wire.endTransmission(true);
};

void MPU_6050_Wire::setGyroConfig(uint8_t GFS) {
    Wire.beginTransmission(this->address);
    Wire.write(byte(GYRO_CONFIG_REG));
    this->GFS = GFS;
    switch (GFS) {
        case 0:
            Wire.write(B00000000); // Set Full Scale Range to +- 250 deg/s & Set Sensitivity to 131 LSB changes per 1 degree/s change
            break;
        case 1:
            Wire.write(B00001000); // Set Full Scale Range to +- 500 deg/s & Set Sensitivity to 65.5 LSB changes per 1 degree/s change
            break;
        case 2:
            Wire.write(B00010000); // Set Full Scale Range to +- 1000 deg/s & Set Sensitivity to 32.8 LSB changes per 1 degree/s change
            break;
        case 3:
            Wire.write(B00011000); // Set Full Scale Range to +- 2000 deg/s & Set Sensitivity to 16.4 LSB changes per 1 degree/s change
            break;
    }
    Wire.endTransmission(true);
};

int16_t MPU_6050_Wire::readAccelX() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(ACCELX_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->AccelX = (Wire.read()<<8) | Wire.read();

    return this->AccelX;

};

int16_t MPU_6050_Wire::readAccelY() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(ACCELY_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->AccelY = (Wire.read()<<8) | Wire.read();

    return this->AccelY;

};

int16_t MPU_6050_Wire::readAccelZ() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(ACCELZ_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->AccelZ = (Wire.read()<<8) | Wire.read();

    return this->AccelZ;

};

int16_t MPU_6050_Wire::readGyroX() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(GYROX_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->GyroX = (Wire.read()<<8) | Wire.read();

    return this->GyroX;

};

int16_t MPU_6050_Wire::readGyroY() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(GYROY_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->GyroY = (Wire.read()<<8) | Wire.read();

    return this->GyroY;

};

int16_t MPU_6050_Wire::readGyroZ() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(GYROZ_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->GyroZ = (Wire.read()<<8) | Wire.read();

    return this->GyroZ;

};

int16_t MPU_6050_Wire::readTemp() {

    Wire.beginTransmission(this->address);
    Wire.write(byte(TEMP_REG));
    Wire.endTransmission(false);
    Wire.requestFrom(this->address,2,true);

    this->Temp = (Wire.read()<<8) | Wire.read();

    return this->Temp;

};

double MPU_6050_Wire::accelInGs(int16_t rawAccel) {
    switch (this->AFS) {
        case 0:
            return ((double)rawAccel / 16384);
            break;
        case 1:
            return ((double)rawAccel / 8192);
            break;
        case 2:
            return ((double)rawAccel / 4096);
            break;
        case 3:
            return ((double)rawAccel / 2048);
            break;
    }
};

double MPU_6050_Wire::gyroInDegPerSec(int16_t rawGyro) {
    switch (this->GFS) {
        case 0:
            return ((double)rawGyro / 131);
            break;
        case 1:
            return ((double)rawGyro / 65.5);
            break;
        case 2:
            return ((double)rawGyro / 32.8);
            break;
        case 3:
            return ((double)rawGyro / 16.4);
            break;
    }
};

double MPU_6050_Wire::tempInCelcius(int16_t rawTemp) {
    return (((double)rawTemp / 340) + 36.53);
};