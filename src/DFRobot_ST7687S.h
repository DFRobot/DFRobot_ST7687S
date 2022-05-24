/*!
 * @file DFRobot_ST7687S.h
 * @brief Define the infrastructure of the DFRobot_ST7687S class
 * @details The library defines some functions required for the communication between the main controller and the screen, but some of them are virtual functions and require their subclass to implement the specific function.
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @License     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2022-03-25
 * @url https://github.com/DFRobot/DFRobot_ST7687S
 */
#ifndef DFROBOT_ST7687S_H
#define DFROBOT_ST7687S_H

#include "DFRobot_Display_Config.h"
#include "SPI.h"


class DFRobot_ST7687S : public DFRobot_Display
{
public:
  
  /**
   * @fn DFRobot_ST7687S
   * @brief Constructor
   * @return None
   */
  DFRobot_ST7687S(void);
  
  /**
   * @fn begin
   * @brief Init function, this function is a virtual function, the specific function is implemented by its subclass
   * @return Error code
   */
  virtual int16_t begin() = 0;

  /**
   * @fn writeCmd
   * @brief Write command to screen control chip, this function is a virtual function, the specific function is implemented by its subclass
   * @param cmd 命令
   */
  virtual void writeCmd(uint8_t cmd) = 0;

  /**
   * @fn writeDat
   * @brief Write data to screen control chip, this function is a virtual function, the specific function is implemented by its subclass
   * @param dat data
   */
  virtual void writeDat(uint8_t dat) = 0;

  /**
   * @fn writeDatBytes
   * @brief Write multiple data to screen controller chip, this function is a virtual function, the specific function is implemented by its subclass
   * @param pDat The first address for data storage
   * @param count The number of data
   */
  virtual void writeDatBytes(uint8_t* pDat, uint16_t count) = 0;

  /**
   * @fn writeRepeatPixel
   * @brief Repeatedly write pixel data to the screen, generally draw lines on the screen
   * @param color data in RGB565 format
   * @param count the number of data
   * @param repeatCount data repeat count
   */
  virtual void writeRepeatPixel(uint16_t color, uint16_t count, uint16_t repeatCount) = 0;

  /**
   * @fn fillScreen
   * @brief Fill screen with a color
   * @param color data in RGB565 format
   */
  void fillScreen(uint16_t color);    
  
  /**
   * @fn setCursorAddr
   * @brief Set the screen area to be operated
   * @param x0 with the top left corner of the screen as the origin, the x-coordinate of the starting point of the screen area
   * @param y0 the y-coordinate of the starting point of the screen area
   * @param x1 the x-coordinate of the end point of the screen area
   * @param y1 the y-coordinate of the end point of the screen area
   */
  void setCursorAddr(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
  
  /**
   * @fn drawHLine
   * @brief Draw a line parallel to x-axis on the screen
   * @param x with the top left corner of the screen as the origin, the x-coordinate of the starting point of the line
   * @param y the y-coordinate of the starting point of the line
   * @param width the line width
   * @param color the line color
   */
  void drawHLine(int16_t x, int16_t y, int16_t width, uint16_t color);

  /**
   * @fn drawVLine
   * @brief Draw a line parallel to y-axis on the screen
   * @param x with the top left corner of the screen as the origin, the x-coordinate of the starting point of the line
   * @param y the y-coordinate of the starting point of the line
   * @param width the line width
   * @param color the line color
   */
  void drawVLine(int16_t x, int16_t y, int16_t height, uint16_t color);

  /**
   * @fn writeToRam
   * @brief Write data to the screen, it is the code for configuring the screen display area before this function,  and is the specific data of the screen pixel display color after it.
   */
  void writeToRam(void) {writeCmd(0x2c);}
private:

  void        displayON(void);
  void        displayOFF(void);
  void        displaySleepIN(void);
  void        displaySleepOUT(void);
};

#endif
