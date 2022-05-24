/*!
 * @file drawBmp.ino
 * @brief Display bitmap on the circular screen
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT license (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2022-03-25
 * @https://github.com/DFRobot/DFRobot_ST7687S
 */
#include "DFRobot_ST7687S_Latch.h"
#include "DFRobot_Display_Clock.h"
#include "weixinpic.c"
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
  //Fill the screen with black
  tft.fillScreen(DISPLAY_BLACK);
  //Display bitmap
  tft.drawBmp((uint8_t*)gImage_weixin, -50, -50, 100, 100);
}

void loop(void)
{

}
