#ifndef __KEY_H__
#define __KEY_H__

#include "flexible_button.h"

bool main_key_is_pressed(void);
bool up_key_is_pressed(void);
bool down_key_is_pressed(void);

void main_key_trigger_reset(void);
void up_key_trigger_reset(void);
void down_key_trigger_reset(void);

void user_button_init(void);
uint16_t key_get_key_code(void);


#endif

