/*
 * file drawBmp.ino
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
 * a BMP demo
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2016
 * Copyright   GNU Lesser General Public License
 *
 * version  V1.0
 * date  2018/4/27
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

DFRobot_ST7687S_Latch tft(pin_cs, pin_rs, pin_wr, pin_lck);

void setup(void)
{
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(DISPLAY_BLACK);
  tft.drawBmp((uint8_t*)gImage_weixin, -50, -50, 100, 100);
}

void loop(void)
{

}
