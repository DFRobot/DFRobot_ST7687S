/*!
 * @file ST7687SLatchDemo.ino
 * @brief Use this library to display various patterns on the screen, such as, rectangles, circles, lines. 
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT license (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2022-03-25
 * @https://github.com/DFRobot/DFRobot_ST7687S
 */
 
#include "DFRobot_ST7687S_Latch.h"
#include "DFRobot_Display_Clock.h"
#include "SPI.h"

#ifdef __AVR__
uint8_t pin_cs = 3, pin_rs = 5, pin_wr = 6, pin_lck = 7;
#else
uint8_t pin_cs = D3, pin_rs = D5, pin_wr = D6, pin_lck = D7;
#endif
/**
 * @fn DFRobot_ST7687S_Latch
 * @brief Constructor pass the pins on the main controller to enable SPI communication
 * @param pin_cs the chip select pin in SPI communication
 * @param pin_cd the data/command select pin in communication
 * @param pin_wr the data pin (MOSI) in communication
 * @param pin_rck the clock pin in communication
 * @return None
 */
DFRobot_ST7687S_Latch tft(pin_cs, pin_rs, pin_wr, pin_lck);

void setup(void)
{
  Serial.begin(115200);
  tft.begin();
}

void loop(void)
{
  delay(1000);
  tft.fillScreen(DISPLAY_RED);  //fill screen with color
  delay(1000);
  tft.fillScreen(DISPLAY_WHITE);

  tft.fillScreen(DISPLAY_BLACK);
  tft.drawCircle(0, 0, 20, DISPLAY_GREEN);  //draw circle at (0, 0) and radius = 20
  tft.drawRect(-20, -30, 40, 60, DISPLAY_CYAN);  //draw rectangle at (-20, -30), width = 40, height = 60
  tft.drawLine(-64, -64, 64, 64, DISPLAY_RED);  //draw line at (-64, -64) to (64, 64)
  tft.drawHLine(-64, 0, 128, DISPLAY_WHITE);  //draw horizontal line at (-64, 0), length = 128
  tft.drawVLine(0, -64, 128, DISPLAY_WHITE);  //draw vertical line at (0, -128), length = 128
  tft.drawTriangle(-20, -50, 0, 0, 50, 20, DISPLAY_ORANGE);  //draw triangle at (-20, -50), (0, 0), (50, 20)
  delay(1000);
  tft.fillCircle(0, 0, 20, DISPLAY_GREEN);  //fill circle
  delay(500);
  tft.fillRect(-20, -20, 40, 40, DISPLAY_CYAN);  //fill rectangle
  delay(500);
  tft.fillTriangle(-20, -50, -20, 0, 50, 20, DISPLAY_ORANGE);  //fill triangle with color
  delay(500);
  tft.fillScreen(DISPLAY_BLACK);
  tft.setTextColor(DISPLAY_WHITE);  //set text color to white
  tft.setTextBackground(DISPLAY_BLACK);  //set text background to black
  tft.setTextSize(2);  //2 * text size, default text size: 6 * 8
  tft.setCursor(tft.width / 2, tft.height / 2);  //set text position to center
  tft.print("fire");
  delay(1000);
  tft.setCursor(tft.width / 2, tft.height / 2);
  tft.print("beet");
  delay(1000);
}
