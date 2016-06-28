// Library for MPU-6050 6 axis Accel/Gryo/Temp

#include "Arduino.h"
#include "MPU_6050.h"

MPU_6050::MPU_6050() {

};

/* ======================================================================================================
Private Functions
*/

int MPU_6050::begin(uint8_t SDA_pin, uint8_t SCL_pin, uint8_t INT_pin) {

    this->SDA_pin = SDA_pin;

    digitalWrite(SDA_pin, LOW);

    this->SCL_pin = SCL_pin;

    digitalWrite(SCL_pin, LOW);

    this->INT_pin = INT_pin;

    pinMode(SDA_pin, OUTPUT);

    pinMode(SCL_pin, OUTPUT);

    startLine();

    writeAddress(104, 0); // Write Address with AD0 to GND and RW to Write

    writeByte(B00111000); // Write to Register 56

    writeByte(B00000001); // Set Data ready interrupt to on

    endLine();

};








/* ======================================================================================================
Private Functions
*/


void MPU_6050::startLine() { // SDA goes low then SCL goes low to send start condition

    digitalWrite(SDA_pin, HIGH); // SDA goes up first incase of repeated start condition

    digitalWrite(SCL_pin, HIGH);

    delayMicroseconds(PULSE_DELAY);

    digitalWrite(SDA_pin, LOW);

    delayMicroseconds(PULSE_DELAY);

    digitalWrite(SCL_pin, LOW);

};

void MPU_6050::endLine() { // SCL goes high then SDA goes high to send stop condition
    // SDA and SCL should already be low
    digitalWrite(SCL_pin, HIGH);

    delayMicroseconds(PULSE_DELAY);

    digitalWrite(SDA_pin, HIGH);

};

int MPU_6050::writeAddress(uint8_t address, uint8_t RW) {
    
    for (uint8_t i = 0; i < BITS_IN_ADDRESS; i++) {

        digitalWrite(SDA_pin, ((address>>i) & B00000001); // Write bits of address, starting with rightmost bit

        digitalWrite(SCL_pin, HIGH);

        delayMicroseconds(PULSE_DELAY);

        digitalWrite(SCL_pin, LOW);

    }

    digitalWrite(SDA_pin, RW); // Write Read/Write bit

    digitalWrite(SCL_pin, HIGH);

    delayMicroseconds(PULSE_DELAY);

    digitalWrite(SCL_pin, LOW);

    digitalWrite(SDA_pin, LOW);

    pinMode(SDA_pin, INPUT); // Set SDA to Input to read ACK value from slave

    digitalWrite(SCL_pin, HIGH);

    if (digitalRead(SDA_pin) == HIGH) {

        return 1; // Unhappy

    }

    else {

        return 0; // Happy

    }

    digitalWrite(SCL_pin, LOW);

    pinMode(SDA_pin, OUTPUT); // Set SDA back to Output

};

int MPU_6050::writeByte(uint8_t val) {

    for (uint8_t i = 0; i < 8; i++) {

        digitalWrite(SDA_pin, ((val>>i) & B00000001)); // Write bits of value, starting with rightmost bit

        digitalWrite(SCL_pin, HIGH);

        delayMicroseconds(PULSE_DELAY);

        digitalWrite(SCL_pin, LOW);

    }

    digitalWrite(SDA_pin, LOW);

    pinMode(SDA_pin, INPUT); // Set SDA as input to read ACK bit

    digitalWrite(SCL_pin, HIGH);

    if (digitalRead(SDA_pin) == HIGH) {

        return 1; // Unhappy

    }

    else {

        return 0; // Happy

    }

    digitalWrite(SCL_pin, LOW);

    pinMode(SDA_pin, OUTPUT); // Set SDA back to Output

};