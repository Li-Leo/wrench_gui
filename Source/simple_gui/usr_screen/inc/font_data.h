#include "stdint.h"
#include "SGUI_Typedef.h"

#ifndef __FONT_DATA_H__
#define __FONT_DATA_H__

typedef struct {
	uint16_t char_code;
	const unsigned char *data;
	unsigned char width;	//in pixels
	unsigned char height;	//in pixels
} char_info_t;

typedef enum {
	INCONSOLATA_REGULAR_12,
	INCONSOLATA_REGULAR_16,
	INCONSOLATA_BOLD_20,
} font_name_t;

typedef struct {
	font_name_t name;
	const char_info_t *char_info;
	int half_width;
	int height;
	int total_count;
} font_t;


extern const char_info_t inconsolata_regular_12[];
extern const char_info_t inconsolata_regular_16[];
extern const char_info_t inconsolata_bold_20[];

extern const SGUI_FONT_RES font_inconsolata_regular_12;
extern const SGUI_FONT_RES font_inconsolata_regular_16;
extern const SGUI_FONT_RES font_inconsolata_bold_20;


void set_display_font(font_name_t name);

// const SGUI_FONT_RES font_15 ;

#endif
