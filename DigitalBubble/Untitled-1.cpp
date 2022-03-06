void getAttitude(double* pitch, double* roll)
{
    double acc_x, acc_y, acc_z;

    getGAccel(&acc_x, &acc_y, &acc_z);

    *roll = atan2(acc_y , acc_z) * radToDeg;
    *pitch = atan2((acc_x) , sqrt(acc_y * acc_y + acc_z * acc_z)) * radToDeg;

#ifdef ACCEL_DEBUG
    Serial.print("roll:");
    Serial.print(*roll);
    Serial.print("|pitch:");
    Serial.println(*pitch);
#endif
}


    // getAttitude(&roll, &pitch);

    // Serial.print("roll:");
    // Serial.println(roll);
    // Serial.print("pitch:");
    // Serial.println(pitch);

  //  Serial.println("----------------");

  


// void computeAngles(int rawX, int rawY, int rawZ, double* pitch, double* roll)
// {
//     double aX = computeAccel(rawX);
//     double aY = computeAccel(rawY);
//     double aZ = computeAccel(rawZ);

//     double aX2 = pow2(aX);
//     double aY2 = pow2(aY);
//     double aZ2 = pow2(aZ);

//     //*roll = atan(aY / sqrt(aX2 + aZ2)) * radToDeg;
//     //*pitch = atan(aX / sqrt(aY2 + aZ2)) * radToDeg;

//     // (better ?) alternative solution
//     *roll  = atan2(-aY, aZ) * radToDeg;
//     *pitch = atan2(aX, sqrt( aY2 + aZ2)) * radToDeg;
// }

// double computeAccel(double rawAxis)
// {
//     return rawAxis / g;
// }

// double pow2(double val)
// {
//     return val * val;
// }

// MPU-6050
// void initAccel()
// {
//     // We need to do three things.  1. Disable sleep mode on the MPU (it activates on powerup).  2. Set the scale of the Gyro.  3. Set the scale of the accelerometer
//     // We do this by sending 2 bytes for each:  Register Address & Value
//     Wire.beginTransmission(MPU_ADDRESS);
//     Wire.write(0x6B);       //  Power setting address
//     Wire.write(0b00000000); // Disable sleep mode (just in case)
//     Wire.endTransmission();
//     Wire.beginTransmission(MPU_ADDRESS);
//     Wire.write(0x1B);       // Config register for Gyro
//     Wire.write(0x00000000); // 250° per second range (default)
//     Wire.endTransmission();
//     Wire.beginTransmission(MPU_ADDRESS); //I2C address of the MPU
//     Wire.write(0x1C);            // Accelerometer config register
//     Wire.write(0b00000000);      // 2g range +/- (default)
//     Wire.endTransmission();
// }

// void readAccelerometerValues()
// {
//     Wire.beginTransmission(MPU_ADDRESS); //I2C address of the MPU
//     Wire.write(0x3B);            //  Acceleration data register
//     Wire.endTransmission();
//     Wire.requestFrom(MPU_ADDRESS, 6); // Get 6 bytes, 2 for each DoF
//     rawX = Wire.read() << 8;  // Get X upper byte first
//     rawX |= Wire.read();      // lower
//     rawY = Wire.read() << 8;  // Get Y upper byte first
//     rawY |= Wire.read();      // lower
//     rawZ = Wire.read() << 8;  // Get Z upper byte first
//     rawZ |= Wire.read();      // lower
// }

// void computeAngles(int rawX, int rawY, int rawZ, double* pitch, double* roll)
// {
//     double aX = computeAccel(rawX);
//     double aY = computeAccel(rawY);
//     double aZ = computeAccel(rawZ);

//     double aX2 = pow2(aX);
//     double aY2 = pow2(aY);
//     double aZ2 = pow2(aZ);

//     //*roll = atan(aY / sqrt(aX2 + aZ2)) * radToDeg;
//     //*pitch = atan(aX / sqrt(aY2 + aZ2)) * radToDeg;

//     // (better ?) alternative solution
//     *roll  = atan2(-aY, aZ) * radToDeg;
//     *pitch = atan2(aX, sqrt( aY2 + aZ2)) * radToDeg;
// }

// double computeAccel(double rawAxis)
// {
//     return rawAxis / g;
// }

// double pow2(double val)
// {
//     return val * val;
// }

// Serial.print("rawX:");
//     Serial.println(rawX);
//     Serial.print("rawY:");
//     Serial.println(rawY);
//     Serial.print("rawZ:");
//     Serial.println(rawZ);