/*!
 * @file DFRobot_ST7687S_Latch.h
 * @brief Define the infrastructure of the DFRobot_ST7687S_Latch class
 * @details Drive screen DFR0529 to display various images
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @License     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2022-03-25
 * @url https://github.com/DFRobot/DFRobot_ST7687S_Latch
 */
 
#ifndef DFROBOT_ST7687S_LATCH_H
#define DFROBOT_ST7687S_LATCH_H

#include "DFRobot_ST7687S.h"
#include "src/HC595.h"

// __GNUC__ 、__GNUC_MINOR__ 、__GNUC_PATCHLEVEL__

#if ((__GNUC__ > 3) && (__GNUC_MINOR__ <= 3))
  #define ST7687S_SPIBEGIN(x)       SPI.begin()
  #define ST7687S_SPIEND()          SPI.end()
#else
  #define ST7687S_SPIBEGIN(x)       SPI.begin();SPI.beginTransaction(SPISettings(x, MSBFIRST, SPI_MODE0))
  #define ST7687S_SPIEND()          SPI.endTransaction()
#endif



class DFRobot_ST7687S_Latch : public DFRobot_ST7687S
{
public:
  /**
   * @fn DFRobot_ST7687S_Latch
   * @brief Constructor pass the pins on the main controller to enable SPI communication
   * @param pin_cs the chip select pin in SPI communication
   * @param pin_cd the data/command select pin in communication
   * @param pin_wr the data pin (MOSI) in communication
   * @param pin_rck the clock pin in communication
   * @return None
   */
  DFRobot_ST7687S_Latch(uint8_t pin_cs, uint8_t pin_cd, uint8_t pin_wr, uint8_t pin_rck);
  /**
   * @fn begin
   * @brief Init function, initialize some parameters displayed on the screen, and enable display
   * @return Error code
   */
  int16_t begin();
  
  /**
   * @fn drawPixel
   * @brief Draw point function, draw a point on the screen
   * @param x x-coordinate
   * @param y y-coordinate
   * @param color pixel color
   */
  void drawPixel(int16_t x, int16_t y, uint16_t color);

private:
  uint8_t     pin_cs, pin_cd, pin_wr, pin_rck;
  void        writeCmd(uint8_t cmd);
  void        writeDat(uint8_t dat);
  void        writeDatBytes(uint8_t* pDat, uint16_t count);
  void        writeRepeatPixel(uint16_t color, uint16_t count, uint16_t repeatCount);
};


#endif


