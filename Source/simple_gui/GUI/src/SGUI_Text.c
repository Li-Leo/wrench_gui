/*************************************************************************/
/** Copyright.                                                          **/
/** FileName: SGUI_Text.c                                               **/
/** Author: XuYulin                                                     **/
/** Description: Text display interface                                 **/
/*************************************************************************/

//=======================================================================//
//= Include files.                                                      =//
//=======================================================================//
#include "SGUI_Text.h"

//=======================================================================//
//= Public variable declaration.                                        =//
//=======================================================================//
SGUI_CSZSTR     SGUI_EMPTY_STRING = {""};

//=======================================================================//
//= Static function declaration.                                        =//
//=======================================================================//

//=======================================================================//
//= Function define.                                                    =//
//=======================================================================//
/*************************************************************************/
/** Function Name:  SGUI_Text_GetTextExtent                             **/
/** Purpose:        Get the area size if show given text completely.    **/
/** Params:                                                             **/
/** @ szText[in]:   Text array pointer.                                 **/
/** @ pstFontRes[in]: Font resource, improve font size info.            **/
/** @ pstTextExtent[out]: Text extent size.                             **/
/** Return:         Next character X coordinate in current line.        **/
/** Limitation:     None.                                               **/
/*************************************************************************/
void SGUI_Text_GetTextExtent(SGUI_CSZSTR cszText, const SGUI_FONT_RES* pstFontRes, SGUI_AREA_SIZE* pstTextExtent)
{
    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    const SGUI_CHAR*            pcChar;
    SGUI_UINT32                 uiCharacterCode;

    /*----------------------------------*/
    /* Initialize                       */
    /*----------------------------------*/
    pcChar =                    (SGUI_CSZSTR)ENCODE(cszText);

    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    if((NULL != pcChar) && (NULL != pstTextExtent))
    {
        pstTextExtent->iHeight = pstFontRes->iHeight;
        pstTextExtent->iWidth=0;
        while('\0' != *pcChar)
        {
            uiCharacterCode = 0;
            pcChar = pstFontRes->fnStepNext(pcChar, &uiCharacterCode);
            if('\0' !=uiCharacterCode)
            {
                pstTextExtent->iWidth+=(pstFontRes->fnIsFullWidth(uiCharacterCode)?pstFontRes->iFullWidth:pstFontRes->iHalfWidth);
            }
        }
    }
}

