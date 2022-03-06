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

void BMI160Accelerometer::getRawAccel(int16_t& rawX, int16_t& rawY, int16_t& rawZ)
{
    // perform any axis swap or inversion to comply with following axis order:
    // (level laying flat on 'wide' side)
    // x facing front
    // y facing left
    // z facing top
    BMI160.getAcceleration(&rawX, &rawY, &rawZ);
}

double BMI160Accelerometer::convertRawToGAccel(int16_t rawAccel)
{
    return rawAccel / G;
}

void BMI160Accelerometer::getGAccel(double& acc_x, double& acc_y, double& acc_z)
{
    int16_t rawX, rawY, rawZ;

    getRawAccel(rawX, rawY, rawZ);

    acc_x = convertRawToGAccel(rawX);
    acc_y = convertRawToGAccel(rawY);
    acc_z = convertRawToGAccel(rawZ);

#ifdef DEBUG_ACCEL
    Serial.print("acc_x:");
    Serial.print(*acc_x);
    Serial.print("|acc_y:");
    Serial.print(*acc_y);
    Serial.print("|acc_z:");
    Serial.println(*acc_z);
#endif
}