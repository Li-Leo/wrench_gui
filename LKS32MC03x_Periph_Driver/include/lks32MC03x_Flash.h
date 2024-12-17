
#ifndef __LKS32MC03x_FLASH__
#define __LKS32MC03x_FLASH__
#include "lks32mc03x.h"

extern volatile u32 erase_flag;
extern volatile u32 progm_flag;
void EraseSector(u32 adr);
void ProgramPage (unsigned long adr, unsigned long sz, unsigned char *buf);
void Read_More_Flash(u32 adr, u32 sz, u32 *buf);

#endif


