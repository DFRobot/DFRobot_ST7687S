#include "HC595.h"


void HC595_begin(sHC595_t* psHC595)
{
  psHC595->pWriteRCK(0);
}


void HC595_writeReg(sHC595_t* psHC595, uint8_t dat, uint8_t action)
{
  psHC595->pWrite(dat);
  if(action) {
    psHC595->pWriteRCK(1);
    psHC595->pDelay();
    psHC595->pWriteRCK(0);
  }
}


