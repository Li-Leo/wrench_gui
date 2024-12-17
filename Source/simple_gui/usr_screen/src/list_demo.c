/*************************************************************************/
/** Copyright.                                                          **/
/** FileName: List.c                                                    **/
/** Author: Polarix                                                     **/
/** Description: HMI demo for list control interface.                   **/
/*************************************************************************/
//=======================================================================//
//= Include files.                                                      =//
//=======================================================================//
#include "screen_proc.h"
#include "SGUI_List.h"
#include "SGUI_FontResource.h"
#include "Resource.h"
#include "font_data.h"

//=======================================================================//
//= Macro definition.                                                   =//
//=======================================================================//
#define                 NOTICE_TEXT_BUFFER_SIZE             (64)

//=======================================================================//
//= Static function declaration.                                        =//
//=======================================================================//
static HMI_ENGINE_RESULT    HMI_DemoList_Initialize(SGUI_SCR_DEV* pstDeviceIF);
static HMI_ENGINE_RESULT    HMI_DemoList_Prepare(SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters);
static HMI_ENGINE_RESULT    HMI_DemoList_RefreshScreen(SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters);
static HMI_ENGINE_RESULT    HMI_DemoList_ProcessEvent(SGUI_SCR_DEV* pstDeviceIF, const HMI_EVENT_BASE* pstEvent, SGUI_INT* piActionID);
static HMI_ENGINE_RESULT    HMI_DemoList_PostProcess(SGUI_SCR_DEV* pstDeviceIF, HMI_ENGINE_RESULT eProcResult, SGUI_INT iActionID);

//=======================================================================//
//= Static variable declaration.                                        =//
//=======================================================================//

SGUI_CHAR password_extended[20] = "Password";

static SGUI_ITEMS_ITEM      s_arrstListItems[] =        {   {SCR1_LIST_ITEM1, NULL},
                                                            {SCR1_LIST_ITEM2, NULL},
                                                            {SCR1_LIST_ITEM3, NULL},
                                                            {SCR1_LIST_ITEM4, NULL},
                                                            {NULL, password_extended, NULL},
                                                            {SCR1_LIST_ITEM6, NULL},
                                                        };

typedef struct
{
    SGUI_ITEMS_ITEM stItem;
    SGUI_BOOL       bUsed;
}SGUI_TEST_ITEM;



static SGUI_LIST        s_stDemoListObject =        {0x00};

//=======================================================================//
//= Global variable declaration.                                        =//
//=======================================================================//
HMI_SCREEN_ACTION       s_stDemoListActions =           {   HMI_DemoList_Initialize,
                                                            HMI_DemoList_Prepare,
                                                            HMI_DemoList_RefreshScreen,
                                                            HMI_DemoList_ProcessEvent,
                                                            HMI_DemoList_PostProcess
                                                        };
HMI_SCREEN_OBJECT       g_stHMIDemo_List =              {   HMI_SCREEN_ID_DEMO_LIST,
                                                            &s_stDemoListActions
                                                        };

//=======================================================================//
//= Function define.                                                    =//
//=======================================================================//
HMI_ENGINE_RESULT HMI_DemoList_Initialize(SGUI_SCR_DEV* pstDeviceIF)
{
    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    SGUI_RECT                   stListLayout;
    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    // Initialize list data.
    SGUI_SystemIF_MemorySet(&s_stDemoListObject, 0x00, sizeof(SGUI_LIST));
     //Initialize list object.
    stListLayout.iX = 0;
    stListLayout.iY = 0;
    stListLayout.iWidth = pstDeviceIF->stSize.iWidth;
    stListLayout.iHeight = pstDeviceIF->stSize.iHeight;
    set_display_font(INCONSOLATA_REGULAR_12);
    SGUI_List_Initialize(&s_stDemoListObject, &stListLayout, &font_inconsolata_regular_12, NULL, s_arrstListItems, sizeof(s_arrstListItems)/sizeof(SGUI_ITEMS_ITEM));
    // SGUI_List_Initialize(&s_stDemoListObject, &stListLayout, &GB2312_FZXS12, SCR1_TITLE, s_arrstListItems, sizeof(s_arrstListItems)/sizeof(SGUI_ITEMS_ITEM));
    return HMI_RET_NORMAL;
}

