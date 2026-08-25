/*
    Siemens A70 (phone) LCD with PCF8812 controller;
    based on ancient german arduino library of author unthor;

    GP 2026
*/

#ifndef PCF8812_h

#define PCF8812_h
#define OLED_TINY
#define OLEDDISPLAY_REDUCE_MEMORY

// defaults for siemens A70 LCD, redefine in your variant.h when needed
#ifndef PCF8812_WIDTH
#define PCF8812_WIDTH 101
#endif
#ifndef PCF8812_HEIGHT
#define PCF8812_HEIGHT 64
#endif
// actually it is 102x64, but last is byte invisie (padding? protocol?): 1=yes, 0=no
#ifndef PCF8812_EXTRA_BYTE
#define PCF8812_EXTRA_BYTE 1
#endif
// each unit might reqire tuning contrast: 0-255
#ifndef PCF8812_CONTRAST
#define PCF8812_CONTRAST 215
#endif
// display mode: normal = 0x0C, inverted = 0x0D
#ifndef PCF8812_INVERT
#define PCF8812_INVERT 0x0C
#endif
// vertical flip by altering buffer read math: 1=yes, 0=no
#ifndef PCF8812_FLIP
#define PCF8812_FLIP 0
#endif
// backlight pin, not mandatory
#ifndef PCF8812_BL
#define PCF8812_BL -1
#endif
// level for backlight "ON" state: HIGH/LOW, 1/0
#ifndef PCF8812_BLSTATE
#define PCF8812_BLSTATE HIGH
#endif
// "Brightness" is intended to control backlight: 0-255
#ifndef PCF8812_BRIGHTNESS
#define PCF8812_BRIGHTNESS 255
#endif

#include "OLEDDisplay.h"
#include <DebugConfiguration.h>

class PCF8812 : public OLEDDisplay
{

private:
    uint8_t this_brightness;
    uint8_t this_contrast;
    uint8_t this_invert;
    uint8_t this_flip;
    uint8_t this_mode;

    void PCF_HW_RESET()
    {
        delayMicroseconds(10);
        digitalWrite(PCF8812_DAT, LOW);
        digitalWrite(PCF8812_CLK, LOW);
        digitalWrite(PCF8812_DC, LOW);
        delayMicroseconds(10);
        digitalWrite(PCF8812_RST, HIGH);
        delayMicroseconds(20);
        digitalWrite(PCF8812_RST, LOW);
        delayMicroseconds(10);
        digitalWrite(PCF8812_RST, HIGH);
    }

    // "send command", same as "write data" except DC pin is LOW
    void PCF_CMD(uint8_t cmd)
    {
        uint8_t i, s;
        s = 0x80;
        digitalWrite(PCF8812_DAT, LOW);
        digitalWrite(PCF8812_CLK, LOW);
        digitalWrite(PCF8812_DC, LOW);
        for (i = 0; i < 8; i++)
        {
            if (cmd & s)
            {
                digitalWrite(PCF8812_DAT, HIGH);
            }
            else
            {
                digitalWrite(PCF8812_DAT, LOW);
            }
            s = s >> 1;
            delayMicroseconds(1);
            digitalWrite(PCF8812_CLK, HIGH);
            delayMicroseconds(1);
            digitalWrite(PCF8812_CLK, LOW);
        }
    }

    // "write data", same as "send command" except DC pin is HIGH
    void PCF_WRITE(uint8_t val)
    {
        uint8_t i;
        digitalWrite(PCF8812_DAT, LOW);
        digitalWrite(PCF8812_CLK, LOW);
        digitalWrite(PCF8812_DC, HIGH);
        for (i = 0; i < 8; i++)
        {
            if (val & (1 << i))
            {
                digitalWrite(PCF8812_DAT, HIGH);
            }
            else
            {
                digitalWrite(PCF8812_DAT, LOW);
            }
            delayMicroseconds(1);
            digitalWrite(PCF8812_CLK, HIGH);
            delayMicroseconds(1);
            digitalWrite(PCF8812_CLK, LOW);
        }
    }

    // same as "write data" but bits in reverse order
    void PCF_WRITE_FLIP(uint8_t val)
    {
        uint8_t i, s;
        s = 0x80;
        digitalWrite(PCF8812_DAT, LOW);
        digitalWrite(PCF8812_CLK, LOW);
        digitalWrite(PCF8812_DC, HIGH);
        for (i = 0; i < 8; i++)
        {
            if (val & s)
            {
                digitalWrite(PCF8812_DAT, HIGH);
            }
            else
            {
                digitalWrite(PCF8812_DAT, LOW);
            }
            s = s >> 1;
            delayMicroseconds(1);
            digitalWrite(PCF8812_CLK, HIGH);
            delayMicroseconds(1);
            digitalWrite(PCF8812_CLK, LOW);
        }
    }

    // here used only to reset pos to 0, but needed if implementing double buffer
    void PCF_GOTO(uint8_t Line, uint8_t Row)
    {
        PCF_CMD(0b00101000);
        PCF_CMD((0b01000000 + Line));
        PCF_CMD((0b10000000 + Row));
    }

