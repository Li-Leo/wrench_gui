#include "font_data.h"
#include "SGUI_Typedef.h"

SGUI_INT get_char_index(SGUI_UINT32 uiCode, const SGUI_FONT_RES* font);
SGUI_BOOL char_is_fullwidth(SGUI_UINT32 uiCode);
SGUI_CSZSTR step_next_char_code(SGUI_CSZSTR cszSrc, SGUI_UINT32* puiCode);
SGUI_SIZE get_char_data(SGUI_SIZE sStartAddr, SGUI_BYTE* pDataBuffer, SGUI_SIZE sReadSize, const SGUI_FONT_RES* font);

const char_info_t* get_font(font_name_t name);
int get_font_size(font_name_t name);


font_t all_font_info[] = {
	{inconsolata_regular_12, 6, 12, 90},
	{inconsolata_regular_16, 8, 16, 52},
	{inconsolata_bold_22, 12, 22, 24},
};

const SGUI_FONT_RES font_inconsolata_regular_12 = {
	6,
	12,
	12,
	INCONSOLATA_REGULAR_12,
	get_char_index,
	get_char_data,
	step_next_char_code,
	char_is_fullwidth
};

const SGUI_FONT_RES font_inconsolata_regular_16 = {
	8,
	16,
	16,
	INCONSOLATA_REGULAR_16,
	get_char_index,
	get_char_data,
	step_next_char_code,
	char_is_fullwidth
};



const SGUI_FONT_RES font_inconsolata_bold_22 = {
	12,
	22,
	22,
	INCONSOLATA_BOLD_22,
	get_char_index,
	get_char_data,
	step_next_char_code,
	char_is_fullwidth
};


SGUI_INT get_char_index(SGUI_UINT32 uiCode, const SGUI_FONT_RES* font)
{
	for (int i = 0; i < get_font_size(font->current_font); i++) {
		if (uiCode == get_font(font->current_font)[i].char_code) {
			return i;
		}
	}
	return -1;
}

SGUI_CSZSTR step_next_char_code(SGUI_CSZSTR cszSrc, SGUI_UINT32* puiCode)
{
    const SGUI_CHAR* p;
    SGUI_UINT32 uiCode;
	int bytes = 0;

    p = cszSrc;
    uiCode = 0;


    if (NULL != p) {
        do {
			if ((*p & 0x80) == 0) {
            	// 1-byte character (ASCII)
            	uiCode = *p;
				bytes = 1;
			} else if ((*p & 0xE0) == 0xC0) {
				// 2-byte character
				uiCode = *p & 0x1F;
				bytes = 2;
			} else if ((*p & 0xF0) == 0xE0) {
				// 3-byte character
				uiCode = *p & 0x0F;
				bytes = 3;
			} else if ((*p & 0xF8) == 0xF0) {
				// 4-byte character
				uiCode = *p & 0x07;
				bytes = 4;
			} else {
				// Invalid UTF-8 byte
				// printf("Invalid UTF-8 sequence\n");
				// return;
			}
			// Read the remaining bytes
			for (int i = 1; i < bytes; ++i) {
				p++;
				if ((*p & 0xC0) != 0x80) {
					// printf("Invalid UTF-8 sequence\n");
					// return -1;
				}
				uiCode = (uiCode << 6) | (*p & 0x3F);
			}
			p++;
        } while(0);
    }
    *puiCode = uiCode;
	// printf("U+%04X ", uiCode);

    return p;
}

SGUI_BOOL char_is_fullwidth(SGUI_UINT32 uiCode)
{
    SGUI_BOOL bReturn;

    if (uiCode < 0x7F) {
        bReturn = SGUI_FALSE;
    } else {
        bReturn = SGUI_TRUE;
    }

    return bReturn;
}

const char_info_t* get_font(uint8_t index)
{
	return all_font_info[index].char_info;
}

int get_font_half_width(uint8_t index)
{
	return all_font_info[index].half_width;
}

int get_font_height(uint8_t index)
{
	return all_font_info[index].height;
}

int get_font_size(uint8_t index)
{
	return all_font_info[index].total_count;
}

SGUI_SIZE get_char_data(SGUI_SIZE sStartAddr, SGUI_BYTE* pDataBuffer, SGUI_SIZE sReadSize, const SGUI_FONT_RES* font)
{
    SGUI_SIZE sReadCount;
    const SGUI_BYTE* pSrc;
    SGUI_BYTE* pDest;
	int index;

	index = sStartAddr / (get_font_half_width(font->current_font) * (((get_font_height(font->current_font) - 1) / 8) + 1));
	// printf("index = %d, sReadSize = %d,  %d %d, %d \n", index, sReadSize, sStartAddr, get_font_half_width(g_set_font), (get_font_height(g_set_font) - 1) / 8 + 1);

    pSrc = get_font(font->current_font)[index].data;
    pDest = pDataBuffer;

    if (NULL != pDataBuffer) {
        for (sReadCount = 0; sReadCount < sReadSize; sReadCount++) {
            *pDest++ = *pSrc++;
        }
    }
    return sReadCount;
}


// static const unsigned char font_2713[] = {//✓
// 0x00,0x00,0x40,0x80,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,
// 0xf0,0xf0,0xf0,0xf0,0xf1,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,
// };