HMI_ENGINE_RESULT HMI_DemoList_Prepare (SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters)
{
    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    SGUI_List_Repaint(pstDeviceIF, &s_stDemoListObject);
    return HMI_RET_NORMAL;
}

HMI_ENGINE_RESULT HMI_DemoList_RefreshScreen(SGUI_SCR_DEV* pstDeviceIF, const void* pstParameters)
{
    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    SGUI_List_Repaint(pstDeviceIF, &s_stDemoListObject);
    return HMI_RET_NORMAL;
}

HMI_ENGINE_RESULT HMI_DemoList_ProcessEvent(SGUI_SCR_DEV* pstDeviceIF, const HMI_EVENT_BASE* pstEvent, SGUI_INT* piActionID)
{
    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    HMI_ENGINE_RESULT           eProcessResult;
    SGUI_UINT16                 uiKeyCode;
    SGUI_UINT16                 uiKeyValue;
    SGUI_INT                    iProcessAction;
    // SGUI_SIZE                   sInsertDataIdx;
    // SGUI_ITEMS_ITEM*            pstItemObj;

    /*----------------------------------*/
    /* Initialize                       */
    /*----------------------------------*/
    eProcessResult =            HMI_RET_NORMAL;
    // pstKeyEvent =               (KEY_PRESS_EVENT*)pstEvent;
    iProcessAction =            HMI_DEMO_PROC_NO_ACT;

    if(EVENT_ID_KEY_PRESS == pstEvent->id)
    {
        uiKeyCode = pstEvent->data;
        uiKeyValue = KEY_CODE_VALUE(uiKeyCode);
        switch(uiKeyValue)
        {
            case KEY_VALUE_ENTER:
            {
                iProcessAction = HMI_DEMO_PROC_CONFIRM;
                break;
            }
            case KEY_VALUE_ESC:
            {
                iProcessAction = HMI_DEMO_PROC_CANCEL;
                break;
            }
            case KEY_VALUE_UP:
            {
                if(SGUI_List_GetSelection(&s_stDemoListObject)->iIndex > 0)
                {
                    SGUI_List_Selecte(&s_stDemoListObject, SGUI_List_GetSelection(&s_stDemoListObject)->iIndex-1);
                }
                SGUI_List_Repaint(pstDeviceIF, &s_stDemoListObject);
                break;
            }
            case KEY_VALUE_DOWN:
            {
                if(SGUI_List_GetSelection(&s_stDemoListObject)->iIndex < (s_stDemoListObject.stItems.iCount-1))
                {
                    SGUI_List_Selecte(&s_stDemoListObject, SGUI_List_GetSelection(&s_stDemoListObject)->iIndex+1);
                }
                SGUI_List_Repaint(pstDeviceIF, &s_stDemoListObject);
                break;
            }

            default:
            {
                break;
            }
        }
    }
    if(NULL != piActionID)
    {
        *piActionID = iProcessAction;
    }

    return eProcessResult;
}

HMI_ENGINE_RESULT HMI_DemoList_PostProcess(SGUI_SCR_DEV* pstDeviceIF, HMI_ENGINE_RESULT eProcResult, SGUI_INT iActionID)
{
    if(HMI_DEMO_PROC_CONFIRM == iActionID)
    {
        switch(SGUI_List_GetSelection(&s_stDemoListObject)->iIndex)
        {
            case 0:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_BASIC_PAINT, NULL);
                break;
            }
            case 1:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_PAINT_TEXT, NULL);
                break;
            }
            case 2:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_VARIABLE_BOX, NULL);
                break;
            }
            case 3:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_REAL_TIME_GRAPH, NULL);
                break;
            }
            case 4:
            {
                // HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_MENU, NULL);
                HMI_SwitchScreen(HMI_SCREEN_ID_EXTENDED_LIST, NULL);
                break;
            }
            case 5:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_TEXT_NOTICE, SCR7_NOTICE_TEXT);
                break;
            }
            case 6:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_CURVE, NULL);
                break;
            }
            case 7:
            {
                HMI_SwitchScreen(HMI_SCREEN_ID_DEMO_POLOR_COORD, NULL);
                break;
            }
            default:
            {
                /* do nothing. */
            }
        }
    }
    else if(HMI_DEMO_PROC_CANCEL == iActionID)
    {
        HMI_GoBack(NULL);
    }

    return HMI_RET_NORMAL;
}