/*************************************************************************/
/** Function Name:  SGUI_Text_DrawASCIICharacter                        **/
/** Purpose:        Write a single line text in a fixed area.           **/
/** Params:                                                             **/
/** @ pstDeviceIF[in]: SimpleGUI object pointer.                        **/
/** @ cChar[in]:    Character, only allow ASCII characters.             **/
/** @ pstFontRes[in]: Font resource object.                             **/
/** @ pstDisplayArea[in]: Display area size.                            **/
/** @ pstInnerPos[in]: Character paint position in display area.        **/
/** @ eFontMode[in] Character display mode(normal or reverse color).    **/
/** Return:         None.                                               **/
/*************************************************************************/
void SGUI_Text_DrawASCIICharacter(SGUI_SCR_DEV* pstDeviceIF, SGUI_CHAR cChar, const SGUI_FONT_RES* pstFontRes, const SGUI_RECT* pstDisplayArea, const SGUI_POINT* pstInnerPos, SGUI_DRAW_MODE eFontMode)
{
	/*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    SGUI_BMP_RES                stCharBitmap;

	/*----------------------------------*/
    /* Initialize                       */
    /*----------------------------------*/
	stCharBitmap.iHeight = pstFontRes->iHeight;
	stCharBitmap.iWidth = pstFontRes->iHalfWidth;
	stCharBitmap.pData = pstDeviceIF->stBuffer.pBuffer;

	/*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    if((cChar < 0x7F) && (pstInnerPos->iX < (pstDisplayArea->iX+pstDisplayArea->iWidth)))
	{
		SGUI_Text_GetCharacterData(pstFontRes, cChar, pstDeviceIF->stBuffer.pBuffer, pstDeviceIF->stBuffer.sSize);
		SGUI_Basic_DrawBitMap(pstDeviceIF, pstDisplayArea, pstInnerPos, &stCharBitmap, eFontMode);
	}
}

/*************************************************************************/
/** Function Name:  SGUI_Text_DrawSingleLineText                        **/
/** Purpose:        Write a single line text in a fixed area.           **/
/** Params:                                                             **/
/** @ pstDeviceIF[in]:  SimpleGUI object pointer.                       **/
/** @ cszText[in]:  Text array pointer.                                 **/
/** @ pstFontRes[in]: Font resource object.                             **/
/** @ pstDisplayArea[in]: Display area size.                            **/
/** @ pstInnerPos[in]: Text paint position in display area.             **/
/** @ eFontMode[in] Character display mode(normal or reverse color).    **/
/** Return:         None.                                               **/
/*************************************************************************/
void SGUI_Text_DrawText(SGUI_SCR_DEV* pstDeviceIF, SGUI_CSZSTR cszText, const SGUI_FONT_RES* pstFontRes, const SGUI_RECT* pstDisplayArea, const SGUI_POINT* pstInnerPos, SGUI_DRAW_MODE eFontMode)
{

    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    const SGUI_CHAR*            pcChar = (SGUI_CSZSTR)ENCODE(cszText);// Text character pointer.
    SGUI_UINT32                 uiCharacterCode;                // Character byte, might be tow bytes.
    SGUI_COLOR                  eBackColor = (eFontMode == SGUI_DRAW_NORMAL)?SGUI_COLOR_BKGCLR:SGUI_COLOR_FRGCLR;
    SGUI_BMP_RES                stCharBitmap;
    SGUI_POINT                  stPaintPos;

    // (SGUI_RECT_X_START(*pstDisplayArea) < SGUI_RECT_WIDTH(pstDeviceIF->stSize))

    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    if((NULL != pcChar) && (SGUI_RECT_X_START(*pstDisplayArea) < SGUI_RECT_WIDTH(pstDeviceIF->stSize)))
    {
        // Adapt text display area and data area.
        //-SGUI_Common_AdaptDisplayInfo(pstDisplayArea, pstInnerPos);
        // Clear text area.
        SGUI_Basic_DrawRectangle(pstDeviceIF, SGUI_RECT_X_START(*pstDisplayArea), SGUI_RECT_Y_START(*pstDisplayArea),
                        SGUI_RECT_WIDTH(*pstDisplayArea), SGUI_RECT_HEIGHT(*pstDisplayArea),
                        eBackColor, eBackColor);
        // Initialize drawing area data.
        SGUI_RECT_X_START(stPaintPos) = SGUI_RECT_X_START(*pstInnerPos);
        SGUI_RECT_Y_START(stPaintPos) = SGUI_RECT_Y_START(*pstInnerPos);
        SGUI_RECT_HEIGHT(stCharBitmap) = pstFontRes->iHeight;
        stCharBitmap.pData = pstDeviceIF->stBuffer.pBuffer;

        // Loop for Each char.
        while(((NULL != pcChar) && ('\0' != *pcChar)) && (SGUI_RECT_X_START(stPaintPos) < SGUI_RECT_WIDTH(*pstDisplayArea)))
        {
            uiCharacterCode = 0;
            pcChar = pstFontRes->fnStepNext(pcChar, &uiCharacterCode);
            //if(SGUI_IS_VISIBLE_CHAR(uiCharacterCode))
            {
                SGUI_RECT_WIDTH(stCharBitmap) = pstFontRes->fnIsFullWidth(uiCharacterCode)?pstFontRes->iFullWidth:pstFontRes->iHalfWidth;
                if((stPaintPos.iX+stCharBitmap.iWidth-1) >= 0)
                {
                    SGUI_Text_GetCharacterData(pstFontRes, uiCharacterCode, pstDeviceIF->stBuffer.pBuffer, pstDeviceIF->stBuffer.sSize);
                    SGUI_Basic_DrawBitMap(pstDeviceIF, pstDisplayArea, &stPaintPos, &stCharBitmap, eFontMode);
                }
                SGUI_RECT_X_START(stPaintPos) += SGUI_RECT_WIDTH(stCharBitmap);
            }
        }
    }
}

/*************************************************************************/
/** Function Name:  GUI_DrawMultipleLinesText                           **/
/** Purpose:        Write a mulitiplt line text in a rectangular area.  **/
/** Params:                                                             **/
/** @ pstDeviceIF[in]:  SimpleGUI object pointer.                           **/
/** @ cszText[in]:  Text array pointer.                                 **/
/** @ pstFontRes[in]: Font resource object.                             **/
/** @ pstDisplayArea[in]: Display area size.                            **/
/** @ iTopOffset[in]: Text paint offset in vertical.                    **/
/** @ eFontMode[in]: Character display mode(normal or reverse color).   **/
/** Return:         Used line count.                                    **/
/** Notice:         None.                                               **/
/*************************************************************************/
SGUI_SIZE SGUI_Text_DrawMultipleLinesText(SGUI_SCR_DEV* pstDeviceIF, SGUI_CSZSTR cszText, const SGUI_FONT_RES* pstFontRes, SGUI_RECT* pstDisplayArea, SGUI_INT iTopOffset, SGUI_DRAW_MODE eFontMode)
{
    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    const SGUI_CHAR*            pcChar;
    SGUI_UINT32                 uiCharacterCode;
    SGUI_SIZE                   uiLines;
    SGUI_COLOR                  eBackColor;
    SGUI_BMP_RES                stCharBitmap;
    SGUI_POINT                  stPaintPos;
    SGUI_INT                    iStartOffsetX;

    /*----------------------------------*/
    /* Initialize                       */
    /*----------------------------------*/
    pcChar =                    (SGUI_CSZSTR)ENCODE(cszText);
    uiCharacterCode =           0;
    uiLines =                   0;
    eBackColor =                (eFontMode == SGUI_DRAW_NORMAL)?SGUI_COLOR_BKGCLR:SGUI_COLOR_FRGCLR;

    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    if((cszText != NULL) && (SGUI_RECT_X_START(*pstDisplayArea) < SGUI_RECT_WIDTH(pstDeviceIF->stSize)))
    {
        // Initialize drawing position.
        SGUI_RECT_X_START(stPaintPos) = 0;
        SGUI_RECT_Y_START(stPaintPos) = iTopOffset;
        // Adapt text display area and data area.
        SGUI_Common_AdaptDisplayInfo(pstDisplayArea, &stPaintPos);
        iStartOffsetX = stPaintPos.iX;
        // Clear text area.
        SGUI_Basic_DrawRectangle(pstDeviceIF,
                        SGUI_RECT_X_START(*pstDisplayArea), SGUI_RECT_Y_START(*pstDisplayArea),
                        SGUI_RECT_WIDTH(*pstDisplayArea), SGUI_RECT_HEIGHT(*pstDisplayArea),
                        eBackColor, eBackColor);
        
        SGUI_RECT_HEIGHT(stCharBitmap) = pstFontRes->iHeight;
        uiLines = 1;
        stCharBitmap.pData = pstDeviceIF->stBuffer.pBuffer;
        // Loop for each word in display area.
        while(((NULL != pcChar) && ('\0' != *pcChar)))
        {
            uiCharacterCode = 0;
            pcChar = pstFontRes->fnStepNext(pcChar, &uiCharacterCode);

            // Judge change line symbol.
            if(uiCharacterCode == '\n')
            {
                // Change lines.
                SGUI_RECT_X_START(stPaintPos) = iStartOffsetX;
                SGUI_RECT_Y_START(stPaintPos) += pstFontRes->iHeight;
                uiLines ++;
                continue;
            }
            // Get character width;
            SGUI_RECT_WIDTH(stCharBitmap) = pstFontRes->fnIsFullWidth(uiCharacterCode)?pstFontRes->iFullWidth:pstFontRes->iHalfWidth;

            // Judge change line
            if((stPaintPos.iX+stCharBitmap.iWidth-1) >= SGUI_RECT_WIDTH(*pstDisplayArea))
            {
                // Change lines.
                SGUI_RECT_X_START(stPaintPos) = iStartOffsetX;
                SGUI_RECT_Y_START(stPaintPos) += pstFontRes->iHeight;
                uiLines ++;
            }
            // Draw characters.
            if(((stPaintPos.iX+stCharBitmap.iWidth-1) >= 0) && (SGUI_RECT_Y_START(stPaintPos) < SGUI_RECT_HEIGHT(*pstDisplayArea)))
            {
                // Draw character.
                SGUI_Text_GetCharacterData(pstFontRes, uiCharacterCode, pstDeviceIF->stBuffer.pBuffer, pstDeviceIF->stBuffer.sSize);
                SGUI_Basic_DrawBitMap(pstDeviceIF, pstDisplayArea, &stPaintPos, &stCharBitmap, eFontMode);
            }
            else
            {
                // character is not in visible area, ignore.
            }
            SGUI_RECT_X_START(stPaintPos) += SGUI_RECT_WIDTH(stCharBitmap);
        }
    }
    return uiLines;
}

/*************************************************************************/
/** Function Name:  SGUI_Text_GetMultiLineTextLines                     **/
/** Purpose:        Get a string's lines in a fixed width area.         **/
/** Resources:      None.                                               **/
/** Params:                                                             **/
/** @ cszText[in]:  Text array pointer.                                 **/
/** @ pstFontRes[in]: Font resource object.                             **/
/** @ uiDisplayAreaWidth[in]: Display area width.                       **/
/** Return:         String lines.                                       **/
/*************************************************************************/
SGUI_SIZE SGUI_Text_GetMultiLineTextLines(SGUI_CSZSTR cszText, const SGUI_FONT_RES* pstFontRes, SGUI_SIZE uiDisplayAreaWidth)
{
    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    SGUI_SIZE                   uiLineNumber, uiLineLength;
    SGUI_UINT32                 uiCharacterCode;
    SGUI_UINT16                 uiCharWidth;
    SGUI_CSZSTR                 pcChar;

    /*----------------------------------*/
    /* Initialize                       */
    /*----------------------------------*/
    uiLineLength =              0;
    uiLineNumber =              1;
    pcChar =                    (SGUI_CSZSTR)ENCODE(cszText);

    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    while('\0' != *pcChar)
    {
        uiCharacterCode = 0;
        pcChar = pstFontRes->fnStepNext(pcChar, &uiCharacterCode);
        if('\n' == uiCharacterCode)
        {
            uiLineNumber++;
            uiLineLength = 0;
        }
        else
        {
            uiCharWidth = pstFontRes->fnIsFullWidth(uiCharacterCode)?pstFontRes->iFullWidth:pstFontRes->iHalfWidth;
            if((uiLineLength+uiCharWidth)>uiDisplayAreaWidth)
            {
                uiLineNumber++;
                uiLineLength = uiCharWidth;
            }
            else
            {
                uiLineLength+=uiCharWidth;
            }
        }
    }
    return uiLineNumber;
}

/*****************************************************************************/
/** Function Name:  SGUI_Text_GetCharacterData                              **/
/** Purpose:        Get character data form font resource by char code.     **/
/** Params:                                                                 **/
/** @ pstFontRes[in]:   Font resource structure pointer.                    **/
/** @ uiCode[in]:       Character code.                                     **/
/** @ pDataBuffer[out]: Buffer for output char data.                        **/
/** @ sBufferSize[in]:  Output buffer size.                                 **/
/** Return:             Number of read data, return 0 when error occurred.  **/
/*****************************************************************************/
SGUI_SIZE SGUI_Text_GetCharacterData(const SGUI_FONT_RES* pstFontRes, SGUI_UINT32 uiCode, SGUI_BYTE* pDataBuffer, SGUI_SIZE sBufferSize)
{
    /*----------------------------------*/
    /* Variable Declaration             */
    /*----------------------------------*/
    SGUI_SIZE                   sGetDataSize;
    SGUI_SIZE                   sReadDataSize;
    SGUI_SIZE                   sDataBlockSize;
    SGUI_INT                    iCharIndex;

    /*----------------------------------*/
    /* Initialize                       */
    /*----------------------------------*/
    sGetDataSize = 0;

    /*----------------------------------*/
    /* Process                          */
    /*----------------------------------*/
    if((NULL != pstFontRes) && (NULL != pDataBuffer) && (0 != sBufferSize))
    {
        iCharIndex = pstFontRes->fnGetIndex(uiCode, pstFontRes);
        if(SGUI_INVALID_INDEX != iCharIndex)
        {
            sDataBlockSize = SGUI_USED_BYTE(pstFontRes->iHeight)*(pstFontRes->iHalfWidth);
            sReadDataSize = pstFontRes->fnIsFullWidth(uiCode)?(SGUI_USED_BYTE(pstFontRes->iHeight)*(pstFontRes->iFullWidth)):sDataBlockSize;  // modified
            sGetDataSize = pstFontRes->fnGetData(iCharIndex*sDataBlockSize, pDataBuffer, sReadDataSize>sBufferSize?sBufferSize:sReadDataSize, pstFontRes);
        }
    }

    return sGetDataSize;
}
