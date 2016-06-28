// Library for MPU-6050 6 axis Accel/Gryo/Temp


#ifndef  MPU_6050.h
#define MPU_6050.h

#define PULSE_DELAY 4
#define BITS_IN_ADDRESS 7

class MPU_6050 {
    
    public:

        MPU_6050();

        int begin(uint8_t SDA_pin, uint8_t SCL_pin, uint8_t INT_pin); // Initialize & set Pins

        int readAccelX();

        int readAccelY();

        int readAccelZ();

        int readGyroX();

        int readGyroY();

        int readGyroZ();

        int readTemp();

    private:

        uint8_t SDA_pin;

        uint8_t SCL_pin;

        uint8_t INT_pin;

        void startLine(); // Function to send start condition
        
        int writeAddress(uint8_t address, uint8_t RW); // Write the address to I2C

        int writeByte(uint8_t val); // Write data to I2C

        void endLine(); // Function to send stop condition

};