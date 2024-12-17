#ifndef __lks32mc03x_IWDG_H
#define __lks32mc03x_IWDG_H

/* Includes ------------------------------------------------------------------*/
#include "lks32mc03x.h"
#include "basic.h"

typedef struct
{
    __IO uint32_t PSW;
    __IO uint32_t CFG;
    __IO uint32_t CLR;
    __IO uint32_t WTH;
    __IO uint32_t RTH;
    __IO uint32_t CNT;
} IWDG_TypeDef;

typedef struct
{
    u32 DWK_EN;             // ������߶�ʱ����ʹ��
    u32 WDG_EN;             // �������Ź�ʹ��
    u32 WTH;                // ���Ź���ʱ����ʱ�䣨21λ������������12��λ0��
    u32 RTH;                // ���Ź���ʱ��λʱ��
}IWDG_InitTypeDef;

/*******************************************************************************
 �������ƣ�    u32 SECOND2IWDGCNT(float)
 ����������    ���Ź�ʱ�����
 ���������    ʱ�䣬��λS
 �� �� ֵ��    ���Ź�����ֵ
 ����˵����    RCʱ�Ӿ������ޣ�ȫ�¶ȷ�Χ������20%
               0x1000Ϊ�����ȡ��
 �޸�����      �汾��          �޸���            �޸�����
 -----------------------------------------------------------------------------
 2021/11/10    V1.0           Yangzj              ����
 *******************************************************************************/
#define SECOND2IWDGCNT(x)   ((u32)(64000*x)&0x1ff000)

void IWDG_Init(IWDG_InitTypeDef *);                 //���Ź���ʼ��
void IWDG_StrutInit(IWDG_InitTypeDef *);            //���Ź����ýṹ���ʼ��
void IWDG_DISABLE(void);                            //�رտ��Ź�
void IWDG_Feed(void);                               //���Ź�ι��
#endif 
