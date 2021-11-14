#ifndef Accelerometer_h
#define Accelerometer_h

#include <stdint.h>

class Accelerometer
{
    public:
        virtual void init();
        virtual void getGAccel(double& acc_x, double& acc_y, double& acc_z);
};

class BMI160Accelerometer : public Accelerometer
{
    public:
        virtual void init();
        virtual void getGAccel(double& acc_x, double& acc_y, double& acc_z);

    private:
        const int MPU_ADDRESS = 0x68;
        const double G = 16384.0;

        void getRawAccel(int16_t& rawX, int16_t& rawY, int16_t& rawZ);
        double convertToGAccel(int16_t rawAccel);
};

#endif