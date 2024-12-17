/*******************************************************************************
 * ��Ȩ���� (C)2015, LINKO SEMICONDUCTOR Co.ltd
 *
 * �ļ����ƣ� Control_Param.h
 * �ļ���ʶ��
 * ����ժҪ�� ��������ײ�ͷ�ļ�
 * ����˵���� ��
 * ��ǰ�汾�� V 1.0
 * ��    �ߣ� Howlet
 * ������ڣ� 2015��11��5��
 *
 * �޸ļ�¼1��
 * �޸����ڣ�2015��11��5��
 * �� �� �ţ�V 1.0
 * �� �� �ˣ�Howlet
 * �޸����ݣ�����
 *
 * �޸ļ�¼2��
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 *
 *******************************************************************************/
 
/*------------------------------prevent recursive inclusion -------------------*/
#ifndef __PWM_PARAM_H
#define __PWM_PARAM_H

/* ==============================PWM Ƶ�ʼ���������=========================== */
#define PWM_MCLK	((u32)50000000uL) /* PWMģ��������Ƶ */
#define PWM_PRSC ((u8)0) /* PWMģ������Ԥ��Ƶ�� */
#define PWM_FREQ ((u16)30000) /* PWMն��Ƶ�� */
/* PWM ���ڼ�����ֵ */
#define PWM_PERIOD ((u16) (PWM_MCLK / (u32)(2 * PWM_FREQ *(PWM_PRSC+1))))

#define DEADTIME_NS0 ((u16)800)/* ����ʱ�� */
#define DEADTIME_NS1 ((u16)1000)/* ����ʱ�� */
#define DEADTIME_NS2 ((u16)1200)/* ����ʱ�� */
#define DEADTIME_NS3 ((u16)1400)/* ����ʱ�� */
#define DEADTIME_NS4 ((u16)1600)/* ����ʱ�� */
#define DEADTIME_NS5 ((u16)1800)/* ����ʱ�� */
#define DEADTIME_NS6 ((u16)2000)/* ����ʱ�� */
#define DEADTIME_NS7 ((u16)2200)/* ����ʱ�� */

#define DEADTIME0  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS0)/1000000000uL)
#define DEADTIME1  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS1)/1000000000uL)
#define DEADTIME2  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS2)/1000000000uL)
#define DEADTIME3  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS3)/1000000000uL)
#define DEADTIME4  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS4)/1000000000uL)
#define DEADTIME5  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS5)/1000000000uL)
#define DEADTIME6  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS6)/1000000000uL)
#define DEADTIME7  (u16)(((unsigned long long)PWM_MCLK * (unsigned long long)DEADTIME_NS7)/1000000000uL)
   
#define MAX_MODULATION_100_PER_CENT
/* Current reading parameters ----------------------------------------------- */
///****************************�˴�����ABC ����������˿�  end**********************************************///



///****************************�˴��������ߵ�ѹ  �����˿�  start**********************************************///
#define VOL_BUS_ADC_CHANNEL     ADC_Channel_7   //PA_7
#define VOL_BUS_GPIO_PORT       GPIOA
#define VOL_BUS_GPIO_PIN        GPIO_Pin_7
///****************************�˴��������ߵ�ѹ  �����˿�  end**********************************************///



#define VOLATAGE_RAMP         15 /* 0.3V/S */



/*  Power Stage management Conversions setting */

#define SPEED_CMD_CHANNEL                 ADC_Channel_3
#define SPEED_CMD_CHANNEL_GPIO_PORT       GPIOA
#define SPEED_CMD_CHANNEL_GPIO_PIN        GPIO_Pin_3


#define BUS_VOLT_FDBK_CHANNEL             ADC_Channel_7
#define BUS_VOLT_FDBK_CHANNEL_GPIO_PORT   GPIOA
#define BUS_VOLT_FDBK_CHANNEL_GPIO_PIN    GPIO_Pin_7



/////////////////////////////Ƿѹ  ��ѹ �趨����  start////////////////////////////////
#define LOW_VOLATAGE_THD                  3000 /* 30VΪǷѹֵ */   
#define RSM_LO_VOLATAGE_THD               3100 /* Ƿѹ�ָ���ѹ */
#define OV_VOLTAGE_THD                    6100 /* ��ѹ�ż� */
#define RSM_OV_VOLTAGE_THD                5500 /* ��ѹ�ָ��ż� */
/////////////////////////////Ƿѹ  ��ѹ �趨����  end////////////////////////////////

#define BREAK_INPUT                       (GPIOA->IDR & GPIO_Pin_12)
#define LEARN_INPUT                       (GPIOB->IDR & GPIO_Pin_1)


#endif  /*__MC_PWM_3SHUNT_PRM_H*/

/************************ (C) COPYRIGHT LINKO SEMICONDUCTOR **********************/
/* ------------------------------END OF FILE------------------------------------ */
