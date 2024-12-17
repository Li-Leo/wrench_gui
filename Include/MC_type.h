
#ifndef __MC_TYPE_H
#define __MC_TYPE_H

#include "basic.h"

/*! Macro converting a signed fractional [-1,1) number into a fixed point 16-bit
 * number in the format Q1.15. */
#define FRAC16(x)           ((s16) ((x) < (S16_MAX) ? ((x) >= S16_MIN ? (x)*0x8000 : 0x8000) : 0x7fff))

/*! Macro converting a signed fractional [-1,1) number into a fixed point 32-bit
 * number in the format Q1.31. */
#define FRAC32(x)           ((s32) ((x) < (S32_MAX) ? ((x) >= S32_MIN ? (x)*0x80000000 : 0x80000000) : 0x7fffffff))

#define ABS(X)              ( ( (X) >= 0 ) ? (X) : -(X) )

#define sat(x,ll,ul) ( (x) > (ul) ) ? (ul) : ( ( (x) < (ll) ) ? (ll) : (x) )
// set X value   Min --- Max
#define LimitTheSizeMinVsMax(x,min,max) ( (x) > (max) ) ? (max) : ( ( (x) < (min) ) ? (min) : (x) )

enum 
{
    MODE_CW_FAN = 0,    // CW£ºclockwise Ë³Ê±Õë
    MODE_CCW_ZHEN        // CCW£ºcounterclockwise ÄæÊ±Õë
} ;

typedef const struct
{	
    u16 hPWM_LOW_ON_IO01;
    u16 hPWM_LOW_ON_IO23;
    u16 hPWM_PERIOD;
    u16 SeekPosWidth;
} Stru_BLDC_Control_Parama, *pStru_BLDC_Control_Parama;

#define U8_MAX     ((u8)255)
#define S8_MAX     ((s8)127)
#define S8_MIN     ((s8)-128)
#define U16_MAX    ((u16)65535u)
#define S16_MAX    ((s16)32767)
#define S16_MIN    ((s16)-32768)
#define U32_MAX    ((u32)4294967295uL)
#define S32_MAX    ((s32)2147483647)
#define S32_MIN    ((s32)-2147483648)

#define S16P80     ((s16)26213)
#define S16P65     ((s16)25000)
#define S16P50     ((s16)13000)
#define S16P95     ((s16)30000)

#define SHORT_ERROR             BIT0    // ¶ÌÂ·¹ÊÕÏ
#define LOW_VOL_ERROR           BIT1    // µÍÑ¹¹ÊÕÏ
#define HIG_VOL_ERROR           BIT2    // ¹ýÑ¹¹ÊÕÏ
#define OV_TEMPER_ERROR         BIT3    // ¹ýÎÂ¹ÊÕÏ
#define OVER_LOAD_ERROR         BIT4    // ¹ýÔØ¹ÊÕÏ
#define OVER_TIME_ERROR         BIT5    // ³¬Ê±»»Ïà¹ÊÕÏ
#define MOSFET_ERROR            BIT6    // MOSFET¹ÊÕÏ
#define BLOCK_ERROR             BIT7   // µç»ú¶à´Î¶Â×ª¹ÊÕÏ
#define OV_MOS_TEMPER_ERROR     BIT8   //
#define OV_BAT_TEMPER_ERROR     BIT9   //

#endif


