#include "DFRobot_ST7687S.h"


DFRobot_ST7687S::DFRobot_ST7687S(void) :
                 DFRobot_Display(128, 128)
{
  setDisplayShape(eSHAPE_CIRCLE);
  setOrign(64, 64);
}


void DFRobot_ST7687S::setCursorAddr(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
  uint8_t addrBuf[2] = {(uint16_t)x0 , (uint16_t)x1};
  writeCmd(0x2a);
  writeDatBytes(addrBuf, 2);
  addrBuf[0] = (uint16_t)y0; addrBuf[1] = (uint16_t)y1;
  writeCmd(0x2b);
  writeDatBytes(addrBuf, 2);
}


void DFRobot_ST7687S::fillScreen(uint16_t color)
{
  uint8_t i, j;
  _DEBUG_PRINT("\nfill screen");
  setCursorAddr(0, 0, 128, 128);
  writeToRam();
  writeRepeatPixel(color, 128, 128);
}


void DFRobot_ST7687S::drawVLine(int16_t x, int16_t y, int16_t height_, uint16_t color)
{
  _DEBUG_PRINT("\n  drawVLine at :");
  _DEBUG_PRINTVAR(x, DEC);
  _DEBUG_PRINT(" ");
  _DEBUG_PRINTVAR(y, DEC);
  _DEBUG_PRINT(" ");
  _DEBUG_PRINTVAR(width, DEC);
  
  if(limitVLine(x, y, height_) < 0) {return;}
  setCursorAddr(x, y, x, y + height_ - 1);
  writeToRam();
  writeRepeatPixel(color, height_, 1);
}


void DFRobot_ST7687S::drawHLine(int16_t x, int16_t y, int16_t width_, uint16_t color)
{
  _DEBUG_PRINT("\n  drawHLine at :");
  _DEBUG_PRINTVAR(x, DEC);
  _DEBUG_PRINT(" ");
  _DEBUG_PRINTVAR(y, DEC);
  _DEBUG_PRINT(" ");
  _DEBUG_PRINTVAR(width_, DEC);
  
  if(limitHLine(x, y, width_) < 0) {Serial.print("drawHLine error \n");return;}
  setCursorAddr(x, y, x + width_ - 1, y);
  writeToRam();
  writeRepeatPixel(color, width_, 1);
}


inline void DFRobot_ST7687S::displayON(void)
{
  writeCmd(0x29);
}


inline void DFRobot_ST7687S::displayOFF(void)
{
  writeCmd(0x28);
}


inline void DFRobot_ST7687S::displaySleepIN(void)
{
  writeCmd(0x10);
}


inline void DFRobot_ST7687S::displaySleepOUT(void)
{
  writeCmd(0x11);
}

