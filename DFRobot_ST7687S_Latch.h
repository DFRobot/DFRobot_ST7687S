#ifndef DFROBOT_ST7687S_LATCH_H
#define DFROBOT_ST7687S_LATCH_H

#include "DFRobot_ST7687S.h"
#include "HC595.h"

// __GNUC__ 、__GNUC_MINOR__ 、__GNUC_PATCHLEVEL__

#if ((__GNUC__ > 3) && (__GNUC_MINOR__ <= 3))
  #define ST7687S_SPIBEGIN(x)       SPI.begin()
  #define ST7687S_SPIEND()          SPI.end()
#else
  #define ST7687S_SPIBEGIN(x)       SPI.begin();SPI.beginTransaction(SPISettings(x, MSBFIRST, SPI_MODE0))
  #define ST7687S_SPIEND()          SPI.endTransaction()
#endif

enum ST7687S_Rotation {ST7687S_Rotation_0, ST7687S_Rotation_90, ST7687S_Rotation_180, ST7687S_Rotation_270 };

class DFRobot_ST7687S_Latch : public DFRobot_ST7687S
{
  public:
    DFRobot_ST7687S_Latch(uint8_t pin_cs, uint8_t pin_cd, uint8_t pin_wr, uint8_t pin_rck);

    int16_t     begin(ST7687S_Rotation rotation);  
    virtual int16_t     begin();
    void        drawPixel(int16_t x, int16_t y, uint16_t color);

  private:
    uint8_t     pin_cs, pin_cd, pin_wr, pin_rck;
  
    void        writeCmd(uint8_t cmd);
    void        writeDat(uint8_t dat);
    void        writeDatBytes(uint8_t* pDat, uint16_t count);
    void        writeRepeatPixel(uint16_t color, uint16_t count, uint16_t repeatCount);
};


#endif


