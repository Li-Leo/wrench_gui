#ifndef _CONNIE_DAC_H_
#define _CONNIE_DAC_H_

/* Includes ------------------------------------------------------------------*/
#include "lks32mc03x.h"
#include "basic.h"
typedef struct
{	
	  uint8_t DACOUT_EN;                /* DAC�����IOʹ�ܣ�0����ʹ�ܣ�1��ʹ�ܡ� */
}DAC_InitTypeDef;



void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);/* DAC�ṹ���ʼ�� */
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct);      /* DAC��ʼ�� */
void DAC_OutputValue(uint32_t DACValue);             /* DAC�����ֵ����--������ */
void DAC_OutputVoltage(uint16_t DACVoltage);         /* DAC���ģ������ֵ����--ģ���� */

#endif

