/*
 * file clock.ino
 *
 * @ https://github.com/DFRobot/DFRobot_ST7687S
 *
 * connect with your board (please reference board compatibility)
 * 
 * controler (uno)        DFRobot 2.2 inch tft lcd display
 * SPI_SCK         ---->  SPI_SCL
 * SPI_MOSI        ---->  SPI_MOSI
 * 3               ---->  cs
 * 5               ---->  rs
 * 6               ---->  wr
 * 7               ---->  lck
 * 
 * a clock demo
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V1.0
 * date  2017-12-7
 */

#include "DFRobot_ST7687S_Latch.h"
#include "DFRobot_Display_Clock.h"
#include <TimeLib.h>

#ifdef __AVR__
uint8_t pin_cs = 3, pin_rs = 5, pin_wr = 6, pin_lck = 7;
#else
uint8_t pin_cs = D3, pin_rs = D5, pin_wr = D6, pin_lck = D7;
#endif

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
