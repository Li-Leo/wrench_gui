/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� lks32mc08x_opa.h
 * �ļ���ʶ��
 * ����ժҪ�� OPA����ͷ�ļ�
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
 
#ifndef __lks32mc03x_OPA_H
#define __lks32mc03x_OPA_H


/* Includes ------------------------------------------------------------------*/
#include "lks32mc03x.h"
#include "basic.h"

typedef enum
{
   OPA = 0
	
}enumOPA;

typedef struct
{
   uint32_t OPA_Gain;         /*�˷űջ�����*/
   uint32_t OPA_CLEna;        /*�˷űջ�ʹ��:Enable,Disable*/
	uint32_t OPA_B_EN;         /*OPA0�˿�����ѡ��
	                            0��OPA0 ʹ�� OPA0_IN/OPA0_IP ��Ϊ�������
	                            1: OPA0 ʹ�� OPA0_IN_B/OPA0_IP_B ��Ϊ�������*/
}OPA_InitTypeDef;

/* ------------------------------PGA������ض��� ------------------------------ */
#define PGA_GAIN_20                    0x00                   /* ��������200:10 */
#define PGA_GAIN_9P5                   0x01                   /* ��������190:20 */
#define PGA_GAIN_6                     0x02                   /* ��������180:30 */
#define PGA_GAIN_4P25                  0x03                   /* ��������170:40 */                                                                                 

#define OPA0_IN_IP                     0x00                   /*OPA0ʹ�� OPA0_IN/OPA0_IP ��Ϊ�������*/
#define OPA0_IN_IP_B                   0x01                   /*OPA0ʹ�� OPA0_IN_B/OPA0_IP_B ��Ϊ�������*/

void OPA_Init(enumOPA opa, OPA_InitTypeDef* OPA_InitStruct);
void OPA_StructInit(OPA_InitTypeDef* OPA_InitStruct);
void OPA_OUT(enumOPA opa, FuncState state);

#endif /*__lks32mc08x_OPA_H */



/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR *****END OF FILE****/
