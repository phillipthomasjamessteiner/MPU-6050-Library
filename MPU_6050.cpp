// Library for MPU-6050 6 axis Accel/Gryo/Temp

#include "Arduino.h"
#include "MPU_6050.h"

MPU_6050::MPU_6050() {

};

void MPU_6050::begin(uint8_t SDA_pin, uint8_t SCL_pin, uint8_t INT_pin) {

    this->SDA_pin = SDA_pin;

    this->SCL_pin = SCL_pin;

    this->INT_pin = INT_pin;

    pinMode(SDA_pin, OUTPUT);

    pinMode(SCL_pin, OUTPUT);

};