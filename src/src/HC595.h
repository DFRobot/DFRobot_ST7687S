#ifndef HC595_H
#define HC595_H

#include "stdint.h"
#include "stdlib.h"

typedef void (* HC595_write_t) (uint8_t dat);
typedef void (* HC595_writeRCK_t) (uint8_t value);
typedef void (* HC595_delay_t) (void);

typedef struct sHC595_TypeDef {
  HC595_write_t pWrite;
  HC595_writeRCK_t pWriteRCK;
  HC595_delay_t pDelay;
} sHC595_t;

#ifdef __cplusplus
extern "C" {
#endif

void        HC595_begin(sHC595_t* psHC595);
void        HC595_writeReg(sHC595_t* psHC595, uint8_t dat, uint8_t action);

#ifdef __cplusplus
}
#endif

#endif
