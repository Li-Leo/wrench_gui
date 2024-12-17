/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc03x_dsp.h
 * �ļ���ʶ��
 * ����ժҪ�� DSP����ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� 
 * ������ڣ� 
 *
 * �޸ļ�¼1��
 * �޸����ڣ�
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�
 * �޸����ݣ�����
 *
 * �޸ļ�¼2��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/
 
#ifndef __lks32mc03x_DSP_H
#define __lks32mc03x_DSP_H

/* Includes ------------------------------------------------------------------*/
#include "lks32mc03x_lib.h"
#include "basic.h"

typedef struct
{
	  s32 Dividend;     /* ������ */
	  s32 Divisor;      /* ����   */
    s16 Quotient;     /* ��     */
    s16 Remainder;    /* ����   */
} stru_DiviComponents;/* ��������ṹ�� */

void DSP_Cmd(FuncState state);                          /* DSPʹ�ܺ͹ر� */
void DSP_CalcDivision(stru_DiviComponents *stru_Divi);  /* DSP�������� */
uint32_t DSP_GetSqrt(u32 Data); /*DSPȡ�ÿ����� sprt(Data)*/

#endif 

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
