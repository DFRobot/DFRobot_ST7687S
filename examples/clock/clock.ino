/*!
 * @file clock.ino
 * @brief Display a clock on the circular screen
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT license (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2022-03-25
 * @https://github.com/DFRobot/DFRobot_ST7687S
 */
 
#include "DFRobot_ST7687S_Latch.h"
#include "DFRobot_Display_Clock.h"
#include <src/TimeLib.h>
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
DFRobot_Display_Clock clk(&tft);

void setup(void)
{
  Serial.begin(115200);
  setTime(18,0,0,19,4,2018);
  tft.begin();
  tft.fillScreen(DISPLAY_BLACK);
  clk.setPointerLength(32, 40, 48);  //pointer length: hour, minute, second
  clk.setPointerWidth(3, 2, 2);  //pointer width: hour, minute, second
  clk.setPointerColor(DISPLAY_RED, DISPLAY_GREEN, DISPLAY_BLUE);  //pointer color: hour, min, second
  clk.setClockDial(0, 0, 60);  //clock position x, y, clock radius
  clk.setDialColor(DISPLAY_WHITE, DISPLAY_BLACK);  //clock border volor, background
  clk.showDial();  //draw dial
}

void loop(void)
{
  clk.updateClock(hour(), minute(), second());
}
