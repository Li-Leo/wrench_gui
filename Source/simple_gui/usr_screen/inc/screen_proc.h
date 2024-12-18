#ifndef __INCLUDE_DEMO_PROC_H__
#define __INCLUDE_DEMO_PROC_H__
//=======================================================================//
//= Include files.                                                      =//
//=======================================================================//
#include <stdlib.h>
#include <stdio.h>
#include "SGUI_Typedef.h"
#include "SGUI_Common.h"
#include "HMI_Engine.h"
#include "DemoActions.h"
#include "Resource.h"

//=======================================================================//
//= Data type definition.                                               =//
//=======================================================================//
// HMI action type
typedef enum
{
    EVENT_ID_UNKNOW =               0,
    // User defined action type.
    EVENT_ID_KEY_PRESS,
    EVENT_ID_TIMER,
    EVENT_ID_RTC,
    // User defined action above.
    EVENT_ID_MAX
}EVENT_ID;

// HMI event type.
typedef enum
{
    EVENT_TYPE_ANY =                0,
    EVENT_TYPE_ACTION,
    EVENT_TYPE_DATA,
} EVENT_TYPE;

enum DEMO_PROC_ACTION_ID
{
    HMI_DEMO_PROC_NO_ACT =          0,
    HMI_DEMO_PROC_CONFIRM =         1,
    HMI_DEMO_PROC_CANCEL =          2,
};

typedef struct
{
    SGUI_UINT16     uiKeyValue;
}KEY_EVENT_DATA;

typedef struct
{
    SGUI_INT        iValue;
}DUMMY_DATA_EVENT_DATA;

HMI_EVENT_TYPE_DECLARE(KEY_PRESS_EVENT, KEY_EVENT_DATA)
HMI_EVENT_TYPE_DECLARE(DATA_EVENT, DUMMY_DATA_EVENT_DATA);

//=======================================================================//
//= Macro definition.                                                   =//
//=======================================================================//
#define     HMI_SCREEN_ID_DEMO_SCROLLING_TEXT           (1001)
#define     HMI_SCREEN_ID_MAIN_SCREEN               (1002)
#define     HMI_SCREEN_ID_MAIN_LIST                     (1003)
#define     HMI_SCREEN_ID_DEMO_TEXT_NOTICE              (1004)
#define     HMI_SCREEN_ID_DEMO_BASIC_PAINT              (1005)
#define     HMI_SCREEN_ID_DEMO_VARIABLE_BOX             (1006)
#define     HMI_SCREEN_ID_DEMO_REAL_TIME_GRAPH          (1007)
#define     HMI_SCREEN_ID_DEMO_MENU                     (1008)
#define     HMI_SCREEN_ID_DEMO_CURVE                    (1009)
#define     HMI_SCREEN_ID_DEMO_POLOR_COORD              (1010)

#define     HMI_SCREEN_ID_EXTENDED_LIST                  (1011)
#define     HMI_SCREEN_ID_SETTING_LIST                  (1012)

#define     DEMO_HEART_BEAT_INTERVAL_MS                 (20)

#define     DISPLAY_LINE_BUFF                 100


//=======================================================================//
//= Public variable declaration.                                        =//
//=======================================================================//
/* HMI engine object. */
extern HMI_ENGINE_OBJECT        g_stDemoEngine;

/* Screen display objects. */
extern HMI_SCREEN_OBJECT        g_stHMI_menu_List;
extern HMI_SCREEN_OBJECT		g_stHMI_extended_List;
extern HMI_SCREEN_OBJECT		g_stHMI_settings_List;
extern HMI_SCREEN_OBJECT		g_stHMI_main_screen;

//=======================================================================//
//= Function declare.                                                   =//
//=======================================================================//
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

void gui_main_process(void);
HMI_ENGINE_RESULT hmi_engine_obj_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif // __INCLUDE_DEMO_PROC_H__
