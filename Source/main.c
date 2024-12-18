
#include "bsp.h"
#include "oled.h"
#include "key.h"
#include "screen_proc.h"

int main(void)
{
    Hardware_init();
    oled_init();
    user_button_init();
    oled_clear();
    hmi_engine_obj_init();
    
    while(1) {
        gui_main_process();
    }
}

void delay(u16 cnt)
{
    u16 t_cnt;
    for (t_cnt = 0; t_cnt < cnt; t_cnt++) {
        __nop();
    }
}


