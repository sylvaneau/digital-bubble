#include "accelerometer.h"

#include <Math.h>
#include <Wire.h>

// Uncomment to enable DEBUG
//#define DEBUG_ACCEL

/******************************
 *       BMI160 Impl         
 *****************************/

#include <BMI160Gen.h>

void BMI160Accelerometer::init()
{
    BMI160.begin(BMI160GenClass::I2C_MODE, MPU_ADDRESS);
}

// Get raw values from sensor and adapt axis orientation differences
void BMI160Accelerometer::getRawAccel(int16_t& rawX, int16_t& rawY, int16_t& rawZ)
{
    int16_t sensorX, sensorY, sensorZ;

    BMI160.getAcceleration(&sensorX, &sensorY, &sensorZ);

    rawX = sensorZ;
    rawY = sensorY;
    rawZ = -sensorX;
}

double BMI160Accelerometer::convertToGAccel(int16_t rawAccel)
{
    return rawAccel / G;
}

void BMI160Accelerometer::getGAccel(double& acc_x, double& acc_y, double& acc_z)
{
    int16_t rawX, rawY, rawZ;

    getRawAccel(rawX, rawY, rawZ);

    acc_x = convertToGAccel(rawX);
    acc_y = convertToGAccel(rawY);
    acc_z = convertToGAccel(rawZ);

#ifdef DEBUG_ACCEL
    Serial.print("acc_x:");
    Serial.print(*acc_x);
    Serial.print("|acc_y:");
    Serial.print(*acc_y);
    Serial.print("|acc_z:");
    Serial.println(*acc_z);
#endif
}