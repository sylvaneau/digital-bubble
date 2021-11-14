#include <Wire.h>

#include "accelerometer.h"
#include "screen.h"
#include "level.h"

// Uncomment to enable unit tests execution
// #define UNIT_TEST

// Uncomment to enable DEBUG
// #define DEBUG

#ifdef UNIT_TEST
#include "test/unitTests.h"
#endif

BMI160Accelerometer accelerometer = BMI160Accelerometer();
Screen screen = Screen();
Level level = Level();

void setup()
{
    Wire.begin();         // init I2C
    Serial.begin(115200); // init Serial

#ifdef UNIT_TEST
    runUnitTests(); // run unit tests and loop forever
    for (;;)
        ;
#endif

    accelerometer.init();
    screen.init();
}

void loop()
{
    double acc_x, acc_y, acc_z;

    accelerometer.getGAccel(acc_x, acc_y, acc_z);
    level.update(acc_x, acc_y, acc_z);
    screen.update(level.getAngle());

    delay(100);
}
