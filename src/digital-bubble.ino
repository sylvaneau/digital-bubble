#include <TinyWireM.h>
#include <Tiny4kOLED.h>

char mpu = 0x68; // I2C address of MPU.

int rawX, rawY, rawZ; // for storing raw accelerometer values
double aX, aY, aZ; // axis acceleration in g
double angleX, angleY, angleZ; // inclinaison in degrees around each axes

const double g = 16384.0;
const double radToDeg = 57.2958;

void setup()
{
    TinyWireM.begin(); // init I2C

    init_mpu();
    init_display();
}

void loop()
{
    getAccel();
    computeAngles();

    updateDisplay();
    delay(100);
}

void init_mpu()
{
    // We need to do three things.  1. Disable sleep mode on the MPU (it activates on powerup).  2. Set the scale of the Gyro.  3. Set the scale of the accelerometer
    // We do this by sending 2 bytes for each:  Register Address & Value
    TinyWireM.beginTransmission(mpu);
    TinyWireM.write(0x6B);       //  Power setting address
    TinyWireM.write(0b00000000); // Disable sleep mode (just in case)
    TinyWireM.endTransmission();
    TinyWireM.beginTransmission(mpu);
    TinyWireM.write(0x1B);       // Config register for Gyro
    TinyWireM.write(0x00000000); // 250° per second range (default)
    TinyWireM.endTransmission();
    TinyWireM.beginTransmission(mpu); //I2C address of the MPU
    TinyWireM.write(0x1C);            // Accelerometer config register
    TinyWireM.write(0b00000000);      // 2g range +/- (default)
    TinyWireM.endTransmission();
}

void init_display()
{
    oled.begin();

    oled.setFont(FONT8X16);

    // Clear the memory before turning on the display
    oled.clear();

    // Turn on the display
    oled.on();

    // Switch the half of RAM that we are writing to, to be the half that is non currently displayed
    oled.switchRenderFrame();
}

void getAccel()
{
    TinyWireM.beginTransmission(mpu); //I2C address of the MPU
    TinyWireM.write(0x3B);            //  Acceleration data register
    TinyWireM.endTransmission();
    TinyWireM.requestFrom(mpu, 6);  // Get 6 bytes, 2 for each DoF
    rawX = TinyWireM.read() << 8; // Get X upper byte first
    rawX |= TinyWireM.read();     // lower
    rawY = TinyWireM.read() << 8; // Get Y upper byte first
    rawY |= TinyWireM.read();     // lower
    rawZ = TinyWireM.read() << 8; // Get Z upper byte first
    rawZ |= TinyWireM.read();     // lower
}

void computeAngles()
{
    aX = rawX / g;
    aY = rawY / g;
    aZ = rawZ / g;

    double aX2 = aX * aX;
    double aY2 = aY * aY;
    double aZ2 = aZ * aZ;

    angleX = atan(aY / sqrt(aX2 + aZ2)) * radToDeg;
    angleY = atan(aX / sqrt(aY2 + aZ2)) * radToDeg;
    angleZ = atan(sqrt(aX2 + aY2) / aZ) * radToDeg;
}

void updateDisplay() {
  // Clear the half of memory not currently being displayed.
  oled.clear();

  // Position the text cursor
  // In order to keep the library size small, text can only be positioned
  // with the top of the font aligned with one of the four 8 bit high RAM pages.
  // The Y value therefore can only have the value 0, 1, 2, or 3.
  // usage: oled.setCursor(X IN PIXELS, Y IN ROWS OF 8 PIXELS STARTING WITH 0);
  oled.setCursor(0, 1);

  // Write text to oled RAM (which is not currently being displayed).
  

  // Write the number of milliseconds since power on.
  oled.print(angleX);

  oled.print(F(":"));

  oled.print(angleY);

  oled.print(F(":"));

  oled.print(angleZ);

  // Swap which half of RAM is being written to, and which half is being displayed.
  // This is equivalent to calling both switchRenderFrame and switchDisplayFrame.
  oled.switchFrame();
}