#ifndef __BSP_H__
#define __BSP_H__

#define DEBUG_TRUE              0
#define DEBUG_FAULT             1
#define MACHINE_MODE_DEBUG      DEBUG_FAULT   //  DEBUG_UART

#define PROTECTION_ENABLE       1
#define PROTECTION_DISABLE      2 
#define CODE_PROTECTION         PROTECTION_ENABLE

#define ONFLY_ENABLE            1
#define ONFLY_DISABLE           2 
#define MOTOR_ONFLY_MODE        ONFLY_ENABLE

#define MOS_LOW_NO_INVERTED     1
#define MOS_LOW_INVERTED        2 
#define MOS_DRIVE_PWM           MOS_LOW_INVERTED

#define MOS_EBS_ALL_ON          1
#define MOS_EBS_ALL_SOFT        2
#define MOS_EBS_ALL_OFF         3
#define MOS_EBS_MODE            MOS_EBS_ALL_ON

#define CMP_IP                  1
#define CMP_OUT                 2
#define CMP_SAFE_MODE           CMP_OUT
 

#define RESTART_ENABLE          1
#define RESTART_DISABLE         2 
#define MOTOR_RESTART_MODE      RESTART_ENABLE
#define ERROR_RESTART           3

#define SPEED_CONSTANT          1
#define SPEED_K_MODE            2
#define SPEED_SET_MODE          SPEED_K_MODE

#define LED_SW_UPDATE           1
#define LED_REAL_TIME_UPDATE    2
#define LED_POWER_DISPLAY_MODE  LED_REAL_TIME_UPDATE

#define MAX_START_TIME          100
#define POLE_NUMBER             (2)

// Key 
#define KEY_S1_DOWN     0
#define KEY_S1_UP       1

#define KEY_S2_DOWN     0
#define KEY_S2_UP       1

#define KEY_DOWN        1
#define KEY_UP          0
#define KEY_LONG        2

#define DIRECT_FAN      0
#define DIRECT_ZHEN     1

#define MOTOR_RUN_ZHEN       1
#define MOTOR_STOP_FAN      0

#define LED_STATE_ON    1
#define LED_STATE_OFF   0

#include "basic.h"
#include "mc_type.h"
#include "absacc.h"
////////////////////////////////

#include "string.h"
#include "lks32mc03x.h"
#include "lks32mc03x_MCPWM.h"
#include "lks32mc03x_sys.h"
#include "lks32mc03x_adc.h"
#include "lks32mc03x_MCPWM.h"
#include "lks32mc03x_flash.h"
#include "lks32mc03x_gpio.h"
#include "lks32mc03x_DMA.h"
#include "lks32mc03x_cmp.h"
#include "lks32mc03x_uart.h"
#include "lks32mc03x_hall.h"
#include "lks32mc03x_timer.h"
#include "lks32mc03x_NVR.h"
#include "lks32mc03x_iwdg.h"
#include "lks32mc03x_dac.h"
#include "lks32mc03x_spi.h"
#include "lks32mc03x_I2C.h"
#include "delay.h"
//////////////////////////////////////
#include "interrupt.h"
#include "Global_Variable.h"
#include "hardware_config.h"
#include "function_config.h"
// #include "HandlerbarControl.h"
#include "hardware_init.h"
// #include "Etool_related.h"

// #include "bldc.h"
// #include "motor.h"
//#include "onfly.h"
//#include "NTC.h"
//#include "alarm.h"
// #include "fifo.h"
// #include "uartcmd.h"
// #include "font.h"
#include "delay.h"



#endif


