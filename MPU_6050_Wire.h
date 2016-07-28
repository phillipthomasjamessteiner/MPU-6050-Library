// Library for MPU-6050 6 axis Accel/Gryo/Temp


#ifndef  MPU_6050_Wire_h
#define MPU_6050_Wire_h

#define ACCELX_REG 59
#define ACCELY_REG 61
#define ACCELZ_REG 63
#define GYROX_REG 67
#define GYROY_REG 69
#define GYROZ_REG 71
#define TEMP_REG 65
#define ACCEL_CONFIG_REG 28
#define GYRO_CONFIG_REG 27

class MPU_6050_Wire {

    public:

        MPU_6050_Wire();

        void begin(uint8_t address); // Initialize w/ address

        void setAccelConfig(uint8_t AFS); // Accuracy Config for Accelerometers

        void setGyroConfig(uint8_t GFS); // Accuracy Config for Gyroscopes

        int16_t readAccelX();
 
        int16_t readAccelY();

        int16_t readAccelZ();

        int16_t readGyroX();

        int16_t readGyroY();

        int16_t readGyroZ();

        int16_t readTemp(); // Read Internal Temperiture Register

    private:

        uint8_t address;

        int16_t AccelX, AccelY, AccelZ, GyroX, GyroY, GyroZ, Temp;

};

#endif