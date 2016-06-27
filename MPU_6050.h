// Library for MPU-6050 6 axis Accel/Gryo/Temp


#ifndef  MPU_6050.h
#define MPU_6050.h

#define PULSE_DELAY 4

class MPU_6050 {
    
    public:

        MPU_6050();

        void begin(uint8_t SDA_pin, uint8_t SCL_pin, uint8_t INT_pin); // Initialize & set Pins

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
        
        void writeReg(uint8_t reg);

};