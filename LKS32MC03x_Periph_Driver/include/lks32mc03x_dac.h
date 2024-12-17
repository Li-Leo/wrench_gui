#ifndef _CONNIE_DAC_H_
#define _CONNIE_DAC_H_

/* Includes ------------------------------------------------------------------*/
#include "lks32mc03x.h"
#include "basic.h"
typedef struct
{	
	  uint8_t DACOUT_EN;                /* DAC输出到IO使能：0，不使能；1，使能。 */
}DAC_InitTypeDef;



void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);/* DAC结构体初始化 */
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct);      /* DAC初始化 */
void DAC_OutputValue(uint32_t DACValue);             /* DAC输出数值设置--数字量 */
void DAC_OutputVoltage(uint16_t DACVoltage);         /* DAC输出模拟量数值设置--模拟量 */

#endif

