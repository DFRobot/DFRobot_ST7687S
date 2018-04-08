#include "DFRobot_ST7687S_Latch.h"

static uint8_t        HC595_pin_rck = 0;


static void hc595_delayUS(void)
{
  //delayMicroseconds(1);
}


static void hc595_writeDat(uint8_t dat)
{
  SPI.transfer(dat);
}


static void hc595_writeRCK(uint8_t value)
{
  digitalWrite(HC595_pin_rck, value);
}


sHC595_t sHC595;

DFRobot_ST7687S_Latch::DFRobot_ST7687S_Latch(uint8_t pin_cs_, uint8_t pin_cd_,uint8_t pin_wr_, uint8_t pin_rck_)
{
  pin_cs = pin_cs_;
  pin_cd = pin_cd_;
  pin_wr = pin_wr_;
  pin_rck = pin_rck_;
  sHC595.pDelay = hc595_delayUS;
  sHC595.pWriteRCK = hc595_writeRCK;
  sHC595.pWrite = hc595_writeDat;
  HC595_pin_rck = pin_rck;
  HC595_begin(&sHC595);
  pinMode(pin_cs, OUTPUT);
  digitalWrite(pin_cs, 1);
  pinMode(pin_cd, OUTPUT);
  digitalWrite(pin_cd, 1);
  pinMode(pin_rck, OUTPUT);
  digitalWrite(pin_rck, 1);
  pinMode(pin_wr, OUTPUT);
  digitalWrite(pin_wr, 1);
}


int16_t DFRobot_ST7687S_Latch::begin(void)
{
  _DEBUG_PRINT("\nST7687S begin");
  delay(120);
	
  writeCmd(0xd7);
	writeDat(0x9f);
	
	writeCmd(0xE0);
	writeDat(0x00);
	delay(10); 
	
	writeCmd(0xFA);
	writeDat(0x01);
	delay(20); 
	
	writeCmd(0xE3);
	delay(20);
  writeCmd(0xE1);	
	
	writeCmd(0x28);
  writeCmd(0x11);	
	delay(30);
  writeCmd(0xc0); 
  writeDat(0x17);  //ctrL=0x1b 080416 5PCS 0X1E; 8PCS 0X2A
  writeDat(0x01);
	
	writeCmd(0x25);
	writeDat(0x1E);
	writeCmd(0xC3);
	writeDat(0x03);
	
	writeCmd(0xC4);
  writeDat(0x07);
	
	writeCmd(0xC5);
  writeDat(0x01);

	writeCmd(0xCB);
  writeDat(0x01);
	
	writeCmd(0xB7);
  writeDat(0x00);

	writeCmd(0xD0);
  writeDat(0x1d);
	writeCmd(0xB5);
  writeDat(0x89);

	writeCmd(0xBD);
  writeDat(0x02); 
	
	writeCmd(0xF0);	
	writeDat(0x07);
	writeDat(0x0C);
	writeDat(0x0C);
	writeDat(0x12);

	writeCmd(0xF4);	
	writeDat(0x33);
	writeDat(0x33);
	writeDat(0x33);
	writeDat(0x00);
	writeDat(0x33);
	writeDat(0x66);
	writeDat(0x66);
	writeDat(0x66);

  writeCmd(0x20);
	writeCmd(0x2A);
  writeDat(0x00);
	writeDat(0x7F);
	
	writeCmd(0x2B);
  writeDat(0x00);
	writeDat(0x7f);
	
	writeCmd(0x3A);
  writeDat(0x05);

	writeCmd(0x36);
  writeDat(0x80); //0xc8
	
	writeCmd(0xB0);
  writeDat(0x7F);
		
	writeCmd(0x29);
	////////	
	writeCmd(0xF9);	
	writeDat(0x00);
	writeDat(0x02);
	writeDat(0x04);
	writeDat(0x06);
	writeDat(0x08);
	writeDat(0x0a);
	writeDat(0x0c);
	writeDat(0x0e);
	writeDat(0x10);
	writeDat(0x12);
	writeDat(0x14);
	writeDat(0x16);
	writeDat(0x18);
	writeDat(0x1A);
	writeDat(0x1C);
	writeDat(0x1E);

	writeCmd(0x29);
	return BEGIN_WAR_NOTEST;
}


void DFRobot_ST7687S_Latch::drawPixel(int16_t x, int16_t y, uint16_t color)
{
  uint8_t colorBuf[2] = {color >> 8, color};
  if(limitPixel(x, y) < 0) {return;}
  setCursorAddr(x, y, x, y);
  writeToRam();
  writeDatBytes(colorBuf, 2);
}


void DFRobot_ST7687S_Latch::writeCmd(uint8_t cmd)
{
  ST7687S_SPIBEGIN(4000000);
  digitalWrite(pin_cd, 0);
  digitalWrite(pin_cs, 0);
  HC595_writeReg(&sHC595 ,cmd, 1);
  digitalWrite(pin_wr, 0);
  hc595_delayUS();
  digitalWrite(pin_wr, 1);
  digitalWrite(pin_cs, 1);
  ST7687S_SPIEND();
}


void DFRobot_ST7687S_Latch::writeDat(uint8_t dat)
{
  ST7687S_SPIBEGIN(4000000);
  digitalWrite(pin_cd, 1);
  digitalWrite(pin_cs, 0);
  HC595_writeReg(&sHC595, dat, 1);
  digitalWrite(pin_wr, 0);
  hc595_delayUS();
  digitalWrite(pin_wr, 1);
  digitalWrite(pin_cs, 1);
  ST7687S_SPIEND();
}


void DFRobot_ST7687S_Latch::writeDatBytes(uint8_t* pDat, uint16_t count)
{
  ST7687S_SPIBEGIN(4000000);
  #ifdef __ets__
    ESP.wdtFeed();
  #endif
  digitalWrite(pin_cd, 1);
  digitalWrite(pin_cs, 0);
  while(count --) {
    HC595_writeReg(&sHC595, *pDat, 1);
    digitalWrite(pin_wr, 0);
    hc595_delayUS();
    digitalWrite(pin_wr, 1);
    pDat ++;
  }
  digitalWrite(pin_cs, 1);
  ST7687S_SPIEND();
}


void DFRobot_ST7687S_Latch::writeRepeatPixel(uint16_t color, uint16_t count, uint16_t repeatCount)
{
  uint8_t       colorBuf[2] = {color >> 8, color};
  uint32_t      i = 0;
  for(i = 0; i < repeatCount * count; i ++) {
    writeDatBytes(colorBuf, 2);
  }
}


