#ifndef __OLED_H__
#define __OLED_H__

#include "stdint.h"


void oled_draw_point(int X, int Y, unsigned int color);
void oled_clear(void);
void oled_update(void);
void oled_init(void);
void oled_draw_rectangle(int16_t X, int16_t Y, uint8_t Width, uint8_t Height, uint8_t IsFilled, unsigned int color);


#endif

