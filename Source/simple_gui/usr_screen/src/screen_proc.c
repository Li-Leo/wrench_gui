
#include "screen_proc.h"
#include "SGUI_Typedef.h"
#include "SGUI_Basic.h"
#include "oled.h"
#include "key.h"
#include "DemoActions.h"


SGUI_SCR_DEV g_stDeviceInterface;
HMI_SCREEN_OBJECT* g_arrpstScreenObjs[] = {
                                &g_stHMIDemo_List,
                                &g_stHMI_extended_List,
                                &g_stHMI_settings_List,
                            };
HMI_ENGINE_OBJECT g_stDemoEngine;

SGUI_BYTE s_pBmpDataBuffer[DISPLAY_LINE_BUFF];
void key_press_event(void);
bool key_event_is_triggered(void);



HMI_ENGINE_RESULT InitializeHMIEngineObj(void)
{

    HMI_ENGINE_RESULT eProcessResult;
    int iIndex;
    eProcessResult = HMI_RET_NORMAL;

    SGUI_SystemIF_MemorySet(&g_stDeviceInterface, 0x00, sizeof(SGUI_SCR_DEV));
    SGUI_SystemIF_MemorySet(&g_stDemoEngine, 0x00, sizeof(HMI_ENGINE_OBJECT));

    /* Initialize display size. */
    g_stDeviceInterface.stSize.iWidth = 128;
    g_stDeviceInterface.stSize.iHeight = 64;
    g_stDeviceInterface.stBuffer.pBuffer = s_pBmpDataBuffer;
    g_stDeviceInterface.stBuffer.sSize = DISPLAY_LINE_BUFF;
    /* Initialize interface object. */
    g_stDeviceInterface.fnSetPixel = oled_draw_point;
    // g_stDeviceInterface.fnGetPixel = OLED_GetPoint;
    g_stDeviceInterface.fnClear = oled_clear;
    g_stDeviceInterface.fnSyncBuffer = oled_update;

    do {
        /* Prepare HMI engine object. */
        g_stDemoEngine.ScreenCount = sizeof(g_arrpstScreenObjs)/sizeof(*g_arrpstScreenObjs);
        g_stDemoEngine.ScreenObjPtr = g_arrpstScreenObjs;
        g_stDemoEngine.Interface = &g_stDeviceInterface;

        /* Initialize all screen object. */
        if(NULL != g_stDemoEngine.ScreenObjPtr)
        {
            for(iIndex=0; iIndex<g_stDemoEngine.ScreenCount; iIndex++)
            {
                if( (NULL != g_stDemoEngine.ScreenObjPtr[iIndex])
                    && (NULL != g_stDemoEngine.ScreenObjPtr[iIndex]->pstActions)
                    && (NULL != g_stDemoEngine.ScreenObjPtr[iIndex]->pstActions->Initialize)
                    )
                {
                    g_stDemoEngine.ScreenObjPtr[iIndex]->pstActions->Initialize(&g_stDeviceInterface);
                    g_stDemoEngine.ScreenObjPtr[iIndex]->pstPrevious = NULL;
                }
            }
        }
        else
        {

        }
        /* Active engine object. */
        eProcessResult = HMI_ActiveEngine(&g_stDemoEngine, HMI_SCREEN_ID_DEMO_LIST);
        //eProcessResult = HMI_ActiveEngine(&g_stDemoEngine, HMI_SCREEN_ID_DEMO_ITEMS_BASE);
        if(HMI_PROCESS_FAILED(eProcessResult))
        {
            /* Active engine failed. */
            break;
        }
        /* Start engine process. */
        eProcessResult = HMI_StartEngine(NULL);
        if(HMI_PROCESS_FAILED(eProcessResult))
        {
            /* Start engine failed. */
            break;
        }
    } while(0);

    return eProcessResult;
}


void gui_main_process(void)
{
    if (main_key_is_pressed() || up_key_is_pressed() || down_key_is_pressed()) {
        main_key_trigger_reset();
        up_key_trigger_reset();
        down_key_trigger_reset();

        key_press_event();
    }
}


void key_press_event(void)
{
    HMI_EVENT_BASE stEvent;

    stEvent.id = EVENT_ID_KEY_PRESS;
    stEvent.data = key_get_key_code();

    HMI_ProcessEvent(&stEvent);
}

bool key_event_is_triggered(void)
{
    if (main_key_is_pressed() || up_key_is_pressed() || down_key_is_pressed()) {
        main_key_trigger_reset();
        up_key_trigger_reset();
        down_key_trigger_reset();

        key_press_event();

        return true;
    }

    return false;
}


void SysTickTimerEnable(bool bEnable)
{
    
}


void key_value(uint16_t key)
{
    // USARTReceiveProc(USART_INT_REASON_REV, key);
}

