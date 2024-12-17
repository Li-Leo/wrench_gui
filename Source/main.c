

#include "bsp.h"
#include "oled.h"
#include "key.h"
#include "screen_proc.h"

void Task_Scheduler(void);
void para_init(void);
volatile u16 TimeCnt1ms, TimeCnt1000ms;


int main(void)
{
    Clock_Init();
    Hardware_init();
    oled_init();
    user_button_init();

    oled_draw_rectangle(0, 0, 20, 20, 1, 1);
    oled_update();
    InitializeHMIEngineObj();
    

    while(1) {
        // Task_Scheduler();
        gui_main_process();
    }
}

void delay(u16 cnt)
{
    u16 t_cnt;
    for (t_cnt = 0; t_cnt < cnt; t_cnt++){
        __nop();
    }
}


void Task_Scheduler(void)
{
    if (gTimeBaseFlg) {
        gTimeBaseFlg = 0;
        if (++TimeCnt1ms >= 20) {  //20ms
            TimeCnt1ms = 0;
            // oled_update();
            // flex_button_scan();
        }
    }
}

