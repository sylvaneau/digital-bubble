#include "level.h"

#include <math.h>
#include <Arduino.h>

// Uncomment to enable DEBUG
//#define DEBUG_LEVEL

Level::Level()
{

}

void Level::update(double acc_x, double acc_y, double acc_z)
{
    this->acc_x == acc_x;
    this->acc_y == acc_y;
    this->acc_z == acc_z;

    roll = atan2(acc_y , acc_z) * RAD_TO_DEG;
    pitch = atan2(acc_x , sqrt(acc_y * acc_y + acc_z * acc_z)) * RAD_TO_DEG;

#ifdef DEBUG_LEVEL
    Serial.print("roll:");
    Serial.print(roll);
    Serial.print("|pitch:");
    Serial.println(pitch);
#endif
}

double Level::getAngle()
{
    return roll;
}