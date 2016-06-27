// Library for MPU-6050 6 axis Accel/Gryo/Temp


#ifndef  MPU_6050.h
#define MPU_6050.h


class MPU_6050 {
    
    public:

        void begin(uint8_t SDA_pin, uint8_t SCL_pin, uint8_t INT_pin);

        int readAccelX();

        int readAccelY();

        int readAccelZ();

        int readGyroX();

        int readGyroY();

        int readGyroZ();

    private:



}