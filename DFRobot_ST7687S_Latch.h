#ifndef DFROBOT_ST7687S_LATCH_H
#define DFROBOT_ST7687S_LATCH_H

#include "DFRobot_ST7687S.h"
#include "HC595.h"

#define ST7687S_SPIBEGIN(x)         SPI.begin();SPI.beginTransaction(SPISettings(x, MSBFIRST, SPI_MODE0))
#define ST7687S_SPIEND()            SPI.endTransaction()


class DFRobot_ST7687S_Latch : public DFRobot_ST7687S
{
  public:
    DFRobot_ST7687S_Latch(uint8_t pin_cs, uint8_t pin_cd, uint8_t pin_wr, uint8_t pin_rck);
  
    int16_t     begin();
    void        drawPixel(int16_t x, int16_t y, uint16_t color);

  private:
    uint8_t     pin_cs, pin_cd, pin_wr, pin_rck;
  
    void        writeCmd(uint8_t cmd);
    void        writeDat(uint8_t dat);
    void        writeDatBytes(uint8_t* pDat, uint16_t count);
    void        writeRepeatPixel(uint16_t color, uint16_t count, uint16_t repeatCount);
};


#endif


