#ifndef UnitTests_h
#define UnitTests_h

#include "testUtils.h"
#include "angleCalculation_tests.h"

void runUnitTests()
{
    Serial.println("Starting Unit Test Session.");

    runTest(test_pow2);
    runTest(test_computeAccel);
    runTest(test_computeAngles);

    Serial.println("Session completed.");
}

#endif