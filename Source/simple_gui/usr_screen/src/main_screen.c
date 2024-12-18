
#include "screen_proc.h"
#include "font_data.h"
#include "SGUI_Basic.h"
#include "SGUI_Text.h"

static HMI_ENGINE_RESULT    HMI_main_screen_Prepare(SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters);
static HMI_ENGINE_RESULT    HMI_main_screen_RefreshScreen(SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters);
static HMI_ENGINE_RESULT    HMI_main_screen_ProcessEvent(SGUI_SCR_DEV* pstDeviceIF, const HMI_EVENT_BASE* pstEvent, SGUI_INT* piActionID);
static HMI_ENGINE_RESULT    HMI_main_screen_PostProcess(SGUI_SCR_DEV* pstDeviceIF, HMI_ENGINE_RESULT eProcResult, SGUI_INT iActionID);


HMI_SCREEN_ACTION s_st_main_screen_actions = { 
    NULL,
    HMI_main_screen_Prepare,
    HMI_main_screen_RefreshScreen,
    HMI_main_screen_ProcessEvent,
    HMI_main_screen_PostProcess
};


HMI_SCREEN_OBJECT g_stHMI_main_screen = {
    HMI_SCREEN_ID_MAIN_SCREEN,
    &s_st_main_screen_actions
};


HMI_ENGINE_RESULT HMI_main_screen_Prepare (SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters)
{
    if (NULL != pstDeviceIF->fnClear) {
        pstDeviceIF->fnClear();
    } else {
        SGUI_Basic_DrawRectangle(pstDeviceIF, 0, 0, pstDeviceIF->stSize.iWidth, pstDeviceIF->stSize.iHeight, SGUI_COLOR_BKGCLR, SGUI_COLOR_BKGCLR);
    }
    HMI_main_screen_RefreshScreen(pstDeviceIF, pstParameters);
    return HMI_RET_NORMAL;
}


HMI_ENGINE_RESULT HMI_main_screen_RefreshScreen(SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters)
{

    SGUI_RECT stDisplayArea;
    SGUI_POINT stInnerPos;
    SGUI_INT torque;
    SGUI_INT angle;
    SGUI_CHAR buff[8];

    torque = 8639;
    memset(buff, 0, sizeof(buff));
    SGUI_Common_IntegerToString(torque, buff, 10, -1, ' ');

    stInnerPos.iX = 0;
    stInnerPos.iY = 0;

    stDisplayArea.iX = 2;
    stDisplayArea.iY = 3;
    stDisplayArea.iWidth = 108;
    stDisplayArea.iHeight = font_inconsolata_regular_12.iHeight;
    SGUI_Text_DrawText(pstDeviceIF, CLOCKWISE, &font_inconsolata_regular_12, &stDisplayArea, &stInnerPos, SGUI_DRAW_NORMAL);

    SGUI_Basic_DrawHorizontalLine(pstDeviceIF, 0, 128, 17, SGUI_COLOR_FRGCLR);
    SGUI_Basic_DrawHorizontalLine(pstDeviceIF, 0, 128, 42, SGUI_COLOR_FRGCLR);

    // display torque
    stDisplayArea.iX = 2;
    stDisplayArea.iY = 19;
    stDisplayArea.iWidth = font_inconsolata_bold_22.iHalfWidth * 5;
    stDisplayArea.iHeight = font_inconsolata_bold_22.iHeight;
    SGUI_Text_DrawText(pstDeviceIF, buff, &font_inconsolata_bold_22, &stDisplayArea, &stInnerPos, SGUI_DRAW_REVERSE);

    stDisplayArea.iX = 110;
    stDisplayArea.iY = 29;
    stDisplayArea.iWidth = 20;
    stDisplayArea.iHeight = font_inconsolata_regular_12.iHeight;
    SGUI_Text_DrawText(pstDeviceIF, "Nm", &font_inconsolata_regular_12, &stDisplayArea, &stInnerPos, SGUI_DRAW_NORMAL);

    // display angle
    stDisplayArea.iX = 2;
    stDisplayArea.iY = 44;
    stDisplayArea.iWidth = font_inconsolata_bold_22.iHalfWidth * 3;
    stDisplayArea.iHeight = font_inconsolata_bold_22.iHeight;

    angle = 60;
    memset(buff, 0, sizeof(buff));
    SGUI_Common_IntegerToString(angle, buff, 10, -1, ' ');
    SGUI_Text_DrawText(pstDeviceIF, buff, &font_inconsolata_bold_22, &stDisplayArea, &stInnerPos, SGUI_DRAW_REVERSE);

    stDisplayArea.iX = 88;
    stDisplayArea.iY = 52;
    stDisplayArea.iWidth = 40;
    stDisplayArea.iHeight = font_inconsolata_regular_12.iHeight;
    SGUI_Text_DrawText(pstDeviceIF, "degree", &font_inconsolata_regular_12, &stDisplayArea, &stInnerPos, SGUI_DRAW_NORMAL);

    return HMI_RET_NORMAL;
}


HMI_ENGINE_RESULT HMI_main_screen_ProcessEvent(SGUI_SCR_DEV* pstDeviceIF, const HMI_EVENT_BASE* pstEvent, SGUI_INT* piActionID)
{
    HMI_ENGINE_RESULT           eProcessResult;
    SGUI_INT                    iProcessAction;

    eProcessResult =            HMI_RET_NORMAL;
    iProcessAction =            HMI_DEMO_PROC_NO_ACT;

    if (EVENT_ID_KEY_PRESS == pstEvent->id) {
        iProcessAction = HMI_DEMO_PROC_CANCEL;
    }

    if (NULL != piActionID) {
        *piActionID = iProcessAction;
    }

    return eProcessResult;
}


HMI_ENGINE_RESULT HMI_main_screen_PostProcess(SGUI_SCR_DEV* pstDeviceIF, HMI_ENGINE_RESULT eProcResult, SGUI_INT iActionID)
{
    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    if(HMI_PROCESS_SUCCESSFUL(eProcResult))
    {
        if(HMI_DEMO_PROC_CANCEL == iActionID)
        {
            // HMI_GoBack(NULL);
            HMI_SwitchScreen(HMI_SCREEN_ID_MAIN_LIST, NULL);
        }
    }

    return HMI_RET_NORMAL;
}

