#ifndef DFROBOT_ST7687S_H
#define DFROBOT_ST7687S_H

#include "DFRobot_Display_Config.h"


class DFRobot_ST7687S : public DFRobot_Display
{
  public:
    DFRobot_ST7687S(void);

    virtual int16_t     begin() = 0;
    virtual void        writeCmd(uint8_t cmd) = 0;
    virtual void        writeDat(uint8_t dat) = 0;
    virtual void        writeDatBytes(uint8_t* pDat, uint16_t count) = 0;
    virtual void        writeRepeatPixel(uint16_t color, uint16_t count, uint16_t repeatCount) = 0;

    void        fillScreen(uint16_t color);    
    void        setCursorAddr(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
    void        drawHLine(int16_t x, int16_t y, int16_t width, uint16_t color);
    void        drawVLine(int16_t x, int16_t y, int16_t height, uint16_t color);
    void        writeToRam(void) {writeCmd(0x2c);}
    
    void        displayON(void);
    void        displayOFF(void);
    void        displaySleepIN(void);
    void        displaySleepOUT(void);
};

#endif