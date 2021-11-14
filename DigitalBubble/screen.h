#ifndef Screen_h
#define Screen_h

#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

class Screen
{
    public:
        Screen();

        void init();
        void update(double angle);

    private:
        Adafruit_SSD1306 display;
};

#endif