    // why is this needed?
    int getBufferOffset(void) { return 0; }

public:
    PCF8812()
    {
        setGeometry(GEOMETRY_RAWMODE, PCF8812_WIDTH, PCF8812_HEIGHT);
        // defaults
        this_brightness = PCF8812_BRIGHTNESS;
        this_contrast = PCF8812_CONTRAST;
        this_invert = PCF8812_INVERT;
        this_flip = PCF8812_FLIP;
        this_mode = 1;
    }

    void sendInitCommands()
    {
        // hardware reset reqired before init
        PCF_HW_RESET();
        // must be sent in sequence
        PCF_CMD(0x21);          // Extended instruction set
        PCF_CMD(0x14);          // Bias System
        PCF_CMD(0x0A);          // HV-gen stages
        PCF_CMD(0x00);          // Temperature Control
        PCF_CMD(this_contrast); // Contrast level (normal~0xCC)
        PCF_CMD(0x20);          // Standard instruction set
        PCF_CMD(0x11);          // VLCD programming range high
        PCF_CMD(this_invert);   // Display mode (normal=0x0C, inverted=0x0D)
    }

    bool connect()
    {
        // configure pins before sending commands init
        pinMode(PCF8812_DAT, OUTPUT);
        pinMode(PCF8812_CLK, OUTPUT);
        pinMode(PCF8812_DC, OUTPUT);
        pinMode(PCF8812_RST, OUTPUT);
#if (PCF8812_BL >= 0)
        pinMode(PCF8812_BL, OUTPUT);
#endif
        return true;
    }

    void display()
    {
        uint16_t x, y, pos;
        PCF_GOTO(0, 0);
        if (this_mode == 0)
        { // forece clear when display is "off"
            for (y = 0; y < displayHeight / 8; y++)
            {
                for (x = displayWidth; x > 0; x--)
                {
                    PCF_WRITE(0x00);
                    yield();
                }
#if (PCF8812_EXTRA_BYTE > 0)
                PCF_WRITE(0x00); // invisible byte #102 every row
#endif
            }
        }
        else if (this_flip == 0)
        { // normal: Y forward, X reverse, low bit first
            for (y = 0; y < displayHeight / 8; y++)
            {
                for (x = displayWidth; x > 0; x--)
                {
                    pos = x + (y * displayWidth) - 1;
                    PCF_WRITE(buffer[pos]);
                    yield();
                }
#if (PCF8812_EXTRA_BYTE > 0)
                PCF_WRITE(0x00); // invisible byte #102 every row
#endif
            }
        }
        else
        { // flipped: Y reverse, X forward, high bit first
            for (y = displayHeight / 8; y > 0; y--)
            {
                for (x = 0; x < displayWidth; x++)
                {
                    pos = x + ((y - 1) * displayWidth);
                    PCF_WRITE_FLIP(buffer[pos]);
                    yield();
                }
#if (PCF8812_EXTRA_BYTE > 0)
                PCF_WRITE_FLIP(0x00); // invisible byte #102 every row
#endif
            }
        }
    }

    void displayOn()
    {
        this_mode = 1;
        sendInitCommands();
        // backlight
#if (PCF8812_BL >= 0)
#ifdef ESP_PLATFORM
#if (PCF8812_BLSTATE == HIGH)
        analogWrite(PCF8812_BL, this_brightness);
#else
        analogWrite(PCF8812_BL, (255 - (this_brightness)));
#endif
#else
        digitalWrite(PCF8812_BL, PCF8812_BLSTATE);
#endif
#endif
    }

    void displayOff()
    {
        this_mode = 0;
        display();
        // backlight
#if (PCF8812_BL >= 0)
#ifdef ESP_PLATFORM
#if (PCF8812_BLSTATE == HIGH)
        analogWrite(PCF8812_BL, 0);
#else
        analogWrite(PCF8812_BL, 255);
#endif
#else
        digitalWrite(PCF8812_BL, !PCF8812_BLSTATE);
#endif
#endif
    }

    void setBrightness(uint8_t new_brightness)
    {
        this_brightness = new_brightness;
        // backlight
#if (PCF8812_BL >= 0)
#ifdef ESP_PLATFORM
#if (PCF8812_BLSTATE == HIGH)
        analogWrite(PCF8812_BL, this_brightness);
#else
        analogWrite(PCF8812_BL, (255 - this_brightness));
#endif
#else
        if (this_brightness > 128)
        {
            digitalWrite(PCF8812_BL, PCF8812_BLSTATE);
        }
        else
        {
            digitalWrite(PCF8812_BL, !PCF8812_BLSTATE);
        }
#endif
#endif
    }

    void setContrast(uint8_t new_contrast)
    {
        this_contrast = new_contrast;
        sendInitCommands();
    }

    void setInvert(uint8_t new_invert)
    {
        this_invert = new_invert;
        sendInitCommands();
    }

    void flipScreenVertically()
    {
        this_flip = 1;
    }

    void resetOrientation()
    {
        this_flip = 0;
    }

    void mirrorScreen()
    {
        // not supported
    }
};

#endif