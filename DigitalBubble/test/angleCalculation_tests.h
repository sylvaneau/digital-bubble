#ifndef AngleCalculation_tests_h
#define AngleCalculation_tests_h

#include "testUtils.h"

#include "../angleCalculation.h"

TestResult test_pow2()
{
    double actual = pow2(4.0);
    double expected = 16.0;

    return AssertEquals(__func__, actual, expected);
}

TestResult test_computeAccel()
{
    double actual = computeAccel(8192);
    double expected = 0.5;

    return AssertEquals(__func__, actual, expected);
}

TestResult test_computeAngles()
{
    double x, y;

    double aX = 0;
    double aY = 0;
    double aZ = 16384;

    double eX = 0;
    double eY = 0;

    computeAngles(aX, aY, aZ, &x, &y);

    if (x == eX && y == eY)
    {
        return AssertSuccess(__func__);
    }
    else
    {
        String actual = x + String(":") + y;
        String expected = eX + String(":") + eY;

        return AssertFaillure(__func__, actual, expected);
    }
}

#endif